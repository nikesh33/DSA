#include <iostream>
#include <unordered_map>
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
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, bool> mapping;
        ListNode *temp = head;

        while (temp != NULL)
        {
            // address check
            // pehle se visited hai ki nahi
            if (mapping.find(temp) != mapping.end())
            {
                // cycle present
                return true;
            }

            else
            {
                // Node not visited beforeHand
                // store
                mapping[temp] = true;
            }
            temp = temp->next;
        }
        // cycle not present
        return false;
    }
};

int main()
{
    // Create nodes for the linked list
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    // Link the nodes to form a cycle (3 -> 2 -> 0 -> -4 -> 2 ...)
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates a cycle
    // node4->next = NULL; // No cycle we are placing to null node

    Solution solution;
    if (solution.hasCycle(node1))
    {
        cout << "Cycle detected in the linked list." << endl;
    }
    else
    {
        cout << "No cycle in the linked list." << endl;
    }

    // Clean up the allocated memory (not necessary if there's a cycle, but a good practice)
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}