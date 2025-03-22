// EvenOdd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

//using namespace std;

std::mutex mu;
std::condition_variable cond;
std::condition_variable cond1, cond2;
int count = 1;


//#######################using notify one#######################

void Odd()
{
  while(count < 100)
  {
    std::unique_lock<std::mutex> locker(mu);
    cond1.wait(locker, []() {return (count % 2 == 1); });
    std::cout << "From Odd : " << count << std::endl;
    count++;
    locker.unlock();
    cond2.notify_one();
  }
}

void Even()
{
  while (count < 100)
  {
    std::unique_lock<std::mutex> locker(mu);
    cond2.wait(locker, []() {return (count % 2 == 0); });
    std::cout << "From Even : " << count << std::endl;
    count++;
    locker.unlock();
    cond1.notify_one();
  }
}

//##############################################################



//#######################using notify all#######################
void PrintOdd()
{
  for (; count < 100;)
  {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker, []() { return (count % 2 == 1); });
    std::cout << "From Odd:    " << count << std::endl;
    count++;
    locker.unlock();
    cond.notify_all();
  }
}

void PrintEven()
{
  for (; count < 100;)
  {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker, []() { return (count % 2 == 0); });
    std::cout << "From Even: " << count << std::endl;
    count++;
    locker.unlock();
    cond.notify_all();
  }
}

//###############################################################

//#######################using one callbale######################
void PrintOddAndEven(bool flag, int n, std::string str) {
  while (count < n) {
    std::unique_lock<std::mutex> lk(mu);
    cond.wait(lk, [flag]() {return count % 2 == flag; });
    std::cout << str << " : " << count++ << " " << std::endl;
    lk.unlock();
    cond.notify_all();
  }
}

//###############################################################


int main() {
  //Print using notify all
  //std::thread t1(PrintOdd);
  //std::thread t2(PrintEven);

  //Print using one callable
  int n = 100;
  std::thread t1(PrintOddAndEven, true, n, "odd");
  std::thread t2(PrintOddAndEven, false, n, "even");

  //Print using notify one
  //std::thread t1(Odd);
  //std::thread t2(Even);
  //cond1.notify_one();

  t1.join();
  t2.join();
  return 0;
}


