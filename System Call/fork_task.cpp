#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
    int pid = fork();

    if(pid==0)
    {
        cout << "This is Child Process" << endl;
        for (int i = 0; i <= 4;i++)
        {
            cout << "Child Process Executing" << endl;
        }
    }
    else{
        cout << "This is Parent Process" << endl;
    }
    return 0;
}