#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstdint> 
#include <unordered_set>
using namespace std;
// 5-1
// easy exercise
class Solution {
    public:
        int countElements(vector<int>& arr) {
            int res = 0;
            unordered_set<int> st(arr.begin(), arr.end());

            for(int i = 0; i < arr.size(); i++) {
                if(st.count(arr[i] + 1)) {
                    res++;
                }
            }

            return res;
        }
    };

int main() {
    cout << "阿斯蒂芬" << endl;
    // throw std::bad_alloc();
    char a[10] = "ccccc";
    char *x = a;
    printf("%x,  %x, %s, %p\n", x, *x, x, &a[0]);
    // x += 2;
    int b = 3;
    *reinterpret_cast<char**>(x) = (char*)(&b);
    printf("%x,  %x, %s, %s, %p\n", x, *x, x, a, &b);
    // for(int i = 0; i < 10; i++) {
    //     cout << static_cast<uint16_t>(a[i]) << " ";
    // }cout << endl;
    for(int i = 0; i < 10; i++) {
        printf("%d ", (uint8_t)a[i]);
    }

    return 0;
}