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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow in the middle
        ListNode* second = slow->next;
        slow->next = nullptr;
        slow = second;
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        //now prev has the head of Ln
        ListNode* start = head;
        while (start && prev) {
            ListNode* startnext = start->next;
            ListNode* prevnext = prev->next;

            start->next = prev;
            prev->next = startnext;

            prev = prevnext;
            start = startnext;
        }
        ListNode* hold = start ? start : prev;
        return;
    }
};