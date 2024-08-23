#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

int main()
{
    Solution sol;

    // Create nodes
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);

    // Create a linked list: 1 -> 2 -> 3 -> 4
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Check for loop in the list (no loop here)
    bool hasLoop = sol.checkLoop(head);
    cout << "List has loop: " << (hasLoop ? "Yes" : "No") << endl;

    // Create a loop for testing
    fourth->next = second; // Loop: 1 -> 2 -> 3 -> 4 -> 2 ...

    // Check for loop in the list (loop present now)
    hasLoop = sol.checkLoop(head);
    cout << "List has loop: " << (hasLoop ? "Yes" : "No") << endl;

    // Cleanup (not needed in real code, but good practice to avoid memory leaks)
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}