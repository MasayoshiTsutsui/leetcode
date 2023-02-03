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
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.at(0).size();
        vector<vector<int> > ans(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int liveNeighbs = 0;
                if (i - 1 >= 0 && board.at(i-1).at(j) == 1) {
                    liveNeighbs++;
                }
                if (j - 1 >= 0 && board.at(i).at(j-1) == 1) {
                    liveNeighbs++;
                }
                if (i + 1 < m && board.at(i+1).at(j) == 1) {
                    liveNeighbs++;
                }
                if (j + 1 < n && board.at(i).at(j+1) == 1) {
                    liveNeighbs++;
                }
                if (i - 1 >= 0 && j - 1 >= 0 && board.at(i-1).at(j-1) == 1) {
                    liveNeighbs++;
                }
                if (i + 1 < m && j - 1 >= 0 && board.at(i+1).at(j-1) == 1) {
                    liveNeighbs++;
                }
                if (i - 1 >= 0 && j + 1 < n && board.at(i-1).at(j+1) == 1) {
                    liveNeighbs++;
                }
                if (i + 1 < m && j + 1 < n && board.at(i+1).at(j+1) == 1) {
                    liveNeighbs++;
                }
                if (board.at(i).at(j) == 1) {
                    if (liveNeighbs < 2) {
                        ans.at(i).at(j) = 0;
                    }
                    else if (liveNeighbs <= 3) {
                        ans.at(i).at(j) = 1;
                    }
                    else {
                        ans.at(i).at(j) = 0;
                    }
                }
                else {
                    if (liveNeighbs == 3) {
                        ans.at(i).at(j) = 1;
                    }
                    else {
                        ans.at(i).at(j) = 0;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board.at(i).at(j) = ans.at(i).at(j);
            }
        }
    }
};