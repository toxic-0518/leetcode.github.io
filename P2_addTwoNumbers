/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        if(l1 == NULL) {
            return l2;
        } 
        else if(l2 == NULL) {
            return l1;
        }
        ListNode* res = l1;
        while(true) {
            l1->val += (l2->val + c);
            if(l1->val >= 10) {
                c = 1;
                l1->val -= 10;
            } 
            else {
                c = 0;
            }
            if(l1->next == NULL) {
                l1->next = l2->next;
                break;
            } 
            else if(l2->next == NULL) {
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1->next != NULL) {
            l1 = l1->next;
            l1->val += c;
            if(l1->val >= 10) {
                c = 1;
                l1->val -= 10;
            } 
            else {
                c = 0;
            }
        }
        if(c == 1) {
            l2 -> val = c;
            l2 -> next = NULL;
            l1 -> next = l2;
        }
        return res;
    }
};
