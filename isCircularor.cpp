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
    bool iscircularlist()
    {
        Node *fast = head;
        Node *slow = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast = fast->next->next;
        }
        if(fast->next==nullptr)
        {
            return false;
        }
        else{
            return true;
        }
    }
    bool anothercircularlist()
    {
        Node *fast = head;
        Node *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
    // Function to create a loop in the linked list from the specified start index
    void makecircular(int startIndex)
    {
        Node *startNode = head;
        Node *temp = head;
        int index = 0;
        while (temp != nullptr)
        {
            if (index == startIndex)
            {
                startNode = temp;
            }
            temp = temp->next;
            index++;
        }
        if (startNode == nullptr)
        {
            cout << "Invalid start index." << endl;
            return;
        }
        // Find the last node
        Node *lastNode = head;
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }
        // Create the loop
        lastNode->next = startNode;
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
    list.insert(7);
    cout << "Original linked list: ";
    list.makecircular(5);
    list.display();
  
    // list.iscircularlist();
    // list.anothercircularlist();
    // if (list.iscircularlist())
    // {
    //     cout << "The linked list is a Circular." << endl;
    // }
    // else
    // {
    //     cout << "The linked list is not a Circular." << endl;
    // }
    // if (list.anothercircularlist())
    // {
    //     cout << "The linked list is a Circular." << endl;
    // }
    // else
    // {
    //     cout << "The linked list is not a Circular." << endl;
    // }

    return 0;
}
