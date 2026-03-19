#include<iostream>
#include<unistd.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    int pid = fork();

    if(pid==0)
    {
        cout << "This is Child Process" << endl;
        execl("./hello","hello",NULL);
        cout << "This is Child Process Finished" << endl;
        perror("execl failed");
    }
    else{
        wait(NULL);
        cout << "This is Parent Process" << endl;
    }
    return 0;
}