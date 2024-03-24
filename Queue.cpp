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
        if(front==-1 && rear==-1)
        {
            cout << "Queue us Empty" << endl;
        }
        else{
            for (int i = front; i <=rear; i++)
            {
                cout << array[i] << " ";
            }
            
        }
    }
    void dequeue()
    {
        if(front==-1 && rear==-1)
        {
            cout << "Queue is Empty" << endl;
        }
         else if(front==rear)
         {
             front = rear = -1;
         }
        else{
            front++;
        }
    }
};

int main()
{
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    return 0;
}