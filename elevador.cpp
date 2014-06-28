#include <cstdio>
#include <cmath>

#define pow2(a) ((a)*(a))

int main(void)
{
    int l, c, r1, r2;

    while (1)
    {
        scanf ("%d %d %d %d", &l, &c, &r1, &r2);
        if (!l) break;

        int c1x = r1;
        int c1y = r1;
        int c2x = l-r2;
        int c2y = c-r2;

        if (2*r1 > l || 2*r1 > c) { puts("N"); continue; }
        if (2*r2 > l || 2*r2 > c) { puts("N"); continue; }

        int dx = c2x-c1x;
        int dy = c2y-c1y;

        int dist_sq = (dx)*(dx) + (dy)*(dy);
        int min_dist = r1+r2;

        if (dist_sq < min_dist*min_dist) puts("N");
        else puts("S");
    }

    return 0;

}

