class A 
{
 private:
  void private_func() {}
  int private_num;

  friend class B;

  friend void func();
};

class B {
 public:
  void b() {
    A a;

    a.private_func();
    a.private_num = 2;
  }
};

void func() {
  A a;

  // 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근
  // 가능하다.
  a.private_func();
  a.private_num = 2;
}

int main() {}

//friend 로 지정한 class는 private에 들어올수잇다