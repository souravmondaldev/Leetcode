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
        ListNode *start= new ListNode();
        start->next= head;
        ListNode * fastPtr= start;
        ListNode * slowPtr= start;
        for(int i=0; i< n + 1;i++){
            fastPtr= fastPtr->next;
        }
        while(fastPtr){
            fastPtr= fastPtr->next;
            slowPtr= slowPtr->next;
        }
        ListNode * temp= slowPtr->next;
        slowPtr->next= slowPtr->next->next;
        delete(temp);
        return start->next;
    }
};