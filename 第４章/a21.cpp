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
    vector<int> p(n+1), a(n+1);
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    rep(i,1,n+1) cin >> p[i] >> a[i];
    dp[1][n] = 0;
    for(int len = n-2;len>=0;len--){
        for(int l =1;l<=n-len;l++){
        int r = l+len;
            int score1 = 0, score2 = 0;
            if(l<=p[l-1] && p[l-1]<=r) score1 = a[l-1];
            if(l<=p[r+1] && p[r+1]<=r) score2 = a[r+1];
            if(l == 1) dp[l][r] = dp[l][r+1] + score2;
            else if(r == n)dp[l][r] = dp[l-1][r] + score1;
            else dp[l][r] = max(dp[l-1][r]+score1, dp[l][r+1] + score2);
        }
    }

    int ans = 0;
    rep(i,1,n+1) ans = max(ans, dp[i][i]);
    cout << ans << endl;
    return 0;
}   