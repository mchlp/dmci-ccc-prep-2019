#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[1000000];

bool dfs(int start, int end) {
    bool visited[1000000];
    memset(visited, false, sizeof visited);
    stack<int> stack;
    stack.push(start);
    while (!stack.empty()) {
        int cur = stack.top();
        stack.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int visit = graph[cur][i];
            if (!visited[visit]) {
                if (visit == end) {
                    return true;
                }
                stack.push(visit);
            }
        }
    }
    return false;
}

int main() {

    scanf("%d%d", &N, &M);
    for (int _ = 0; _ < M; _++) {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[y].push_back(x);
    }

    int p, q;
    scanf("%d%d", &p, &q);

    if (dfs(p, q)) {
        printf("no");
    } else if (dfs(q, p)) {
        printf("yes");
    } else {
        printf("unknown");
    }

    return 0;
}