class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int bigi = -1, smalli = INT_MAX, bigj = -1, smallj = INT_MAX;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    bigi = max(bigi, i);
                    smalli = min(smalli, i);
                    bigj = max(bigj, j);
                    smallj = min(smallj, j);
                }
            }
        }

        return (bigi - smalli + 1) * (bigj - smallj + 1);

    }
};