/**
 * 2025-1-9
 * 1-：把每个字符串排序之后分配一个对应的value，然后按照value进行分类输出
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


/*================1-: 55ms=====================*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, int> my_map;
        vector<pair<string, int>> my_pair;
        if(strs.empty()) {
            return res;
        }
        int j = 1;
        for(auto i: strs) { // 按值传递才能不修改原数组
            string tmp_str = i;
            sort(i.begin(), i.end());
            if(my_map.count(i)) {
                my_pair.push_back(pair<string, int>(tmp_str, my_map[i])); // 记录原字符串和与之对应的value
            } else {
                my_pair.push_back(pair<string, int>(tmp_str, j)); // 记录原字符串和与之对应的value
                my_map.insert(pair<string, int>(i, j));  // map是为了记录value
                j++;
            }
        }

        sort(my_pair.begin(), my_pair.end(), [](pair<string, int>& x, pair<string, int>& y){  // 按照value进行排序
            return x.second < y.second;
        });

        for(int i = 0; i < my_pair.size(); i++) {
            cout << my_pair[i].first << ' ';
        }
        cout << endl;

        int tmp_index = -1;
        vector<string> tmp_res;
        for(int i = 0; i < my_pair.size(); i++) {
            
            if(i == 0) {
                tmp_index = my_pair[i].second; // 记录第一个字符串对应的value，以便于后面的进行对比
                tmp_res.push_back(my_pair[i].first);
            } else {
                if(my_pair[i].second == tmp_index) { // 如果是同一个字符串的变体
                    tmp_res.push_back(my_pair[i].first);
                } else { // 否则
                    res.push_back(tmp_res);
                    tmp_res.clear();
                    tmp_res.push_back(my_pair[i].first);
                    tmp_index = my_pair[i].second;
                }
            }
        }
        if(!tmp_res.empty()) {
            res.push_back(tmp_res);
        }

        return res;
    }
};


int main() {
    Solution solu;
    vector<string> x = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = solu.groupAnagrams(x);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}