class LRUCache {
public:

    class Node {
    public:
        int value;
        int key;
        Node* next = nullptr;
        Node* prev = nullptr;   

        Node(int k, int v) {
            this->value = v;
            this->key = k;
        } 

        Node() = default;
    };

    int capacity;
    unordered_map<int, Node*> mapp;
    Node* mostRecent = nullptr;
    Node* leastRecent = nullptr;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mapp.contains(key)) {
            int value = mapp.find(key)->second->value;
            refresh(key, value);
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mapp.contains(key)) {
            // move around
            refresh(key, value);

        } else {
            if (mapp.size() == capacity && leastRecent != nullptr) {
                // remove least recent
                Node* nexttLeast = leastRecent->prev;
                if (nexttLeast != nullptr) {
                    nexttLeast->next = nullptr;
                }
                
                leastRecent->prev = nullptr;
                mapp.erase(leastRecent->key);
                leastRecent = nexttLeast;
            }

            Node* newNode = new Node(key,value);
            mapp[key] = newNode;

            if (mostRecent == nullptr) { 
                mostRecent = newNode;
                leastRecent = newNode;
            } else {
                
                mostRecent->prev = newNode;
                newNode->next = mostRecent;
                mostRecent = newNode;
            }

            
        }
    }

    void refresh(int key, int value) {
        Node* nodePtr = mapp.find(key)->second;
        nodePtr->value = value;

        if (mostRecent == nodePtr) return;

        Node* prev = nodePtr->prev;
        Node* next = nodePtr->next;

        if (prev != nullptr) {
            prev->next = next;
        }

        if (next != nullptr) {
            next->prev = prev;
        }

        if (mostRecent != nullptr) {
            mostRecent->prev = nodePtr;
        }
        
        nodePtr->next = mostRecent;
        mostRecent = nodePtr;
        nodePtr->prev = nullptr;

        if (leastRecent == nodePtr) {
            leastRecent = prev;
        }
    }


};
