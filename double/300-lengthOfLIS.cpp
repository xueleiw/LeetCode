/**
 * 2025-3-12
 * 1-：dp-还有待理解
 */ // $$

 #include<iostream>
 #include<vector>
 #include<algorithm>
 #include<unordered_set>
 using namespace std;
 
 
 /*================1-: 135ms=====================*/
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size() + 1, 1);
            for(int i = 0; i < nums.size(); i++) {
                for(int j = 0; j < i; j++) {
                    if(nums[i] > nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }

            return dp[nums.size()];
        }
};
 
int main() {

    return 0;
}