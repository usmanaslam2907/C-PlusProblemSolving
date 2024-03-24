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
                    cout << current->data << " ";
                    current = current->next;
                }
            }
        }
        Node *reverse()
        {
            Node *pre = nullptr;
            Node *current = head;
            Node *nextNode = nullptr;
            while (current != nullptr)
            {
                nextNode = current->next;
                current->next = pre;
                pre = current;
                current = nextNode;
            }
            head = pre;
            return head;
        }
        void delete_m_n(int m, int n)
        {
            Node *current = head;
            for (int i = 1; i < m; i++)
            {
                current = current->next;
            }
            if (current == nullptr || current->next == nullptr)
            {
                return;
            }
            for (int i = 1; i < n; i++)
            {
                Node *temp = current->next;
                current->next = temp->next;
                delete temp;
            }
        }
        void remove_duplicates()
        {
            Node *current = head;
            for (int i = 0; current != nullptr; i++)
            {
                Node *runner = current;
                for (int j = 0; runner->next != nullptr; j++)
                {
                    if (current->data == runner->next->data)
                    {
                        Node *temp = runner->next;
                        runner->next = runner->next->next;
                        delete temp;
                    }
                    runner = runner->next;
                }
                current = current->next;
            }
        }
        void deleteNthNodeatend(int nth)
        {
            Node *current = reverse();
            for (int i = 1; i < nth; i++)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
            // current = reverse();
        }
        void reorderList()
        {
            if (head == nullptr || head->next == nullptr)
                return;

            // Step 1: Find the midpoint
            Node *slow = head, *fast = head;
            while (fast->next != nullptr && fast->next->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            // Split the list into two halves
            Node *secondHalf = slow->next;
            slow->next = nullptr;

            // Step 2: Reverse the second half
            Node *prev = nullptr;
            Node *curr = secondHalf;
            Node *nextNode = nullptr;
            while (curr != nullptr)
            {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            secondHalf = prev;

            // Step 3: Merge the two halves alternatively
            Node *first = head;
            while (secondHalf != nullptr)
            {
                Node *temp1 = first->next;
                Node *temp2 = secondHalf->next;

                first->next = secondHalf;
                secondHalf->next = temp1;

                first = temp1;
                secondHalf = temp2;
            }
        }
    };
    int main()
    {
        LinkedList L1;
        L1.insertatend(1);
        L1.insertatend(2);
        L1.insertatend(3);
        L1.insertatend(4);
        L1.insertatend(5);
        L1.insertatend(6);
        L1.insertatend(5);
        L1.insertatend(6);
        L1.insertatend(7);
        L1.insertatend(8);
        L1.insertatend(9);
        L1.insertatend(10);
        L1.reorderList();
        // L1.remove_duplicates();
        // L1.deleteNthNodeatend(3);
        L1.display();

        return 0;
    }