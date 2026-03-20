#include<iostream>
#include<unistd.h>
using namespace std;

int main()
{
    int fd[2];
    pipe(fd);
    
    int pid = fork();
    if(pid==0)
    {
        char msg[10];
        read(fd[0], msg, 10);
        cout << "Data Received " << msg << endl;
        cout << "Child Process" << endl;
    }
    else{
        write(fd[1], "Hello", 5);
        cout << "Data Send " << "Hello" << endl;
        cout << "This is Parent Process" << endl;
    }
    return 0;
}