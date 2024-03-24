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
public:
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

    void display(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *merge(Node *list1, Node *list2)
    {
        Node *dummy = new Node(0);
        Node *tail = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->data <= list2->data)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes from list1 or list2
        if (list1 != nullptr)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }

        // Return the head of the merged list (excluding dummy node)
        Node *mergedHead = dummy->next;
        delete dummy; // Free the dummy node
        return mergedHead;
    }
};

int main()
{
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(5);

    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(3);
    list2.insert(4);
    list2.insert(5);
    list2.insert(6);
    list2.insert(7);

    cout << "Original linked list 1: " << endl;
    // list1.display();
    cout << "Original linked list 2: " << endl;
    // list2.display();
    LinkedList mergedList;
    Node *mergedHead = mergedList.merge(list1.head, list2.head);
    cout << "Merged linked list: " << endl;
    mergedList.display(mergedHead);

    return 0;
}
