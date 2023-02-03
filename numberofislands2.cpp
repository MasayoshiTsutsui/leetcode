#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<char>> grid;
public:
    void dfs(vector<vector<char>>& grid, int32_t y, int32_t x) {
        if (grid.at(y).at(x) == '0' || grid.at(y).at(x) == '2')
        {
            return;
        }
        grid.at(y).at(x) = '2';
        if (y + 1 < this->m)
        {
            this->dfs(grid, y + 1, x);
        }
        if (x + 1 < this->n)
        {
            this->dfs(grid, y, x + 1);
        }
        if (y - 1 >= 0)
        {
            this->dfs(grid, y - 1, x);
        }
        if (x - 1 >= 0)
        {
            this->dfs(grid, y, x - 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        this->m = grid.size();
        this->n = grid.at(0).size();
        int ans = 0;
        for (size_t i = 0; i < this->m; i++)
        {
            for (size_t j = 0; j < this->n; j++)
            {
                if (grid.at(i).at(j) == '1')
                {
                    this->dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};