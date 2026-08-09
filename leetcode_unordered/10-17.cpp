#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int res = 0;
//         int i = 0, j = height.size() - 1;
//         while(i < j) {
//             res = max(res, (min(height[i], height[j])) * (j - i));
//             if(height[i] < height[j]) {
//                 i++;
//             } else {
//                 j--;
//             }
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0;
//         int i = 0, j = height.size() - 1;
//         int le = 0,ri = 0;
//         while(i < j) {
//             le = max(le, height[i]);
//             ri = max(ri, height[j]);
//             if(le <= ri) {
//                 res += (le - height[i]);
//                 i++;
//             } else {
//                 res += (ri - height[j]);
//                 j--;
//             }
//         }
//      return res;
//     }
// };


// -1,0,1,2,-1,-4
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> st;
//         vector<vector<int>> res;
//         unordered_map<int, int> mp;
//         vector<int> tmp;
//         for(int i = 0; i < nums.size(); i++) {
//             mp[nums[i]] = i;
//         }
//         // int i = 0, j = nums.size() - 1;
//         for(int i = 0; i < nums.size(); i++) {
//             for(int j = i + 1; j < nums.size(); j++) {
//                 int sum = nums[i] + nums[j];
//                 sum = 0 - sum;
//                 if(mp.count(sum)) {
//                     int k = mp[sum];
//                     if(i != k && j != k) {
//                         tmp.push_back(nums[i]);
//                         tmp.push_back(nums[j]);
//                         tmp.push_back(nums[sum]);
//                         sort(tmp.begin(), tmp.end());
//                         st.insert(tmp);
//                         tmp.clear();
//                     }
//                 }
//             }
//         }

//         for(auto& x: st) {
//             res.push_back(x);
//         }

//         return res;
//     }
// };

// "pw wke w"
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char, int> mp;
//         int res = 0;
//         int start = 0;

//         for(int i = 0; i < s.length(); i++) {
//             if(!mp.count(s[i])) {
//                 mp[s[i]] = i;
//             } else {
//                 for(start; start <= mp[s[i]]; start++) {
//                     mp.erase(s[start]);
//                 }
//                 mp[s[i]] = i;
//             }
//             res = max(res, (int)mp.size());
//         }
        
//         return res;
//     }
// };

//  "cbaebabacd", p = "abc"
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> res;
//         // unordered_map<char,
//         vector<int> p1(26, 0);
//         vector<int> tmp(26, 0);

//         if(s.length() < p.length()) return res;
//         for(int i = 0; i < p.length(); i++) {
//             p1[p[i] - 'a']++;
//             tmp[s[i] - 'a']++;
//         }

//         if(p1 == tmp) res.push_back(0);
        
