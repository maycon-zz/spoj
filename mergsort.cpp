#include <stdio.h>
#include <vector>
#include <algorithm>

#define EACH(it,x) for(__typeof((x).begin()) it =  (x).begin(); it != (x).end(); it++)

using namespace std;

int main(void)
{
    vector<int> vec;
    int n;

    while (scanf("%d ", &n) != EOF) {
        vec.push_back(n);
    }

    sort(vec.begin(), vec.end());

    EACH(it, vec) {
        printf ("%d ", *it);
    }

    return 0;
}

