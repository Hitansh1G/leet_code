class Solution {
public:
    vector<string> fullJustify(vector<string>& word, int maxWidth) {
        int i=0;
        vector<string>ans;
        int n = word.size();
        for(int i=0; i<n;)
        {
            queue<string>q;
            q.push(word[i]);
            int w=word[i].size();
            while(i<n-1 && w+1+word[i+1].size()<=maxWidth)
            {
                q.push(word[i+1]);
                w+=1+word[i+1].size();
                i++;
            }
            int sz = q.size();
            int exsp = maxWidth-w;
            if(i==n-1)
            {
                string temp = q.front();
                q.pop();
                while(!q.empty())
                {
                    temp+=' '+q.front();
                    q.pop();
                }
                
                while(exsp--)
                {
                    temp+=' ';
                }
                ans.push_back(temp);
            }
            else{
                int rem = sz-1;
                string temp = q.front();
                q.pop();
                // if(temp=="acknowledgment")
                //     cout<<q.size();
                if(q.size()==0)
                {
                    while(exsp--)
                    {
                        temp+=' ';
                    }
                }
                while(!q.empty())
                {
                    temp+=' ';
                    int sp = ceil(1.0*exsp/q.size());
                    cout<<exsp<<" "<<q.size()<<" "<<sp<<endl;
                    if(exsp>0 && exsp<q.size())
                        sp = 1;
                    // cout<<sp<<" ";
                    exsp-=sp;
                    while(sp--)
                    {
                        temp+=' ';
                    }
                    temp+=q.front();
                    q.pop();
                }
                cout<<"\nend\n";
                ans.push_back(temp);
            }
            i++;
 
        }
        return ans;
    }
};