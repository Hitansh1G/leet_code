class Solution {
public:
    bool isValid(vector<vector<int>> &adjMat, int src, int dest, vector<bool> &visited){
        if(src == dest){
            return true;
        }
        visited[src] = true;
        for(auto &neighbor : adjMat[src]){
            if(!visited[neighbor]){
                if(isValid(adjMat, neighbor, dest, visited)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjMat(n);
        
        for(auto &edge : edges){
            adjMat[edge[0]].push_back(edge[1]);
            adjMat[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return isValid(adjMat, source, destination, visited);
    }
};