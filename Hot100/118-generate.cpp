// 4-7
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> res;
            
            if(numRows == 1) {
                res.push_back({{1}});
                return res;
            }

            vector<vector<int>> a(numRows, vector<int>(numRows, 0));
            a[0][0] = 1;
            for(int i = 1; i < numRows; i++) {
                for(int j = 0; j <= i; j++) {
                    if(j == 0) {
                        a[i][j] = 1; // 第一列永远是1
                    } else {
                        a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                    }
                }
            }

            vector<int> tmp;
            for(int i = 0; i < numRows; i++) {
                tmp.clear();
                for(int j = 0; j <= i; j++) {
                    tmp.push_back(a[i][j]);
                }
                res.push_back(tmp);
            }

            return res;
        }
    };