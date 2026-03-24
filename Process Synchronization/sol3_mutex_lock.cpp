#include <iostream>
#include <thread>
#include<mutex>
using namespace std;
mutex mtx;
long long int count = 0;
void taskA()
{
    mtx.lock();//acquire the lock
    for (long long int i = 0; i < 1000000; i++)
    {   //critical section
        count++;
    }
    mtx.unlock();
}

void taskB()
{
    mtx.lock();//acquire the lock
    for (long long int i = 0; i < 1000000; i++)
    {   //critical section
        count++;
    }
    mtx.unlock();
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