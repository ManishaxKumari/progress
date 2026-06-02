/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopyInBetween(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* nextelement=temp->next;
            Node* copy= new Node(temp->val);
            copy->next=nextelement;
            temp->next=copy;
            temp=nextelement;
        }
    }
    void connectRandomPointers(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copynode=temp->next;
            if(temp->random){
                copynode->random=temp->random->next;
            }
            else{
                copynode->random=nullptr;
            }
            temp=temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head){
        Node* temp=head;
        Node* dummynode=new Node(-1);
        Node* res=dummynode;
        while(temp!=nullptr){
            res->next=temp->next;
            res=res->next;

            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummynode->next;
    }


    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};