class Solution {
public:
    long long totalCost(vector<int>& a, int k, int x) {
        unsigned long long int i,j,c=0,s=0;
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        
        for(i=0 ; i<x ; i++)  
        pq1.push(a[i]);

        if(2*x<=a.size()){    
        for(i=a.size()-1 ; i>=a.size()-x ; i--)
        pq2.push(a[i]);
        j=i;
        i=x;      

        } else{        
            for(; i<a.size() ; i++){
                pq2.push(a[i]);
            }
            i=2;  
            j=1;
        }

        while(k--){
            int m1=pq1.size()!=0 ? pq1.top():INT_MAX;
            int m2=pq2.size()!=0 ? pq2.top():INT_MAX;
            
            if(m1<=m2){
                c+=m1;
                pq1.pop();
                if(i<=j)
                pq1.push(a[i++]);
            } else{
                c+=m2;
                pq2.pop();
                if(i<=j)
                pq2.push(a[j--]);
            }
          
        }
        return c;

        

    }
};