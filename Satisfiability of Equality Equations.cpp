class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, vector<char>> incident;
        for(string equation : equations){
            bool equal = equation[1]=='=' ? true : false;
            if(equation[0]==equation[3] && !equal) return false;            
            if(equal){
                if(equation[0]==equation[3]) continue;
                incident[equation[0]].push_back(equation[3]);
                incident[equation[3]].push_back(equation[0]);
            }
        }
        
        for(string equation : equations){
            bool equal = equation[1]=='=' ? true : false;
            if(!equal){
                bool res = BFS(incident, equation[3], equation[0]);
                if(res==true) return false;
            }
        }
        return true;
    }
    
    bool BFS(unordered_map<char, vector<char>>& incident, char start, char value){
        queue<char> q;
        q.push(start);
        unordered_map<char, bool> visited;
        while(q.size()){
            char current = q.front();
            q.pop();
            if(!visited[current]){
                visited[current] = true;
                if(current==value) return true;
                for(char x: incident[current]) q.push(x);
            }
        }
        return false;
    }
    
};