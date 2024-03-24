#include <iostream>
using namespace std;
int wordcounter(string str)
{
    bool flag = false;
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            if (!flag)
            {
                flag = true;
                count++;
            }
        }
        else
        {
            if (str[i] == ' ')
            {
                flag = false;
            }
        }
    }

    return count;
}
string shortest_word(string str)
{
    int len = 50;
    string word;
    string temp;
    int count = 0;

    bool flag = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            flag = true;
            temp += str[i];
            count++;
        }
        else
        {
            if (flag)
            {
                if (count < len)
                {
                    len = count;
                    word = temp;
                }
                count = 0;
                temp.clear();
            }
        }
    }
    if (count < len)
    {
        len = count;
        word = temp;
    }
    return word;
}

string remover_externel(string str)
{
    string temp;
    int left = 0;
    int right = str.length() - 1;
    bool l1 = false;
    bool r1 = false;
    while (left <= right)
    {
        if (str[left] == ' ' && l1 == false)
        {
            left++;
        }
        else
        {
            l1 = true;
        }
        //
        if (str[right] == ' ' && r1 == false)
        {
            right--;
        }
        else
        {
            r1 = true;
        }
        if (r1 && l1)
        {
            for (int i = left; i <= right; i++)
            {
                temp += str[i];
            }
            
            break;
        }
    }
   
    

    return temp;
}
int main()
{
    string str = "    bca  ";
    int count = wordcounter(str);
    string s_word = shortest_word(str);
    string remove_space = remover_externel(str);
    cout << remove_space << endl;
    return 0;
}
