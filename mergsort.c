#include <stdio.h>

int vec[100001];

int main(void)
{
    int n, qt = 0;

    while (scanf("%d", &n) != EOF) {
        vec[n]++;
        qt++;
    }

    n = 1;
    while (qt) {
        while (vec[n]) {
            printf("%d ", n);
            vec[n]--;
            qt--;
        }
        n++;
    }

    return 0;
}

