#include <cstdio>
#include <cstring>
#include <queue>

#define ZERO(x) memset(x, 0, sizeof(x))

using namespace std;



int main(void)
{
	int r, c, k, i, f, b;
	char s[301][301], v[301], h[301];
	
	while (1)
	{
		scanf ("%d %d %d", &r, &c, &k);
		if (!r && !c && !k) break;

		ZERO(v); ZERO(h);
		
		for (i = 0; i < r; i++)
			scanf ("%s", s[i]);

		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++) {
				if (s[i][j] == '.') {
					h[i]++;
					v[j]++;
				}
			}
			
		
	}

	return 0;
}

