#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

#define MAX 10

condition_variable cv1, cv2, cv3;
mutex m1;

//void fun1()
//{
//  for (int i = 0; i < 5; i++) {
//    unique_lock<mutex> ul(m1);
//    cv1.wait(ul);
//    cout << "A" << endl;
//    ul.unlock();
//    cv2.notify_one();
//  }
//}
//
//void fun2()
//{
//  for (int i = 0; i < 5; i++) {
//    unique_lock<mutex> ul(m1);
//    cv2.wait(ul);
//    cout << "B" << endl;
//    ul.unlock();
//    cv1.notify_one();
//  }
//}
//
//void main()
//{
//  thread t1(fun1);
//  thread t2(fun2);
//
//  cv1.notify_one();
//
//  t1.join();
//  t2.join();
//
//  getchar();
//}
int i;
void function1()
{
  while (i < MAX) {
    unique_lock<mutex> lock(m1);
    cv1.wait(lock);
    cout << "1" << endl;
    i++;
    lock.unlock();
    cv2.notify_one();
  }

}
void function2()
{
  while (i < MAX) {
    unique_lock<mutex> lock(m1);
    cv2.wait(lock);
    cout << "2" << endl;
    i++;
    lock.unlock();
    cv3.notify_one();
  }
}

void function3()
{
  while (i < MAX) {
    unique_lock<mutex> lock(m1);
    cv3.wait(lock);
    cout << "3" << endl;
    i++;
    lock.unlock();
    cv1.notify_one();
  }
}

int main()
{

  thread t1(function1);
  thread t2(function2);
  thread t3(function3);

  cv1.notify_one();

  t1.join();
  t2.join();
  t3.join();

  getchar();
  return 0;
}



