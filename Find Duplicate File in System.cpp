class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
      unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        
        for(int i=0;i<paths.size();i++)
        {
            stringstream ss(paths[i]);
            string root_dir;
            string s;
            getline(ss,root_dir,' ');
            while(getline(ss,s,' ')){
                string fileName = root_dir+'/'+s.substr(0,s.find('('));
                string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                mp[fileContent].push_back(fileName);
            }
            
        }
        
        
        for (auto file : mp) {
            if (file.second.size() > 1)
                ans.push_back(file.second);
        }

    return ans;
        
    }
};