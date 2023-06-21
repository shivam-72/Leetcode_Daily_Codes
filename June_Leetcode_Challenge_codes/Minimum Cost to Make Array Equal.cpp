class Solution {
public:
   long long solve(vector<int>& nums,vector<int>& cost,int c){
     long long costt=0;
     for(int i=0;i<nums.size();i++){
         costt=costt+(1L)*abs(c-nums[i])*cost[i];
     }
     return costt;
   } 
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        long long ans=0;
        while(l<r){
            int mid=l+(r-l)/2;
            long long c1=solve(nums,cost,mid);
            long long c2=solve(nums,cost,mid+1);
            if(c1>c2){
                l=mid+1;
                ans=c2;
            }
            else{
                ans=c1;
                r=mid;
            }
        }
        return ans;
    }
};
