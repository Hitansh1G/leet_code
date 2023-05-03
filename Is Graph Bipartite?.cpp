class Solution {
public:
    bool isBip(int node, int par, vector<int>& color, vector<int> adj[]){
        color[node] = 1;
        queue<int> bfs;
        bfs.push(node);
        
        while(!bfs.empty()){
            int src = bfs.front();
            bfs.pop();
            
            for(auto child: adj[src]){
                if(color[child] == -1){
                    color[child] = 1 - color[src];
                    bfs.push(child);
                }
                else if(color[child] == color[src]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++){
            for(auto j: graph[i]){
                adj[i].push_back(j);
            }
        }
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++){
            if(color[i] == -1)
                if(!isBip(i, -1, color, adj)) return false;
        }
        return true;
    }
};