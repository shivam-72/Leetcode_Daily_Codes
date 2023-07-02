class Solution {
public:
    int mxreq=0;
    void subset(vector < vector < int > > & req , vector < int > & comb , int ind , int reqd ){ 
    
        if(ind >= req.size()){ 
           
            for(auto x : comb){ 
              if( x != 0) return;  
            }
            mxreq = max(mxreq , reqd); 
            return; 
        }
        
        
        subset(req , comb , ind+1 , reqd ); 
        
        comb[req[ind][0]]--; 
        comb[req[ind][1]]++; 

        
      subset(req , comb , ind+1 , reqd+1 );  
        
         comb[req[ind][0]]++; 
         comb[req[ind][1]]--;   
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
      
        vector < int > comb(n , 0);  
        subset(requests , comb , 0 , 0 ); 
        return mxreq; 
    }
};
