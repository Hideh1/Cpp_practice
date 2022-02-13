#include <iostream>
#include <sstream>
/*
int main() 
{
  std::istringstream ss("123");
  //문자열을 하나의 스트림으로
  //파일에서 읽어온것 같은 것과 동일
  int x;
  ss >> x; // 그래서 값을 읽어내는 것

  std::cout << "inputed data :: " << x << std::endl;

  return 0;
}
*/

//이를 이용하면 문자열에서 숫자로 변환하는 함수가 만들어진다.

double to_number(std::string s) 
{
  std::istringstream ss(s);
  double x;

  ss >> x;
  return x;
}

//반대로 출력하는 것도 가능. 이렇게하면 숫자를 문자열로 바꾸는 것도 가능하다.
std::string to_str(int x)
 {
  std::ostringstream ss;
  ss << x;

  return ss.str();
}
int main() {
  std::cout << "trans to number:: 1 + 2 = " << to_number("1") + to_number("2") << std::endl;
  std::cout << "trans to string:: 1 + 2 = " << to_str(1 + 2) << std::endl;
  return 0;
}