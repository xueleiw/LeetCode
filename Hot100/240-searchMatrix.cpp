// 2025-4-6
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 44ms
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int i = 0;
            int j = matrix[0].size() - 1;

            while(i < matrix.size() && j >= 0) {
                // cout << i << ' ' << j << ' ' << matrix[i][j] << ' ' << endl;
                if(matrix[i][j] == target) {
                    return true;
                } else if(matrix[i][j] < target) {
                    i++;
                } else if(matrix[i][j] > target) {
                    j--;
                }
            }

            return false;
        }
    };
