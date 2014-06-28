#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
	int N, D;

	while (1) {
		cin >> N;
		if (!N) break;

		int qt = 0, r;
		while (N--) {
			qt = 0;
			for (int i = 0; i < 5; ++i) {
				cin >> D;
				if (D <= 127) {
					qt++;
					r = i;
				}
			}
			if (qt == 1) printf ("%c\n", 'A' + r);
			else printf ("*\n");
		}

	}

	return 0;
}

