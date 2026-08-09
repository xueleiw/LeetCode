#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;


int main() {
    string s;
    vector<int> a;
    getline(cin, s);

    for(int i = 0; i < s.length(); i++) {
        if(isdigit(s[i])) {
            a.push_back(s[i] - '0');
        }
    }
    sort(a.begin(), a.end());

    int j = 0;
    for(int i = 0; i < s.length(); i++) {
        if(isdigit(s[i])) {
            s[i] = a[j] + '0';
            j++;
        }
    }

    cout << s << endl;
    return 0;
}