typedef long long ll;
struct DSU{
 
	ll n;
	vector<ll> parent,size;
	DSU(ll sz){
 
		n= sz;
		parent.resize(n+1);
		size.resize(n+1);
 
	    for(ll i=1;i<=n;i++){
	    	parent[i]= i;
	    	size[i]  = 1;
	    }
	}
 
	ll find_parent(ll a){
 
		if(a==parent[a]) return a;
		return parent[a]=find_parent(parent[a]);
	}
 
	void merge(ll a,ll b){
 
		ll par_a= find_parent(a);
		ll par_b= find_parent(b);
 
		if(par_a==par_b) return;
        if(size[par_a]<size[par_b]) swap(par_a,par_b);
		size[par_a] += size[par_b];
		parent[par_b]= par_a;
		return;
	}
 
	void reset(ll n){
 
		n= n;
		parent.resize(n+1);
		size.resize(n+1);
 
	    for(ll i=1;i<=n;i++){
	    	parent[i]= i;
	    	size[i]  = 1;
	    }
	}
};
class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    int getMSTWt(int n, vector<vector<int>>& edges,int skip,int take=-1){
        DSU d(n);
        int minWt=0;
				if(take != -1) {
					d.merge(edges[take][0] , edges[take][1]); 
					minWt += edges[take][2]; 
        }
        for(int i=0;i<edges.size();i++){
            if(i==skip) continue;
						int par_a=d.find_parent(edges[i][0]);
            int par_b=d.find_parent(edges[i][1]);
            int wt=edges[i][2];
            if(par_a!=par_b){
							d.merge(edges[i][0],edges[i][1]);
							minWt+=wt;
            }
        }
				for(int i=0;i<n;i++){
					if(d.find_parent(i)!=d.find_parent(0)){
						return 1e9;
					}
				}
        return minWt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
				for(int i=0;i<edges.size();i++){
					edges[i].push_back(i);
				}
				sort(edges.begin(),edges.end(),comp);
        int mstWt=getMSTWt(n,edges,-1);
				vector<vector<int>>ans;
				vector<int>criticalEdges;
				vector<int>nonCriticalEdges;
				for(int i=0;i<edges.size();i++){
						if(getMSTWt(n,edges,i)>mstWt){
							criticalEdges.push_back(edges[i][3]);
						}
						else if(mstWt==getMSTWt(n,edges,-1,i)){
							nonCriticalEdges.push_back(edges[i][3]);
						}
				}
        return {criticalEdges,nonCriticalEdges}; 

    }
};