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
    int getLength(ListNode* head) {
        int result = 0;
        ListNode* curr = head;
        while (curr) {
            result++;
            curr = curr->next;
        }
        return result;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = getLength(head);
        if (n == 1) {return nullptr;}
        ListNode* curr = head;
        int count = 0;
        while (count < (n / 2) - 1) {
            curr = curr->next;
            count++;
        }
        
        curr->next  = curr->next->next;


        return head;
    }
};