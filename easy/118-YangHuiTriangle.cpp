/**
 * 2024-12-28
 * 1-: 经典的dp，将等边三角形转换为左下三角形，这样的话每个点的值就是上方坐标点的值加上左上对角点的值，注意一下初始情况即可 
 *     a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
 */
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;



/*=================1-: 0ms======================*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int a[numRows + 5][numRows + 5];
        memset(a, 0, sizeof(a));
        if(numRows == 1) {
            res.push_back({1});
            return res;
        }
        a[1][1] = 1;
        for(int i = 2; i <= numRows; i++) {
            for(int j = 1; j <= i; j++) {
                if(j == 1) {
                    a[i][j] = 1;
                } else {
                    a[i][j] = a[i - 1][j] + a[i - 1][j - 1]; // 动态方程
                }
                
            }
        }
        // 把a数组的值放到res中
        for(int i = 1; i <= numRows; i++) {
            vector<int> tmp;
            for(int j = 1; j <= i; j++) {
                tmp.push_back(a[i][j]);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        // 返回结果
        return res;

    }
};

int main() {
    Solution solu;
    vector<vector<int>> res = solu.generate(1);

    return 0;
}