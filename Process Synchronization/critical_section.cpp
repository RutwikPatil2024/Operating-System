#include <iostream>
#include <thread>
using namespace std;
long long int count = 0;
void taskA()
{
    for (long long int i = 0; i < 1000000; i++)
    {
        count++;
    }
}

void taskB()
{
    for (long long int i = 0; i < 1000000; i++)
    {
        count++;
    }
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
//After running code for each time values are diffrent
// 1578448
// 1323964
// 1432573