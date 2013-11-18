#include <stdio.h>
#include <string.h>

#define MEMSIZE 30000
#define INBUF   100000

int main(void)
{
	unsigned char buffer_entrada[INBUF];
	unsigned char memoria[MEMSIZE];
	int ptr_in, ptr_mem, len_in;
	int n, i;
	char c;
	
	
	scanf ("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		printf ("Instancia %d\n", i);
		
		ptr_in = 0;
		ptr_mem = 0;
		bzero(memoria, MEMSIZE);
		
		scanf("%s%*[\r\n]", buffer_entrada);
		len_in = strlen(buffer_entrada);
		
		while ((scanf ("%c", &c) != EOF) && (c != '\n'))
		{
			switch (c)
			{
				case '>':
					ptr_mem++;
				break;

				case '<':
					ptr_mem--;
				break;
				
				case '+':
					memoria[ptr_mem]++;
				break;
				
				case '-':
					memoria[ptr_mem]--;
				break;
				
				case '.':
					putc(memoria[ptr_mem], stdout);
				break;
				
				case ',':
					if (ptr_in < len_in)
						memoria[ptr_mem] = buffer_entrada[ptr_in++];
					else
						memoria[ptr_mem] = 0;
				break;

				case '[':
				break;
				
				case ']':
				break;

				case '#':
				break;				
			}
		}
		
		printf ("\n\n");
	}
	
	return 0;
}
