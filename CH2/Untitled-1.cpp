#include <iostream>

using namespace std;

// 레퍼런스 안쓰고 포인터로 값 바꾸는 방법 
// 고전적인 C 의 방식

/*
void changval(int *p)
{
    *p = 3;
    return ;
}


int main()
{
    int n = 5 ;

    cout << n << endl;
    changval(&n);
    cout << n << endl;

    return 0;
}
*/


/*
int main()
{
    int a = 3;
    int *pa = &a;
    int &ra = a;  
    
    // 주소를 일치화? 할당? 하는듯
    // 변경 불가
    // 초기값 반드시 필요



    ra = 5;

    *pa = 4;
    cout << a << endl;
    cout << ra << endl;
    cout << *pa << endl;


    //포인터 변수 자체는 주소를 저장함
    // 그러나 할당자는 주소에 저장된 값이 저장?됨
    return 0;
}
*/

/*
void changeval(int &p) 
// 이제 포인터 대신 일반변수를 넣어도 p가 주소를 할당받아서 값 자체를 바꿔준다
{
    p = 3;
    return ;
}

int main()
{
    int n = 5 ; 
    cout << n << endl;
    changval(n) ;
    cout << n << endl;
}

*/

//이중참조는 x
/*
int main()
{
    int x ;
    int &y = x;
    int &z = y;

    x= 1;
    cout << x << y<< z << endl;

    y=2;
    cout << x << y<< z << endl;

    z=3;
    cout << x << y<< z << endl;
    // 주소를 공유하기 때문에 하나를 바꾸면 다같이 바뀐다.

    // int &re = 4;
    // 상수는 안됨

    const int &re = 4; // 상수라고 해두면 이렇게는 가능

    int a = re; // int a = 4; 

    //int &arr[2] = {a,b};
    // 배열 = 포인터 = 메모리에 존재 , 즉 이래는 안됨

    // 대신 배열의 레퍼런스는 가능

    int arr[3] = {1,2,3};
    int (&brr)[3] = arr ; // 배열 크기 반드시 명시

    brr[0] = 2;
    brr[1] = 3;
    brr[2] = 1;

    cout << arr[0] <<arr[1]<<arr[2] << endl;


    return 0;
}
*/
/*
int f()
{
    int a=2;
    return a;
}

int main()
{
    int b = f(); //a는 메모리에서 사라짐. b에 복사

    cout <<b<<endl;

    return 0;
}
*/

int& f()
{
    int a= 2;
    return a;
}
 //지역변수의 ref를 리턴, 컴파일은 됨
 //그러나 런타임에러
//이유는 ref할 변수인 a가 사라졋기 떄문


int& f(int &a)
{
    a= 5;
    return a;
}
//a의 ref를 받아서 그대로 리턴 

int main()
{
    int c=2;
    int b = f();
    //int b = f(c);
    b = 3;
    return 0;
}

//참조자 리턴 장점
//변수 크기(str,cls 등)가 클때 주소복사로 끝남 -> 속도
//지역변수의 ref 리턴하지 않도록 조심
/*

리턴        int f       int& f

받는자료형
int         값 복사     값 복사
int&        컴파일오류  가능
const int&  가능        가능

//매개변수에 NULL 포인터를 넘겨주는 것 or 리턴값으로 NULL 포인터를 반환하는 것이 허용될 경우, 포인터를 사용해야 한다.
//참조자는 선언과 동시에 초기화 되어야해서 NULL이 허용되지 않기 때문이다. 

