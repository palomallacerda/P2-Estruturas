#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct livros /*dados do livro*/
{
    char titulo[60];
    char autor[20];
    int qtd_biblioteca, qtd_emprest, ano_publi;
}livros;
typedef struct registro /*ficha do livro*/
{
    char titulo[60];
    char autor[20];
    int ano_p;
}registro;

int inserindo(livros book[200], int tam, int i, registro reg) /*cadastro dos livros*/
{
    if(i < tam)
    {  
        //printf("tam: %d %d", tam, i);
        if ((reg.titulo != book[i].titulo) && (reg.autor != book[i].autor) && (reg.ano_p != book[i].ano_publi))  
        {
            strcpy(book[i].titulo, reg.titulo);
            strcpy(book[i].autor, reg.autor);
            book[i].ano_publi = reg.ano_p;   
            return printf("\n ########### Livro sendo cadastrado #############\n\n"); /*espaço*/
            
        }
        else if ((strcmp(reg.titulo, book[i].titulo) == 0) && (strcmp(reg.autor, book[i].autor) == 0) && (reg.ano_p == book[i].ano_publi) )  /*já tem registro*/
        {
            book[i].qtd_biblioteca += 1;
           return printf("\n ######## Inserindo mais uma unidade ########## \n\n");
        }

        inserindo(book, tam, i+1, reg);
    }
}
int ler_livro(registro *reg, int *tam)
{
    fflush(stdin);
    printf("----------> Insira  o Título do livro <--------------- \n");
    getchar();
    //scanf("%[^\n]", reg.titulo);
    fgets(reg->titulo, 60, stdin);
    printf("\n----------> Insira  o autor do livro <---------------- \n");
   // scanf("%[^\n]", reg.autor);
    fgets(reg->autor, 20, stdin);
    printf("\n------> Insira  o ano de publicação do livro <-------- \n");
    scanf("%d", &reg->ano_p);
   
    *tam += 1;
}

int status_livro(livros book[200], registro reg, int i, int tam) /*ver a quantidade que ainda tem disponivel*/
{
     if (book->qtd_biblioteca < 0) /*não possui livros*/
    {
        printf("############ Livro indisponível  ###############\n");
    }
    else
    {
        if (i < tam)
        {
            if ((strcmp(reg.titulo, book[i].titulo) == 0) && (strcmp(reg.autor, book[i].autor) == 0) && (reg.ano_p == book[i].ano_publi))
            {
                if (book[i].qtd_biblioteca <= 0) /*precisa ter um volume na bib*/
                {
                   return printf("Apenas volume leitura disponível\n");
                }
                else return printf("Quantidade disponível: %d\n", book[i].qtd_biblioteca);
            }
            else return printf("Não existe volume cadastrado\n");

            status_livro(book, reg, i+1, tam);
        }
    }    
}
int empresta_livro(livros book[200], registro reg, int i, int tam)
{
    if (book->qtd_biblioteca <= 0) /*não possui livros*/
    {
        printf("############ Livro indisponível  ###############\n");
    }
    else
    {
        if (i < tam)
        {
             //printf("AQUI\n");
            if ((strcmp(reg.titulo, book[i].titulo) == 0) && (strcmp(reg.autor, book[i].autor) == 0) && (reg.ano_p == book[i].ano_publi))
            {
                book[i].qtd_emprest += 1;
                book[i].qtd_biblioteca -= 1;
                return printf("-----> Empréstimo finalizado <------\n");
            }
            else return printf("------------> Livro não cadastrado <---------- \n");
          
           empresta_livro(book, reg, i+1, tam);
        }
       
    }
}
int sistema(registro reg, int tam, int action, livros book[200], int count)
{
    if (count > 0) 
    { 
       ler_livro(&reg, &tam);          
    }
    
    if (action == 1) /*cadastro do livro*/
    {  
        inserindo(book, tam, 0, reg);    
    }
    else if (action == 2)
    {
        status_livro(book, reg, 0, tam);
    }
    else if (action == 3)
    {
        empresta_livro(book, reg, 0, tam);
    }
 
     printf("Insira o que deseja fazer:\n [0] Finalizar\n [1] Cadastro de livro\n [2] Status do livro\n [3] Pegar emprestado\n\n");
     scanf("%d", &action);
    if (action != 0) 
    {
        sistema(reg, tam, action, book, count+1);
    }
}
int main()
{
    livros book[200];
    registro reg;
    int action = 0;
    int tam;

    printf("\n---------> Sistema de livros da biblioteca <----------\n\n");
    printf("Insira o que deseja fazer:\n [0] Finalizar\n [1] Cadastro de livro\n [2] Status do livro\n [3] Pegar emprestado\n");
    scanf("%d", &action);
    if (action != 0)
    {
        ler_livro(&reg, &tam);      
    }
    sistema(reg, tam, action, book, 0);
    
    return 0;
}
