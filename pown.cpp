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
    double myPow(double x, int n) {
        if (n == 0)
        {
            return 1.,;
        }
        double ans;
        int poweredN;
        vector<double> powX(32, -1.);

        if (n > 0)
        {
            ans = x;
            poweredN = 1;
            int exp = 0;
            powX.at(exp) = ans;
            while(poweredN <= n / 2)
            {
                ans = ans * ans;
                poweredN *= 2;
                exp++;
                powX.at(exp) = ans;
            }
            int n_remain = n - poweredN;
            while (n_remain > 0)
            {
                if (n_remain >= poweredN)
                {
                    n_remain -= poweredN;
                    ans *= powX.at(exp);
                }
                poweredN /= 2;
                exp--;
            }
        }
        else
        {
            ans = 1. / x;
            poweredN = -1;
            int exp = 0;
            powX.at(exp) = ans;
            while(poweredN >= n / 2)
            {
                ans = ans * ans;
                poweredN *= 2;
                exp++;
                powX.at(exp) = ans;
            }
            int n_remain = n - poweredN;
            while (n_remain < 0)
            {
                if (n_remain <= poweredN)
                {
                    n_remain -= poweredN;
                    ans *= powX.at(exp);
                }
                poweredN /= 2;
                exp--;
            }
        }
        return ans;
    }
};