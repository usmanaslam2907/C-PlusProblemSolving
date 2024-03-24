#include <iostream>
using namespace std;
void sum(int number)
{
    int digit = 0;
    int sum = 0;
    while (number > 0)
    {
        digit = number % 10;
        sum = sum + digit;
        number = number / 10;
    }
    cout << "Sum mof is: "<<sum << endl;
}
bool ispalin(int number)
{
    int reversed_number = 0;
    int orginal = number;
    while (orginal > 0)
    {
        reversed_number = reversed_number * 10 + (orginal % 10);
        orginal = orginal / 10;
    }
    return reversed_number == number;
}
int main()
{
    int number = 122221;
    sum(number);
    if (ispalin(number))
    {
        cout << "Palindrome number" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}