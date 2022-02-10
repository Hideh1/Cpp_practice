#include <cstring>
#include <iostream>

using namespace std;


class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);

  Complex& operator=(const Complex& c);

  // 나머지 연산자 함수들은 생략 

  void println() {
    std::cout << "( " << real << " , " << img << " ) " << std::endl;
  }

  friend Complex operator+(const Complex& a, const Complex& b); //private에 접근가능하게 함

  friend ostream& operator<<(ostream& os, const Complex& c);
};

Complex operator+(const Complex& a, const Complex& b) {
  Complex temp(a.real + b.real, a.img + b.img);
  return temp;
}



Complex::Complex(const char* str) {
  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  // 그 이외의 이상한 문자들이 올 경우
  }

  if (minus) num *= -1.0;

  return num;
}

Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

ostream& operator<<(ostream& os, const Complex& c) {
  os << "( " << c.real << " , " << c.img << " ) ";
  return os;
}


int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;
  cout << "a 의 값은 : " << a << " 이다. " << endl;
}