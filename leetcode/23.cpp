/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (ListNode* list : lists) {
            while (list) {
                heap.push(list->val);
                list = list->next;
            }
        }
        ListNode* result = new ListNode();
        ListNode* curr = result;
        while (!heap.empty()) {
            ListNode* newnode = new ListNode(heap.top());
            heap.pop();
            curr->next = newnode;
            curr = curr->next;
        }
        result = result->next;
        return result;
    }
};