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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        if (head->next == NULL)
        {
            return head;
        }

        // main logic
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL && temp->val == temp->next->val)
            {
                // remove logic
                ListNode *nextNode = temp->next;
                temp->next = nextNode->next;
                nextNode->next = NULL;
                delete nextNode;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};

// Function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3 -> 4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);

    Solution solution;
    cout << "Original Linked List: ";
    printList(head);

    head = solution.deleteDuplicates(head);

    cout << "Linked List after removing duplicates: ";
    printList(head);

    return 0;
}