#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while(a != 0)
    {
        int c = a;
        a = b % a;
        b = c;
    }
    return b;
    //return gcd(b % a, a);
}

int main()
{
    int a = 10, b = 15;

    cout << gcd(a, b);

    return 0;
}