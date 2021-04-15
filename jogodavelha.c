#include <stdio.h>
#include <stdlib.h>

void inicializar_matriz(int i, int j, char tab[][3]) // inicializando a matriz e retirando lixo de memoria
{
    if (i < 3){
        if (j < 3){
            tab[i][j] = 'q';
            inicializar_matriz(i, j+1, tab);
        }
        else inicializar_matriz(i+1, 0, tab);
    }
}

int isvalid(char letra){  //verificando se a entrada e valida

    if (letra == 'x' || letra == '0'){
        return 1;
    }
    else return 0;
}
int coordenadavalida(int x, int y){  //verificando se a ordenada e valida
    
    if (x < 3 && x >= 0 && y < 3 && y >= 0){
        return 1;
    }
    else return 0;
}


int posicaovazia(int x, int y, char tabuleiro[][3]){  // verificando se a posição é valida
    
    if (tabuleiro[x][y] != 'x' && tabuleiro[x][y] != 'x') {
        return 1;
    }
    else return 0;
    
}

int ganhou_linha(int i, int j, int same, char tabuleiro[][3]){
    
    if (i < 3) {
        if (j < 2)  {
            if (isvalid(tabuleiro[i][j]) && tabuleiro[i][j] == tabuleiro[i][j+1]){
                same+=1;
            }
            
           ganhou_linha(i, j+1, same, tabuleiro);
        }
        else{
           if (same == 3){
               return 1;
           }
          
          ganhou_linha(i+1, 0, 1, tabuleiro);
        } 
    }
    else return 0;
}

int ganhou_Coluna(int i, int j, int same, char tabuleiro[][3]){
    
    if (j < 3){
        if (i < 2){
            if (isvalid(tabuleiro[i][j]) && tabuleiro[i][j] == tabuleiro[i+1][j])
            {
                same+=1;
            }
            
           ganhou_Coluna(i+1, j, same, tabuleiro);
        }
        else{
           if (same == 3) {
               return 1;
           }
          
          ganhou_Coluna(0, j+1, 1, tabuleiro);
        } 
    }
    else return 0;
}

int ganhou_diagprincipal(int i, int same, char tabuleiro[][3]){
    if (i < 2){
        if (isvalid(tabuleiro[i][i]) && tabuleiro[i][i] == tabuleiro[i+1][i+1])    {
            same+=1;
        }
            
        ganhou_diagprincipal(i+1, same, tabuleiro);
    }
    else {
        if (same == 3) return 1;
        else return 0;
    }
    
}

int ganhou_diagsecundaria(int i, int j, int same, char tabuleiro[][3]){
    
    if (i < 2){
        if (j > 0){
            if (isvalid(tabuleiro[i][j]) &&  tabuleiro[i][j] == tabuleiro[i+1][j-1]){
              same+=1;
            }
        }
        ganhou_diagsecundaria(i+1, j-1, same, tabuleiro);
    }
    else {
        if (same == 3) return 1;
        else return 0;
    }
    
}

void imprimir(int i, int j, char tab[][3]){
    
    if (i < 3){
        if (j < 3){
            if (isvalid(tab[i][j]))
            {
                if (j < 2)
                {
                    printf(" %c |", tab[i][j]);
                }
                else printf(" %c ", tab[i][j]);
            }
            else
            {
                if (j < 2)
                {
                   printf("  |");
                }
                else printf(" ");
            }
             
             
          imprimir(i, j+1, tab);
        }
        else{
            if (i < 2)
            {
                printf("\n----------\n");
            }
            else printf("\n");
            
            
            imprimir(i+1, 0, tab);
        }
    }
}

void menu(char tabuleiro[][3], char jogador1[], char jogador2[])
{
    int x, y, valida, ganhou= 0, ordem = 1, jogadas= 0;
    do{ 
        do{    
            puts("Seu tabuleiro atual");
            imprimir(0, 0, tabuleiro);
            printf("Insira as coordenadas x y: ");
            scanf("%d %d", &x, &y);
            valida = coordenadavalida(x, y);
            if (valida)
            {
                valida += posicaovazia(x, y, tabuleiro);
            }
        }while(valida != 2);
        
        if (ordem == 1){
            tabuleiro[x][y] = 'x';
        }
        else tabuleiro[x][y] = '0';

        ordem +=1;
        if (ordem == 3){
            ordem = 1;
        }
        
        ganhou += ganhou_Coluna(0, 0, 1, tabuleiro);
        ganhou += ganhou_linha(0, 0, 1, tabuleiro);
        ganhou += ganhou_diagprincipal(0,1, tabuleiro);
        ganhou += ganhou_diagsecundaria(0, 2, 1, tabuleiro);
        jogadas+=1;
    }while(ganhou == 0 && jogadas < 9); 
    puts("Seu tabuleiro atual");
    imprimir(0, 0, tabuleiro);

    if (ganhou != 0) {
        
        if (ordem - 1 == 1)
        {   
          printf("Parabéns %s você ganhou!\n", jogador1);
        }
        else printf("Parabéns %s você ganhou!\n", jogador2);
    }
    else puts("Ops... Empatou");
}
int main(){
    puts("------------- JOGO DA VELHA ---------------");
    char tabuleiro[3][3];
    char jogador1[30], jogador2[30];
    printf("Jogador 1 digite seu nome-> ");
    fgets(jogador1, 50, stdin);
    printf("Jogador 2 digite seu nome-> ");
    fgets(jogador2, 50, stdin);
    int op=1;
    while (op == 1)
    {
        inicializar_matriz(0, 0, tabuleiro);

        menu(tabuleiro, jogador1, jogador2);    
        printf("Deseja jogar novamente? \n1 - Sim\n2 - Não\n");
        scanf("%d", &op);
    }
    
    return 0;
}