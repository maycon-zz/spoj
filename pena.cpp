#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Task {
	int id, pts, stime, etime;
	int start_h, start_m, end_h, end_m;
	char week[4];
};

int weekid(char *w) {
	switch(w[0]) {
		case 'S': return (w[2] == 'g' ? 0 : 4);
		case 'T': return 1;
		case 'Q': return (w[2] == 'a' ? 2 : 3);
	}
}

int fulltime_s(Task T) {
	return weekid(T.week)*60*24 + (T.start_h*60 + T.start_m);
}

int fulltime_e(Task T) {
	return weekid(T.week)*60*24 + (T.end_h*60 + T.end_m);
}

bool operator<(const Task &a, const Task &b) {
	return a.stime < b.stime;
}

int main(void)
{
	int n;
	int w[5];

	while (scanf("%d", &n) != EOF && n) {
		vector<Task> T(n);
		for (int i = 0; i < n; i++) {
			scanf ("%d %d %s %d:%d %d:%d", &T[i].id, &T[i].pts, T[i].week,
					&T[i].start_h, &T[i].start_m, &T[i].end_h, &T[i].end_m);
			T[i].stime = fulltime_s(T[i]);
			T[i].etime = fulltime_e(T[i]);
		}

		sort(T.begin(), T.end());

		memset(w, 0, sizeof(w));

		int last = T[0].etime;


		for (int i = 0; i < n; i++) {
			printf ("%d %d %s %d:%d %d:%d\n", T[i].id, T[i].pts, T[i].week,
					T[i].start_h, T[i].start_m, T[i].end_h, T[i].end_m);
		}
		printf ("\n");
	}

	return 0;
}

