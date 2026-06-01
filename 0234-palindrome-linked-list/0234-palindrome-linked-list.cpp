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
    ListNode* reversell(ListNode* node){
        ListNode* prev=nullptr;
        ListNode* curr=node;
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* revhead=reversell(slow);
        ListNode* l1=head;
        ListNode* l2=revhead;
        while(l2!=nullptr){
            if(l1->val != l2->val){
                reversell(revhead);
                return false;
            }
            l1=l1->next;
            l2=l2->next;
        }
        reversell(revhead);
        return head;

    }
};