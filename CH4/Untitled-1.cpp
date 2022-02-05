
//기존방식
/*
typedef struct Animal {
  char name[30];  // 이름
  int age;        // 나이

  int health;  // 체력
  int food;    // 배부른 정도
  int clean;   // 깨끗한 정도
} Animal;


*/

// 그래서 원래는 아래 코드로 함수를 적용
/*
play(list[play_with]);

*/

// 객체 자체에 함수를 넣으면
/*
animal.play();   // 즉 내가 (animal 이) Play 를 한다!
animal.sleep();  // 내가 sleep 을 한다!
*/

//대신 외부에서 직접 수정은 안됨
/*

animal.food += 100;         // --> 불가능
animal.increase_food(100);  // --> 가능

*/

#include <iostream>
// class의 등장.
class Animal {
 private: //내부에서만 접근가능(내부 함수등) , 기본값
  int food;
  int weight;

 public:
  void set_animal(int _food, int _weight) {
    food = _food;
    weight = _weight;
  }
  void increase_food(int inc) {
    food += inc;
    weight += (inc / 3);
  }
  void view_stat() {
    std::cout << "이 동물의 food   : " << food << std::endl;
    std::cout << "이 동물의 weight : " << weight << std::endl;
  }
};  // 세미콜론 잊지 말자!

int main() {
  Animal animal;
  animal.set_animal(100, 50);
  animal.increase_food(30);

  animal.view_stat();
  return 0;
}

//파이썬이랑 비슷한듯?