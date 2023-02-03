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
    void checkNeighbor(vector<vector<int>>& grid, int x, int y, int* area) {
        int h = grid.size();
        int w = grid.at(0).size();

        if (x < 0 || x >= w || y < 0 || y >= h || grid.at(y).at(x) != 1) {
            return;
        }

        grid.at(y).at(x) = 2;
        *area += 1;
        checkNeighbor(grid, x-1, y, area);
        checkNeighbor(grid, x+1, y, area);
        checkNeighbor(grid, x, y-1, area);
        checkNeighbor(grid, x, y+1, area);
        return;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid.at(0).size(); x++)
            {
                if (grid.at(y).at(x) == 1)
                {
                    int areasize = 0;
                    checkNeighbor(grid, x, y, &areasize);
                    ans = max(ans, areasize);
                }
                
            }
        }
        return ans;
    }
};