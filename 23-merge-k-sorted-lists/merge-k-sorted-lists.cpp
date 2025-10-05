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
        priority_queue<pair<int, ListNode*>> sortedNodeStore;
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        int n = lists.size();
        for(int i = 0; i < n; i ++){
            if(lists[i] != nullptr){
                sortedNodeStore.push({-lists[i]->val, lists[i]});
            }
        }
        while(!sortedNodeStore.empty()){
            auto topEl = sortedNodeStore.top();
            sortedNodeStore.pop();
            ListNode* node = topEl.second;
            // cout << node->val << endl;
            temp->next = node;
            temp = temp->next;
            if(node->next){
                node = node->next;
                sortedNodeStore.push({-node->val, node});
            }
        }

        return head->next;
    }
};