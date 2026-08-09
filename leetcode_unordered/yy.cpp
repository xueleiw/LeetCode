#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    string s;
    cin >> s;

    string tmp = "";
    int index = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '|') {
            index = i;
            break;
        } 
    }

    vector<string> st;
    for(int i = index + 1; i < s.length(); i++) {
        if(s[i] == '|') {
            st.push_back(tmp);
            tmp.clear();
        } else {
            tmp.push_back(s[i]);
        }
    }
    st.push_back(tmp);

    int yy = atoi(st[0].c_str());
    int pyy = atoi(st[1].c_str());
    int ll = atoi(st[2].c_str());
    int pll = atoi(st[3].c_str());

    int nyy = yy / 60;
    if(nyy % 60 != 0) nyy++;
    int nll = ll / 1024;
    // if()

    int res = 0;
    if(nyy <= 1) {

    } else if(nyy <= 5 && nyy >= 2) {
        res += (nyy - 1) * (pyy / 10) * 1.5;

    } else if(nyy <= 10 && nyy >= 6) {
        res += 4 * (pyy / 10) * 1.5;
        res += (nyy - 5) * (pyy / 10);

    } else if(nyy <= 20 && nyy >= 11) {
        res += 4 * (pyy / 10) * 1.5;
        res += 5 * (pyy / 10);
        res += (nyy - 10) * (pyy / 10) * 0.5;

    } else if(nyy >= 21) {
        res += 4 * (pyy / 10) * 1.5;
        // cout << res << ' ';
        res += 5 * (pyy / 10);
        // cout << res << ' ';
        res += 10 * (pyy / 10) * 0.5;
        // cout << res << ' ';
        res += (nyy - 20) * (pyy / 10) * 0.2;
    }

    int totll = 0;// res += nll * 1024 / 10 * pll / 10;
    if(nll >= 100) {
        nll -= 25;

        if(nll >= 200) {
            nll -= 100;
            if(nll >= 500) {
                nll -= 500;
                totll = 500;
                int a = nll / 100;
                if(a % 2 == 0) {
                    totll += (a / 2) * 100;
                    totll += nll % 100;
                } else {
                    a++;
                    totll += (a / 2) * 100;
                }

            } else {
                totll = nll;
            }
        } else {
            totll = nll;
        }
    } else {
        totll = nll;
    }
    res += totll * 1024 / 10 * pll / 10;
    

    cout << res << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")