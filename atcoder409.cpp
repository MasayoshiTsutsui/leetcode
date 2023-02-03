#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (int64_t i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    int flipping = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (a.at(i) == 1) {
            flipping = (1-flipping);
        }
    }
    




    return 0;
}