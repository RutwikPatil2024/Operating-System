#include <iostream>
#include <thread>
using namespace std;
//peterson solution
long long int count = 0;//shared variable
bool flag[2] = {false, false};
int turn = 0;
void taskA()
{
    flag[0] = true;//this thread 0 want to enter
    turn = 1;//give chance to thread 1
    while(flag[1] and turn==1); //busy waiting
    for (long long int i = 0; i < 1000000; i++)
    {   
        //critical section
        count++;
    }
    flag[0] = false;
}

void taskB()
{
    flag[1] = true;//this thread 1 want to enter
    turn = 0;//give chance to thread 0
    while(flag[0] and turn==0); //busy waiting
    for (long long int i = 0; i < 1000000; i++)
    {   
        //critical section
        count++;
    }
    flag[1] = false;
}
int main()
{
    thread t1(taskA);
    thread t2(taskB);
    t1.join();
    t2.join();
    cout <<"Actual it should run this much time " <<(1000000 + 1000000)<<endl;
    cout <<"But it is running this much time " <<count;
    return 0;
}
// Actual it should run this much time 2000000
// But it is running this much time 2000000   