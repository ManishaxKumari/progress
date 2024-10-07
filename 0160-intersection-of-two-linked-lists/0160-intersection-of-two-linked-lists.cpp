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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_A=0,len_B=0;
        ListNode * node = headA;
        while(node){
            len_A++;
            node = node->next;
        }
         ListNode * Node = headB;
         while(Node){
            len_B++;
            Node = Node->next;
        }
        node = headA;
        Node=headB;
       
        while(len_A>len_B) {
                node=node->next;
                 len_A--;
            }
        while(len_A<len_B){
                 Node = Node->next;
                  len_B--;
            }
            while(node && Node){
         if(node ==Node){
           return node;
         }  
         else  {
             node = node->next;
            Node = Node->next;
         }
        }
        return NULL;
    }
};