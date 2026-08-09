#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
// 4-18


class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            int n = numCourses;
            vector<list<int>> g(n);
            vector<int> indegree(n, 0); // 每个点的入度为0
            queue<int> q;

            for(int i = 0; i < prerequisites.size(); i++) {
                indegree[prerequisites[i][0]]++;
                g[prerequisites[i][1]].push_back(prerequisites[i][0]); // 邻接表记录吧
            }

            for(int i = 0; i < n; i++) {
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }

            while(!q.empty()) {
                int x = q.front();
                q.pop();
                for(auto &ele: g[x]) {
                    indegree[ele]--;
                    if(indegree[ele] == 0) {
                        q.push(ele);
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                if(indegree[i] != 0) {
                    return false;
                }
            }

            return true;
        }
    };