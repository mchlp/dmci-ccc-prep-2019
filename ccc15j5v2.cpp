#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[252][252][252];

int recur(int pieLeft, int maxPie, int pplLeft) {
    if (dp[pieLeft][maxPie][pplLeft] == -1) {
        if (pieLeft == 0) {
            dp[pieLeft][maxPie][pplLeft] = 0;
        } else if (pplLeft == 0) {
            dp[pieLeft][maxPie][pplLeft] = 0;
        } else if (pieLeft == 1 && pplLeft != 1) {
            dp[pieLeft][maxPie][pplLeft] = 0;
        } else if (pplLeft == 1) {
            if (pieLeft > maxPie) {
                dp[pieLeft][maxPie][pplLeft] = 0;
            } else {
                dp[pieLeft][maxPie][pplLeft] = 1;
            }
        } else {
            int sum = 0;
            for (int i = min(pieLeft, maxPie); i > 0; i--) {
                sum += recur(pieLeft - i, i, pplLeft - 1);
            }
            dp[pieLeft][maxPie][pplLeft] = sum;
        }
    }
    return dp[pieLeft][maxPie][pplLeft];
}

int main() {
    for (int i = 0; i < 252; i++) {
        for (int j = 0; j < 252; j++) {
            for (int k = 0; k < 252; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    scanf("%d %d", &N, &K);
    printf("%d\n", recur(N, N, K));

    return 0;
}