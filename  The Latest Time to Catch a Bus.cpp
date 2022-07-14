class Solution {
public:
    /*
    TC: O(NLog(N))  BECAUSE OF SORTING
    SC: O(1)
    
    1) THE INTUITION IS TO ASSIGN BUSES TO PASSENGERS (IN SORTED ORDER SINCE A PASSENGER WHO ARRIVES FIRST GETS ON THE EARLIEST BUS POSSIBLE FIRST) 
    
    2) TAKE TWO POINTERS I AND J USED FOR ITERATING THROUGH THE BUSES ARRAY AND PASSENGERS ARRAY RESPECTIVELY
    
    3) WHILE THE BUS IS UNDER CAPACITY KEEP ASSIGNING THE I'TH BUS TO A J'TH PASSENGER TILL THE DEPARTURE TIME OF THE I'TH BUS IS GREATER THAN OR EQUAL TO THE ARRIVAL TIME OF THE J'TH PASSENGER (buses[i]>= passengers[j] && count< capacity)
    
    4) KEEP TRACK OF THE DIFFERENCE BETWEEN CONSECUTIVE PASSENGERS TO KNOW POSSIBLE EMPTY SLOTS
    
    5) IF THERE IS NO MORE PASSENGER LEFT TO ASSIGN TO BUS, CHECK IF IT IS NOT AT FULL CAPACITY, AND IF WE DONT HAVE A PASSENGER ARRIVING AT THE SAME TIME AS THE DEPARTURE OF THE BUS, UPDATE THE ANSWER TO THAT
    
    6) WHILE FILLING ALL THE BUSES IF WE ASSIGNED ALL THE PASSENGERS AND STILL THERE ARE BUSES LEFT, THEN THE ANSWER WOULD BE THE DEPARTURE TIME OF THE LAST BUS
    
    */
    
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        
        int i=0; 
        int j=0; 
        int m=buses.size();
        int n= passengers.size();
        int ans= min(passengers[0]-1, buses[m-1]); 
        while(i<m && j<n){
            int count=0;
            while(j<n && buses[i]>=passengers[j] && count< capacity){
                if(j>0 && passengers[j]-passengers[j-1]>1) 
                    ans= passengers[j]-1;
                count++; 
                j++;
            }
            if(count < capacity){
                if(j>0 && passengers[j-1]!=buses[i])
                    ans=buses[i];
            }
            i++;
        }
        if(i!=m){
            ans= buses[m-1];
        }
        return ans; 
    }
};