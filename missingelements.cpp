#include <iostream>
using namespace std;
int missing(int array[],int size)
{
    int miss;
    int n = size + 1;
    int expected_Sum = n * (n + 1) / 2;
    int actual_sum = 0;
    for (int i = 0; i < size; i++)
    {
        actual_sum = actual_sum + array[i];
    }
    
    return expected_Sum-actual_sum;
}

int main()
{
    int array[] = {1,2, 3,4,5,7,8};
    int size = sizeof(array) / sizeof(array[0]);
    int element = missing(array, size);
    cout << "The element is: " << element << endl;
    return 0;
}
