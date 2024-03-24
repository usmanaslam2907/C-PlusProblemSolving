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
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void removeduplicates()
    {
        bool flag = false;
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == current->next->data)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
                flag = true;
            }
            else
            {
                if (flag == true)
                {
                    Node *temp = current;
                    current = current->next;
                    delete temp;
                    flag = false;
                }
                else
                {
                    current = current->next;
                }
            }
        }
    }
};

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.removeduplicates();

    cout << "Original linked list: ";
    list.display();

    return 0;
}
