class Solution {
public:

    void dfs(vector<vector<int>>& points, int u, int n, vector<bool>& vis){
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && (points[u][0] == points[v][0] || points[u][1] == points[v][1])){
                dfs(points, v, n, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                dfs(points, i, n, vis);
                count++;
            }
        }
        return n - count;
    }
};