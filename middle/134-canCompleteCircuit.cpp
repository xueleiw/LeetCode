#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stdio.h>
using namespace std;
// 5-12


// 2ms 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int tot = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            tot += gas[i] - cost[i];
            if(sum < 0) {
                start = i + 1;
                // sum = gas[i] - cost[i];
                sum = 0;
            } else {

            }

        }
        if(tot < 0) {
            return -1;
        }
        return start;
    }
};

int main() {

    int x = 42;
    int& ref = x;

    std::cout << sizeof(ref) << ' ';
    cout << sizeof('\0')  << ' ';
    // extern "C" {
    //     printf("%d\n", sizeof('\0'));
    // }
    
    return 0;
}