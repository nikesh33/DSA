#include <iostream>
#include <map>

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
        std::map<ListNode *, bool> table;

        ListNode *temp = head;
        while (temp != NULL)
        {
            if (table[temp] == false)
            {
                table[temp] = true;
            }
            else
            {
                // cycle present
                return true;
            }
            temp = temp->next;
        }
        // loop not present
        return false;
    }
};

int main()
{
    // Create nodes
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);

    // Set up the list: 1 -> 2 -> 3 -> 4
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Uncomment the line below to create a cycle: 4 -> 2
    node4->next = node2;

    // Check for cycle
    Solution solution;
    bool result = solution.hasCycle(node1);

    // Output result
    if (result)
    {
        std::cout << "Cycle detected in the linked list." << std::endl;
    }
    else
    {
        std::cout << "No cycle detected in the linked list." << std::endl;
    }

    // Clean up the nodes (not necessary if there is a cycle as it will not terminate)
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
