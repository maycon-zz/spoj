#include <cstdio>
#include <cstring>
#include <queue>

#define ZERO(x) memset(x, 0, sizeof(x))

using namespace std;


int func(char *s, int len, int n)
{
	int i = 0, q = 0, r;
	queue<int> pos;

	while ((q < n) && (i < len)) {
		if (s[i] == '.') {
			q++;
			pos.push(i);
		}
		i++;
	}

	if (q != n) return 0;

	r = i;
	while (i < len) {
		if (s[i] == '.') {
			pos.pop();
			r = min(r, i - pos.front() + 1);
			printf ("%d %d\n", i, pos.front());
			pos.push(i);
		}
		i++;
	}

	return r;
}

int main(void)
{
	int r, c, k, i, f;
	char s[301][301], v[301], h[301];
	
	while (1)
	{
		scanf ("%d %d %d", &r, &c, &k);
		
		ZERO(v);
		ZERO(h);
	}

	return 0;
}

