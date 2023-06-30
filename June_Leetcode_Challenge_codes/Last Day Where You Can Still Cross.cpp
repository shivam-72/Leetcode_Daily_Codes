class Solution {
public:
vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    bool ispossible(int day,int n,int m,vector<vector<int>> &cells){
          queue<pair<int, int>> q;
         vector<vector<int>> cell(n, vector<int>(m, 0));
             for (int i = 0; i <day ; i++) {
            cell[cells[i][0]-1][cells[i][1]-1] = 1; 
        }
        for (int i = 0; i <m; i++) {
            if (cell[0][i] == 0) {
                q.push({0, i}); 
                cell[0][i] = 1; 
            }
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second; 
            for (auto x : dir) {
                int newi = i + x[0], newj = j + x[1]; 
                if (newi >= 0 && newj >= 0 && newi < n && newj < m && cell[newi][newj] == 0) {
                    cell[newi][newj] = 2; 
                    if (newi == n-1) {
                        return true; 
                    }
                    q.push({newi, newj}); 
                }
            }
        }
        return false; 
    }
    bool canreachlast(vector<vector<int>> &cells,int i,int j){
        int n=cells.size();
        int m=cells[0].size();
        if(i<0||j<0||i>=n||j>=m||cells[i][j]!=0)
        return false;
        if(i==n-1)
        return true;
        cells[i][j]=1;
        for(auto x:dir){
            int newi=i+x[0];
            int newj=j+x[1];
            if(canreachlast(cells,newi,newj))
            return true;
        }
        return false;

    }
    // bool ispossible(int day,int row,int col,vector<vector<int>>& cells){
    //     vector<vector<int>>newcell(row,vector<int>(col,0));
    //       for(int i=0;i<day;i++){
    //         newcell[cells[i][0]-1][cells[i][1]-1]=1;
    //       }
    //       for(int j=0;j<col;j++){
    //           if(canreachlast(newcell,0,j))
    //           return true;
    //       }
    //       return false;
    // }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low=1;
        int high=cells.size();
        int ans=-1;
        while(low<high){
            int mid=high-(high-low)/2;
            if(ispossible(mid,row,col,cells)){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
