#include <iostream>

class A 
{
  mutable int data_; //이러면 const여도 수정가능

 public:
  A(int data) : data_(data) {}
  void DoSomething(int x) const {
    data_ = x;  // 가능!
  }

  void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
  A a(10);
  a.DoSomething(3);
  a.PrintData();
}

//근데 왜ㅡㅆ는지 여전히모르겟음