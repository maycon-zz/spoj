#include <stdio.h>
#include <string.h>

#define MAX_TAM_NOME 20
#define MAX_PROBLEMAS 10

int main(void)
{
	int i, n;
	char nome[MAX_TAM_NOME+1], nome_reprovado[MAX_TAM_NOME+1];
	int qt_problemas, qt_problemas_reprovado;
	
	i = 1;
	while (scanf("%d", &n) != EOF)
	{
		qt_problemas_reprovado = MAX_PROBLEMAS+1;
		while (n--)
		{
			scanf ("%s %d", nome, &qt_problemas);
			
			if (qt_problemas < qt_problemas_reprovado)
			{
				qt_problemas_reprovado = qt_problemas;
				strcpy(nome_reprovado, nome);
			}
			else if ((qt_problemas == qt_problemas_reprovado) && (strcmp(nome, nome_reprovado) > 0))
			{
				strcpy(nome_reprovado, nome);
			}
		}
		
		printf ("Instancia %d\n%s\n\n", i++, nome_reprovado);
	}
	
	return 0;
}
