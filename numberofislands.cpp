#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
private:
    void bfs(vector<vector<char> >& grid, int m, int n, int i, int j) {
        queue<pair<int, int>> que;
        que.push(pair<int,int>{i, j});
        
        while(!que.empty()) {
            pair<int, int> indices = que.front();
            int i_ = indices.first;
            int j_ = indices.second;
            que.pop();
            if (i_ < 0 || j_ < 0 || i_ >= m || j_ >= n) {
                continue;
            }
            if (grid.at(i_).at(j_) == '1') {
                grid.at(i_).at(j_) = '2';
                que.push(pair<int,int>{i_+1, j_});
                que.push(pair<int,int>{i_, j_+1});
                que.push(pair<int,int>{i_, j_-1});
                que.push(pair<int,int>{i_-1, j_});
            }
        }
    }
public:
    int numIslands(vector<vector<char> >& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid.at(0).size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char c = grid.at(i).at(j);
                if (c == '1') {
                    bfs(grid, m, n, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};