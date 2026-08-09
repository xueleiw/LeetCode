// 4-8
#include<iostream>
#include<vector>
using namespace std;

// 0ms 
class Solution {
    public:
        int missingNumber(vector<int>& arr) {
            int d = (arr[arr.size() - 1] - arr[0]) / arr.size();

            for(int i = 1; i < arr.size(); i++) {
                if(arr[i] - arr[i - 1] != d) {
                    return arr[i] + d;
                }
            }
        }
    };


int main() {
    vector<int> arr{15,13,12};

    unsigned int a = 3;
    int b = -3;
    cout << b / a << endl;
    // int x = arr[arr.size() - 1] - arr[0];
    // int y = arr.size();
    int x = -3;
    int y = 3;
    int z = (arr[arr.size() - 1] - arr[0]) / (int)arr.size();
    cout << z << endl;
    printf("%x\n", z);
    int d = x / y;
    cout << arr[arr.size() - 1] - arr[0] << ' ' <<  arr.size() << endl;
    cout << d << endl;

    return 0;
}