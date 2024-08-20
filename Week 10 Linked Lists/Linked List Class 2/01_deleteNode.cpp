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

    ~Node()
    {
        cout << "Destrutor called: " << this->data << endl;
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

void inserAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty LL
        // Step 1 : create new node
        Node *newNode = new Node(data);
        // step 2 : update head
        head = newNode;
        tail = newNode;
    }

    else
    {
        // Non-empty LL wala case
        // create a new node
        Node *newNode = new Node(data);
        // attach new node to head node
        newNode->next = head;
        // update head
        head = newNode;
    }
}

void inserAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty LL
        // step 1: create toh karo node
        Node *newNode = new Node(data);
        // step 2:single node hai entire list main, thats whyhead and tail ko ispar point karwado
        head = newNode;
        tail = newNode;
    }

    else
    {
        // non empty
        // step 1 : Create new Node
        Node *NewNode = new Node(data);
        // step 2 : tail node ko attach karo newNode se
        tail->next = NewNode;
        // step 3 : upate tail
        tail = NewNode;
    }
}

void deleteNode(Node *&head, Node *tail, int position)
{
    // empty list
    if (head == NULL)
    {
        cout << "Cannot delete, coz LL is Empty" << endl;
        return;
    }

    if (head == tail)
    {
        // single element
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    int len = getLength(head);

    // delete from head
    if (position == 1)
    {
        // first node ko delete kardo
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else if (position == len)
    {
        // last node ko delete kardo

        // find prev
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }

        // prev node ka link null karo
        prev->next = NULL;

        // Node delete karo
        delete tail;

        // update tail
        tail = prev;
    }

    else
    {
        // middle me koi node ko delete kardo

        //  step 1: set prev/curr pointers
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }

        // step 2: prev -> next me curr ka next node add karo
        prev->next = curr->next;

        // step 3: node isolate kardo
        curr->next = NULL;

        // step 4: delete node
        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    inserAtHead(head, tail, 50);
    inserAtHead(head, tail, 40);
    inserAtHead(head, tail, 30);
    inserAtHead(head, tail, 20);
    inserAtHead(head, tail, 10);

    printLL(head);
    cout << endl;

    deleteNode(head, tail, 3);
    printLL(head);
    cout << endl;
}