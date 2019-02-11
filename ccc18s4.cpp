#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, ll> dp;

ll go(int n){
    if(dp[n])
        return dp[n];
    ll ret = 0;
    for(int f = n,w,nx; f > 1; f = nx){
        w = n/f;
        nx = n/(w+1);
        ret += (f-nx)*go(w);
    }
    return dp[n] = ret;
}

int main(){
    
    dp[1] = 1;
    
    int n;
    scanf("%d", &n);
    
    printf("%lld\n", go(n));
    
    return 0;
}
