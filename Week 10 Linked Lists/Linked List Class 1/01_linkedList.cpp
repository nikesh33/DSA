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
        cout << "Default ctor" << endl;
        this->next = NULL;
    }

    // parameterized ctor
    Node(int data)
    {
        cout<<"param ctor"<<endl;
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->"; 
        temp = temp-> next; //update
    }
    cout<<endl;
}

int main()
{
    // creation of Node
    // Node a;  //static allocation

    // dynamic allocation
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Linked List Create Ho chuka hai

    Node* head = first;
    cout<<"Printing: ";
    printLL(head);
    return 0;
}