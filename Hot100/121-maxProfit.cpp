// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 0ms 维护一个最大最小值，如果当前值比最小还小，同时修改两个值，否则就再去判断最大值是否需要修改
// 或者直接找出数组最小值，然后判断每天能获得的利润
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int min = INT_MAX;
            int _max = 0;
            int res = 0;
            
            for(int i = 0; i < prices.size(); i++) {
                if(prices[i] < min) {
                    min = prices[i];
                    _max = prices[i];
                } else {
                    if(prices[i] > _max) {
                        _max = prices[i];
                    }
                }

                res = max(res, _max - min);
            }
            
            return res;
        }
    };