#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {
    long long t,n,m,x;
    cin >> t;
    while(t > 0) {
        t--;
        cin >> n >> m;
        vector<long long> q,l,r;
        for(long long i = 0; i < m; i++) {
            cin >> x;
            q.push_back(x);
        }
        for(long long i = 0; i < m; i++) {
            cin >> x;
            l.push_back(x);
        }
        for( long long i = 0; i < m; i++) {
            cin >> x;
            r.push_back(x);
        }
        //
        vector<pair<long long, long long>> list;
        for(long long i = 0; i < m; i++) {
            if(q[i] == 1) {
                list.push_back(pair<long long, long long>(l[i], r[i]));
            } else {
                vector<pair<long long, long long>> list2;
                for(long long j = 0; j < list.size(); j++) {
                    if(list[j].first != l[i] && list[j].second != r[i]) {
                        list2.push_back(list[j]);
                    }
                }
                list.clear();
                list = list2;
            }
            //
            if(list.size() > 2) {
                cout << "YES";
            } else if(list.size() == 0) {
                cout << "NO";
            } else if(list.size() == 1) {
                long long l1 = list[0].first;
                long long r1 = list[0].second;
                if(r1-l1 >= 3) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
            } else if(list.size() == 2) {
                long long l1 = list[0].first;
                long long r1 = list[0].second;
                long long l2 = list[1].first;
                long long r2 = list[1].second;

                if(l1 > l2) {
                    swap(l1, l2);
                    swap(r1, r2);
                }
                if(l2 <= r1) {
                    if((r2 - l1) >= 3) {
                        cout << "YES";
                    } else {
                        cout << "NO";
                    }
                } else {
                    cout << "YES";
                }

            }

            if(i != m - 1) {
                cout << ' ';
            }
        }
        cout << endl;
    }


    return 0;
}