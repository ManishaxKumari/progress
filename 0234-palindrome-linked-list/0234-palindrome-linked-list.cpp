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
   
    // bool isPalindrome(ListNode* head) {
    //     ListNode* orghead=head;
    //     ListNode* revhead=reverseLL(head);
    //     ListNode* temp1=orghead;
    //     ListNode* temp2=revhead;
    //     while(temp1 != nullptr){
    //         if(temp1->val != temp2->val){
    //             return false;
    //         }
    //         temp1=temp1->next;
    //         temp2=temp2->next;
    //     }
    //     return true;

    //     above method is not work because reverse karne ke bad tum orginal head ko hi 
    //     reverse kar dete ho , tum orginal ko store nhi rkh sakte kyuki memory address 
    //     same hota h 


    // }

     ListNode* reverseLL(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr =head;
        while(curr != nullptr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head){
        if(head==nullptr || head->next == nullptr){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next !=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newHead; 
        while(second != nullptr){
            if(first->val != second->val){
                //reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        //reverseLL(newHead);
        return true;


    }
};