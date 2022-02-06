#include <iostream>
using namespace std;

class A
{
    int x;

    public:
        A(int c) : x(c){}

        int& acces_x() {return x;}
        int get_x() {return x;}
        void show_x() {cout << x << endl; }
};

int main()
{
    A a(5);
    a.show_x();

    int& c = a.acces_x(); //c가 a.x의 ref. 즉 c를 바꾸면 a.x가 바뀜
    c = 4;
    a.show_x();

    int d = a.acces_x(); //a.x의 'ref값'을 c가받음. 즉 c를 바꿔도 a.x 그대로
    d=  3;
    a.show_x();

/*
    int& e = a.get_x(); // 임시객체의 값을 받아서 에러,
    e=2;
    a.show_x();
*/

    int f = a.get_x();
    f=1;
    a.show_x();

}