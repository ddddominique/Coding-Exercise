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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // reverse the link, remove it, and reverse it again
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // now prev has the head
        curr = prev;
        int counter = 0;
        if (n == 1) {
            prev = prev->next;
        } else {
            ListNode* myprev = nullptr;
            while (curr) {
                counter++;
                ListNode* mynext = curr->next;
                if (counter == n) {
                    myprev->next = mynext;
                    break;
                } else {
                    myprev = curr;
                    curr = mynext;
                }
            }
        }
        curr = prev;
        prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return head;
    }
};