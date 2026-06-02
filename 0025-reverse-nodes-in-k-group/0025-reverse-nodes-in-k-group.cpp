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
    ListNode* reversell(ListNode* temp){ // here we doesnot change temp position
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
    ListNode* getkthnode(ListNode* temp,int k){ // here we change the temp position
        k=k-1;
        while(temp!=nullptr && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=nullptr;

        while(temp!=nullptr){
            ListNode* kthnode=getkthnode(temp,k);
            if(kthnode==nullptr){
                if(prevnode){
                    prevnode->next=temp;
                }
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=nullptr;

            reversell(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevnode->next=kthnode;
            }
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};