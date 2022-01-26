#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector <string> ans;

void compare(vector<pair<string,pair<int,int> > >pairs){
    for(int i=0 ; i<pairs.size() ; i++){
        if(pairs[i].second.first>pairs[i].second.second){
            ans.push_back(pairs[i].first);
        }
        else{
            continue;
        }
    }
}
int main(){
    int n;
    string str;
    vector<pair<string,pair<int,int> > >pairs;
    vector <string> likedIngredients;
    vector <string> dislikedIngredients;
    pair<string,pair<int,int> >pin,pout;
    int count=0;
    int noOfLikes, noOfDislikes;
    
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> noOfLikes;
        for(int j=0 ; j<noOfLikes ; j++){
            cin >> str;
            likedIngredients.push_back(str);
        }
        cin >> noOfDislikes;
        for(int j=0 ; j<noOfDislikes ; j++){
            cin >> str;
            dislikedIngredients.push_back(str);
        }
    }

    // pairs[0].first = likedIngredients[0];
    // pairs[0].second.first = 1;
    // pairs[0].second.second=0;

    pout.first=likedIngredients[0];
    pout.second.first=1;
    pout.second.second=0;
    pairs.push_back(pout);
 
    // for(int i=0 ; i<pairs.size() ; i++){
    //     cout<<pairs[i].first<<" ";
    //     cout<<pairs[i].second.first<<" ";
    //     cout<<pairs[i].second.second<<" ";
    // }
    

    for(int i=1 ; i<likedIngredients.size() ; i++){      
        int flag = 0;
        for(int j=0 ; j<pairs.size() ; j++){
            if(likedIngredients[i] ==pairs[j].first){
                pairs[j].second.first++;
                flag =1;
            }
            // cout<<"*"<<endl;
        }
        if(flag==0){
            pout.first=likedIngredients[i];
            pout.second.first=1;
            pout.second.second=0;
            pairs.push_back(pout);
        }
        // cout<<"+"<<endl;
    }
    for(int i=0;i<dislikedIngredients.size();i++){
        string str=dislikedIngredients[i];
        for(int j=0 ; j<pairs.size() ; j++){
            if(str==pairs[j].first){
                pairs[j].second.second++;
            }
            else{
                continue;
            }
        }
    }
    
    // for(int i=0 ; i<pairs.size() ; i++){
    //     cout<<pairs[i].first<<" ";
    //     cout<<pairs[i].second.first<<" ";
    //     cout<<pairs[i].second.second<<" ";
    // }
    compare(pairs);
    cout<<ans.size()<<" ";
    for(int i=0 ; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
