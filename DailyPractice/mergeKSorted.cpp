#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class comparator {
    public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator > minHeap;

        int k = lists.size();

        ListNode* head = NULL;
        ListNode* tail = NULL;

        if (k == 0) {
            return NULL;
        }

        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }

        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            if (top -> next != NULL) {
                minHeap.push(top->next);
            }

            if (head == NULL) {
                head = top;
                tail = top;
            }
            else {
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};

int main()
{
    Solution sol;
    vector<ListNode*> lists;
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);
    lists.push_back(head1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    lists.push_back(head2);

    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(6);
    lists.push_back(head3);

    ListNode* result = sol.mergeKLists(lists);

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}