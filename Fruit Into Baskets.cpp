class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int lastfruit = -1;
        int secondlastfruit=-1;
        int lastfruitcount=0;
        int count=0;
        int currmax=0;
        int maxi= 0;
        for(int fruit : tree){
            if(fruit == lastfruit || fruit == secondlastfruit){
                currmax +=1;
            }
            else{
                currmax = lastfruitcount +1;
            }

            if(fruit == lastfruit){
                lastfruitcount++;
            }
            else{
                lastfruitcount=1;
            }

            if(fruit != lastfruit){
                secondlastfruit=lastfruit;
                lastfruit = fruit;
            }
            maxi = max(currmax,maxi);

        }
        return maxi;
        
    }
};