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
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr){
            int sum=carry;
            if(l1!=nullptr && l2!=nullptr){
                sum+=l1->val+l2->val;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1!=nullptr){
                sum+=l1->val;
                l1=l1->next;
            }
            else{
                sum+=l2->val;
                l2=l2->next;
            } 

            if(sum<=9){
                prev->next=new ListNode(sum);
                carry=0;
            }
            else{
                carry=1;
                prev->next=new ListNode(sum%10);
            }
            prev=prev->next;

        }
        if(carry==1){
            prev->next=new ListNode(1);
        }
        return dummy->next;
    }
};