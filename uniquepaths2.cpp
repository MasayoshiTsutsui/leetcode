#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        vector<vector<int> > pathsFromO(m, vector<int> (n, 0));

        bool blockflag = false;

        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid.at(0).at(i) != 1 && !blockflag)
            {
                pathsFromO.at(0).at(i) = 1;
            }
            else
            {
                pathsFromO.at(0).at(i) = 0;
                blockflag = true;
            }
        }
        blockflag = false;
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid.at(i).at(0) != 1 && !blockflag)
            {
                pathsFromO.at(i).at(0) = 1;
            }
            else
            {
                pathsFromO.at(i).at(0) = 0;
                blockflag = true;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid.at(i).at(j) != 1)
                {
                    pathsFromO.at(i).at(j) = pathsFromO.at(i-1).at(j) + pathsFromO.at(i).at(j-1);
                }
            }
        }

        return pathsFromO.at(m-1).at(n-1);
    }
};