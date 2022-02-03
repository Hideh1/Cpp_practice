#include <iostream>
#include "header1.h"
#include "header2.h"


using header2::foo;
//using namespace::std;

namespace 
{
    int p = 1;
}

int main()
{
    //std::cout << "Hello world" << std:: endl;
/*

    cout << foo  << "\t" << header1::foo <<  endl;

    cout << "Hello, World!!" << endl;
*/
std::cout << "hi" << std::endl
          << "my name is "
          << "Haechan" << std::endl;

std::cout << p << std:: endl;

return 0;
}
