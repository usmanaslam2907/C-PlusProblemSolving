#include <iostream>
using namespace std;
void reverser(int array[], int s, int e)
{
    int helper = 0;
    while (s < e)
    {
        helper = array[s];
        array[s] = array[e];
        array[e] = helper;
        s++;
        e--;
    }
}
void reversedarray(int array[], int size,int k)
{
   
    reverser(array, 0, size - 1);
    reverser(array, 0, k - 1);
    reverser(array, k, size - 1);
}



int main()
{

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(array) / sizeof(array[0]);
    reversedarray(array, size,5);
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<"  ";
    }

    return 0;
}