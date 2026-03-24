#include <iostream>
#include <thread>
using namespace std;

long long int count = 0;//shared variable
bool lock = false;
void taskA()
{
    while(lock);
    lock = true;//acquire the lock
    for (long long int i = 0; i < 1000000; i++)
    {   
        //critical section
        count++;
    }
    lock = false;//release the lock
}

void taskB()
{
    while(lock);
    lock = true;//acquire the lock
    for (long long int i = 0; i < 1000000; i++)
    {
        //critical section
        count++;
    }
    lock = false;//release the lock
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
// here data is consistent
// Actual it should run this much time 2000000
// But it is running this much time 2000000   