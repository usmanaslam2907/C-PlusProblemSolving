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

    bool isPalindrome()
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find the midpoint
        Node *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        Node *prev = nullptr, *curr = slow->next, *nextNode = nullptr;
        while (curr != nullptr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow->next = prev;

        // Compare the first half with the reversed second half
        Node *left = head, *right = slow->next;
        while (right != nullptr)
        {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
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
    list.insert(8);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    list.insert(6);

    cout << "Original linked list: ";
    list.display();

    if (list.isPalindrome())
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
