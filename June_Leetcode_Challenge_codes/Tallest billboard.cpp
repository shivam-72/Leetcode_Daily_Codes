class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int diff,vector<int>&rods){
    if(i==rods.size()){
        if(diff==0)
        return 0;
        return -1e9;
    }
    if(dp[i][diff+5000]!=-1)
    return dp[i][diff+5000];
    int ltake=rods[i]+solve(i+1,diff+rods[i],rods);
    int rtake=solve(i+1,diff-rods[i],rods);
    int ntake=solve(i+1,diff,rods);
    return dp[i][diff+5000]=max(max(ltake,rtake),ntake);
}
    int tallestBillboard(vector<int>& rods) {
       dp=vector<vector<int>>(21,vector<int>(10000,-1));
       return solve(0,0,rods); 
    }
};
