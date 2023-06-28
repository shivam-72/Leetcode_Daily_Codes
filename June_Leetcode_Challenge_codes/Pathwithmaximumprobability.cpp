class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
       vector<vector<pair<int,double>>>adj(n);
       int i=0;
       for(auto x:edges){
           adj[x[0]].push_back({x[1],succProb[i]});
           adj[x[1]].push_back({x[0],succProb[i]});
           i++;
       }
       vector<double>prob(n,0.0);
       priority_queue<pair<double,int>>p;
       p.push({1.0,start});
       prob[start]=1.0;
       while(p.size()>0){
           pair<double,int>f=p.top();
           double pr=f.first;
           int edge=f.second;
           p.pop();
           for(auto x:adj[edge]){
               if(prob[x.first]<pr*x.second){
                 prob[x.first]=pr*x.second;
                  p.push({prob[x.first],x.first});
               }
           }
       }
       return prob[end];
    }
};
