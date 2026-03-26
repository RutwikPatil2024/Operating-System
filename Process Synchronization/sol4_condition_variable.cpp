#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;

long long int count = 0;
bool finished = false; 

void TaskA(){
    mtx.lock();//acquire the lock
    cout << "Thread1 is Running" << endl;
    for (long long int i = 0;i<1000000;i++)
    {
        //critical section
        count++;
    }
    finished = true;
    mtx.unlock();//release the lock
    cout << "Thread1 is Finished" << endl;

    cv.notify_one(); // notify waiting thread2
}

void TaskB(){

    unique_lock<mutex> lock(mtx);//acquire the lock
    cout << "Thread B is waiting"<<endl;
    cv.wait(lock,[]{return finished;});
    lock.unlock();
    for (long long int i = 0;i<1000000;i++)
    {
        //critical section
        count++;
    }
}
int main()
{
    thread t1(TaskA);
    thread t2(TaskB);

    t1.join();
    t2.join();

    cout <<"Actual it should run this much time " <<(1000000 + 1000000)<<endl;
    cout <<"But it is running this much time " <<count;
    return 0;
}


// We will use:
//   Thread 1 → increments count
//   Thread 2 → waits until Thread 1 finishes
//   Then Thread 2 continues

// 👉 Thread 2 should wait
// 👉 Thread 1 should notify when done

// cv.wait(lock,[]{return finished;});
// “Thread, sleep until finished becomes true.”
// If finished == true
// 👉 It does NOT sleep
// 👉 It continues immediately.
// If finished == false
// 👉 It goes to next step.