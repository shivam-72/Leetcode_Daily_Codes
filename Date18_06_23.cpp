 class Solution {
public:
int mod=1e9+7;
int dp[1005][1005];
int solve(vector<vector<int>>&grid,int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    long long ans=1;
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    for(int k=0;k<4;k++){
        int nx=i+dir[k][0];
        int ny=j+dir[k][1];
        if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&grid[nx][ny]>grid[i][j]){
            ans=(ans+solve(grid,nx,ny))%mod;
        }
    }
    return dp[i][j]=ans%mod;
}
    int countPaths(vector<vector<int>>& grid) {
        long long ans=0;
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));
      for(int i=0;i<grid.size();i++){
          for(int j=0;j<n;j++){
             ans=(ans+solve(grid,i,j))%mod;
          }
      } 
      return ans%mod; 
    }
};