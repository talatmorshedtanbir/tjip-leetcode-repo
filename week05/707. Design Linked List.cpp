// https://leetcode.com/problems/design-linked-list/
// Time Complexity: O(N)
// Space Complexity; O(N)

class Node {
    public:
     int val;
     Node* next;

     Node(int val) {
         this->val = val;
         next = NULL;
     }
};

class MyLinkedList {
public:
    int size = 0;
    Node* head = new Node(0);
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(index >= size)
            return -1;

        Node* temp = head->next;
        for(int i=0; i<index; ++i) {
            temp = temp->next;
        }

        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next->next;
        head->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = head;

        while(temp->next) {
            temp = temp->next;
        }

        temp->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)
            return;

        Node* temp = head;
        for(int i=0; i<index; ++i) {
            temp = temp->next;
        }

        Node* nextNode = temp->next;
        temp->next = new Node(val);
        temp->next->next = nextNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size)
            return;

        Node* temp = head;
        for(int i=0; i<index; ++i) {
            temp = temp->next;
        }

        Node* nextNode = temp->next;
        temp->next = nextNode->next;
        nextNode->next = NULL;
        size--;
        delete nextNode;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */