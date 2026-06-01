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
    ListNode* reverseLL(ListNode* head){
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode* prevnode=nullptr;
        ListNode* nextnode=nullptr;
        ListNode* temp=head;

        while(temp!=nullptr){
            nextnode=temp->next;
            temp->next=prevnode;
            prevnode=temp;
            temp=nextnode;
        }
        return prevnode;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newhead=reverseLL(head);
        ListNode* temp=newhead;
        int cnt=1;
        if(n==1){
            ListNode* newnode=temp->next;
            delete temp;
            return reverseLL(newnode);
        }
        while(temp!=nullptr){
            if(cnt==n-1){
                ListNode* node=temp->next;
                temp->next=temp->next->next;
                delete node;
            }
            cnt++;
            temp=temp->next;
        }
        return reverseLL(newhead);

    
    }
};