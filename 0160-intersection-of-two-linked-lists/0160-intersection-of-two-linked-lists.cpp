/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
      ListNode* colPoint(ListNode *smallHead, ListNode *longHead, int len){
        ListNode *temp1=smallHead;
        ListNode *temp2=longHead;
        for(int i=0;i<len;i++){
            temp2=temp2->next;
        }
        while(temp1 != temp2) {
            temp1 = temp1-> next;
            temp2 = temp2-> next;
        }
        return temp1;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode* temp1=headA;
        ListNode* temp2=headB;
        int l1=0,l2=0;
        while(temp1 != nullptr){
            l1++;
            temp1=temp1->next;
        }
         while(temp2 != nullptr){
            l2++;
            temp2=temp2->next;
        }
        if(l1<l2) return colPoint(headA,headB,l2-l1);
        return colPoint(headB,headA,l1-l2);
    }
};