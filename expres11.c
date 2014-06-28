#include <stdio.h>
#include <string.h>

int MAX = 1000001;

int main(void)
{
    char pilha[MAX];
    char in[MAX], inv;
    int t, tam, i, pos, err;

    scanf ("%d", &t);
    while (t--) {
        scanf("%s", in);
        tam = strlen(in);

        pos = err = 0;
        for (i = 0; i < tam; i++) 
        {
            if (strchr("([{", in[i])) {
                pilha[pos++] = in[i];
            } else {
                inv = (in[i] == ')' ? '(' : (in[i] == ']' ? '[' : '{'));
                if ((pos == 0) || (pilha[--pos] != inv)) {
                    err = 1;
                    break;
                }
            }
        }
        if ((pos > 0) || err) {
            puts("N");
        } else {
            puts("S");
        }
    }

    return 0;

}

