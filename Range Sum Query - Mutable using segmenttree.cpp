class NumArray {
    int n;
    vector<int> segTree;
    
    void buildTree(vector<int> &arr,int l,int r,int ind){
        if(l==r){
            segTree[ind] = arr[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildTree(arr,l,mid,2*ind+1);
        buildTree(arr,mid+1,r,2*ind+2);
        segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
    }
    
    void update(int l,int r,int ind,int &i,int &x){
        if(l==r){
            segTree[ind] = x;
            return;
        }
        int mid = l + (r-l)/2;
        if(i<=mid){
            update(l,mid,2*ind+1,i,x);
        }
        else{
           update(mid+1,r,2*ind+2,i,x); 
        }
        segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
    }
    int query(int l,int r,int ind,int &s,int &e){
        if(l>=s && r<=e) return segTree[ind];
        if(l>e || r<s) return 0;
        int mid = l + (r-l)/2;
        return query(l,mid,2*ind+1,s,e) + query(mid+1,r,2*ind+2,s,e);
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree = vector<int>(4*n);
        buildTree(nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        update(0,n-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,n-1,0,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */