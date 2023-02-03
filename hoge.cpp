#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


void step1() {
    int m = 0;
    cin >> m;
    unordered_map<int, vector<int> > menuInfo;
    for (int i = 0; i < m; i++)
    {
        vector<int> stockPrice(2);
        int dishId; 

        cin >> dishId; //dish Id
        cin >> stockPrice.at(0); // stock
        cin >> stockPrice.at(1); // price
        menuInfo.emplace(dishId, stockPrice);
    }
    while(1) {
        string order; int table = -1; int dishId = -1; int orderNum = -1;
        cin >> order >> table >> dishId >> orderNum;
        if (order == "") {
            break;
        }
        if (menuInfo.at(dishId).at(0) < orderNum) {
            cout << "sold out " << table << endl;
        }
        else {
            for (int _ = 0; _ < orderNum; _++)
            {
                cout << "received order " << table  << " " << dishId << endl;
            }
            menuInfo.at(dishId).at(0) -= orderNum;
        }
    }
}

void step2() {
    queue<int> OrderQue;
    int m = -1; int lengeNum = -1;
    cin >> m >> lengeNum;
    unordered_map<int, vector<int> > menuInfo;
    unordered_map<int, int> nowCooking;
    for (int i = 0; i < m; i++)
    {
        vector<int> stockPrice(2);
        int dishId; 

        cin >> dishId; //dish Id
        cin >> stockPrice.at(0); // stock
        cin >> stockPrice.at(1); // price
        menuInfo.emplace(dishId, stockPrice);
        nowCooking.emplace(dishId, 0);
    }
    while(1) {
        string firstString;
        cin >> firstString;
        if (firstString == "complete") {
            int dishId = -1;
            cin >> dishId;
            if (nowCooking.at(dishId) <= 0) {
                cout << "unexpected input" << endl;
            }
            else {
                nowCooking.at(dishId)--;
                lengeNum++;
                if (!OrderQue.empty()) {
                    lengeNum--;
                    int nextDish = OrderQue.front();
                    OrderQue.pop();
                    nowCooking.at(nextDish)++;
                    cout << "ok" << " " << nextDish << endl;
                }
                else {
                    cout << "ok" << endl;
                }
            }
        }
        else if (firstString == "received"){
            string order; int table = -1; int dishId = -1;;
            cin >> order >> table >> dishId;
            if (order != "order") {
                cout << "error!!!!!" << endl;
                break;
            }
            if (lengeNum > 0) {
                lengeNum--;
                nowCooking.at(dishId)++;
                cout << dishId << endl;
            }
            else {
                cout << "wait" << endl;
                OrderQue.push(dishId);
            }
        }
        else {
            break;
        }
    }
}

void step3() {
    int m = -1;
    cin >> m;
    unordered_map<int, vector<int> > menuInfo;
    unordered_map<int, queue<int> > dishId_Tables;
    for (int i = 0; i < m; i++)
    {
        vector<int> stockPrice(2);
        int dishId; 

        cin >> dishId; //dish Id
        cin >> stockPrice.at(0); // stock
        cin >> stockPrice.at(1); // price
        menuInfo.emplace(dishId, stockPrice);
        dishId_Tables.emplace(dishId, queue<int>());
    }
    while(1) {
        string firstString;
        cin >> firstString;
        if (firstString == "complete") {
            int dishId = -1;
            cin >> dishId;
            cout << "ready " << dishId_Tables.at(dishId).front() << " " << dishId << endl;
            dishId_Tables.at(dishId).pop();
        }
        else if (firstString == "received"){
            string order; int table = -1; int dishId = -1;;
            cin >> order >> table >> dishId;
            if (order != "order") {
                cout << "error!!!!!" << endl;
                break;
            }
            dishId_Tables.at(dishId).push(table);
        }
        else {
            break;
        }
    }
}

void step4() {
    int m = -1;
    cin >> m;
    unordered_map<int, vector<int> > menuInfo;
    unordered_map<int, int> table_unservedDishnum;
    unordered_map<int, int> table_bills;

    for (int i = 0; i < m; i++)
    {
        vector<int> stockPrice(2);
        int dishId; 

        cin >> dishId; //dish Id
        cin >> stockPrice.at(0); // stock
        cin >> stockPrice.at(1); // price
        menuInfo.emplace(dishId, stockPrice);
    }
    while(1) {
        string firstString;
        cin >> firstString;
        if (firstString == "ready") {
            int table = -1; int dishId = -1;
            cin >> table >> dishId;
            table_bills.at(table) += menuInfo.at(dishId).at(1);
            table_unservedDishnum.at(table)--;
        }
        else if (firstString == "received"){
            string order; int table = -1; int dishId = -1;;
            cin >> order >> table >> dishId;
            if (order != "order") {
                cout << "error!!!!!" << endl;
                break;
            }

            if (table_bills.find(table) == table_bills.end()) {
                table_bills.emplace(table, 0);
            }
            if (table_unservedDishnum.find(table) == table_unservedDishnum.end()) {
                table_unservedDishnum.emplace(table, 0);
            }
            table_unservedDishnum.at(table)++;
        }
        else if (firstString == "check"){
            int table = -1;
            cin >> table;
            
            if (table_unservedDishnum.find(table) == table_unservedDishnum.end()) {
                cout << 0 << endl;
            }
            else if (table_unservedDishnum.at(table) == 0) {
                cout << table_bills.at(table) << endl;
                table_bills.at(table) = 0;
            }
            else {
                cout << "please wait" << endl;
            }
        }
        else {
            break;
        }
    }

}


int main(int argc, char *argv[]) {
    int step = -1;
    cin >> step;
    

    switch (step)
    {
    case 1:
        step1();
        break;
    
    case 2:
        step2();
        break;
    
    case 3:
        step3();
        break;
    
    case 4:
        step4();
        break;
    
    default:
        break;
    }



    return 0;
}