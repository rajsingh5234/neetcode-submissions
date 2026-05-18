
class Node{
    public:
    int val;
    Node* next;

    Node(int d){
        val = d;
        this->next = NULL;
    }
};

class MyCircularQueue {
public:

    Node* head;
    Node* tail;
    int size;

    MyCircularQueue(int k) {
        size = k;
        head = NULL;
        tail = NULL;
    }
    
    bool enQueue(int value) {
        if(isFull()) return 0;
        if(!head){
            head = new Node(value);
            tail = head;
        }
        else{
            tail->next = new Node(value);
            tail = tail->next;
        }
        size--;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty()) return 0;

        Node* temp = head->next;
        delete head;
        head = temp;

        if(!head){
            head = NULL;
            tail = NULL;
        }

        size++;
        return 1;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return tail->val; 
    }
    
    bool isEmpty() {
        return !head;
    }
    
    bool isFull() {
        return size == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */