class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node *next;
        Node *prev;

        Node(int k, int v){
            key = k;
            val = v;
            next = NULL;
            prev = NULL;

        }
    };

    Node *head;
    Node *tail;
    unordered_map<int, Node *>m;
    int k = 0;
    int c = 0;
    LRUCache(int capacity) {
        k = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node *nn = new Node(m[key]->key, m[key]->val);
            head->next->prev = nn;
            nn->next = head->next;
            head->next = nn;
            nn->prev = head;

            Node *p = m[key]->prev;
            Node *n = m[key]->next;

            p->next = n;
            n->prev = p;
            m[key] = nn;

            return nn->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node *nn = new Node(key, value);
        if(m.find(key) != m.end()){
            head->next->prev = nn;
            nn->next = head->next;
            head->next = nn;
            nn->prev = head;

            Node *p = m[key]->prev;
            Node *n = m[key]->next;

            p->next = n;
            n->prev = p;
            m[key] = nn;
        }
        else{
            if(c == k){
                m.erase(tail->prev->key);
                tail->prev = tail->prev->prev;
                tail->prev->next = tail;  
                c--;
            }
            head->next->prev = nn;
            nn->next = head->next;
            head->next = nn;
            nn->prev = head;
            m[key] = nn;
            c++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */