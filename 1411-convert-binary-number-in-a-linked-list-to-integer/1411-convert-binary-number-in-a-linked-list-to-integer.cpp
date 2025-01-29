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
    ListNode* reverse(ListNode* head){
        //base case
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newhead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;

    }

    int getDecimalValue(ListNode* head) {
        ListNode* temp=reverse(head);
        int x,total=0,i=0;
        while(temp!=nullptr){
            x=temp->val;
            total=total+pow(2,i)*x;
            i++;
            temp=temp->next;
        }
        return total;
    }
};