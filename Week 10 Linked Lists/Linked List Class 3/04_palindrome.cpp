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

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL)
        {
            // fast kon2 step
            fast = fast->next;
            if (fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    bool compareList(ListNode *head1, ListNode *head2)
    {
        while (head2 != NULL)
        {
            if (head1->val != head2->val)
            {
                return false;
            }
            else
            {
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode *head)
    {
        // break into 2 halfs
        ListNode *midNode = middleNode(head);
        ListNode *head2 = midNode->next;
        midNode->next = NULL;
        //  reverse second half
        ListNode *prev = NULL;
        ListNode *curr = head2;
        head2 = reverseUsingRecursion(prev, curr);
        // compare both Linked List
        bool ans = compareList(head, head2);
        return ans;
    }
};

int main()
{
    // // Creating a linked list: 1 -> 2 -> 2 -> 1
    // ListNode *node4 = new ListNode(1);
    // ListNode *node3 = new ListNode(2, node4);
    // ListNode *node2 = new ListNode(2, node3);
    // ListNode *head = new ListNode(1, node2);
    
     // Creating a linked list: 1 -> 2 -> 3 -> 4
    ListNode *node4 = new ListNode(4);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *head = new ListNode(1, node2);

    // Creating Solution object to use its methods
    Solution solution;

    // Check if the linked list is a palindrome
    bool result = solution.isPalindrome(head);

    if (result)
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Free allocated memory
    delete node4;
    delete node3;
    delete node2;
    delete head;

    return 0;
}