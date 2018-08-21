// Copyright 2018 Caoyang Jiang

#include <functional>  // std::ref
#include <future>      // std::promise, std::future
#include <iostream>    // std::cout
#include <thread>      // std::thread

void print_int(std::future<int>& fut)
{
  std::cout << "Future try get" << std::endl;
  int x = fut.get();
  std::cout << "value: " << x << '\n';
}

void test1()
{
  std::promise<int> prom;  // create promise

  std::future<int> fut = prom.get_future();  // engagement with future

  std::thread th1(print_int, std::ref(fut));  // send future to new thread

  std::cout << "Before fulfill" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(5));
  prom.set_value(10);  // fulfill promise
  std::cout << "After fulfill" << std::endl;
  // (synchronizes with getting the future)
  th1.join();
}

bool is_prime(int x)
{
  std::cout << "Start is_prime" << std::endl;
  int ret = true;
  for (int i = 2; i < x; ++i)
  {
    if (x % i == 0)
    {
      ret = false;
      break;
    }
  }
  std::cout << "Finish is_prime" << std::endl;

  return ret;
}

void test2()
{
  std::future<bool> fut = std::async(is_prime, 444444443);

  std::cout << "checking, please wait";
  std::chrono::milliseconds span(100);
  while (fut.wait_for(span) == std::future_status::timeout)
    std::cout << '.' << std::flush;

  bool x = fut.get();

  std::cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";
}

void is_prime2()
{
  std::cout << "Start is_prime" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "Finish is_prime" << std::endl;
}

void test3()
{
  std::future<void> fut = std::async(is_prime2);

  std::cout << "checking, please wait";
  std::chrono::milliseconds span(100);
  while (fut.wait_for(span) == std::future_status::timeout)
    std::cout << '.' << std::flush;

  fut.get();
}

int main()
{
  test2();

  return 0;
}
