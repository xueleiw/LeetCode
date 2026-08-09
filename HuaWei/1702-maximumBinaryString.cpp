/**
 * 2025-4-1
 * 1-: 数学问题，没看懂。
 * 2-：直接模拟，如果当前是0，那么往后再找一个0，将这段区间的首尾进行变换
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*============1-: 21ms=================*/

// class Solution {
//     public:
//         string maximumBinaryString(string binary) {
//             if(binary.length() == 1) {
//                 return binary;
//             }

//             int index = -1;
//             int count = 0; // 记录0的个数
//             for(int i = 0; i < binary.length(); i++) {
//                 if(binary[i] == '0'){
//                     index = i;
//                     break;
//                 }
//             }
//             for(int i = 0; i < binary.length(); i++) {
//                 if(binary[i] == '0'){
//                     count++;
//                 }
//             }

//             if(count == 0) {
//                 return binary;
//             }
//             cout << index << ' ' << count << endl;
//             string res(binary.length(), '1');
//             res[index + count - 1] = '0';
//             return res;
//         }
//     };

/*============1-: 28ms=================*/
class Solution {
    public:
        string maximumBinaryString(string binary) {
            if(binary.length() == 1) {
                return binary;
            }
            int j = 0;
            for(int i = 0; i < binary.length(); i++) {
                if(binary[i] == '0') {
                    while(j <= i || (j < binary.length() && binary[j] == '1')) {
                        j++;
                    }

                    if(j < binary.length()) {
                        binary[i] = '1';
                        binary[j] = '1';
                        binary[i + 1] = '0';
                    } else {
                        break;
                    }
                }
            }

            return binary;
            
        }
    };

int main() {

    
    cerr << "asdfasdf" << endl;
    return 0;
}