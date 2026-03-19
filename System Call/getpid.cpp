#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
    int pid = fork();

    if(pid==0){
        cout << "Child PID : " << getpid() << endl;
        cout << "This is Child Process" << endl;
        cout << "Parent of child: " << getppid() << endl;
    }
    else{
        cout << "Parent PID : " << getpid() << endl;
        cout << "This is Parent Process" << endl;
    }
    return 0;
}