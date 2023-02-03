#include <iostream>
#include <vector>
using namespace std;

void printLine(char* str) {
    for (int i = 0; i < 100; i++)
    {
        if (str[i] == '.') {
            break;
        }
        cout << str[i];
    }
    cout << endl;
}

void initStr(char* str) {
    for (int i = 0; i < 100; i++)
    {
        str[i] = '.';
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    vector<char*> strs;
    char* str = new char[100];

    string funcname = argv[1];

    fp = fopen(&argv[2][12], "r");
    if (fp == NULL) {
        printf("%s file not open!\n", &argv[2][12]);
        return -1;
    }

    initStr(str);

    fgets(str, 100, fp);
    printLine(str);
    strs.push_back(str);

    vector<vector<int>> lack_idx;
    vector<vector<int>> lack_param;

    vector<int> sales;
    vector<int> is_hot;
    vector<int> cloud;
    vector<int> rainfall;
    vector<int> temparature;
    vector<int> humidity;

    int sales_sum = 0;
    int line_idx = 0;
    while (1) {
        char* str = new char[100];
        if (fgets(str, 100, fp) == NULL) {
            break;
        }
        int comma_cnt = 0;
        int num = 0;
        lack_idx.push_back({});
        lack_param.push_back({});
        for (int i = 0; i < 100; i++)
        {
            if (str[i] == ',') {
                if (str[i-1] == ',') {
                    num = -9999;
                    //lack_idx.at(line_idx).push_back(i);
                    //lack_param.at(line_idx).push_back(comma_cnt);
                }
                if (comma_cnt == 1) {
                    sales.push_back(num);
                }
                switch (comma_cnt)
                {
                case 1:
                    sales.push_back(num);
                    break;
                case 2:
                    is_hot.push_back(num);
                    break;
                case 3:
                    cloud.push_back(num);
                    break;
                case 4:
                    rainfall.push_back(num);
                    break;
                case 5:
                    temparature.push_back(num);
                    break;
                case 6:
                    humidity.push_back(num);
                    break;
                default:
                    break;
                }
                num = 0;
                comma_cnt++;
                continue;
            }
            switch (comma_cnt)
            {
            case 1:
                if (str[i] <= '9' && str[i] >= '0') {
                    num *= 10;
                    num += str[i] - '0';
                }
                break;
            default:
                break;
            }
        }
        strs.push_back(str);
        line_idx++;
    }
    float sales_mean = 0.;
    float is_hot_mean = 0.;
    float cloud_mean = 0.;
    float rainfall_mean = 0.;
    float temp_mean = 0.;

    for (int i = 0; i < sales.size(); i++)
    {
        sales_mean += sales.at(i);
        is_hot_mean += is_hot.at(i);
        cloud_mean += cloud.at(i);
        rainfall_mean += rainfall.at(i);
        temp_mean += temparature.at(i);
    }
    sales_mean /= sale.size();
    is_hot_mean /= sale.size();
    cloud_mean /= sale.size();
    rainfall_mean /= sale.size();
    temp_mean /= sale.size();

    for (int i = 0; i < sale.size(); i++)
    {
        char* str = strs.at(i);
        for (int i = 0; i < 19; i++)
        {
            cout << str[i];
        }
        cout << ',';

        if (sale.at(i) == -9999) {
            cout << sales_mean;
        }
        else {
            cout << sale.at(i);
        }

        if (is_hot.at(i) == -9999) {
            cout << is_hots_mean;
        }
        else {
            cout << is_hot.at(i);
        }
        if (cloud.at(i) == -9999) {
            cout << clouds_mean;
        }
        else {
            cout << cloud.at(i);
        }
        if (is_hot.at(i) == -9999) {
            cout << is_hots_mean;
        }
        else {
            cout << is_hot.at(i);
        }

        if (sale.at(i) == -9999) {
            cout << sales_mean;
        }

        cout << endl;
    }
    



    int sum_sales = 0;

    for (int i = 0; i < sales.size(); i++)
    {
        sum_sales += sale.at(i);
    }
    cout << sum_sales << endl;
    
    fclose(fp);
    return 0;
}