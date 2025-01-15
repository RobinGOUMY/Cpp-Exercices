/* Documentation section
*/

//Linking section
#include <iostream>
#include <string>

//Definition section
#define message "Factorial"
typedef int GT_INT;

//Gloabl declaration sections
GT_INT num = 0;
GT_INT fact = 1;
GT_INT storage = 0;

//function section
GT_INT factorial(GT_INT num)
{
    GT_INT fact = 1;
    for(GT_INT i = 1; i <= num; i++)
    {
        fact *= i;
    } 
    return fact;  
}

//
GT_INT main()
{
    GT_INT num = 0;
    std::string msg = "Please give a number: ";
    const char* c_msg = msg.c_str();
    std::cout << msg;
    if(std::cin >> num)
    {
        storage = factorial(num);
        std::cout << message << " of "<< num <<": " << storage << std::endl;
        std::cout << "THIS SHOULD BE A SEPARATE LINE !!!11!"; 
    }
    else
    {
        std::cout << "Bad number format";
    }

    return 0;
}

struct Student
{
    std::string name;
    std::string address;
    int year;
    std::string phone;
};

Student Jason;
Jason.name = "Jason";

class Student
{
    std::string name;
    std::string address;
    int year;
    std::string phone;

    void PerformInCourse()
    {
        //TODO
    }

    
}