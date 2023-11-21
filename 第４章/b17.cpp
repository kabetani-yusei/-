#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define f64 double
#define ll long long
const i64 inf = 1e18;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define bsearch(a,x) distance(a.begin(), lower_bound(all(a), x))
#define all(a) a.begin(),a.end()
#define overload(_1,_2,_3,_4,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define _rep4(i,a,b,c) for(int i = (a); i < (b); i += (c))
#define rep(...) overload(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep2(i,n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep3(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define _rrep4(i,a,b,c) for(int i = (b) - 1; i >= (a); i -= (c))
#define rrep(...) overload(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; i64 cost; Edge(int to, i64 cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(n) cin >> h[i];
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);  
    rep(i,2,n) dp[i] = min(dp[i-2] + abs(h[i]-h[i-2]), dp[i-1] + abs(h[i]-h[i-1]));
    
    int p = n-1;
    vector<int> ans;
    while(true){
        ans.push_back(p+1);
        if(p == 0) break;
        if(dp[p-1] + abs(h[p]-h[p-1]) == dp[p]) p--;
        else p -= 2;
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    rep(ans.size()) cout << ans[i] << " ";
    cout << endl;
    return 0;
}   