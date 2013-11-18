#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, v;
	priority_queue<int> ranking;
	
	scanf ("%d %d\n", &n, &m);
	
	while (n--)
	{
		scanf ("%d", &v);
		ranking.push(v);
	}
	
	while (m--)
	{
		printf ("%d\n", ranking.top());
		ranking.pop();
	}
	
	return 0;
}
