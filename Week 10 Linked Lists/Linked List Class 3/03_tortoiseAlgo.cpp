#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL)
        {
            // fast kon2 step
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                // main yaha keh sakta hu fast ne 2 step chal liya h
                // ab slow ko bhi chalwa do ek step
                slow = slow->next;
            }
        }
        return slow;  
    }
};

// Function to print the linked list.
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating a simple linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "Original list: ";
    printList(head);

    // Finding the middle node.
    Solution solution;
    ListNode *middle = solution.middleNode(head);

    // Print the middle node value.
    if (middle != nullptr)
    {
        cout << "Middle node value: " << middle->val << endl;
    }

    // Free memory allocated for the list nodes.
    ListNode *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}