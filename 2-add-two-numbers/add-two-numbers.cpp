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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *dummyHead= new ListNode(0);
        ListNode *node1= l1;
        ListNode *node2= l2;
        ListNode *head = dummyHead;
        
        while( node1 || node2 ){
            int x= node1? node1->val: 0;
            int y= node2? node2->val: 0;
            int sum= x + y + carry;
            carry= sum/10;
            dummyHead->next= new ListNode(sum%10);
            dummyHead= dummyHead->next;
            if( node1 ) node1= node1->next;
            if( node2 ) node2= node2->next;
        }
        if(carry>0) dummyHead->next= new ListNode(carry);
        
        return head->next;
    }
};