// 2025-4-6
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 0ms
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            vector<pair<int, int>> tmp;

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] == 0) {
                        tmp.push_back(pair<int, int>(i, j));
                    }
                }
            }    

            for(int i = 0; i < tmp.size(); i++) {
                int x = tmp[i].first;
                int y = tmp[i].second;
                for(int k = 0; k < n; k++) {
                    matrix[x][k] = 0;
                }
                for(int k = 0; k < m; k++) {
                    matrix[k][y] = 0;
                }
            }
        }
    };