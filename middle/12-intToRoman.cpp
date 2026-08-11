// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// class Solution {
// public:
//     string intToRoman(int num) {
//         unordered_map<int, string> mp;
//         mp[1] = "I";
//         mp[5] = "V";
//         mp[10] = "X";
//         mp[50] = "L";
//         mp[100] = "C";
//         mp[500] = "D";
//         mp[1000] = "M";
//         mp[9] = "IX";
//         mp[4] = "IV";
//         mp[90] = "XC";
//         mp[400] = "CD";
//         mp[900] = "CM";
//         string res = "";
//         if(num / 1000 > 0) {
//             int c = num / 1000;
//             num -= c * 1000;
//             while(c > 0) {
//                 res.append("M");
//                 c--;
//             }
//         }

//         if(num > 500) {
//             res.append("D");
//             num -= 500;
//         }
//         if(num > 100) {
//             int c = num / 100;
//             num %= 100;
//             if(c == 4){
//                 res.append("CD");
//             } else {
//                 while(c > 0) {
//                     res.append("C");
//                     c--;
//                 }
//             }
//         }

//         if(num > 50) {
//             res.append("L");
//             num -= 50;
//         }
//         if(num > 10) {
//             int c = num / 10;
//             num %= 10;
//             if(c == 4){
//                 res.append("CD");
//             } else {
//                 while(c > 0) {
//                     res.append("C");
//                     c--;
//                 }
//             }
//         }
//     }
// };