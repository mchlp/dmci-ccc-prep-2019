#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> edges;
bool graph[101][101];
bool visited[101];

bool bfs() {
    memset(visited, false, sizeof visited);
    queue<int> queue;
    queue.push(1);
    visited[1] = true;
    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        for (int i = 1; i <= N; i++) {
            if (graph[cur][i] && !visited[i]) {
                queue.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i=1; i<=N; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int NUM_CASES = 5;
    while (NUM_CASES--) {
        edges.clear();
        fill(&graph[0][0], &graph[0][0] + sizeof graph, false);
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[b][a] = true;
            graph[a][b] = true;
            edges.push_back(make_pair(a, b));
        }

        int bridgeCount = 0;
        for (int i = 0; i<edges.size(); i++) {
            int e1 = edges[i].first;
            int e2 = edges[i].second;
            graph[e1][e2] = false;
            graph[e2][e1] = false;

            if (!bfs()) {
                bridgeCount++;
            }

            graph[e1][e2] = true;
            graph[e2][e1] = true;
        }

        printf("%d\n", bridgeCount);
    }
}