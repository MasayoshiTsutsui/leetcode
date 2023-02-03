#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

double p(int numdices, int dicepip) { //サイコロの個数と出目を受け取って、その出目が最大値となる確率を返す
    double probability = 0;
    uint64_t xPowN = 1;
    uint64_t x_1PowN = 1;
    uint64_t hundredPowN = 1;
    for (int i = 0; i < numdices; i++)
    {
        xPowN *= dicepip;
        x_1PowN *= dicepip - 1;
        hundredPowN *= 100;
    }
    probability = ((double)xPowN - (double)x_1PowN) / (double)hundredPowN;
    return probability;
}
int main() {
    int m[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> m[i];
    }

    double p_at_dices[5] = {1,1,1,1,1}; //i+1個のサイコロがある時、与えられた一連の出目が出る確率をもつ

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            p_at_dices[i] *= p(i+1, m[j]);
        }
    }
    
    double max = -1;
    int maxIdx = -1;
    for (int i = 0; i < 5; i++)
    {
        if (max < p_at_dices[i]) {
            max = p_at_dices[i];
            maxIdx = i;
        }
    }
    cout << maxIdx + 1 << endl;
    return 0;
}

double calcMyu(int numdices) {
    double myu = 0;
    for (int i = 1; i <= 100; i++)
    {
        myu += (double)i * p(numdices, i);
    }
    return myu;
}

double calcSigma(int numdices, double myu) {
    double sigma = 0;
    for (int i = 1; i <= 100; i++)
    {
        sigma += p(numdices, i) * ((double)i - myu) * ((double)i - myu);
    }
    sigma = sqrt(sigma);
    return sigma;
}
