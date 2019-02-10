#include<bits/stdc++.h>

using namespace std;

char graph[101][101];
int res[101][101];
deque<pair<int, int>> q;
int ways[4][2] = {{1,  0},
                  {-1, 0},
                  {0,  1},
                  {0,  -1}};

void spread(int x, int y) {
    int i = x;
    while (graph[i][y] != 'W') {
        if (graph[i][y] == '.' || graph[i][y] == 'S') {
            graph[i][y] = 'V';
        }
        i++;
    }
    i = x;
    while (graph[i][y] != 'W') {
        if (graph[i][y] == '.' || graph[i][y] == 'S') {
            graph[i][y] = 'V';
        }
        i--;
    }
    int j = y;
    while (graph[x][j] != 'W') {
        if (graph[x][j] == '.' || graph[x][j] == 'S') {
            graph[x][j] = 'V';
        }
        j++;
    }
    j = y;
    while (graph[x][j] != 'W') {
        if (graph[x][j] == '.' || graph[x][j] == 'S') {
            graph[x][j] = 'V';
        }
        j--;
    }
}

int main() {

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            res[i][j] = -1;
        }
    }

    int N, M;
    pair<int, int> start;
    scanf("%d %d\n", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c = '0';
            do {
                scanf("%c", &c);
            } while (c == '\n');
            if (c == 'S') {
                start.first = i;
                start.second = j;
                res[i][j] = 0;
            }
            graph[i][j] = c;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 'C') {
                spread(i, j);
            }
        }
    }

    q.push_back(start);
    if (graph[start.first][start.second] == 'S') {
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop_front();

            for (int w = 0; w < 4; w++) {

                bool left = graph[cur.first][cur.second] == 'L';
                bool right = graph[cur.first][cur.second] == 'R';
                bool up = graph[cur.first][cur.second] == 'U';
                bool down = graph[cur.first][cur.second] == 'D';
                bool any = graph[cur.first][cur.second] == '.' || graph[cur.first][cur.second] == 'S';

                if (cur.first == 2 && cur.second == 59) {
                    printf("\n");
                }

                if ((w == 0 && (down | any)) || (w == 1 && (up | any)) || (w == 2 && (right | any)) ||
                    (w == 3 && (left | any))) {
                    int newX = cur.first + ways[w][0];
                    int newY = cur.second + ways[w][1];

                    if (res[newX][newY] == -1) {
                        if (graph[newX][newY] == 'L') {
                            res[newX][newY] = res[cur.first][cur.second];
                            q.push_front(pair<int, int>(newX, newY));
                        } else if (graph[newX][newY] == 'R') {
                            res[newX][newY] = res[cur.first][cur.second];
                            q.push_front(pair<int, int>(newX, newY));
                        } else if (graph[newX][newY] == 'U') {
                            res[newX][newY] = res[cur.first][cur.second];
                            q.push_front(pair<int, int>(newX, newY));
                        } else if (graph[newX][newY] == 'D') {
                            res[newX][newY] = res[cur.first][cur.second];
                            q.push_front(pair<int, int>(newX, newY));
                        } else if (graph[newX][newY] == '.') {
                            res[newX][newY] = res[cur.first][cur.second] + 1;
                            q.push_back(pair<int, int>(newX, newY));
                        } else {
                            continue;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == '.') {
                printf("%d\n", res[i][j]);
            } else if (graph[i][j] == 'V' && !(i ==start.first && j == start.second)) {
                printf("-1\n");
            }
        }
    }

    return 0;
}