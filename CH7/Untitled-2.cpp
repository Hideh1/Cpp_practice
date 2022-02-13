#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() 
{
  // 파일 읽기 준비
  ifstream in("test.txt");
  string s;


  if (in.is_open()) {
    // 위치 지정자를 파일 끝으로 옮긴다.
    in.seekg(0, std::ios::end);

    // 그리고 그 위치를 읽는다. (파일의 크기)
    int size = in.tellg();

    // 그 크기의 문자열을 할당한다.
    s.resize(size);

    // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
    in.seekg(0, std::ios::beg);

    // 파일 전체 내용을 읽어서 문자열에 저장한다.
    in.read(&s[0], size);
    std::cout << s << std::endl;
  } else {
    std::cout << "파일을 찾을 수 없습니다!" << std::endl;
  }

  /*
  // 한줄씩 ㅇ읽기
  while (in) 
// while 조건으로 in.eof 사용 x 
// 끝에 도달한 이후에 true 반환하기 때문에 다음 데이터를 읽는 것에 대한 안정성 x
  {
    //in.getline(buf, 100);
    getline(in, s);

    // 너무 크면 failbit를 뱉으므로 string에서 getline함수 제공
    std::cout << buf << std::endl;
  }

  */

  in.close();

  in.open()
  return 0;
}