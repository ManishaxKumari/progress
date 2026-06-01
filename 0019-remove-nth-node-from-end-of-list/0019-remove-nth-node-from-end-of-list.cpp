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
    int length(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totallen=length(head);
        int k=totallen-n+1;
        ListNode* temp=head;
        int cnt=1;
        if(k==1){
            head=head->next;
            delete temp;
            return head;
        }
        while(temp!=nullptr){
            if(cnt==k-1){
                ListNode* node=temp->next;
                temp->next=temp->next->next;
                delete node;
            }
            cnt++;
            temp=temp->next;
        }
        return head;


    
    }
};