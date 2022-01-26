#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int main(){
    Fast
    long int n;
    string str;
    set<string>s;


    // vector <string> likedIngredients;
    vector <string> dislikedIngredients;
    vector <string> ans;

    int noOfLikes, noOfDislikes;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> noOfLikes;
        for(int j=0 ; j<noOfLikes ; j++){
            cin >> str;
            // likedIngredients.push_back(str);
            
            ans.push_back(str);
        }
        cin >> noOfDislikes;
        for(int j=0 ; j<noOfDislikes ; j++){
            cin >> str;
            dislikedIngredients.push_back(str);
        }
    }
    for(int i=0 ; i<dislikedIngredients.size() ; i++){
        for(int j=0 ; j<ans.size() ; j++){
            if(dislikedIngredients[i]==ans[j]){
                ans.erase(ans.begin()+j);
            }
        }
    }
                // for(int i=0;i<ans.size();i++){
                //     cout<<ans[i]<<" ";
                // }
    for(int i=0;i<ans.size();i++){
        s.insert(ans[i]);
    }
    cout<<s.size()<<" ";
    for(auto it=s.begin() ; it!=s.end() ; it++){
        cout<<*it<<" ";
    }
    
    // for(auto it:s)
    // {
    //     cout<<it<<" ";
    // }
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    return 0;
}