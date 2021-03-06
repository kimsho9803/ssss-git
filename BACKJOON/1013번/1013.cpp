#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int num;
    int back = 0;
    long unsigned int idx = 0;

    cin >> num;

    string s[num];
    bool anw[num];

    for(int j = 0; j < num; j++) {
        cin >> s[j];

        back = 0;
        idx = 0;
        while(s[j].length() > idx) {
            if(s[j].length() >= idx + 1) {
                if(s[j][idx] == '0' && s[j][idx + 1] == '1') {
                    back = 0;
                    idx += 2;
                    if(s[j].length() == idx) {
                        anw[j] = true;
                        break;
                    }
                    continue;
                }
            }
            if(s[j].length() >= idx + 3) {
                if(s[j][idx] == '1' && s[j][idx + 1] == '0') {
                    idx += 2;
                }
                else if(back != 0) {
                    idx = back;
                    back = 0;
                    continue;
                }
                else {
                    break;
                }

                while(s[j].length() > idx && s[j][idx] == '0') {
                    idx += 1;
                }

                while(s[j].length() > idx && s[j][idx] == '1') {
                    idx += 1;
                    if(s[j].length() == idx) {
                        anw[j] = true;
                        break;
                    }
                }

                if(s[j][idx - 2] == '1') {
                    back = idx - 1;
                }
            }
            else {
                break;
            }
        }
        if(anw[j] == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}