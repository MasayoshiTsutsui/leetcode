#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string command, s, ans;
    cin >> command >> s;


    if (command == "compress") {
        bool is_consec = false;
        string char_buff = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (i + 1 < s.size() && s.at(i) == s.at(i + 1)) {
                if (is_consec) {
                    // cout << "a" << endl;
                    char_buff += s.at(i);
                    // cout << char_buff << endl;
                }
                else {
                    // cout << "b" << endl;
                    if (char_buff != "") {
                        ans += '-' + to_string(char_buff.size()) + char_buff;
                    }
                    char_buff = s.at(i);
                    is_consec = true;
                }
            }
            else if (i + 1 == s.size()){
                if (is_consec) {
                    // cout << "c" << endl;
                    ans += to_string(char_buff.size() + 1) + s.at(i);
                }
                else {
                    // cout << "d" << endl;
                    if (char_buff == "") {
                        ans += '-' + to_string(1) + s.at(i);
                    }
                    else {
                        ans += '-' + to_string(char_buff.size() + 1) + char_buff + s.at(i);
                    }
                }
            }
            else {
                if (is_consec) {
                    // cout << "e" << endl;
                    ans += to_string(char_buff.size() + 1) + s.at(i);
                    is_consec = false;
                    char_buff = "";
                }
                else {
                    // cout << "f" << endl;
                    char_buff += s.at(i);
                }
            }

        }
        cout << ans << endl;
        
    }
    else if (command == "decompress") {
        bool is_consec = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s.at(i) == '-') {
                int charcnt = s.at(i+1);
                is_consec = false;
            }
        }
        
        

    }
    //else {
        //// cout << "error" << endl;
        //return -1;
    //}
    return 0;

}