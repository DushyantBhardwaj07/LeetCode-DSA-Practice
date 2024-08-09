class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int data1, int data2){
            key = data1;
            val = data2;
            next = NULL;
            prev = NULL;
        }
    };
    int c = 0;
    int k = 0;
    unordered_map<int, Node *>m;
    Node *head;
    Node *tail;
    LRUCache(int capacity) {
        c = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        Node *ptr = head;
        while(ptr->next != m[key]){
            ptr = ptr->next;            
        }        
        ptr->next = ptr->next->next;
        ptr->next->prev = ptr;
        Node *p = head->next;
        Node *temp = m[key];
        head->next = temp;
        temp->prev = head;
        temp->next = p;
        p->prev = temp;
        return m[key]->val;
    }
    
    void put(int key, int value) {
        Node *n = new Node(key, value);
        if(m.find(key) != m.end()){
            Node *ptr = head;
            while(ptr->next != m[key]){
                ptr = ptr->next;            
            }   
            ptr->next = ptr->next->next;
            ptr->next->prev = ptr;    
            m[key] = n;
            ptr = head->next;
            n->next = ptr;
            ptr->prev = n;
            head->next = n;
            n->prev = head;
        }
        else{
            if(k == c){
                m.erase(tail->prev->key);
                Node *ptr = tail->prev;
                ptr->prev->next = tail;
                tail->prev = ptr->prev;
                k--;
            }
            m[key] = n;
            Node *ptr = head->next;
            n->next = ptr;
            ptr->prev = n;
            head->next = n;
            n->prev = head;
            k++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */