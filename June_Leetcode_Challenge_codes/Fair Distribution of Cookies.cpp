class Solution {
public:
    int mn=INT_MAX;
    void solve(int i,int k,vector<int>&cookies,vector<int>&dis){
        
        if(i==cookies.size()){
            int ans=INT_MIN;
            for(auto x:dis){
                ans=max(ans,x);
            }
            mn=min(ans,mn);
            return;
        }
        
       
        for(int j=0;j<k;j++){
            
            dis[j]+=cookies[i];
           solve(i+1,k,cookies,dis);
            dis[j]-=cookies[i];
        }
    }
	
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>dis(k);
         solve(0,k,cookies,dis);
        return mn;
    }
};
