#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

int N;

int graph[MAXN];
int dp[MAXN];

int bfs(int start, int end) {
    memset(dp, -1,  sizeof dp);
    queue<int> queue;
    queue.push(start);
    dp[start] = -1;
    while (!queue.empty()) {
        int cur = queue.front();
        int check = graph[cur];
        if (dp[check] == -1) {
            queue.push(check);
            dp[check] = dp[cur] + 1;
            if (check == end) {
                return dp[check];
            }
        }
        queue.pop();
    }
    return -1;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a] = b;
    }

    while (1) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) {
            return 0;
        }
        int dis = bfs(a, b);
        if (dis == -1) {
            printf("No\n");
        } else {
            printf("Yes %d\n", dis);
        }
    }
}