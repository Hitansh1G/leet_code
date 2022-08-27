class Solution {
public:
    int parent[60],rank[60] = {0};
    int find(int x){
        if(x==parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int &x,int &y){
        int a = find(x);
        int b = find(y);
        if(a!=b){
            if(rank[a]<rank[b]){
                parent[a] = b;
            }
            else if(rank[a]>rank[b]){
                parent[b] = a;
            }
            else{
                parent[b] = a;
                rank[a]++;
            }
        }
    }
    int minSwapsCouples(vector<int>& row) {
        for(int i = 0;i<row.size();i++)
            parent[i] = i;
        for(int i = 0;i<row.size();i+=2)
            Union(row[i],row[i+1]);
        // for(int i = 0;i<row.size();i++)
        //     cout<<parent[i]<<" "; 
        int ans = 0;
        for(int i = 0;i<row.size();i+=2){
            if(parent[i+1]!=parent[i]){
                for(int j = i+2;j<row.size();j++){
                    if(parent[j]==parent[i]){
                        swap(parent[j],parent[i+1]);
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
        
    }
};