#include <iostream>
using namespace std;

int strlen(const char* str)
{
    int cnt = 0;
    for (cnt =0; str[cnt];cnt++);
    return cnt;
}
class Mystring
{
    char* string_content;
    int string_length;


    public:
        Mystring(char c);
        Mystring(const char* str);
        Mystring(const Mystring& str);
        ~Mystring();

        int length() const;

        void print() const;

        Mystring& assign(const char* str);
        Mystring& assign(const Mystring& str);

        char at(int a) const;

        Mystring& sum(const Mystring& str);
        Mystring& sum(const char* str);

        Mystring& insert(const Mystring& str , int a);
        Mystring& insert(const char* str , int a);

        int find(const Mystring& str) ;
        int find(const char* str) ;

};

int main()
{
    Mystring str1("hello world");

    str1.print();
    cout << str1.length() << endl;

    cout << str1.at(-3) << endl;

    str1.sum("df");

    str1.print();

    str1.insert("ttt" , 3);

    str1.print();

    cout << str1.find("o") << endl;


    Mystring str2("abcdefghijk");

    cout << str2.find("efg") << endl;

    cout << str2.at(str2.find("efg"));
}


char Mystring::at(int a) const
{
    if (a >= string_length)
    return NULL;

    if (0>a && a> -string_length)
    return string_content[string_length+a];

    return string_content[a];
}


Mystring::Mystring(char c)
{
    string_content = new char[1];
    string_content[0] = c;
    string_length =1;
}

Mystring::Mystring(const char* str)
{
    string_length = strlen(str);
    string_content = new char[string_length];

    for(int i=0;i<string_length;i++) string_content[i] = str[i];
}

Mystring::Mystring(const Mystring& str)
{
    string_length = str.string_length;
    string_content = new char[string_length];
    for(int i = 0 ; i<string_length ; i++) 
        string_content[i] = str.string_content[i];

}

Mystring::~Mystring()
{
    delete[] string_content;
}

int Mystring::length() const { return string_length;}


void Mystring::print() const
{
    for(int i=0;i<string_length ; i++)
    {
        cout << string_content[i];
    }
    cout <<endl;
}

Mystring& Mystring::assign(const char* str)
{
    delete[] string_content;
    string_length = strlen(str);
    string_content = new char[string_length];

    for (int i=0 ; i<string_length ; i++)
    {
        string_content[i] = str[i];
    }


    return *this;
}

Mystring& Mystring::assign(const Mystring& str)
{
    delete[] string_content;
    string_length = str.string_length;
    string_content = new char[string_length];


    for(int i=0; i<string_length; i++)
        string_content[i] = str.string_content[i];

    return *this;
}


Mystring& Mystring::sum(const Mystring& str)
{

    char* temp = string_content;

    string_content = new char[string_length+str.string_length];
    for(int i = 0; i<string_length ; i++)
    string_content[i] = temp[i];

    for(int j = 0; j<str.string_length ; j++)
    string_content[j+string_length] = str.string_content[j];

    string_length += str.string_length;

    delete[] temp;
    return *this;    
}


Mystring& Mystring::sum(const char* str)
{
    Mystring temp(str);
    return Mystring::sum(temp);
}

Mystring& Mystring::insert(const Mystring& str , int a)
{
    if (0>a || a>= string_length) return *this;
    char* temp = string_content;
    
    string_content = new char[string_length + str.string_length];

    for (int i = 0; i < a; i++)
    string_content[i] = temp[i];

    for (int j = 0 ; j<str.string_length ; j++)
    string_content[a+j] = str.string_content[j];

    for (int k=a; k<string_length;k++)
    string_content[str.string_length + k] = temp[k];

    string_length += str.string_length;

    delete[] temp;
    return *this;
}

Mystring& Mystring::insert(const char* str, int a)
{
    Mystring temp(str);
    return Mystring::insert(temp, a);
}

int Mystring::find(const Mystring& str) 
{
    if (string_length < str.string_length ) return -1;
    for(int i=0 ; i<string_length - str.string_length ; i++)
    {
        int b= 1;
        for (int j=0; j<str.string_length ; j++)
        {
            if (string_content[i+j] != str.string_content[j] ) 
            {
                b = 0;
                break;
            }
        }

        if (b) return i;
    }
    return -1;
}

int Mystring::find(const char* str)
{
    Mystring temp(str);
    return Mystring::find(temp);
}