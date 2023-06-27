typedef  pair<int,pair<int,int>> t;
//nums1.size()*nums2.size()logn(nums1.size()*nums2.size());
//nums1*size()+logn*k
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<t,vector<t>,greater<t>>pq;
        for(int i=0;i<nums1.size();i++){
          pq.push({nums1[i]+nums2[0],{i,0}});
        }
        vector<vector<int>>ans;
         while(k--&&pq.size()>0){
           pair<int,pair<int,int>> top= pq.top();
           int sum=top.first;
           int i=top.second.first;
           int j=top.second.second;
           ans.push_back({nums1[i],nums2[j]});
           pq.pop();
           if(j+1<nums2.size()){
               pq.push({nums1[i]+nums2[j+1],{i,j+1}});
           }
         }
        return ans;
    }
};
