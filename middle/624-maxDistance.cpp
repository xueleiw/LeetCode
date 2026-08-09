/**
 * 2025-3-22
 * 1-： 具体思路就是用最大元素和其他所有数组作差，然后用其他数组的最大值和最大元素所在数组的最小值作差，求出这两部分的最大值即可
 */ // 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        static bool cmp(pair<int, int> x, pair<int, int> y) {
            return x.second < y.second;
        }

        int maxDistance(vector<vector<int>>& arrays) {
            int n = arrays.size();
            int res = INT_MIN;

            vector<pair<int, int>> index_maxvalue; // 记录是第几个数组，以及最大值
            for(int i = 0; i < n; i++) {
                index_maxvalue.push_back(pair<int, int>(i, arrays[i][arrays[i].size() - 1]));
            }
            sort(index_maxvalue.begin(), index_maxvalue.end(), cmp);

            for(int i = 0; i < index_maxvalue.size() - 1; i++) {
                res = max(res, abs(index_maxvalue[index_maxvalue.size() - 1].second - arrays[index_maxvalue[i].first][0]));  
            }// 用最大的值减去所有数组的第一个值

            // 用其他数组的的最大值减去最大值数组的第一个值 
            for(int i = 0; i < n; i++) {
                // 不能判断值是否相等，索引不一样就行了
                if(i != index_maxvalue[index_maxvalue.size() - 1].first) {
                    res = max(res, abs(arrays[i][arrays[i].size() - 1] - arrays[index_maxvalue[index_maxvalue.size() - 1].first][0]));
                }
            }

            return res;
        }
    };

int main() {

    return 0;
}
