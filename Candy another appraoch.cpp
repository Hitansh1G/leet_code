class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
            
        if(n==1){
            return n;
        }
        vector<int> a;
        for(int i = 0;i<n;i++){
            
            if(i==0 && i!=n-1){
                if(ratings[i]<=ratings[i+1]){
                    a.push_back(i);
                }
            }else if(i==n-1 && i!=0){
                
                if(ratings[i]<=ratings[i-1]){
                    a.push_back(i);
                }
            
            }else if(i>0 && i<n-1){
                
                if(ratings[i]<=ratings[i-1] && ratings[i]<=ratings[i+1]){
                    a.push_back(i);
                }   
            }   
        }
        int ans[n];
        for(int i =0;i<n;i++){
            ans[i] = -1;
        }
        
        for(auto x: a){
            int p1 = x;
            int p2 = x;
            int add=2;
            
            ans[x]=1;
            
            while(p1<n-1 && ratings[p1]<ratings[p1+1]){
                p1++;
                
                ans[p1] = max(ans[p1],add);
                add++;
            }
            
            add= 2;
            
            while(p2>0 && ratings[p2]<ratings[p2-1]){
                p2--;
                ans[p2] = max(ans[p2],add);
                add++;
            }
        }
        
        int ans1 =0;
        
        for(auto x : ans){
            ans1+=x;
        }
        return ans1;
    }
};