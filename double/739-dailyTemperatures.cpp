/**
 * 2025-3-5
 * 1-：单调栈，但是不会用
 */ //$$$

#include<iostream>
#include<vector>
#include<cctype>
#include<stack>
#include<algorithm>
#include<string.h>
using namespace std;

/*================1-: 39ms=====================*/
class Solution {
    private:
        // temperatures = [73,74,75,71,69,72,76,73]
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> res;
            int n = temperatures.size();
            int a[n + 1];
            memset(a, 0, sizeof(a));
            stack<int> my_stack;
            
            for(int i = 0; i < temperatures.size(); i++) {
                while(!my_stack.empty() && temperatures[i] > temperatures[my_stack.top()]) {
                    int x = my_stack.top();
                    a[x] = i - x;
                    my_stack.pop();
                }
                // 温度小直接入栈，说明还未找到比栈里温度大的时候
                my_stack.push(i); // 记录下标
            }

            for(int i = 0; i < temperatures.size(); i++) {
                res.push_back(a[i]);
            }
            return res;
        }
};

int main() {
    
    return 0;
}