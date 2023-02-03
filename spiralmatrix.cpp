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
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        int w = matrix.at(0).size();
        int h = matrix.size();
        int circleIdx = 0;
        int circlenum = min(matrix.size() + 1, matrix.at(0).size() + 1) / 2;
        while (circleIdx < circlenum) {
            for (int x = circleIdx; x < w - circleIdx; x++)
            {
                if (matrix.at(circleIdx).at(x) != 999) {
                    ans.push_back(matrix.at(circleIdx).at(x));
                    matrix.at(circleIdx).at(x) = 999;
                }
            }
            for (int y = circleIdx+1; y < h - circleIdx; y++)
            {
                if (matrix.at(y).at(w - circleIdx - 1) != 999) {
                    ans.push_back(matrix.at(y).at(w - circleIdx - 1));
                    matrix.at(y).at(w - circleIdx - 1) = 999;
                }
            }
            for (int x = w - circleIdx - 2; x >= circleIdx; x--)
            {
                if (matrix.at(h - circleIdx - 1).at(x) != 999) {
                    ans.push_back(matrix.at(h - circleIdx - 1).at(x));
                    matrix.at(h - circleIdx - 1).at(x) = 999;
                }
            }
            for (int y = h - circleIdx - 2; y >= circleIdx + 1; y--)
            {
                if (matrix.at(y).at(circleIdx) != 999) {
                    ans.push_back(matrix.at(y).at(circleIdx));
                    matrix.at(y).at(circleIdx) = 999;
                }
            }
            circleIdx++;
        }
        return ans;
    }
};