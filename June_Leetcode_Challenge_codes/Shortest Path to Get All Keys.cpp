class Solution {
public:
   int dfs(vector<string>& grid,int starti,int startj,int n,int m,int keys){
       queue<pair<int,pair<int,int>>>q;
       vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
       bool vis[n][m][64];
       memset(vis,0,sizeof(vis));
       q.push({0,{starti,startj}});
       vis[starti][startj][0]=true;
       int ans=0;
       while(q.size()>0){
           int size=q.size();
           while(size--){
              pair<int,pair<int,int>>top=q.front();
               int keysinbit=top.first;
               int a=top.second.first;
               int b=top.second.second;
               q.pop();
               if(keysinbit==((1<<keys)-1))
               return ans;
               for(int i=0;i<dir.size();i++){
                 int newi=a+dir[i][0];
                 int newj=b+dir[i][1];
                 int newkeysinbit=keysinbit;
                 if(newi>=0&&newj>=0&&newi<n&&newj<m&&grid[newi][newj]!='#'&&vis[newi][newj][newkeysinbit]==false){
                     if(grid[newi][newj]>='a'&&grid[newi][newj]<='f'){
                         newkeysinbit=keysinbit|(1<<(grid[newi][newj]-'a'));
                     }
                     else if(grid[newi][newj]>='A'&&grid[newi][newj]<='F'){
                       if(  (keysinbit & (1<<(grid[newi][newj]-'A')))==0)
                       continue;
                     }
                     vis[newi][newj][newkeysinbit]=true;
                     q.push({newkeysinbit,{newi,newj}});
                 }
               }
           }
           ans++;
       }
       return -1;

   }
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int starti=-1,startj=-1;
        int keycount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    starti=i;
                    startj=j;
                }
                else if(grid[i][j]>='a'&&grid[i][j]<='f'){
                   keycount++;
                }
            }
        }
        return dfs(grid,starti,startj,n,m,keycount);
    }
};
