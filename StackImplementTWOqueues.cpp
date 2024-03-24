
#include <iostream>
using namespace std;
class Queue
{
private:
    int array[10];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 10; i++)
        {
            array[i] = 0;
        }
    }
    bool isempty()
    {
        return front == -1 && rear == -1;
    }
    void enqueue(int x)
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        array[rear] = x;
    }
    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue us Empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << array[i] << " ";
            }
        }
    }
    int dequeue()
    {

        if (front == -1 && rear == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else if (front == rear)
        {
            int deqq = array[front];
            front = rear = -1;
            return deqq;
        }
        else
        {
            int deqq = array[front];
            front++;
            return deqq;
            
        }
       
    }
};

class Stack{
    Queue q1;
    Queue q2;
    public:
    void push(int x)
    {
        q1.enqueue(x);
        while(!q2.isempty())
        {
            q1.enqueue(q2.dequeue());
        }
        while (!q1.isempty())
        {
            q2.enqueue(q1.dequeue());
        }
    }
    int pop()
    {
        int deqq=q2.dequeue();
        return deqq;
    }
    void display()
    {
        if(q2.isempty())
        {
            cout << "Stack is empty" << endl;
        }
        else{
            q2.display();
        }
    }
};
int main()
{
    Stack stk1;
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    stk1.push(4);
    stk1.pop();
    stk1.display();
    return 0;
}
