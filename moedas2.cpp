#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

typedef struct
{
        int qtd, valor;
} contador;

int main()
{
        int m, n, v, i, moedas[110];

        scanf("%d", &m);
        while(m != 0)
        {
                scanf("%d", &n);

                i=0;
                while(i<n)
                {
                        scanf("%d", &v);
                        moedas[i] = v;
                        i++;
                }

                contador c;
                c.qtd = 0;
                c.valor = 0;
                
                queue<contador> fila;
                fila.push(c);

                while(fila.empty() == false)
                {
                        c = fila.front();
                        fila.pop();
                        for(int i=0; i<n; i++)
                        {
                                contador t = c;
                                t.qtd++;
                                t.valor += moedas[i];

                                if(t.valor < m)
                                {
                                        fila.push(t);
                                }
                                else if(t.valor == m)
                                {
                                        printf("%d\n", t.qtd);
                                        goto saida;
                                }
                        }
                }

                printf("Impossivel\n");

saida:
                scanf("%d", &m);
        }
        return 0;
}
