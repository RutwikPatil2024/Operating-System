#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
    int pid = fork();

    if (pid == 0) {
        cout<<"Child PID : "<<pid<<endl;
        cout << "Child Process" << endl;
    } else {
        cout<<"Parent PID : "<<pid<<endl;
        cout << "Parent Process" << endl;
    }

    return 0;
}