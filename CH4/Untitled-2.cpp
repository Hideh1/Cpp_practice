//오버로드

#include <iostream>

/*
void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
  int a = 1;
  char b = 'c';
  double c = 3.2f;

  print(a);
  print(b);
  print(c);

  return 0;
}
*/
//함수 이름이 print로 같은게 세개 있음에도 인자가 다르면 다른 함수로 처리한다.
/*
void print(int x) { std::cout << "int : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
  int a = 1;
  char b = 'c';
  double c = 3.2f;

  print(a);
  print(b);
  print(c);

  return 0;
}
*/
/*

1 단계
자신과 타입이 정확히 일치하는 함수를 찾는다.

2 단계
정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.

Char, unsigned char, short 는 int 로 변환된다.

Unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다.

Float 은 double 로 변환된다.

Enum 은 int 로 변환된다.

3 단계
위와 같이 변환해도 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.

임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 float -> int)

Enum 도 임의의 숫자 타입으로 변환된다 (예를 들어 Enum -> double)

0 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다

포인터는 void 포인터로 변환된다.
*/


    class Date {
  int year_;
  int month_;  

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();
    //생성자
    //class 이름이랑 일치
    // return 없음
  Date(int year, int month, int day) { //  python의 __init__ 같은느낌
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

void Date::SetDate(int year, int month, int day) {
  year_ = year;
  month_ = month;
  day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
  static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month != 2) {
    return month_day[month - 1];
  } else if (year % 4 == 0 && year % 100 != 0) {
    return 29;  // 윤년
  } else {
    return 28;
  }
}

void Date::AddDay(int inc) {
  while (true) {
    // 현재 달의 총 일 수
    int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

    // 같은 달 안에 들어온다면;
    if (day_ + inc <= current_month_total_days) {
      day_ += inc;
      return;
    } else {
      // 다음달로 넘어가야 한다.
      inc -= (current_month_total_days - day_ + 1);
      day_ = 1;
      AddMonth(1);
    }
  }
}

void Date::AddMonth(int inc) {
  AddYear((inc + month_ - 1) / 12);
  month_ = month_ + inc % 12;
  month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}

// Data::f() <- Data클래스의 함수

int main() {

/*
  Date day;
  day.SetDate(2011, 3, 1);  
  day.ShowDate();
  */
  Date day(2011, 3, 1);             //암시적 방법
  //Date day = Date(2012, 3, 1);  // 명시적 방법  파이썬이랑 비슷함
  // 대신 초기인자 없을떄 암시적 방법은 다음과 같이 사용
  // Data day; <- () 생략. 
  day.ShowDate();
  return 0;
}