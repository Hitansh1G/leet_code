class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;

        vector<bool>visited(n,false);

        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, visited , i);
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>&graph , vector<bool>&visited , int j){
        visited[j]=true;
        for(int i=0 ; i<graph.size() ; i++){
            if(graph[j][i]==1 && !visited[i]){
                dfs(graph,visited ,i);
            }
        }
    }

};