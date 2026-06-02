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
    ListNode* reversell(ListNode* temp){
        ListNode* prev=nullptr;
        ListNode* curr=temp;
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int lenght(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr && k==1){
            return head;
        }
        // ListNode* fast=head;
        int n=lenght(head);
        k=k%n;
        // for(int i=0;i<k;i++){
        //     fast=fast->next;
        // }
        // ListNode* slow=head;
        // while(fast!=nullptr && fast->next!=nullptr){
        //     slow=slow->next;
        //     fast=fast->next;
        // }
        int cnt=n-k-1;
        ListNode* temp=head;
        while(cnt>0){
            cnt--;
            temp=temp->next;
        }
        ListNode* prevnode=head;
        ListNode* nextnode=temp->next;
        temp->next=nullptr;
        reversell(head);
        head=temp;
        prevnode->next=reversell(nextnode);

        return reversell(head);

    }
};