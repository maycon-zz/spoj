#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;


int main(void)
{
    int n, a, b, r, e;

    while (scanf ("%d", &n) != EOF) {
        vii focos;

        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &a, &b);
            focos.push_back(make_pair(a, b));
        }

        sort(focos.begin(), focos.end());

        r = 1;
        __typeof(focos.begin()) it = focos.begin();

        while (it != focos.end()) {
            e = it->second;
            while (it != focos.end() && it->first <= e) it++;
            if (it != focos.end()) r++;
        }


        printf ("%d\n", r);
    }

    return 0;

}

