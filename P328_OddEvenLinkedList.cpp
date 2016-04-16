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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* et = head->next, *ot = head, *eh = head->next;
        while(et && et->next) {
            ot->next = et->next;
            et->next = et->next->next;
            ot = ot->next;
            et = et->next;
        }
        ot->next = eh;
        return head;
    }
};
