#include <iostream>
#include <fstream>
#include <string>

int main() 
{
  // 파일 쓰기 준비
  std::ofstream out("testout.txt");

  std::string s;
  if (out.is_open()) {
    out << "write~~~~~~";
  }

  out.close();

  std::ofstream out2("test2.txt", std::ios::app);
  //app 는 기존내용 보존
  //ate 는 기존내용 보존x
  out2.seekp(3, std::ios::beg);
  out2 << "추가";


}