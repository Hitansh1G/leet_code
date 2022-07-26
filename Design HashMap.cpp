class mapNode{
    public:
    int key; int value;
    mapNode* next;
    mapNode(int key, int val){
        this->key= key;
        this->value= val;
        next=NULL;
    }
};
class MyHashMap {
public:
    mapNode** bucket;
    int capacity;
    int size;
    
    MyHashMap() {
        bucket= new mapNode*[5];
        capacity=5; size=0;
        for(int i=0; i<capacity; i++){
            bucket[i]=NULL;
        }
    }
    
    int hashing(int key){
        int num=1;
        int hash=0;
        while(key){
            hash= ((hash)%capacity + ((key%10)*num)%capacity)%capacity;
            key/=10; num=(((num)%capacity)*37)%capacity;
        }
        return hash%capacity;
    }
    
    void rehash(){
        mapNode** temp=bucket;
        bucket= new mapNode*[2*capacity];
        for(int i=0; i<2*capacity; i++){
            bucket[i]=NULL;
        }
        int oldCapacity=capacity;  capacity*=2;
        size=0;
        for(int i=0; i<oldCapacity; i++){
            mapNode* node= temp[i];
            while(node!=NULL){
                int key=(*node).key; int value=(*node).value;
                put(key,value);
                node=(*node).next;
            }
        }
        return;
    }
    
    void put(int key, int value) {
        
        if(double(size)/capacity>0.7){
            rehash();
        }
        
        int hash= hashing(key);
        mapNode* temp= bucket[hash];
        while(temp!=NULL){
            if((*temp).key==key){
                (*temp).value=value;
                return;
            }
            temp=(*temp).next;
        }
        // Key was not existed before
        mapNode* newNode= new mapNode(key, value);
        temp=bucket[hash]; (*newNode).next=temp;
        bucket[hash]=newNode;
        size++;
    }
    
    int get(int key) {
        int hash= hashing(key);
        mapNode* temp= bucket[hash];
        while(temp!=NULL){
            if((*temp).key==key){
                return (*temp).value;
            }
            temp=(*temp).next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash= hashing(key);
        mapNode* temp= bucket[hash];
        
        mapNode* prev=NULL;
        while(temp!=NULL){
            if((*temp).key==key){
                if(prev==NULL){ // we need to delete the first node itself
                    mapNode* t=temp;
                    bucket[hash]=(*temp).next;
                    (*t).next=NULL; delete(t);
                }
                else{
                    (*prev).next=(*temp).next;
                    (*temp).next=NULL; delete(temp);
                }
                size--;
                return;
            }
            prev=temp;
            temp=(*temp).next;
        }
        return;
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */