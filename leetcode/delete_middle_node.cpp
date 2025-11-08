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
    int get_length(ListNode* head) {
        int result = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            result++;
            curr = curr->next;
        }
        return result;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (get_length(head) == 1) return nullptr;

        int middle = get_length(head) / 2 ;
        int count = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (count == middle - 1) {
                curr->next = curr->next->next;
                break;
            } 
            count++;
            curr = curr->next;
        }
        return head;
    }
};