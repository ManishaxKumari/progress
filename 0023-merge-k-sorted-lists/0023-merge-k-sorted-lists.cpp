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
    using p=pair<int,ListNode*>;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<p,vector<p>,greater<p>> pq; // min heap

        for(int i=0;i<lists.size();i++){
            ListNode* head=lists[i];
            while(head!=nullptr){
                pq.push({head->val,head});
                head=head->next;
            }
        }
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;
        while(!pq.empty()){
            auto [val,node]=pq.top();
            temp->next=node;
            pq.pop();
            temp=temp->next;
        }
        return dummy->next;
       
    }
};