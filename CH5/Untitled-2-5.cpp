#include <iostream>

using namespace std;

class Test {
  int x;

 public:
  Test(int x) : x(x) {}
  Test(const Test& t) : x(t.x) {}

  Test& operator++() {
    x++;
    cout <<  "head " << endl;
    return *this;
  }

  // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를 받지만 실제로는 아무것도 전달되지 않는다.
  Test operator++(int) {
    Test temp(*this);
    x++;
    cout << " later " << endl;
    return temp;
  }

  int get_x() const {
    return x;
  }
};

void func(const Test& t) {
  cout << "x : " << t.get_x() << endl;
}

int main() {
  Test t(3);

  func(++t); // 4
  func(t++); // 4 가 출력됨
  cout << "x : " << t.get_x() << endl;
}