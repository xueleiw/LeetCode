/**
 * 2025-1-12
 * 1-：这道题的精髓在于用哈希表记录每个数据的每一位出现1的次数，哪一位出现1的次数最多，结果就是出现1最多的次数
 * $$
 */


#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<bitset>
using namespace std;


/*================1-: 205ms=====================*/
// class Solution {
// public:
//     int largestCombination(vector<int>& candidates) {
//         unordered_map<int, int> hash_map; // 记录每个数据的每一位出现1的次数
//         int res = 0;

//         for(int i = 0; i < candidates.size(); i++) {
//             int x = candidates[i];
//             bitset<24> binary(x);
//             for(int j = 0; j < binary.size(); j++) {
//                 if(binary[j] == 1) {
//                     hash_map[j]++;
//                 }
//                 res = max(res, hash_map[j]);
//             }
//         }

//         return res;
//     }
// };


/*================1-: 147ms=====================*/
// class Solution {
// public:
//     int largestCombination(vector<int>& candidates) {
//         unordered_map<int, int> hash_map; // 记录每个数据的每一位出现1的次数
//         int res = 0;

//         for(int i = 0; i < candidates.size(); i++) {
//             int x = candidates[i];
//             int index = 0;
//             while (x > 0) {
//                 if(x & 1) {
//                     hash_map[index]++;
//                 }
//                 res = max(res, hash_map[index]);
//                 index++;
//                 x = x >> 1;
//             }
            
//         }

//         //for(int i = 0; i < 23; i++)

//         return res;
//     }
// };


/*================1-: 80ms=====================*/
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        unordered_map<int, int> hash_map; // 记录每个数据的每一位出现1的次数
        int res = 0;

        int index = 0;
        for(int i = 0; i < candidates.size(); i++) {
            int x = candidates[i];
            index = 0;
            while (x > 0) {
                if(x & 1) {
                    hash_map[index]++;
                }
                //res = max(res, hash_map[index]);
                index++;
                x = x >> 1;
            }
            
        }

        for(int i = 0; i < 24; i++) { // 24位
            res = max(res, hash_map[i]);
        }

        return res;
    }
};

int main() {
    return 0;
}