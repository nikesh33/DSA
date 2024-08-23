#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Insert node at head
void insertAtHead(ListNode *&head, ListNode *&tail, int data)
{
    ListNode *newNode = new ListNode(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

// Insert node at tail
void insertAtTail(ListNode *&head, ListNode *&tail, int data)
{
    ListNode *newNode = new ListNode(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert node at position
void insertAtPosition(ListNode *&head, ListNode *&tail, int data, int position)
{
    if (position <= 0)
        return;

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    ListNode *newNode = new ListNode(data);
    ListNode *prevNode = NULL;
    ListNode *currNode = head;
    int len = 1; // Start counting from the head

    while (currNode != NULL && len < position - 1)
    {
        prevNode = currNode;
        currNode = currNode->next;
        len++;
    }

    if (prevNode == NULL) // Inserting at the head
    {
        insertAtHead(head, tail, data);
    }
    else if (currNode == NULL) // Inserting at the tail
    {
        insertAtTail(head, tail, data);
    }
    else // Inserting in the middle
    {
        prevNode->next = newNode;
        newNode->next = currNode;
    }
}

// Print linked list
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
}

class Solution
{
public:
    bool checkLoop(ListNode *&head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            // check for loop
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};

ListNode *getStartingPointOfLoop(ListNode *&head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // check for loop
        if (fast == slow)
        {
            break;
        }
    }
    // Slow and fast pointers meet, indicating a loop
    slow = head;

    // Move both slow and fast one step at a time to find the loop's starting point
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // Return the starting point of the loop
    return slow;
}

void removeLoop(ListNode *&head)
{
    // check for loop
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // check for loop
        if (fast == slow)
        {
            break;
        }
    }

    slow = head;
    // Remove a Loop

    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // starting point
    ListNode *startPoint = slow;

    ListNode *temp = startPoint;
    while (temp->next != startPoint)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

ListNode *reverse(ListNode *&head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void addOne(ListNode *&head)
{
    // reverse
    head = reverse(head);

    // add 1
    int carry = 1;
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        int totalSum = temp->val + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->val = digit;
        temp = temp->next;
        if (carry == 0)
        {
            break;
        }
    }

    // process last node
    if (carry != 0)
    {
        int totalSum = temp->val + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->val = digit;
        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
        }
    }

    // reverse
    head = reverse(head);
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    // Insert nodes
    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 1);
    print(head);
    cout<<endl;
    addOne(head);
    print(head);
    return 0;
}
