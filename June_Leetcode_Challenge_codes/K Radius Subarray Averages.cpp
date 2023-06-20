class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<long long>psum(nums.size());
        int n=nums.size();
        int w=(2*k)+1;
        psum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
         psum[i]=psum[i-1]+nums[i];
        }
        vector<int>ans(nums.size());
        for(int i=0;i<n;i++){
          int c1=i-k;
          int c2=i+k;
          if(i-k>=0&&i+k<n){
              if(c1==0){
                  int sum=psum[i+k]/w;
                  ans[i]=sum;
              }
              else{
                int sum=(psum[i+k]-psum[i-k-1])/w;
                ans[i]=sum;
              }
          }
          else
          ans[i]=-1;
        }
        return ans;
    }
};
