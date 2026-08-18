class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows=grid.size(), cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> directions = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto& dir:directions){
                int nr = front.first + dir[0];
                int nc = front.second + dir[1];

                if(nr < 0 || nr >= rows ||
                   nc < 0 || nc >= cols){
                    continue;
                }

                if(grid[nr][nc]==-1 || grid[nr][nc]!=INT_MAX) continue;

                grid[nr][nc]=1+grid[front.first][front.second];
                q.push({nr,nc});
            }
        }
    }
};
