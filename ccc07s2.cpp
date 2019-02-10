#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> boxes;

int main() {
    scanf("%d", &N);
    for (int _=0; _<N; _++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        vector<int> box;
        box.push_back(a);
        box.push_back(b);
        box.push_back(c);
        sort(box.begin(), box.end());
        boxes.push_back(box);
    }

    scanf("%d", &M);
    for (int _=0; _<M; _++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        vector<int> item;
        item.push_back(a);
        item.push_back(b);
        item.push_back(c);
        sort(item.begin(), item.end());

        bool foundBox = false;
        long long minVol = LONG_LONG_MAX;
        for (int i = 0; i < N; i++) {
            int boxGood = true;
            for (int j = 0; j < 3; j++) {
                if (boxes[i][j] < item[j]) {
                    boxGood = false;
                    break;
                }
            }
            if (boxGood) {
                foundBox = true;
                if (boxes[i][0] * boxes[i][1] * boxes[i][2] < minVol) {
                    minVol = boxes[i][0] * boxes[i][1] * boxes[i][2];
                }
            }
        }
        if (foundBox) {
            printf("%lld\n", minVol);
        } else {
            printf("Item does not fit.\n");
        }
    }

}