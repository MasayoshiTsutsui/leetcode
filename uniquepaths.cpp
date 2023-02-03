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
    int uniquePaths(int m, int n) {
        vector<vector<int> > pathsFromO(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            pathsFromO.at(0).at(i) = 1;
        }
        for (int i = 0; i < m; i++)
        {
            pathsFromO.at(i).at(0) = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                pathsFromO.at(i).at(j) = pathsFromO.at(i-1).at(j) + pathsFromO.at(i).at(j-1);
            }
        }
        return pathsFromO.at(m-1).at(n-1);
    }
};