class MyCircularDeque {
public:
     int *arr;
     int cap,front,size;
    MyCircularDeque(int k) {
        arr=new int[k];
        cap=k;
        front=size=0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front=(front-1+cap)%cap;
        arr[front]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
       int rear=(front+size)%cap;
        arr[rear]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front=(front+1)%cap;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        size--;
        return true;
    }
    
    int getFront() {
        return isEmpty()?-1:arr[front];
    }
    
    int getRear() {
        return isEmpty()?-1:arr[(front+size-1)%cap];
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size==cap);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */