#include <iostream>

class A {
 public:
  virtual void show() { std::cout << "Parent !" << std::endl; }
};
class B : public A {
 public:
  void show() override { std::cout << "Child!" << std::endl; }
};

void test(A& a) { a.show(); }
int main() {
  A a;
  B b;
  test(a);
  test(b);  //A 클래스의 레퍼런스를 받지만, B is a A 이기 떄문에 된다.
  //이떄 B class 의 show가 호출

  return 0;
}