#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;


class NumMatrix {
private:
    int m;
    int n;
    vector<vector<int> > accums;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix.at(0).size();

        accums.resize(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            int accumRow = 0;
            for (int j = 0; j < n; j++)
            {
                int accumCol = 0;
                if (i - 1 >= 0) {
                    accumCol += accums.at(i-1).at(j);
                }
                
                accumRow += matrix.at(i).at(j);
                accums.at(i).at(j) = accumRow + accumCol;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        ans += accums.at(row2).at(col2);
        if (row1 > 0) {
            ans -= accums.at(row1-1).at(col2);
        }
        if (col1 > 0) {
            ans -= accums.at(row2).at(col1-1);
        }
        if (row1 > 0 && col1 > 0) {
            ans += accums.at(row1-1).at(col1-1);
        }
        return ans;
    }
};
