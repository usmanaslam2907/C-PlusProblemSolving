#include <iostream>
using namespace std;
bool isvowels(char a)
{
    if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a == 'a' || a == 'e' || a == 'o' || a == 'i' || a == 'u')
    {
        return true;
    }
    return false;
}
string reversevowels(string str)
{
    string temp;
    char helper;
    int left = 0;
    int right = str.length() - 1;
    while (left < right)
    {
        if (isvowels(str[left]) && isvowels(str[right]))
        {
            helper = str[left];
            str[left] = str[right];
            str[right] = helper;
            left++;
            right--;
        }
        else if (!isvowels(str[left]))
        {
            left++;
        }
        else if (!isvowels(str[right]))
        {
            right--;
        }
    }
    return str;
}
string reversestring(string str)
{
    char helper;
    int left = 0;
    int right = str.length() - 1;
    while (left < right)
    {
        helper = str[left];
        str[left] = str[right];
        str[right] = helper;
        left++;
        right--;
    }

    return str;
}
int main()
{
    string str = "hello world";
    string reversed = reversevowels(str);
    cout << "The reversed Vowels is: " << reversed << endl;
    string reversed_string = reversestring(str);
    cout << "The reversed string is: " << reversed_string << endl;
    // umnocbeoiauklageu  output

    return 0;
}