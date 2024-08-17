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

void createTail(Node *head, Node *&tail)
{
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // jab ye loop khatam hogya hoga
    // then apka temp wala pointer
    // khada hoga last node par
    // tab tail = temp karke, tail ko last node par le aao
    tail = temp;
}

int main()
{
    // // creation of Node
    // // Node a;  //static allocation

    // // dynamic allocation
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);
    // Node *head = first;
    // Node *tail = fifth;

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // // Linked List Create Ho chuka hai

    // cout << "Printing the entire LL: " << endl;
    // printLL(head);

    // // cout << getLength(head) << endl;

    // // inserAtHead(head, tail, 500);
    // // for attaching tail node
    // inserAtTail(head, tail, 500);
    // cout << "Printing the entire LL: " << endl;
    // printLL(head);

    Node *head = NULL;
    Node *tail = NULL;

    inserAtHead(head, tail, 10);
    inserAtHead(head, tail, 20);
    inserAtHead(head, tail, 30);
    inserAtTail(head, tail, 50);
    printLL(head);

    return 0;
}