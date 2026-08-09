/**
 * 2025-3-21
 * 1-： 从每个位置找到当前位置的最长不重复子串，维护一个指针和滑动窗口，窗口是不断右增的，还需要一个哈希表查找元素是否出现过。
 */ // $$

 #include<iostream>
 #include<vector>
 #include<queue>
 #include<unordered_set>
 using namespace std;
 
/*===============1-: 68.42ms=====================*/
// class Solution {
//     public:
//         int lengthOfLongestSubstring(string s) {
//             unordered_set<char> set;
//             int res = 0;

//             int r = 0;
//             for(int i = 0; i < s.length(); i++) {
//                 if(i !=0) {
//                     set.erase(s[i - 1]);
//                 }
//                 while(r < s.length() && !set.count(s[r])) { // 往右找不同的字符一直往set里加
//                     set.insert(s[r]);
//                     r++;
//                 }
//                 // 此时出现了重复字符
//                 res = max(res, r - i);
//             }

//             return res;
//         }
//     };



int main() {

    return 0;
}