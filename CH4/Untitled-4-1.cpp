#include <iostream>

using namespace std;

class Marine {
    static int total_marine_number ; // 사실 정의할떄 바로 0으로 초기화됨
    // const 가 아닌 static은 정의할떄 다른값으로 초기화안됨

  int hp;               
  int coord_x, coord_y;  
  const int damage;        //초기화리스트로 하면 고정가능
  //왜냐? const는 나오자마자 대입되어야하는데 초기화리스트가 그거랳줌   
  bool is_dead;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  
  Marine(int x, int y, int damage);

  int attack();                      
  void be_attacked(int damage_earn);
  void move(int x, int y);     

  void show_status();  
  static void show_total_marine()
  {
      cout << total_marine_number << endl;
  }

  ~Marine() {
      
      if (is_dead == false) total_marine_number--;}
};

int Marine:: total_marine_number = 0; //하지만 초기화하려면 이렇게한다.

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) { total_marine_number++;}
// 초기화리스트 __init__ 같은느낌


Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) { total_marine_number++;}

//
Marine::Marine(int x, int y , int damage)
    : coord_x(x), coord_y(y), hp(50), damage(damage), is_dead(false) { total_marine_number++;}
// 바로대입

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
/*
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) 
  {
    is_dead = true;
    total_marine_number --;
  }
}

*/

Marine& Marine::be_attacked(int damage_earn)
{
    hp -= damage_earn; // this->hp -=damage_earn; 과 같다
    if (hp<=0) is_dead = ture;

    return *this;
}


void Marine::show_status() {
  cout << " *** Marine *** " << endl;
  cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
  cout << " HP : " << hp << endl;   
  cout << "totla marines : " << total_marine_number << endl;

}

int main() {
  Marine marine1(2, 3);
  Marine marine2(3, 5);

  marine1.show_status();
  marine2.show_status();

  //Marine marine3(4,5,100);

  //marine2.be_attacked(marine3.attack());

  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack()); 
  //be_attacked 의 return이  marine2의 ref임. 그래서 두번실행

  marine2.show_status();

  Marine::show_total_marine(); // static 함수, static 변수만 사용가능
  
}