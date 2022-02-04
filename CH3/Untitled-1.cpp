/* new와 delete */

#include <iostream>

using namespace std;
/*
int main()
{
    int *p = new int ; // int 크기만큼 할당한 후 그걸 p에 집어넣음
    *p = 10;

    cout << *p << endl;

    delete p;
    
    return 0;
}
*/
/*
new 와 delete 사용법

<type>* pointer = new T;

delete pointer ; 

만약 할당한게 아니면 빼액댄다
*/
/*
int main()
{
    int a = 5;

    delete &a;

    return 0;
}
*/

/* new 로 배열할당*/
/*
int main()
{
    int ar_size ; 
    cout << "size : " ; cin >> ar_size;
    
    int *list = new int[ar_size];

    for(int i = 0 ; i < ar_size ; i++)
    {
        cin >> list[i];
    }

    for(int i =0; i<ar_size ; i++)
    {
        cout << i << "th element of list : " << list[i] << endl;
    }

    delete[] list;

    return 0;
}

*/

typedef struct student {

    char name[30]; 
    int age;

    int weight;
    int length;
    int grade;
    int hp ; 
} student ;
// 구조 조금만 달라져도 첨부터 해야함
//그러면 밑에 코드도 다 다시해야함


void add_student(student *people)
{
    cout << "name? : " ; cin >> people -> name;
    cout << "age? : " ; cin >> people -> age;
    cout << "length? : " ; cin >> people -> length;

    people -> weight = 70;
    people -> grade = 4.2; 
    people -> hp = 100;

}

void study(student *people)
{
    people -> grade += 0.1;
    people -> hp -= 10;
    people -> weight -=0.3;
}
//차라리 변수 자체에 함수를 만드는거는 어떨까?
int main()
{
    student *list[10];
    int student_num = 0;

    while(1)
    {
        cout << "1. student add" <<endl;
        cout << "2. student study " << endl;
        cout << "3. exit" << endl;

        int input; cin >> input;

        switch(input)
        {
            case 1:
                list[student_num] = new student;
                add_student(list[student_num]); //실수로 뺴먹으면 초기화되지 않은 값들이 버그
                student_num +=1;
                break;
            case 2:
                cout << "study who?" << endl;
                int h ; cin >> h;
                if (h < student_num) study(list[h]); //list[h] 전달해야함
                break;
            case 3:
                return 0;


        }
    }

    for(int i=0;i < student_num ; i++ ) 
    {
        delete list[i];
    }
}