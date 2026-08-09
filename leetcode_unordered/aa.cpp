#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;


int main() {
    string s;
    int n, l;
    cin >> n >> l >> s;
    vector<char> a(26, 0);
    int sum = 0;
    set<int> st;

    for(int i = 0; i < s.length(); i++) {
        if(st.count(s[i])) {

        } else {
            st.insert(s[i]);
            sum++;
        }
        a[s[i] - 'A']++;
    }

    int tmp_n = s.length();
    int res = 0;
    while(tmp_n > 0) {
        for(int i = 0; i < 26; i++) {
            if(a[i] > 0) {
                if(sum > n) {
                    tmp_n--;
                    a[i]--;
                    res++;
                } else {
                    tmp_n--;
                    a[i]--;
                    res++;
                    res += n - (sum - 1);
                }
                // tmp_n--;
                // a[i]--;
                if(a[i] == 0) {
                    sum--;
                }
            }
        }
    }
    
    cout << res << endl;
    return 0;
}
