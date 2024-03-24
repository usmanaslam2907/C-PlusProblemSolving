#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    /////////////////////////     Insertion in LinkedList        ////////////////////

    void insertatbegin(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
    }
    void insertatend(int x)
    {
        Node *temp = new Node(x);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = temp;
        }
    }
    void insertatposition(int x, int y)
    {
        Node *temp = new Node(x);
        if (y == 1)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            Node *current = head;
            for (int i = 1; i < y - 1; i++)
            {
                current = current->next;
            }

            temp->next = current->next;
            current->next = temp;
        }
    }

    /////////////////////////////     Display    ///////////////////////////////////
    void display()
    {
        if (head == nullptr)
        {
            cout << "LinkedList is Empty" << endl;
        }
        else
        {
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->data << " " << endl;
                current = current->next;
            }
        }
    }

    /////////////////////////////        Deletion in LinkedList     ////////////////////////////////

    void deleteatbegin()
    {
        if (head == nullptr)
        {
            cout << "LinkedList is Empty" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void deleteatend()
    {
        Node *current = head;
        while(current->next->next!=nullptr)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    void deleteatposition(int x)
    {
        if (x == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *current = head;
            for (int i = 1; i < x - 1 && current != nullptr; ++i)
            {
                current = current->next;
            }
            if (current == nullptr || current->next == nullptr)
            {
                cout << "Invalid position" << endl;
                return;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
};
int main()
{
    LinkedList L1;
    L1.insertatend(1);
    L1.insertatend(2);
    L1.insertatend(30);
    L1.insertatend(4);
    L1.insertatend(5);
    L1.deleteatposition(3);
    // L1.deleteatend();
    L1.display();
    return 0;
}