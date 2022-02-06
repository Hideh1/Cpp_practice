#include <iostream>

using namespace std;

class Marine {
    int hp;
    int coord_x , coord_y ;
    int damage ; 
    bool is_dead;
    char* name;

    public:
        Marine();
        Marine(int x , int y);
        Marine(int x, int y , const char* marine_name);
        ~Marine();

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
};

Marine::Marine()
{
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;

}


Marine::Marine(int x, int y)
{
    coord_x = x;
    coord_y = y;
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;

}

Marine::Marine(int x, int y, const char* marine_name)
{
    name = new char[strlen(marine_name)+1]; // 소멸자 없으면 이거 죽어도 남아잇음
    strcpy(name , marine_name);
    coord_x = x;
    coord_y = y;
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::~Marine() // ~(클래스 이름) : 객체가 delete 될떄 실행, 인자x
{
    cout << name << "'s destructor is called!" << endl;
    if (name != Null)
    {
        delete[] name;
    }
}

void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
}

int Marine::attack(){ return damage;}

void Marine::be_attacked(int damage_earn)
{
    hp -= damage_earn;
    if (hp<=0) is_dead = true;
}

void Marine::show_status()
{
    cout << "*** Marine ***" << endl;
    cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl; 
    cout << "HP : " << hp << endl; 

}
/*
int main()
{

    // 객체 생성
    Marine marine1(2,3); 
    Marine marine2(3,5);

    marine1.show_status();
    marine2.show_status();

    cout << endl << "Marine1 attack Marine2! " << endl;

    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();

}

*/
// 근데 이렇게 1,2,3 붙일게 아니라 배열을 사용하면?

int main()
{
    // python처럼, class는 마치 하나의 type처럼 사용되는것 같다..
    Marine* marines[100]; 

    marines[0] = new Marine(2,3);
    marines[1] = new Marine(3,5);

    // marines 는 포인터이다. 즉 *로 접근해야한다.
    // 그런데 (*b).f() 는 b->f() 와 같다
    marines[0] -> show_status();
    marines[1] -> show_status();

    cout << endl << "Marine1 attack Marine2! " << endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0] -> show_status();
    marines[1] -> show_status();

    delete marines[0];
    delete marines[1];
}