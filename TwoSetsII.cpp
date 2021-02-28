#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define ll long long int
#define ull  unsigned long long
#define lcm(a,b) a*b/__gcd(a,b)
#define gcd(a,b) __gcd(a,b)

//vectors & pairs
#define all(a) a.begin(),a.end()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define vi  vector<int>
#define vll  vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define vp vector<pair<int,int>>
#define mp make_pair
#define sortVA(a) sort(a.begin(),a.end())
#define sortVD(a) sort(a.rbegin(),a.rend())

//map
#define f first
#define s second
#define mapit unordered_map<int,int>:: iterator

//constants
#define PIE 3.1415926536
#define MOD 1000000007
#define MAX (1e9 + 5)
#define MIN -(1e9 + 5)
#define endl "\n"

//loop
#define ff(i,s,e) for(i=s; i<e; i++)
#define rff(i,s,e) for(i=e; i>=s; i--)
#define vff(a) for(auto x: a)
#define read(a) for(auto &x: a) cin>>x;
#define put(a) for(auto &x: a) cout<<x<<" "; cout<<endl;

// global variables
int i,j;

//helper functions
ll ceil_div(ll x, ll y){
    return (x + y - 1) / y;
}

int fast_pow(int a, int p) {
    int res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = a * 1ll * a % MOD;
            p /= 2;
        }
        else {
            res = res * 1ll * a % MOD;
            p--;
        }
    }
    return res;
}
// void modInverse(int a, int m){
//     return fast_pow(a, m - 2, m);
// }

ll mod_divide(ll a, ll b) {
    return ((a%MOD)*(fast_pow(b,MOD-2)%MOD))%MOD;
}

//coding starts here
void test_cases(){

    int n;
    cin>>n;

    int sum=((n*(n+1))/2);
    if(sum%2!=0){
        cout<<0<<endl;
        return;
    }
    sum/=2;
    vi a(n);
    ff(i,0,n){
        a[i]=i+1;
    }
    // vector<vector<bool>> dp(n+1, vector<bool>(sum+1,false));
    ll dp[n+1][sum+1];
    ff(i,0,n+1){
        ff(j,0,sum+1){
            dp[i][j]=0;
        }
    }
    ff(i,0,n){
        dp[i][0]=1;
    }

    dp[1][1]=1;
    ff(i,2,n+1){
        ff(j,1,sum+1){
            if(j>=a[i-1]){
                dp[i][j] = (dp[i-1][j-a[i-1]] + dp[i-1][j])%MOD;
            }
            else{
                dp[i][j]=(dp[i-1][j])%MOD;
            }
        }
    }

    cout<<(mod_divide(1,2)*dp[n][sum])%MOD<<endl;
    return;
}

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    // cin>>T;
    while(T--){
        test_cases();
    }
    return 0;
}
