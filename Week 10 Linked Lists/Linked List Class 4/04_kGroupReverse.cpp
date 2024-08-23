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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 1)
        {
            return head;
        }

        // Count the nodes to check if we have enough nodes to reverse
        ListNode *curr = head;
        int count = 0;
        while (curr != nullptr && count < k)
        {
            curr = curr->next;
            count++;
        }

        if (count < k)
        {
            return head; // Not enough nodes to reverse
        }

        // Reverse the first k nodes
        ListNode *prev = NULL;
        curr = head;
        ListNode *nextNode = nullptr;
        int pos = 0;
        while (pos < k && curr != nullptr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }

        // Recursively reverse the rest of the list and connect
        if (nextNode != nullptr)
        {
            head->next = reverseKGroup(nextNode, k);
        }

        return prev; // prev is the new head of the reversed list
    }
};

// Function to print the linked list
void printList(ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution solution;
    cout << "Original Linked List: ";
    printList(head);

    head = solution.reverseKGroup(head, k);

    cout << "Reversed Linked List in groups of " << k << ": ";
    printList(head);

    return 0;
}
