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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while ( curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

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
    int pairSum(ListNode* head) {
        int count = 0;
        int middle = get_length(head) / 2 - 1;
        ListNode* curr = head;
        while(count <= middle) {
            curr = curr->next;
            count++;
        }

        ListNode* other_end = reverseList(curr);
        int result = 0;
        while (other_end) {
            int temp = head->val;
            temp += other_end->val;
            other_end = other_end->next;
            head  = head->next;
            result = max(temp, result);
        }

        return result;

    }
};