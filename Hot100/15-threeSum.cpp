#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;

// 2025-4-2
// 921ms 就是把三数之和变成两数之和
// class Solution {
//     public:
//         vector<vector<int>> threeSum(vector<int>& nums) {
//             vector<vector<int>> res;
//             unordered_map<int, int> my_map;
//             set<vector<int>> tmp;
            
//             for(int i = 0; i < nums.size(); i++) {
//                 // if(!my_map.count(nums[i])) {
//                 //     my_map[nums[i]]++;
//                 // }
//                 my_map[nums[i]]++;
//             }

//             sort(nums.begin(), nums.end());
//             int start = 0;
//             if(my_map.count(0)) {
//                 if(my_map[0] >= 3) {
//                     start = my_map[0] - 3;
//                     // res.push_back({0, 0, 0});
//                 }
//             }

//             for(int i = start; i < nums.size() - 1; i++) {
//                 for(int j = i + 1; j < nums.size(); j++) {
//                     int x = 0 - nums[i] - nums[j];
//                     // cout << i  << ' ' << x << endl;
//                     if(my_map.count(x)) {
//                         // cout << my_map[x] << " ";
//                         if(my_map[x] > 2 || (x != nums[i] && x != nums[j])) {
//                             vector<int> t = {nums[i], nums[j], x};
//                             sort(t.begin(), t.end());
//                             tmp.insert(t);
//                         }else if(x == nums[i] && x == nums[j]) {
//                             if(my_map[x] >= 3) {
//                                 cout << "sadf" << endl;
//                                 vector<int> t = {nums[i], nums[j], x};
//                                 // sort(t.begin(), t.end());
//                                 tmp.insert(t);
//                             }
//                         } else if(x == nums[i] || x == nums[j]) {
//                             if(my_map[x] >= 2) {
//                                 vector<int> t = {nums[i], nums[j], x};
//                                 sort(t.begin(), t.end());
//                                 tmp.insert(t);
//                             }
//                         } 
//                     }
//                 }
//             }

//             for(set<vector<int>>::iterator it = tmp.begin(); it != tmp.end(); it++) {
//                 res.push_back(*it);
//             }

//             return res;
//         }
//     };


// 363ms 对上面的优化  if(nums[i] == nums[i - 1]) continue;这句很关键

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            unordered_map<int, int> my_map;
            set<vector<int>> tmp;
            
            for(int i = 0; i < nums.size(); i++) {
                my_map[nums[i]]++;
            }

            sort(nums.begin(), nums.end());

            for(int i = 0; i < nums.size() - 1; i++) {
                if(i > 0) {
                    if(nums[i] == nums[i - 1]) continue;
                }
                for(int j = i + 1; j < nums.size(); j++) {
                    if(j > 1 + i) {
                        if(nums[j] == nums[j - 1])continue;
                    }
                    int x = 0 - nums[i] - nums[j];
                  
                    if(my_map.count(x)) {
                       
                        if(x != nums[i] && x != nums[j]) {
                            
                            vector<int> t = {nums[i], nums[j], x};
                            sort(t.begin(), t.end());
                            tmp.insert(t);
                        } else if(x == nums[i] && x == nums[j]) {
                            cout << "tttt" << endl;
                            if(my_map[x] >= 3) {
                               
                                vector<int> t = {nums[i], nums[j], x};
                                // sort(t.begin(), t.end());
                                tmp.insert(t);
                            }
                        } else if(x == nums[i] || x == nums[j]) {
                            if(my_map[x] >= 2) {
                                vector<int> t = {nums[i], nums[j], x};
                                sort(t.begin(), t.end());
                                tmp.insert(t);
                            }
                        } 
                    }
                }
            }

            for(set<vector<int>>::iterator it = tmp.begin(); it != tmp.end(); it++) {
                res.push_back(*it);
            }

            return res;
        }
    };