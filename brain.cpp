#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

#define MEM 30000
#define TAM 100001

int main(void)
{
	unsigned char mem[MEM];;
	char param[TAM], code[TAM], out[TAM], c;
	int idx_mem, idx_param, idx_code, idx_out;
	int N, sz, sz_param;

	stack<int> S;

	scanf ("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		printf ("Instancia %d\n", i);
		memset(mem, 0, sizeof(mem));

		idx_code = idx_param = idx_mem = idx_out = 0;

		scanf ("%s %s", param, code);

		sz = strlen(code);
		sz_param = strlen(param);

		idx_code = 0;
		while (idx_code < sz)
		{
			switch (code[idx_code])
			{
				case '<': idx_mem--; break;
				case '>': idx_mem++; break;
				case '+': ++mem[idx_mem]; break;
				case '-': --mem[idx_mem]; break;
				case '.': putc(mem[idx_mem], stdout); break;
				case ',': mem[idx_mem] = (idx_param < sz_param ? param[idx_param++] : 0); break;
				case '[':
						   if (!mem[idx_mem]) {
							   int qt = 1;
							   while (qt && (++idx_code < sz)) {
								   if (code[idx_code] == '[') qt++;
								   else if (code[idx_code] == ']') qt--;
							   }
						   }
						   else S.push(idx_code); 
						   break;
				case ']':
						   if (S.size()) {
							   if (mem[idx_mem]) idx_code = S.top();
							   else S.pop();
						   }
						   break;
				case '#':
						   for (int j = 0; j < 10; j++)
							   printf ("%c", mem[j]);
						   break;
			}
			idx_code++;
		}

		printf ("\n\n");
	}

	return 0;
}

