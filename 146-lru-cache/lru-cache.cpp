class LRUCache {
    public:
    class Node{
        public : 
        
        int key ;
        int val ;
        
        // Double Linked List .
        Node * next ;
        Node * prev ;

        Node (int key_ , int val_){
            key = key_ ;
            val = val_ ; 
        } 
    } ;

    Node * head = new Node (-1 , -1 ) ;
    Node * tail = new Node (-1 , -1 ) ;
    int cap  ;

    unordered_map<int , Node*> m ;

    LRUCache(int capacity) {
        cap = capacity ;
        head ->next = tail ;
        tail->prev = head ;
    }

    void addnode (Node * newnode ){
        
        Node * temp = head ->next ;
        head->next = newnode ;
        newnode->prev = head ;
        newnode->next = temp ;
        temp->prev = newnode ;
    }
    void deletenode (Node * deletenode ){

        Node * prevtonode = deletenode->prev ;
        Node * nexttonode = deletenode -> next ;
        prevtonode ->next = nexttonode ;
        nexttonode ->prev = prevtonode ;
    }
    int get(int key) {
        if (m.find(key) != m.end()){
            Node * node1 = m[key] ;
            m.erase (key) ;
            int keyval = node1->val ;
            deletenode(node1) ;
            addnode(node1) ;
            m[key] = head ->next ;
            return keyval ;
        }
        return -1 ;
    }
    void put(int key, int value) {
        if (m.find(key) != m.end()){
            Node * existingnode = m[key] ;
            m.erase (key) ;
            deletenode(existingnode) ;
        }

        if (m.size() == cap) {
            m.erase (tail->prev->key) ;
            deletenode(tail->prev) ;
        }
        addnode(new Node(key , value)) ;
        m[key] = head ->next ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */