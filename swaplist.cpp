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

    void alternateNodesWithGap(int gap)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return; // No need to alter if list has 0 or 1 node
        }

        Node *prev = nullptr;
        Node *curr = head;
        Node *nextNode = nullptr;

        int count = 0;
        while (curr != nullptr && count < gap)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        head->next = curr;

        count = 0;
        while (count < gap - 1 && curr != nullptr)
        {
            curr = curr->next;
            count++;
        }

        if (curr != nullptr)
        {
            curr->next = prev;
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
};

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original linked list: ";
    list.display();

    list.alternateNodesWithGap(2);

    cout << "After alternating nodes with gap of 2: ";
    // list.display();

    return 0;
}
