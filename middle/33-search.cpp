/**
 * 2025-3-6
 * 1-：O(n)遍历很简单；用了二分查找之后就比较巧妙的变成O(logn)了
 */ //

 #include<iostream>
 #include<vector>
 using namespace std;
 
 
 /*================1-: 0ms=====================*/
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            // 虽然是二分查找，但是精髓在于 从中间分开，一定会有一半的区间是有序递增的，
            // 只需要判断target是否在这半个区间里，如果不在，则去另一半区间继续二分
            }

    };
 
 int main() {
 
     return 0;
 }