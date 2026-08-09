/**
 * 2024-12-31
 * 1-: 通过新建一个pair数组存元素和与之对应的数量；将数量按从大到小进行排序，输出前K个频率最高的数即可
 * 
 */

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


/*==============1-: 3ms=============*/
class Solution {
public:
    static bool cmp(pair<int, int> x, pair<int, int> y) {  // 》》 特别注意，这里必须加static才能被sort调用，或者是普通的函数，或者是Lambda表达式
        return x.second > y.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty()) {
            return res;
        }

        pair<int, int> a[100000 + 5];
        // memset(a, 0, 100000 + 5);
        sort(nums.begin(), nums.end());
        int index = 0;
        a[index].first = nums[0]; // 记录元素
        a[index].second = 1;        // 记录元素数量
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != a[index].first) {
                index++;
                a[index].first = nums[i];
                a[index].second = 1;
            } else {
                a[index].second++;
            }
        }
        //
        //sort(a, a + nums.size(), cmp);
        sort(a, a + index + 1, [](const pair<int, int> x, const pair<int, int> y ){
            return x.second > y.second;
        });
        for(int i = 0; i < k; i++) {
            res.push_back(a[i].first);
        }
        
        return res;
    }
};

int main() {


    return 0;
}