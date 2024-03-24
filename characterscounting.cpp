#include <iostream>
using namespace std;
void counting(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        count = 0;
        for (int j = 0; j < str.length() - 1; j++)
        {
            if (str[i] == str[j])
            {
                count++;
            }
        }
        cout << "The frequency of " << str[i] << " " << count << endl;
    }
}
int max_frequency(string str)
{

    int count = 0;
    int max1 = 0;
    int max2 = 0;
    for (int i = 0; i < str.length(); i++)
    {
        count = 0;
        if (str[i] != ' ')
        {
           
            for (int j = 0; j < str.length(); j++)
            {
                if (str[i] == str[j])
                {
                    count++;
                }
            }
            if (count > max1)
            {
                max2 = max1;
                max1 = count;
            }
            else if (count < max1 && count > max2)
            {
                max2 = count;
            }
        }
       
    }
    return max2;
}
int main()
{
    string str = "usman wains kkkkkk gggg gg g";
    int max_second = max_frequency(str);
    counting(str);
    // cout << "Max Second Frequency is: " << max_second << endl;
    return 0;
}
