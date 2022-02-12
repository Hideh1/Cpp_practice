#include <iostream>
#include <string>

using namespace std;

class Employee
{
    protected:
        string name;
        int age;

        string position;    // 직책(이름)
        int rank;           // 순위

    public:
        Employee(string name, int age, string position, int rank)
            :name(name) , age(age) , position(position) , rank(rank) {}

        Employee(const Employee& employee)
        {
            name=  employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        } 

        Employee(){}

        void print_info()
        {
            cout << name << " ( " << position << ", " << age << " ) ==> " << cal_pay() << endl;

        }

        int cal_pay()
        {
            return 200+rank*50;
        }

};

class Manage : public Employee
{
    int year_of_service;

    public:
        Manage(string name, int age, string position, int rank , int year_of_service)
            : Employee(name, age , position , rank) , year_of_service(year_of_service) {}

        Manage(const Manage& manager)
            :   Employee(manager.name , manager.age , manager.position , manager.rank)
            {
                year_of_service = manager.year_of_service;
            }
        Manage() : Employee() {}


    int cal_pay()
    {
         return 200+rank*50 + year_of_service* 40;
    }

    void print_info()
    {
        cout << name << " ( " << position << ", " << age <<',' << year_of_service << "years ) ==> " << cal_pay() << endl;    

    }


};


class EmployeeList
{
    int alloc_employee; // 할당된 직원수
    int current_employee; // 실제 직원수
    int current_manager;


    Employee** employee_list; // EMployee* 를 담을 배열
    Manage** manage_list;

    public:
        EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) 
        {
            employee_list = new Employee*[alloc_employee];
            manage_list = new Manage*[alloc_employee];
            current_employee  = 0;
            current_manager = 0;
        }

        void add_employee(Employee* employee)
        {

            employee_list[current_employee] = employee;
            current_employee ++;
        }

        void add_manager(Manage* manager)
        {

            manage_list[current_manager] = manager;
            current_manager ++;
        }


        int current_employee_num(){return current_employee+current_manager;}

        void print_employee_info()
        {
            int total_pay= 0;
            for(int i=0;i<current_employee ; i++)
            {
                employee_list[i] -> print_info();
                total_pay += employee_list[i]->cal_pay();
            }

            for(int j=0 ; j<current_manager ; j++)
            {
                manage_list[j] -> print_info();
                total_pay += manage_list[j]->cal_pay();
            }

            cout << "total pay : " << total_pay << endl;
        }

        ~EmployeeList()
        {
            for(int i=0; i<current_employee; i++)
            {
                delete employee_list[i];
            }
            for(int j=0; j<current_manager ; j++)
            {
                delete manage_list[j];
            }

            delete[] employee_list;
            delete[] manage_list;
        }
};


int main()
{

    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("zeus",21,"top" , 1));
    emp_list.add_employee(new Employee("oner" , 20 , "jg",2));
    emp_list.add_employee(new Employee("faker" , 27, "mid", 10));
    emp_list.add_employee(new Employee("gumayusi" , 21, "adc", 5));
    emp_list.add_employee(new Employee("keria" , 23 , "sup", 4));
    emp_list.add_manager(new Manage("Teddy" , 23, "adc" , 4,10));
    cout <<emp_list.current_employee_num() << endl;

    emp_list.print_employee_info();

    return 0;


}