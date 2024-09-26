#include <iostream>
#include <queue>
#include <vector>
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

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        // Process First element of every K LL
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *listHead = lists[i];
            if (listHead != NULL)
            {
                pq.push(listHead);
            }
        }

        // for new LinkedLIST
        ListNode *head = NULL;
        ListNode *tail = NULL;

        while (!pq.empty())
        {
            ListNode *topNode = pq.top();
            pq.pop();
            // ye topNode jo nikala hai
            // ye hamari first node ho
            if (head == NULL)
            {
                // pehli node insert krra hu
                head = topNode;
                tail = topNode;
                if (tail->next != NULL)
                {
                    pq.push(tail->next);
                }
            }
            else
            {
                // pehle ke baad me koi node insert krra hu
                tail->next = topNode;
                tail = topNode;
                if (tail->next != NULL)
                {
                    pq.push(tail->next);
                }
            }
        }
        return head;
    }
};

int main()
{
    // Creating example linked lists
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    // Adding the lists to the vector
    vector<ListNode *> lists = {list1, list2, list3};

    // Create an object of Solution class and call the mergeKLists function
    Solution solution;
    ListNode *mergedList = solution.mergeKLists(lists);

    // Printing the merged linked list
    while (mergedList != nullptr)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}
