
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
    int size()
    {
        return rear -front+1;
    }
};
class Stack
{
    Queue q1;

    public:
    void push(int x)
    {
        q1.enqueue(x);
        for (int i = 0; i < q1.size()-1; i++)
        {
            q1.enqueue(q1.dequeue());
        }
        
        
        
    }
    int pop()
    {
        int deqq = q1.dequeue();
        return deqq;
    }
    void display()
    {
        q1.display();
    }
};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.pop();
    s1.display();
    return 0;
}