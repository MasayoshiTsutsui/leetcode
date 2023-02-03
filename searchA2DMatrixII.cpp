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
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int h = matrix.size();
        int w = matrix.at(0).size();
        int i = 0; int j = w - 1;

        while (i < h && j >= 0) {
            if (matrix.at(i).at(j) == target) {
                return true;
            }
            else if (matrix.at(i).at(j) > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
        
};