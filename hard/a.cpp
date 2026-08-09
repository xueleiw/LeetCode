#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    int res = 0;

    // for(int i = s.length() - 1; i > 0; i--) {
    //     if(s[i] == 'p' && s[i-1] == 'd') {
    //         // cout << s[i] << ' ' << s[i-1] << endl;
    //         res++;
    //     }
    // }

    int start = 0;
    set<string> st;
    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == 'd' && s[i + 1] == 'p') {
            cout << start << endl;
            string tmp = s.substr(start, i + 1 - start + 1);
            if(!st.count(tmp)) {
                cout << tmp << endl;
               
                st.insert(tmp);
                res++;
            }
            start = i + 2;
        }
    }

    cout << res << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")