class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude=0;
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            altitude=max(altitude,sum);
        }
        return altitude;
    }
};
