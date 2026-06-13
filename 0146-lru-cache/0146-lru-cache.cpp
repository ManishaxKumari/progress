class Node{
public:
    int key,val;
    Node* next;
    Node* prev;
    Node(){
        key=val=-1;
        next=prev=nullptr;
    }
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=prev=nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int,Node*>mpp;
    int cap;
    Node* head;
    Node* tail;
    void deletenode(Node* node){
        Node* prevnode=node->prev;
        Node* nextnode=node->next;

        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }
    void insertnode(Node* node){
        Node* nextnode=head->next;
        head->next=node;
        node->prev=head;
        node->next=nextnode;
        nextnode->prev=node;
    }

public:
    LRUCache(int capacity) {
        cap=capacity;
        mpp.clear();
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        int value=node->val;
        deletenode(node);
        insertnode(node);
        return value;

    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deletenode(node);
            insertnode(node);
            return;
        }
        if(mpp.size()==cap){
            Node* node=tail->prev;
            mpp.erase(node->key);
            deletenode(node);
        }
        Node* newnode=new Node(key,value);
        mpp[key]=newnode;
        insertnode(newnode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */