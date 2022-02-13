#include <iostream>
#include <string>

/*
int main() {
  int t;
  while (true) {
    std::cin >> t;
    std::cout << "input :: " << t << std::endl;
    if (std::cin.fail()) {
      std::cout << "input correctly " << std::endl;
      std::cin.clear();            // 플래그들을 초기화 하고
      std::cin.ignore(100, '\n');  // 개행문자가 나올 때 까지 무시한다
    }
    if (t == 1) break;
  }

  */

int main() {
  std::string s;
  std::cin >> s; // 위치 지정자는 공백에 간다.

  // 위치 지정자를 한 칸 옮기고, 그 다음 문자를 훔쳐본다 (이 때는 움직이지 않음)
  char peek = std::cin.rdbuf()->snextc();
  if (std::cin.fail()) std::cout << "Failed";
  std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
  std::cin >> s;
  std::cout << "다시 읽으면 : " << s << std::endl;
}