#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 5-11


// 83ms
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    void back(int index, int n, int k) {
        if(tmp.size() == k) {
            res.push_back(tmp);
            return;
        }

        // if(n - index + 1 < k - tmp.size()) {  // 剩下的个数小于需要的个数
        //     return;
        // }

        // if(index > n) {
        //     return;
        // }

        // for(int i = index; i <= n; i++) {
        //     tmp.push_back(i);
        //     back(i + 1, n, k);
        //     tmp.pop_back();
        // }

        // 剪枝优化
        for(int i = index; i <= (n - (k - tmp.size()) + 1); i++) {
            tmp.push_back(i);
            back(i + 1, n, k);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        back(1, n, k);

        return res;
    }
};