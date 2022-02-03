#include <iostream>

int main()
{
    int a[100] = {0};
    int *pa = a;

    int i;
    int *pi = &i;

    *pa = 2;

    int sum = 0;

    for (int k=1; k<=10;k++)
    {
        sum+=k;
    }

    std::cout << "sum from 1 to 10 : " << sum << std::endl;

    int j = 1;
    std::cout << *(pa+1) << std::endl;

    int n=3;
    while(j<100)
    {
        int pk=0 ;
        int Bool = 1;
        for(int pi=0; pi<100; pi++)
        {

            if (*(pa+pi) ==0) break;
            if (n%(*(pa+pi)) ==0 )
            {
                Bool = 0;
                break;
                
            }
            pk++;
        }
        if (Bool) 
        {
            *(pa+pk) = n;
            j++;
        }


    n+=2;
    }

    for(int pf =1; pf<100;pf++)
    {
        std::cout << pf <<"th prime number : " <<  *(pa+pf) << std::endl;
    }

    std::cout << std::endl;
    int B;
    while(1)
    {
        int user_input;
        std::cout << "input the positive interger less than 1000 : ";
        std::cin >> user_input ;
        if (user_input>1000  || user_input < 0)
        {
            continue;
        }
        if (user_input ==1 )
            {
                B = 1;
                break;
            }
        for(int pq =1; pq<100;pq++)
        {
            int u = *(pa+pq);
            if (user_input == u||user_input<u)
            {
                B = 2;
                break;
            }
            if (user_input%u==0)
            {

                B = 0;
                break;
            }
        }
        break;
    }

    std::cout << std::endl;
    switch(B)
    {
        case 0:
            std::cout << "it is not prime" << std::endl;
            break;
        case 1:
            std::cout << "it is just 1" << std::endl;
            break;
        default:
            std::cout << "it is prime number " << std::endl;
            break;
    }

    return 0;
}