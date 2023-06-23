class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
       vector<unordered_map<int,int>>dp(n);
       int mx=0;
       for(int i=0;i<n;i++){
         for(int j=0;j<i;j++){
             int d=nums[j]-nums[i];
             if(dp[j].find(d)==dp[j].end()){
                 dp[i][d]=2;
             }
             else{
                dp[i][d]=dp[j][d]+1; 
             }
             mx=max(mx,dp[i][d]);
         }  
       }
       return mx;
    }
};
