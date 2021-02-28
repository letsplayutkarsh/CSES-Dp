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
int i,j,n;
ll dp[5005][5005];
vi a(5005);

//helper functions
ll ceil_div(ll x, ll y){
    return (x + y - 1) / y;
}

ll recurse(ll l,ll r){

    if(l > r)
        return 0;
        
    if(dp[l][r] != -1)
        return dp[l][r];

    ll op1 = a[l] + min(recurse(l+2,r), recurse(l+1,r-1) );
    ll op2 = a[r] + min(recurse(l+1,r-1), recurse(l,r-2) );

    return dp[l][r] = max(op1,op2);
}


//coding starts here
void test_cases(){

    cin>>n;
    ff(i,0,n){
        cin>>a[i];
    }
    ff(i,0,5000){
        ff(j,0,5000){
            dp[i][j]=-1;
        }
    }
    cout<<recurse(0,n-1)<<endl;

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
    cout.tie(NULL);
    test_cases();
    return 0;
}
