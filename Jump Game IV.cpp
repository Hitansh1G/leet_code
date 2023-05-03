class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        unordered_map<int,vector<int>>m;
        int n=arr.size();
        for(auto i=0; i<n; i++){
            m[arr[i]].push_back(i);
        }
        
        vector<int>visited(n,0);
        int steps=0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int q_size = q.size();
            while( q_size-- ){
                int index= q.front();
                q.pop();
                if(index==n-1) return steps;
                
                m[arr[index]].push_back( index-1 );
                m[arr[index]].push_back( index+1 );
                for( auto &i: m[arr[index]]){
                    if(i>=0 && i<n && !visited[i]){
                        visited[i]=1;
                        q.push(i);
                    }
                }
                m[arr[index]].clear();
            }
            steps++;
        }
        return 0;
    }
};