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
    ListNode* mergeTwosortedll(ListNode* list1 , ListNode* list2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(list1 && list2){
            if(list1->val >= list2->val){
                temp->next=list2;
                list2=list2->next;
            }
            else {
                temp->next=list1;
                list1=list1->next;
            }
            temp=temp->next;
        }
        temp->next=(list1)? list1 : list2;
        ListNode* head=dummy->next;
        delete dummy;
        return head;
    }

    ListNode* getmiddle(ListNode* temp){
        if(temp==nullptr || temp->next==nullptr){
            return temp;
        }
        ListNode* slow=temp;
        ListNode* fast=temp->next; // beacuse we need before first middle not second

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* middle=getmiddle(head); //find mid point
        //divide into 2 half
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=nullptr;

        //recursively sort both side
        left=sortList(left);
        right=sortList(right);

        //merge sorted side
        return mergeTwosortedll(left,right);

    }
};