#include <iostream> 

using namespace std;

int strlen(const char* str)
{
    int cnt = 0;
    for (cnt =0; str[cnt];cnt++);
    return cnt;
}

double get_number(const char *str, int from, int to)
 {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  
  }

  if (minus) num *= -1.0;

  return num;
}

class Complex
{
    private:
        double  real , img;

    public:
        Complex(double real, double img) :  real(real) , img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }
        Complex(const char* str)
        {
            int begin = 0, end = strlen(str);
            img = 0.0;
            real = 0.0;

            int pos_i = -1;
            for (int i = 0; i != end; i++) {
                if (str[i] == 'i') {
                pos_i = i;
                break;
                }
            }
            if (pos_i == -1) {
                real = get_number(str, begin, end - 1);
                return;
            }

            real = get_number(str, begin, pos_i - 1);
            img = get_number(str, pos_i + 1, end - 1);

            if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
        }

    Complex operator+(const Complex& z) const
    {
        Complex temp(real+z.real , img+z.img);
        return temp;
    }
    /*
    Complex operator+(const char* str) const
    {
        Complex z(str);
        return (*this) + z; 
    }
    */
   //알아서 해줌
    
    Complex operator-(const Complex& z) const
    {
        Complex temp(real-z.real , img-z.img);
        return temp;
    }


    Complex operator*(const Complex& z) const 
    {
        Complex temp(real*z.real - img*z.img , real*z.img +img*z.real);
        return temp;
    }


    Complex operator/(const Complex& z) const //자기자신에 연산하는걸 저장하는게아님
    {     Complex temp(
                (real * z.real + img * z.img) / (z.real * z.real + z.img * z.img),
                (img * z.real - real * z.img) / (z.real * z.real + z.img * z.img));
        return temp;
    }


    Complex& operator=(const Complex& z) // 자기자신에 저장함
    {
        real = z.real;
        img = z.img;
        return *this;
    }
//그래서 자기자신에 저장하는 아래 연산자는 다음과 같이 저으이됨

    Complex& operator+=(const Complex& z) 
    {
        (*this) = (*this) + z;
        return *this;
    }

    Complex& operator-=(const Complex& z) 
    {
        (*this) = (*this) - z;
        return *this;
    }
    Complex& operator*=(const Complex& z) 
    {
        (*this) = (*this) * z;
        return *this;
    }
    Complex& operator/=(const Complex& z) 
    {
        (*this) = (*this) / z;
        return *this;
    }
    
    void print() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }

};

int main()
{
    Complex a(1,2);
    Complex b(3,4);

    Complex c= a / b;

    c.print();

    Complex d = c*b;

    d.print();

    d = a+b; // 굳이 op=정의 안해도 되지만 그건 얕은복사임 딥카피 필요하면 만들어야함

    d.print();

    d += "2+i3";

    d.print();  

}

