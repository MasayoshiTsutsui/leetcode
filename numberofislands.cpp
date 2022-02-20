#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    void checkNeighbor(vector<vector<char>>& grid, int x, int y) {
        int w = grid.at(0).size();
        int h = grid.size();

        if (x < 0 || x >= w || y < 0 || y >= h || grid.at(y).at(x) != '1') {
            return;
        }

        grid.at(y).at(x) = '2';
        checkNeighbor(grid, x-1, y);
        checkNeighbor(grid, x+1, y);
        checkNeighbor(grid, x, y-1);
        checkNeighbor(grid, x, y+1);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid.at(0).size(); x++)
            {
                if (grid.at(y).at(x) == '1') {
                    checkNeighbor(grid, x, y);
                    ans++;
                }
            }
        }
        return ans;
    }
};