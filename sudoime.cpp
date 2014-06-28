#include <cstdio>
#include <cstring>

using namespace std;

#define FULL ((1 << 9) - 1)

int main(void)
{
    int t, v, bitval;
    int linhas[10], colunas[10], blocos[4][4];
    
    scanf ("%d", &t);
    for (int inst = 1; inst <= t; inst++)
    {
        memset(linhas, 0, sizeof(linhas));
        memset(colunas, 0, sizeof(colunas));
        memset(blocos, 0, sizeof(blocos));
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                scanf("%d", &v);
                bitval = 1 << (v - 1);
                linhas[i] += bitval;
                colunas[j] += bitval;
                blocos[i/3][j/3] += bitval;
            }
        }

        int err = 0;
        for (int i = 0; i < 9; i++)
        {
            if ((linhas[i] != FULL) || (colunas[i] != FULL) || (blocos[i/3][i%3] != FULL))
            {
                printf ("Instancia %d\nNAO\n\n", inst);
                err = 1;
                break;
            }
        }
        
        if (!err)
        {
            printf ("Instancia %d\nSIM\n\n", inst);
        }
    }
    
    return 0;
}
