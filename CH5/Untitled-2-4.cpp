#include <iostream>

using namespace std;

class Int {
  int data;
  // some other data

 public:
  Int(int data) : data(data) {}
  Int(const Int& i) : data(i.data) {}

  operator int() { return data; } // int로 바꿔서 연산
};
// int 변수를 모아놓은 객체를 int 타입처럼 쓰기.

int main() {
  Int x = 3;
  int a = x + 4;

  x = a * 2 + x + 4;
  cout << x << endl;
}