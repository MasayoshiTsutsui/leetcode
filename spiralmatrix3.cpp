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
    int h = 1;
    int v = 0;

    void changeDir() {
        if (h == 1) {
            h = 0;
            v = 1;
        }
        else if (v == 1) {
            h = -1;
            v = 0;
        }
        else if (h == -1) {
            h = 0;
            v = -1;
        }
        else if (v == -1) {
            h = 1;
            v = 0;
        }
    }

        
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix.at(0).size();
        int i = 0;
        int j = 0;

        while(1) {
            ans.push_back(matrix.at(i).at(j));
            matrix.at(i).at(j) = 999;
            if (i + v >= m || i + v < 0 || j + h >= n || j + h < 0 || matrix.at(i+v).at(j+h) == 999) {
                changeDir();
                if (i + v >= m || i + v < 0 || j + h >= n || j + h < 0 || matrix.at(i+v).at(j+h) == 999) {
                    break;
                }
            }
            i += v;
            j += h;
        }
        return ans;
    }
};