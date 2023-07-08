class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;k--;
   for (int i = 0; i < weights.size() - 1; i++) {
    pq1.push(weights[i] + weights[i + 1]);
    pq2.push(weights[i] + weights[i + 1]);
    if (pq1.size() > k ) {
        pq1.pop();
        pq2.pop();
    }
    }
   long long ans1 = 0, ans2 = 0;
   while (!pq1.empty()) {
    ans1 += pq1.top();
    ans2 += pq2.top();
    pq1.pop();
    pq2.pop();
   }
    return ans2 - ans1;
    }
};
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
         long long  l1 = 0,l2=0;
           k--;
        int n=weights.size();
         vector<long long >res1;
        
          for(int i = 0;i<n-1;i++){
              res1.push_back(weights[i]+weights[i+1]);
              }

        
         sort(res1.begin() , res1.end(),greater<long long>());
        
        int n1=res1.size();

            for( int i =0;i<k;i++) {
              l2+= res1[i];
               l1+=res1[n1-1-i];
            }
        
        return (l2 - l1);
    }
};
