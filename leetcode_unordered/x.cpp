
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
    // please define the C++14 input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++14 output here. For example:cout<<____<<endl;
    int r,k,n;
    cin >> r >> k >> n;
    vector<int> a(n + 1);
    vector<int> b(n+1, 0);
    vector<int> sum(n+1, 0);
    int res = INT_MAX;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];   
        sum[i] = sum[i-1] + a[i];
        //res = min(res, a[i]);
    }
    for(int i = 1; i <= n; i++) {
        int left = max(1, i-r);
        int right = min(n, i+r);
        b[i] = (sum[i] - sum[left-1]) + (sum[right] - sum[i]);
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << b[i] << ' ';
    //     // res = min(res, b[i]);
    // }
    sort(b.begin(), b.end());
    if(r != 0) {
        
        // if(b[1] + k <= b[2]) {
        //     res = b[1] + k;
        // } else {
        //     res = (b[1] + k + b[2]) / 2;
        // }
        res = (b[2], b[1] + k);
        
    } else {
        res = b[1];
        int t = b[1];
        // if(sum[n])
        for(int i = 2; i < n; i++) {
            t += b[i];
            if((t + k) / i < b[i+1]) {
                res = t + k / 2;
                break;
            }
        }
        // cout << res << endl;
        t += b[n];
        res = max(res, (t + k) / n);
    }
    
    // if(k == 0) {
    //     for(int i = 0; i < n; i++) {
    //         for(int j = i; j < n && j <)
    //     }
    // }

    
    cout << res << endl;

    return 0;
}

