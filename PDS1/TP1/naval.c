#include <stdio.h>
int main (void)
{
    //define os tabuleiros iniciais dos 2 jogadores, apenas com água(~)
    char tab1[20][20];
    int i, j;
    for(i=0; i<20; i++){
       for(j=0; j<20; j++)
         tab1[i][j]= '~'; }
    char tab2[20][20];
    int l, m;
    for(l=0; l<20; l++){
       for(m=0; m<20; m++)
         tab2[l][m]= '~';  }

    //obtem a quantidade N de navios que cada jogador posicionará
    int N;
    printf("digite o numero de navios por jogador\n");
    do{scanf(" %d", &N);} while (N<0);//impede que N seja negativo

    //posiciona os navios do jogador 1
    printf("insira as coordenadas x e y, o tipo e a orientação dos navios do jogador 1: \n");
    int contador1;
    char tipo1, orientacao1;
    for(contador1=0; contador1<N; contador1++)
    {
        scanf("%d %d %c %c", &i, &j, &tipo1, &orientacao1);
        switch (tipo1)
        {
        case 'C': {tab1[i][j]='C';
                     if(orientacao1=='V')
                     {
                        tab1[i+1][j]='C';
                        tab1[i-1][j]='C';
                     }
                     if(orientacao1=='H')
                     {
                        tab1[i][j+1]='C';
                        tab1[i][j-1]='C';
                     }
                  }
         break;
         case 'E': {tab1[i][j]='E';
                     if(orientacao1=='V')
                     {
                        tab1[i+1][j]='E';
                        tab1[i+2][j]='E';
                        tab1[i-1][j]='E';
                        tab1[i-2][j]='E';
                     }
                     if(orientacao1=='H')
                     {
                        tab1[i][j+1]='E';
                        tab1[i][j+2]='E';
                        tab1[i][j-1]='E';
                        tab1[i][j-2]='E';
                     }
                   }
         break;
         case 'P': {tab1[i][j]='P';
                     if(orientacao1=='V')
                     {
                        tab1[i+1][j]='P';
                        tab1[i+2][j]='P';
                        tab1[i+3][j]='P';
                        tab1[i-1][j]='P';
                        tab1[i-2][j]='P';
                        tab1[i-3][j]='P';
                     }
                     if(orientacao1=='H')
                     {
                        tab1[i][j+1]='P';
                        tab1[i][j+2]='P';
                        tab1[i][j+3]='P';
                        tab1[i][j-1]='P';
                        tab1[i][j-2]='P';
                        tab1[i][j-3]='P';
                     }
                   }
         break;
        }
    }

    //posiciona os navios do jogador 2
    printf("insira as coordenadas x e y, o tipo e a orientação dos navios do jogador 2: \n");
    int contador2;
    char tipo2, orientacao2;
    for(contador2=0; contador2<N; contador2++)
    {
        scanf("%d %d %c %c", &l, &m, &tipo2, &orientacao2);
        switch (tipo2)
        {
        case 'C': {tab2[l][m]='C';
                     if(orientacao2=='V')
                     {
                        tab2[l+1][m]='C';
                        tab2[l-1][m]='C';
                     }
                     if(orientacao2=='H')
                     {
                        tab2[l][m+1]='C';
                        tab2[l][m-1]='C';
                     }
                  }
         break;
         case 'E': {tab2[l][m]='E';
                     if(orientacao2=='V')
                     {
                        tab2[l+1][m]='E';
                        tab2[l+2][m]='E';
                        tab2[l-1][m]='E';
                        tab2[l-2][m]='E';
                     }
                     if(orientacao2=='H')
                     {
                        tab2[l][m+1]='E';
                        tab2[l][m+2]='E';
                        tab2[l][m-1]='E';
                        tab2[l][m-2]='E';
                     }
                   }
         break;
         case 'P': {tab2[l][m]='P';
                     if(orientacao2=='V')
                     {
                        tab2[l+1][m]='P';
                        tab2[l+2][m]='P';
                        tab2[l+3][m]='P';
                        tab2[l-1][m]='P';
                        tab2[l-2][m]='P';
                        tab2[l-3][m]='P';
                     }
                     if(orientacao2=='H')
                     {
                        tab2[l][m+1]='P';
                        tab2[l][m+2]='P';
                        tab2[l][m+3]='P';
                        tab2[l][m-1]='P';
                        tab2[l][m-2]='P';
                        tab2[l][m-3]='P';
                     }
                   }
        break;
        }
    }

    //obtem a quantidade de rodadas na partida
    int M;
    printf("Digite a quantidade de rodadas na partida: \n");
    do{scanf("%d", &M);} while (M<0); //impede que M seja negativo

    //realiza os ataques, calcula seus resultados e a pontuação dos jogadores
    int rodadas=0, pontos1=0, pontos2=0;
    for(; rodadas<M; rodadas++)
    {
        printf("ataque jogador 1: ");
        scanf ("%d %d", &l, &m); //lê uma posição do tabuleiro 2
        switch(tab2[l][m])
        {
            case 'C': pontos1+=2;
            break;
            case 'E': pontos1+=5;
            break;
            case 'P': pontos1+=10;
            break;
        }
        tab2[l][m]='O';
        printf("ataque jogador 2: ");
        scanf("%d %d", &i, &j); //lê uma posição do tabuleiro 1
        switch(tab1[i][j])
        {
            case 'C': pontos2+=2;
            break;
            case 'E': pontos2+=5;
            break;
            case 'P': pontos2+=10;
            break;
        }
        tab1[i][j]='O';
    }

    //imprime os tabuleiros
      printf("TABULEIRO JOGADOR 1\n");
      for(i=0; i<20; i++){
          for(j=0; j<20; j++)
          {printf("%2c", tab1[i][j]);}
            printf("\n");}
      printf("TABULEIRO JOGADOR 2\n");
      for(l=0; l<20; l++){
          for(m=0; m<20; m++)
          {printf("%2c", tab2[l][m]);}
            printf("\n");}

    //checa a pontuação e imprime a mensagem sobre o vencedor
    if(pontos1==pontos2)
    {
        printf("O jogo terminou empatado em %d pontos.\n", pontos1);
    }
    else
    {
        if(pontos1>pontos2)
          printf("O jogador 1 venceu com %d pontos, contra %d pontos do jogador 2.\n", pontos1, pontos2);
        else
          printf("O jogador 2 venceu com %d pontos, contra %d pontos do jogador 1.\n", pontos2, pontos1);
    }
}
