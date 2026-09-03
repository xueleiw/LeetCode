#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 09-03

// class Solution {
//     private:
//         vector<int> f;
//         unordered_set<int> st;

//         void funion(int i, int j) {
//             // f[i] = j;
//             int f1 = ffind(i);
//             int f2 = ffind(j);
//             f[f1] = f2;
//         }

//         int ffind(int x) {
//             if (f[x] == x) {
//                 return x;
//             }
//             x = f[x];
//             return ffind(x);
//         }

//     public:
//         int findCircleNum(vector<vector<int>>& isConnected) {
//             int n = isConnected.size();
//             st.clear();
//             f.resize(n);
//             for (int i = 0; i < n; i++) {
//                 f[i] = i;
//             }

//             for (int i = 0; i < n; i++) {
//                 for(int j = 0; j <= i; j++) {
//                     if (i != j && isConnected[i][j]) {
//                         funion(i, j);
//                     }
//                 }
//             }

//             for (int i = 0; i < n; i++) {
//                 int x = ffind(i);
//                 st.insert(x);
//             }

//             return st.size();
//         }
// };

class Solution {
    private:
        vector<int> f;
        unordered_set<int> st;

        void funion(int i, int j) {

            int f1 = ffind(i);
            int f2 = ffind(j);
            f[f1] = f2;
        }

        int ffind(int x) {
            if (f[x] == x) {
                return x;
            }
            // x = f[x];
            return f[x] = ffind(f[x]);  // 路径压缩，重点就在这里
        }

    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            st.clear();
            f.resize(n);
            for (int i = 0; i < n; i++) {
                f[i] = i;
            }

            for (int i = 0; i < n; i++) {
                for(int j = 0; j <= i; j++) {
                    if (i != j && isConnected[i][j]) {
                        funion(i, j);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                int x = ffind(i);
                st.insert(x);
            }

            return st.size();
        }
};

int main() {
    Solution solution;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int result = solution.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl; // Output: 2
    return 0;
}