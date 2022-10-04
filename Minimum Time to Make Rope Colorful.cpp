class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length(),timeMin=0;
        for(int i=0;i<n;i++){
            int currMin=neededTime[i],currTime=0,j=i+1;
            while(j<n && colors[j]==colors[i]){
                if(neededTime[j]>currMin){     
                    currTime+=currMin;
                    currMin=neededTime[j];
                }
                else{
                    currTime+=neededTime[j];
                }
                j++;
            }
            i=j-1;
            timeMin+=currTime;
        }
        return timeMin;
    }
};