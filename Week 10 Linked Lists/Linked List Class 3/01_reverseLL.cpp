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

// Function to print the linked list.
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *reverseUsingRecursion(ListNode *prev, ListNode *curr)
    {
        // base case
        if (curr == NULL)
        {
            return prev;
        }

        // 1 Case hum solve karenge
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        // baki ka case recursion
        ListNode *recursionKaAns = reverseUsingRecursion(prev, curr);
        return recursionKaAns;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        // // Ittractive Approach
        // while (curr != NULL)
        // {
        //     ListNode *nextNode = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nextNode;
        // }
        // return prev;

        // Recursion
        return reverseUsingRecursion(prev, curr);
    }
};

int main()
{
    // Creating a simple linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Reverse the linked list.
    Solution solution;
    ListNode *reversedHead = solution.reverseList(head);

    cout << "Reversed list: ";
    printList(reversedHead);

    // Free memory allocated for the list nodes.
    ListNode *temp;
    while (reversedHead != nullptr)
    {
        temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}