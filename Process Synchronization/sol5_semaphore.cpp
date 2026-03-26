#include<iostream>
#include<thread>
#include<semaphore>
using namespace std;

counting_semaphore<2> sem(2);
long long int count = 0;

void taskA(){
    sem.acquire();
    for (int i = 1; i <= 100; i++){
        cout <<i<< " Thread1 Running" << endl;
        count++;
    }
    cout << "Thread1 Finished" << endl;
    sem.release();
}

void taskB(){
    sem.acquire();
    for (int i = 1; i <= 100; i++){
        cout <<i<< " Thread2 Running" << endl;
        count++;
    }
    cout << "Thread2 Finished" << endl;
    sem.release();
}

void taskC(){
    sem.acquire();
    for (int i = 1; i <= 100; i++){
        cout <<i<< " Thread3 Running" << endl;
        count++;
    }
    cout << "Thread3 Finished" << endl;
    sem.release();
}

void taskD(){
    sem.acquire();
    for (int i = 1; i <= 100; i++){
        cout <<i<< " Thread4 Running" << endl;
        count++;
    }
    cout << "Thread4 Finished" << endl;
    sem.release();
}

void taskE(){
    sem.acquire();
    for (int i = 1; i <= 100; i++){
        cout <<i<< " Thread5 Running" << endl;
        count++;
    }
    cout << "Thread5 Finished" << endl;
    sem.release();
}
int main()
{
    thread t1(taskA);
    thread t2(taskB);
    thread t3(taskC);
    thread t4(taskD);
    thread t5(taskE);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    cout <<"Actual it should be: " << 500 << endl;
    cout <<"Count is: " << count << endl;

    return 0;
}


/*
void wait(int &S) {
    S--;
    if (S < 0) {
        // block process
    }
}

void signal(int &S) {
    S++;
    if (S <= 0) {
        // wake up one process
    }
}
*/