//         for(int i = p.length(); i < s.length(); i++) {
//             tmp[s[i - p.length()] - 'a']--;
//             tmp[s[i] - 'a']++;
//             if(p1 == tmp) {
//                 res.push_back(i - p.length() + 1);
//             }
            
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<bool> row(m, false);
//         vector<bool> col(n, false);

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(matrix[i][j] == 0) {
//                     row[i] = true;
//                     col[j] = true;
//                 }
//             }
//         }

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(row[i] && col[j]) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int left = 0, right = matrix[0].size() - 1;
//         int up = 0, down = matrix.size() - 1;
//         vector<int> res;

//         int i = 0, j = 0;
//         while(res.size() < m * n) {
//             for(j; j <= right; j++) {
//                 res.push_back(matrix[i][j]);
//             }
//             up++;j--;i++;
//             if(res.size() == m * n) break;

//             for(i; i <= down; i++) {
//                 res.push_back(matrix[i][j]);
//             }
//             right--,i--,j--;
//             if(res.size() == m * n) break;

//             for(j; j >= left; j--) {
//                 res.push_back(matrix[i][j]);
//             }
//             down--,j++,i--;
//             if(res.size() == m * n) break;

//             for(i; i >= up; i--) {
//                 res.push_back(matrix[i][j]);
//             }
//             left++,i++,j++;
//             if(res.size() == m * n) break;
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();

//         for(int i = 0; i < n / 2; i++) {
//             for(int j = 0; j < n; j++) {
//                 swap(matrix[i][j], matrix[n - i - 1][j]);
//             }
//         }

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j <= i; j++) {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
//     }
// };

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         int i = 0, j = n - 1;

//         while(i < m && j >= 0) {
//             if(matrix[i][j] == target) {
//                 return true;
//             }
//             if(matrix[i][j] < target) {
//                 i++;
//             } else {
//                 j--;
//             }
//         }

//         return false;
//     }
// };


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* p1 = headA;
//         set<ListNode*> st;
//         while(p1 != nullptr) {
//             st.insert(p1);
//             p1 = p1->next;
//         }
//         p1 = headB;
//         while(p1 != nullptr) {
//             if(st.count(p1)) {
//                 return p1;
//             }
//             p1 = p1->next;
//         }

//         return nullptr;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* next = nullptr;
//         ListNode* tmp = head;

//         while(tmp != nullptr) {
//             next = tmp->next;
//             tmp->next = prev;
//             prev = tmp;
//             tmp = next;
//         }

//         return prev;
//     }
// };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == nullptr || head->next == nullptr) {
//             return head;
//         }
        
//         // ListNode* tmp = head;
//         // head->next = nullptr;
//         ListNode* new_head = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;

//         return new_head;
//     }
// };

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> a;
//         while(head != nullptr) {
//             a.push_back(head->val);
//             head = head->next;
//         }
//         for(int i = 0; i < a.size() / 2; i++) {
//             if(a[i] != a[a.size() - i - 1]) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head == nullptr || head->next == nullptr) return false;
//         ListNode* slow = head;
//         ListNode* quic = head->next;
//         while(slow != nullptr && quic != nullptr &&quic->next != nullptr) {
//             if(slow == quic) return true;
//             slow = slow->next;
//             quic = quic->next->next;
//         }

//         return false;
//     }
// };


// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if(head == nullptr || head->next == nullptr) return nullptr;
//         ListNode* slow = head;
//         ListNode* quic = head;
//         while(quic != nullptr && quic->next != nullptr) {
//             slow = slow->next;
//             quic = quic->next->next;
//             if(slow == quic) {
//                 ListNode* tmp = head;
//                 while(slow != tmp) {
//                     slow = slow->next;
//                     tmp = tmp->next;
//                 }
//                 return slow;
//             }
           
//         }

//         return nullptr;
//     }
// };

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* ph = new ListNode(-1);
//         ListNode* tmp = ph;
//         while(list1 != nullptr && list2 != nullptr) {
//             if(list1->val < list2->val) {
//                 ph->next = list1;
//                 list1 = list1->next;
//             } else {
//                 ph->next = list2;
//                 list2 = list2->next;
//             }
//             ph = ph->next;
//         }

//         while(list1 != nullptr) {
//             ph->next = list1;
//             list1 = list1->next;
//             ph = ph->next;
//         }

//         while(list2 != nullptr) {
//             ph->next = list2;
//             list2 = list2->next;
//             ph = ph->next;
//         }

//         ListNode* res = tmp->next;
//         delete tmp;
//         return res;
//     }
// };

// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head == nullptr || head->next == nullptr) {
//             return head;
//         }

        
//         ListNode* next = head->next;
//         ListNode* new_head = swapPairs(head->next->next);
//         head->next = new_head;
//         next->next = head;

//         return next;
//     }
// };

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         for(int i = 0; i < n; i++) {
//             dp[0][i] = 1;
//         }

//         for(int i = 0; i < m; i++) {
//             dp[i][0] = 1;
//         }
        
//         for(int i = 1; i < m; i++) {
//             for(int j = 1; j < n; j++) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }

//         return dp[m - 1][n - 1];
//     }
// };


// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         for(int i = 1; i < n; i++) {
//             grid[0][i] += grid[0][i - 1];
//         }

//         for(int i = 1; i < m; i++) {
//             grid[i][0] += grid[i - 1][0];
//         }

//         for(int i = 1; i < m; i++) {
//             for(int j = 1; j < n; j++) {
//                 grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
//             }
//         }

//         return grid[m - 1][n - 1];
//     }
// };

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         if(n == 0 || n == 1) return s;
//         vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
//         for(int i = 1; i <= n; i++) {
//             dp[i][i] = true;
//         }

//         int length = 1;
//         string res = "";
//         res.push_back(s[0]);
//         for(int i = n - 1; i >= 1; i--) {
//             for(int j = i + 1; j <= n; j++) {
//                 if(s[i - 1] == s[j - 1]) {
//                     if(j == i + 1) {
//                         dp[i][j] = true;
//                     } else {
//                         if(dp[i + 1][j - 1]) {
//                             dp[i][j] = true;
//                         }
//                     }
//                 }
//                 if(dp[i][j]) {
//                     if(j - i + 1 > length) {
//                         length = j - i + 1;
//                         res = s.substr(i - 1, length);
//                     }
//                 }
//             }
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//         for(int i = 1; i <= m; i++) {
//             for(int j = 1; j <= n; j++) {
//                 if(text1[i - 1] == text2[j - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 } else {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }

//         return dp[m][n];
//     }
// };

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; i++) {
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1],dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[m][n];
    }
};