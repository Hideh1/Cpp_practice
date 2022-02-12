#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "abc";

    //string calss의 인자를 const char * 로 받는 생성자를 호출


    
    string t = "def";

    string s2 = s;

    cout << (s+t).length() << endl;

    if (s == s2) 
    {
        cout << s << " and " << s2 << " are same each other" << endl;
    }

    cout << s<< endl;

    return 0;
}