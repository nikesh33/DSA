#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default Ctor
    Node()
    {
        // cout << "Default ctor" << endl;
        this->next = NULL;
    }

    // parameterized ctor
    Node(int data)
    {
        // cout << "param ctor" << endl;
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next; // update
    }
    cout << endl;
}

int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteNode(Node *&head, Node *tail, int position)
{
    // empty list
    if (head == NULL)
    {
        cout << "Cannot delete, coz LL is Empty" << endl;
        return;
    }

    int len = getLength(head);

    // delete from head
    if (position == 1)
    {
        // first node ko delete kardo
    }

    else if (position == len)
    {
        // last node ko delete kardo
    }

    else
    {
        // middle me koi node ko delete kardo
    }
}

int main()
{
}