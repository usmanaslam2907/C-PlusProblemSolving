#include <iostream>
using namespace std;
class Stack
{
private:
    int array[10];
    int top = -1;

public:
    Stack()
    {
        for (int i = 0; i <10; i++)
        {
            array[i] = 0;
        }
    }
    bool isempty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
    void push(int x)
    {
        top++;
        array[top] = x;
    }
    void pop()
    {
        if(!isempty())
        {
            top--;
        }
    }
    void display()
    {
        if (isempty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << array[i] << " " << endl;
            }
        }
    }
};
int main()
{
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.pop();
    stk.display();
    return 0;
}