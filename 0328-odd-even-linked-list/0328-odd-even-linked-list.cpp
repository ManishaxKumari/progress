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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
            
        vector<int> ans;
        ListNode* temp=head;
        while(temp!=nullptr && temp->next !=nullptr){
            ans.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp!=nullptr){
            ans.push_back(temp->val);
        }
        temp=head->next;
        while(temp != NULL && temp->next != NULL){
            ans.push_back(temp->val);
            temp=temp->next->next;
        }
         if (temp != NULL){
            ans.push_back(temp->val);

         }
            
        temp=head;
        int i=0;
        while(temp!=nullptr){
            temp->val=ans[i];
            temp=temp->next;
            i++;
        }
        return head;

    }
};