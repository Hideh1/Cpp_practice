#include <string.h>
#include <iostream>

using namespace std;

class Photon_Cannon
{
    int hp,shield ;
    int coord_x , coord_y;
    int damage;
    char *name;

    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(int x, int y , const char* cannon_name);
        Photon_Cannon(const Photon_Cannon& pc);
        ~Photon_Cannon();

    void show_status();
};

//복사생성자
//for class T
// T(const T& a);

// 변수를 수정할일이 없다면 const 붙이기

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc)
{
    cout << "copy constructor is called" << endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage; 

    name = new char[strlen(pc.name)+1];
    strcpy(name , pc.name);
}


//디폴트 복사생성자 : 그대로 1대1 복사해줌
//단점 : 포인터까지 복사해서 하나 delete하면 참조할게없음

Photon_Cannon::Photon_Cannon(int x, int y)
{
    cout << "counstructor is called " << endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y , const char *cannon_name)
{
    cout << "counstructor is called " << endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name)+1];
    strcpy(name , cannon_name);
}


void Photon_Cannon::show_status()
{
    cout << " Photon Cannon" << endl;
    cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;

    cout << " HP : " << hp << endl;
}


Photon_Cannon:: ~Photon_Cannon()
{
    if (name) delete[] name;
}

int main()
{
  Photon_Cannon pc1(3, 3, "Cannon");
  Photon_Cannon pc2 = pc1;

  pc1.show_status();
  pc2.show_status();
}