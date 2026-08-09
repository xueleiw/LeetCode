#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include <unordered_set>
#include<algorithm>
using namespace std;
// 4-20  // 正着反着各贪心一遍然后取最大，每次都尽量赋值最小值1
// 571 ms

class Solution {
    public:
        int candy(vector<int>& ratings) {
            vector<int> ans(ratings.size(), 0);
            vector<int> ans2(ratings.size(), 0);
            ans[0] = 1;
            for(int i = 0; i < ratings.size() - 1; i++) {
                if(ratings[i] < ratings[i + 1]) ans[i + 1] = ans[i] + 1;
                if(ratings[i] == ratings[i + 1]) ans[i + 1] = 1;
                if(ratings[i] > ratings[i + 1]) {
                    if(ans[i] == 1) {
                        ans[i] = 2;
                        ans[i + 1] = 1;
                    } else {
                        ans[i + 1] = 1;
                    }
                }
            }
            for(auto &x: ans) {
                cout << x << ' ';
            }cout << endl;
            // 倒着来一遍
            ans2[ratings.size() - 1] = 1;
            for(int i = ratings.size() - 1; i > 0 ; i--) {
                if(ratings[i] < ratings[i - 1]) ans2[i - 1] = ans2[i] + 1;
                if(ratings[i] == ratings[i - 1]) ans2[i - 1] = 1;
                if(ratings[i] > ratings[i - 1]) {
                    if(ans2[i] == 1) {
                        ans2[i] = 2;
                        ans2[i - 1] = 1;
                    } else {
                        ans2[i - 1] = 1;
                    }
                }
            }
            //
            int res = 0;
            for(int i = 0; i < ratings.size(); i++) {
                cout << ans[i] << ' ' << ans2[i] << endl;
                res += max(ans[i], ans2[i]);
            }

            return res;
        }
    };
