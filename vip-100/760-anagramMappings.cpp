#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
// 4-18 0ms

class Solution {
    public:
        vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> p;\
            vector<int> res;

            for(int i = 0; i < nums2.size(); i++) {
                p[nums2[i]] = i;
            }
            for(int i = 0; i < nums1.size(); i++) {
                if(p.count(nums1[i])) {
                    res.push_back(p[nums1[i]]);
                }
            }

            return res;
        }
    };
