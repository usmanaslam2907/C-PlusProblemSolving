#include <iostream>
using namespace std;
string substr(string str, int x, int y)
{
    string temp;
    for (int i = x; i < y; i++)
    {
        temp += str[i];
    }
    return temp;
}
bool isUnique(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }

    return true;
}
string longeststring(string str)
{
    string temp;
    int len=0;
    string substring;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 1; j <= str.length(); j++)
        {
            substring = substr(str, i, j);
            if (isUnique(substring) && substring.length() > len)
            {
                len = substring.length();
                temp = substring;
            }
            // substring.clear();
        }
    }

    return temp;
}
int main()
{
    string str = "aabdabcdemmjkjilklmnopqr";
    string longest = longeststring(str);
    cout << longest << endl;

    return 0;
}
