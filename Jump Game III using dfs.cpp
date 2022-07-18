class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<bool>v(arr.size(),false);
        while(!q.empty()){
            int x= q.front();
            q.pop();
            v[x]=true;
            if(arr[x]==0)   
                return true;
            if( (x+arr[x]) < arr.size() && v[x+arr[x]]==false)
                q.push(x+arr[x]);
            if( (x-arr[x]) >= 0 && v[x-arr[x]]==false)
                q.push(x-arr[x]);

        }
        return false;
    }
};