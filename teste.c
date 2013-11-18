
#include <stdio.h>
int main(void){
  /*declaração de variáveis:
    V -> valor da aposta
    N -> número que o jogador escolhe
    M -> número sorteado
    aux -> valor referente aos 4,3,2 ultimos dígitos de N para podermos fazer os testes
    aux2 -> alor referente aos 4,3,2 ultimos dígitos de M para podermos fazer os testes
    premio -> valor do premio final do apostador
    bicho -> verificação dos grupos dos bichos no final
  */
  int V,N,M;
  int aux,aux2,premio,bicho;
  scanf("%d %d %d",&V,&N,&M);
  /*laço de parada, se o usuário entrar com 0 0 0, o laço se encerrará e o programa
  acabará*/
  while(V != 0 || N != 0 || M != 0){
    /*inicia-se as variáveis com o valor 0*/
    premio = aux = aux2 = 0;
    /*aux recebe os 4 ultimos digitos da variável N
    aux2 recebe os 4 ultimos digitos da variavel M*/
    aux = N%10000;
    aux2 = M%10000;
    /*se os 4 ultimos digitos são iguais então o premio recebe o valor da aposta
    multiplicado por 3000*/
    if(aux == aux2){
      premio = V*3000;
    }
    else{
      /*senão, aux recebe os 3 ultimos digitos da variável N 
      aux2 recebe os 4 ultimos digitos da variável M*/
      aux = N%1000;
      aux2 = M%1000;
      /*se os 3 ultimos digitos são iguais então o premio recebe o valor da aposta
      multiplicado por 500*/
      if(aux == aux2){
        premio = V*500;
      }
      else{
        /*senão, aux recebe os 2 ultimos digitos da variável N 
        aux2 recebe os 2 ultimos digitos da variável M*/
        aux = N%100;
        aux2 = M%100;
        /*se os 2 ultimos digitos são iguais então o premio recebe o valor da aposta
        multiplicado por 50*/
        if(aux == aux2){
          premio = V*50;
        }
        else{
        /*senão, temos que verificar se eles são do mesmo grupo, assim
        se aux ou aux2 forem iguais a zero, eles sao mudados pra 100 para poder
        fazer os calculos referentes ao grupo dos bichos*/
          if(aux == 0 || aux2 == 0){
              if(aux == 0){
                aux = 100;
              }
              else{
                aux2 = 100;
              }
          }
          else{
          /*a variavel bicho recebe o valor do resto da divisao de aux por 4, desse modo
          os unicos valores possiveis para bicho são: 0,1,2,3
          assim podendo fazer a verificação referente ao grupo dos bichos*/
            bicho = aux%4;
            if(bicho == 0){
              /*se bicho é igual a zero, quer dizer que a variável aux refere-se a um bicho onde
              seu valor é o ultimo do grupo, assim sendo, para aux e aux2 serem do mesmo grupo
              aux2 tem que ser no maximo 3 unidades menor que aux*/
              if(aux2<aux && aux2>aux-4){
                premio = V*16;
              }
            }
            else if(bicho == 3){
              /*se bicho é igual a três, quer dizer que a variável aux refere-se a um bicho onde
              seu valor é o penultimo do grupo, assim sendo, para aux e aux2 serem do mesmo grupo
              aux2 tem que ser no maximo 2 unidades menor que aux e 1 unidade maior que aux*/
              if(aux2<aux+2 && aux2>aux-3){
                premio = V*16;
              }
            }
            else if(bicho == 2){
              /*se bicho é igual a dois, quer dizer que a variável aux refere-se a um bicho onde
              seu valor é o segundo do grupo, assim sendo, para aux e aux2 serem do mesmo grupo
              aux2 tem que ser no maximo 1 unidade menor que aux e 2 unidades maior que aux*/
              if(aux2<aux+3 && aux2>aux-2){
                premio = V*16;
              } 
            }
            else{
              /*se bicho é igual a 1, quer dizer que a variável aux refere-se a um bicho onde
              seu valor é o primeiro do grupo, assim sendo, para aux e aux2 serem do mesmo grupo
              aux2 tem que ser no maximo 3 unidades maior que aux*/
              if(aux2>aux && aux2<aux+4){
                premio = V*16;
              }
            }
            /*se tudo for falso, então eles não estão no mesmo grupo, assim o premio vale zero*/
          }
        }       
      }
    }
    /*imprime o premio e lê as variáveis novamente*/
    printf("%d\n",premio);
    scanf("%d %d %d",&V,&N,&M);
  }
  return 0;
}

