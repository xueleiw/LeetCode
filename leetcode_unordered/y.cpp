
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

class S {
    public:
        bool operator() (pair<int,int>&a, pair<int,int>&b) {
            return a.first < b.first;
        }
};

int main()
{
    // please define the C++14 input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++14 output here. For example:cout<<____<<endl;
    int n,k;
    cin >> k >> n;
    int sum = 0;

    vector<int> a(n + 1);
    vector<int> dp(n + 1, INT_MIN);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        // sum += a[i];
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, S> pq;
    dp[1] = a[1];
    pq.push(pair<int, int>(a[1], 1));
    for(int i = 2; i <= n; i++) {
        // for(int j = i - 1; j >= i - k && j >= 1; j--) {
        //     dp[i] = max(dp[i], a[i] + dp[j]);
        // }
        pair<int, int> t = pq.top();
        while(!pq.empty() && t.second < i - k) {
            pq.pop();
            t = pq.top();
        }
        dp[i] = a[i] + t.first;
        pq.push(pair<int, int>(dp[i], i));
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << dp[i] << ' ';
    // }
    
    cout << dp[n] << endl;
    return 0;
}

