#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

// helping defines
#define ll long long int
#define ull  unsigned long long
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)
#define lcm(a,b) a*b/__gcd(a,b)
#define gcd(a,b) __gcd(a,b)
#define sortD(a,n)  sort(a,a+n,greater<int>())
#define sortA(a,n)  sort(a,a+n)

//vectors & pairs
#define sv(a) sort(a.begin(),a.end())
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define vi  vector<int>
#define vll  vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define vp vector<pair<int,int>>
#define mp make_pair
#define ii pair<int,int>
#define sortVA(a) sort(a.begin(),a.end())
#define sortVD(a) sort(a.rbegin(),a.rend())

//map
#define um unordered_map
#define f first
#define s second
#define mapit unordered_map<int,int>:: iterator

//constants
#define pi 3.1415926536
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

//coding starts here
void test_cases(){

    int n,m;
    cin>>n>>m;
    vi a(n);
    read(a);
    int dp[n][m+2];
    ff(i,0,n){
        ff(j,0,m+2){
            dp[i][j]=0;
        }
    }

    if(a[0]==0){
        ff(j,1,m+1){
            dp[0][j]=1;
        }
    }
    else{
        dp[0][a[0]]=1;
    }

    ff(i,1,n){
        if(a[i]==0){
            ff(j,1,m+1){
                dp[i][j]=((dp[i-1][j]+dp[i-1][j+1])%MOD+dp[i-1][j-1])%MOD;
            }
        }
        else{
            dp[i][a[i]]=((dp[i-1][a[i]]+dp[i-1][a[i]+1])%MOD+dp[i-1][a[i]-1])%MOD;
        }
    }

    if(a[n-1]!=0){
        cout<<dp[n-1][a[n-1]]<<endl;
    }
    else{
        int ans=0;
        ff(i,1,m+1){
            ans=(ans+dp[n-1][i])%MOD;
        }
        cout<<ans<<endl;
    }
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
