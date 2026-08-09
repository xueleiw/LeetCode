
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
    // please define the C++14 input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++14 output here. For example:cout<<____<<endl;
    unsigned long long n;
    cin >> n;
    vector<int> a;
    unsigned long long res = n;
    
    while(n > 0) {
        int x = n % 10;
        a.push_back(x);
        n = n / 10;
    }
    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] >= a[i + 1]) {

        } else {
            res = -1;
            break;
        }
    }

    
    cout << res << endl;
    return 0;
}
