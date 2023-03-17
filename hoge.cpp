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
    // 各stoneの中心からの距離
    vector<double> team1_dists;
    vector<double> team2_dists;

    for (size_t i = 0; i < 16; i++)
    {
        double x, y;
        cin >> x >> y;
        if (i % 2 == 0)
        {
            team1_dists.push_back(sqrt(x*x + y*y));
        }
        else
        {
            team2_dists.push_back(sqrt(x*x + y*y));
        }
    }

    double team1_min_dist = *min_element(team1_dists.begin(), team1_dists.end());
    double team2_min_dist = *min_element(team2_dists.begin(), team2_dists.end());

    if (team1_min_dist > 30. && team2_min_dist > 30.)
    {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    if (team1_min_dist < team2_min_dist)
    {
        double threshold = min(team2_min_dist, 30.);
        int points = 0;
        for (size_t i = 0; i < team1_dists.size(); i++)
        {
            if (team1_dists.at(i) < threshold)
            {
                points++;
            }
        }
        cout << points << " " << 0 << endl;
    }
    else {
        double threshold = min(team1_min_dist, 30.);
        int points = 0;
        for (size_t i = 0; i < team2_dists.size(); i++)
        {
            if (team2_dists.at(i) < threshold)
            {
                points++;
            }
        }
        cout << 0 << " " << points << endl;
    }
    return 0;
}