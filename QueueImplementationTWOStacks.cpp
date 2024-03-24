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
        for (int i = 0; i < 10; i++)
        {
            array[i] = 0;
        }
    }
    bool isempty()
    {
        if (top == -1)
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
    int pop()
    {
        if (!isempty())
        {
            int temp = array[top];
            top--;
            return temp;
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
class Queue
{
    Stack s1;
    Stack s2;

    public:
    void enqueue(int x)
    {
         while(!s1.isempty())
         {
             s2.push(s1.pop());
         }
         s1.push(x);
         while(!s2.isempty())
         {
             s1.push(s2.pop());
         }

    }
    int dequeue()
    {
        int temp=s1.pop();
        return temp;
    }
    void display()
    {
        s1.display();
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.display();

    return 0;
}








