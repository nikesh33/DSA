#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

// length
int findLength(Node *&head)
{
    Node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // LL is Empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else
    {
        // LL is not empty
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // LL is Empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = NULL;
        tail = NULL;
    }
    // LL is Non Empty
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Insert At Middle
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // LL is Empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = NULL;
        tail = NULL;
    }
    // LL is Non Empty
    else
    {
        int len = findLength(head);
        if (position == 1)
        {
            insertAtHead(head, tail, data);
        }
        else if (position == len + 1)
        {
            insertAtTail(head, tail, data);
        }

        else
        {
            // Insert at Middle
            // step 1: create node
            Node *newNode = new Node(data);
            // step2: set prev anf curr pointer
            Node *prevNode = NULL;
            Node *currNode = head;
            while (position != 1)
            {
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            // step3: pointers update kar the
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        // LL is empty
        cout << "Cannot delete, coz LL is Empty" << endl;
        return;
    }

    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    int len = findLength(head);

    if (position == 1)
    {
        // delete from head
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if (position == len)
    {
        // delete from tail
        Node *prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }

    else
    {
        // delete from middle
        // step 1: set prevNode/currNode/nextNode
        Node *prevNode = NULL;
        Node *currNode = head;
        while (position != 1)
        {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node *nextNode = currNode->next;

        // pointer
        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        delete currNode;
    }
}

int main()
{
    // Node *head = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    printLL(head);
    cout << endl;
    // insertAtPosition(head, tail, 1000, 6);

    deleteNode(head, tail, 1);
    printLL(head);
    cout << endl;
    deleteNode(head, tail, 2);
    printLL(head);

    cout << endl;
    deleteNode(head, tail, 2);
    printLL(head);

    cout << endl;
    deleteNode(head, tail, 1);
    printLL(head);

    cout << endl;
    deleteNode(head, tail, 1);
    printLL(head);

    cout << "Length of LL is: " << findLength(head) << endl;
    return 0;
}