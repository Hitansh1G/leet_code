class Solution {
    vector<vector<int> >graph;
    vector<int> visited;
public:
    bool dfs(int u){
        for(int v: graph[u]){
            if(visited[v]==-1){
                visited[v]=1-visited[u];
                if(dfs(v)==false)
                    return false;
            }
            else if(visited[v]==visited[u]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph=vector<vector<int> >(n+1);
        visited=vector<int> (n+1,-1);
        for(int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i=1;i<=n;i++){
            if(visited[i]==-1){
                visited[i]=0;
                if(dfs(i)==false)
                    return false;
            }
        }
        return true;
    }
};