#include <fstream>
#include <iostream>
#include <string>

class Human {
  std::string name;
  int age;

 public:
  Human(const std::string& name, int age) : name(name), age(age) {}
  std::string get_info() {
    return "Name :: " + name + " / Age :: " + std::to_string(age);
  }

  friend std::ofstream& operator<<(std::ofstream& o, Human& h);
};

std::ofstream& operator<<(std::ofstream& o, Human& h) 
//ofstream 객체 레퍼런스 받고 이를 리턴해주면 된다.
{
  o << h.get_info();
  return o;
}
int main() {
  // 파일 쓰기 준비
  std::ofstream out("test.txt");

  Human h("Haechan", 22);
  out << h << std::endl;

  return 0;
}