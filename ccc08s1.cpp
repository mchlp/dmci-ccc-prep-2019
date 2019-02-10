#include <bits/stdc++.h>

using namespace std;

int main() {
    char city[257];
    int minTemp = INT_MAX;
    char minCity[257];
    do {
        int temp;
        scanf("%s %d", &city[0], &temp);
        if (temp < minTemp) {
            minTemp = temp;
            strcpy(minCity, city);
        }
    } while (strcmp(city, "Waterloo") != 0);
    printf("%s", minCity);
    return 0;
}