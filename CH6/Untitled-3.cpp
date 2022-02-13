#include <iostream>

class Parent {
 public:
  Parent() { std::cout << "Parent create" << std::endl; }
  virtual ~Parent() { std::cout << "Parent dis" << std::endl; }
};
class Child : public Parent {
 public:
  Child() : Parent() { std::cout << "Child create" << std::endl; }
  ~Child() { std::cout << "Child dis" << std::endl; }
};
int main() {
  std::cout << "--- just Child create ---" << std::endl;
  { 
    // 이 {} 를 빠져나가면 c 가 소멸된다.
    Child c; 
  }
  std::cout << "--- when Parent pointer is pointing Child ---" << std::endl;
  {
    Parent *p = new Child();
    delete p;
  }
}

/*

    상속될 가능성이 있는 Base들은 반드시 소멸자를 virtual로 생성해야 한다.

*/