#include <iostream>

class Animal {
 public:
  Animal() {}
  virtual ~Animal() {}
  virtual void speak() = 0;
  //순수 가상함수 : 반드시 override 되어야 하는 함수
  //즉 이 함수를 호출하는 것은 불가능
  //따라서 이 클래스를 직접 생성하는 것 역시 불가능하다.
}; //이렇게 순수가상함수가 있어 직접 생성하는게 불가능한 class를 추상클래스라고 한다.

class Dog : public Animal {
 public:
  Dog() : Animal() {}
  void speak() override { std::cout << "wal wal" << std::endl; }
};

class Cat : public Animal {
 public:
  Cat() : Animal() {}
  void speak() override { std::cout << "Mew~" << std::endl; }
};

int main() {
  Animal* dog = new Dog();
  Animal* cat = new Cat();

  dog->speak();
  cat->speak();
}