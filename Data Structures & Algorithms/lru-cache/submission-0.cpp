class LRUCache {
    class Node{
        public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int k,int v)
        {
            key=k;
            val=v;
            prev=nullptr;
            next=nullptr;
        }
    };
    int cap;
    unordered_map<int,Node*>mp;
    Node *head;
    Node *tail;
public:
    LRUCache(int capacity) {
        this->cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void remove(Node *node)
    {
        Node *prevnode=node->prev;
        Node *nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }
    void addtoright(Node *node)
    {
        Node *prevnode=tail->prev;
        node->prev=prevnode;
        prevnode->next=node;
        node->next=tail;
        tail->prev=node;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        Node *node=mp[key];
        remove(node);
        addtoright(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node *node=mp[key];
            node->val=value;
            remove(node);
            addtoright(node);
            return;
        }
        Node *node=new Node(key,value);
        mp[key]=node;
        addtoright(node);
        if(mp.size()>cap)
        {
            Node *lru=head->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
