#include<iostream>
#include<vector>
using namespace std;
// 26/8/9

class NumMatrix {
private:    
    vector<vector<int>> nums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        nums.resize(m + 1, vector<int>(n + 1));

        // 构建前缀和数组，需要扩充全0行和全0列，避免边界问题
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                nums[i][j] = matrix[i - 1][j - 1] + nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1];
            }
        }
    }
    
    // 需要考虑到扩充行列之后坐标的变换
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int res = nums[row2 + 1][col2 + 1] - nums[row2 + 1][col1] - nums[row1][col2 + 1] + nums[row1][col1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> nums = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},
                                {1,0,3,0,5}};

    NumMatrix *solu = new NumMatrix(nums);
    

    return 0;
}