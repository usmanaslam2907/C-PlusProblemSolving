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
    Node *rotateRight(int k)
    {
        if (k == 0 || head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Node *tail = head;
        int count = 1; // Initialize count as 1 because we start from head which is not null
        while (tail->next != nullptr)
        {
            count++;
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        k = k % count; // Correct the value of k if it's greater than count

        // Traverse to the (count - k)th node
        int stepsToRotate = count - k;
        Node *newTail = head;
        for (int i = 0; i < stepsToRotate - 1; ++i)
        {
            newTail = newTail->next;
        }

        // Update head and break the circular link
        head = newTail->next;
        newTail->next = nullptr;

        return head;
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
    list.insert(6);
    list.rotateRight(4);

    cout << "Original linked list: ";
    list.display();

    return 0;
}
