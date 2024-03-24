#include <iostream>
using namespace std;
int equalibrium_state(int number[],int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + number[i];
    }
    int left=0;
    int right = sum;
    int i = 0;

    while (true)
    {
        left=left+number[i];
          if(left==right)
          {
              break;
          }   
          right=right-number[i];
          i++;
     }
    

    return number[i];
}
int main()
{
    int numbers[] = {1, 2,1,8,4};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = equalibrium_state(numbers,size);
    cout << "The target is: " << target << endl;
    return 0;
}
