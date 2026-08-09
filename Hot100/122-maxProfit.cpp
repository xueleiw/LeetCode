// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

// 0ms 折线图法--把每个递增的折线段统计一下，最后求和即可
// class Solution {
//     public:
//         int maxProfit(vector<int>& prices) {
//             int res = 0;
//             int low = prices[0];
//             int high = prices[0];

//             for(int i = 1; i < prices.size(); i++) {
//                 if(prices[i] >= high) {
//                     high = prices[i];
//                 } else {
//                     res += high - low;
//                     low = prices[i];
//                     high = prices[i];
//                 }
//             }
//             res += high - low;

//             return res;
//         }
//     };



class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int res = 0;
            vector<int> a(prices.size(), 0);

            for(int i = 1; i < prices.size(); i++) {
                a[i] = prices[i] - prices[i - 1];
            }

            for(int i = 1; i < prices.size(); i++) {
                if(a[i] > 0) {
                    res += a[i];
                }
            }

            return res;
        }
    };