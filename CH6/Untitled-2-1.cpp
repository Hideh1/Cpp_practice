#include <iostream>
#include <string>

using namespace std;

class Base
{
    string str;
    
    public:
        Base() : str("base") {cout << "base class " << endl; }

        virtual void what()
        {
            cout << str << endl;
        }
};

class Derived : public Base
{
    string str;

    public:
        Derived() : str("derived") , Base() {  cout << "derived class " << endl;}

        void what() override
        {
            cout << str << endl;
        }
};

int main()
{
    /*
    cout << "==create base class==" << endl;
    Base p;

    p.what();

    cout << "==create derived class==" << endl;
    Derived q;

    q.what();

    cout << "==pointer version==" << endl;
    Base* p_c = &q;

    //q는 Derived class이지만, Derived is a Base 이기 때문에 Base 포인터로 대입가능

    //대신 p_c는 Base를 가리키기 때문에 Base의 함수를 실행
    p_c->what();

    // 이렇게 파생클래스에서 기반클래스로 캐스팅하는 것을 업캐스팅 이라고 함


    //반대로 다운캐스팅은?
    //기반클래스는 파생클래스를 포함하지 않기때문에 에러가 뜸
    //그러나, 실제로는 파생클래스를 가리킨다면 강제로 형변환해서 사용가능

    Derived* p_p = static_cast<Derived*>(p_c);
    p_p->what();
*/
    //반대로, 실제로는 기반클래스를 가리키지만 강제로 형변환한다면 다음과 같이 에러가 난다.
/*
    Derived* p_p = static_cast<Derived*>(&p);
    p_p->what();
*/
    //이 경우 컴파일에러는 뜨지 않지만 런타임에러가 뜨며, 디버깅하기 굉장히 힘들다.


    Base p;
    Derived q;

    Base* p_q = &q ;
    Base* p_p = &p ;

    cout << "==real object is Base" << endl;
    p_p->what();

    cout<<"==real object is Derived" << endl;
    p_q->what();
    
//p_q는 Base포인터이지만 실제로는 Dervied 객체이다.
// 포인터를 따라간 Base 의 what 함수가 virtual이므로 실제 객체인 Dervied를 실행한다.


// Derived 의 what함수는 Base의 함수를 overrid하나, 명시적으로 밝혀놓기 위해 override 키워드를 사용한다.
//왜냐하면 정확히 같은 형식의 함수가 아니면 overrid하지 않기 때문에, 이 키워드를 사용하면 명시적으로 이를 밝힘으로써 디버깅이 용이하다.
    return 0;
}