#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Use o compilador GCC*/
typedef struct data{ /*lista para as datas/quantidade*/
    int dia;
    int mes;
    int ano;
    int qtd;
    struct data *prox;
}data;

typedef struct estoque{ /*lista para os codigos/produto*/
    int codigo;
    char descricao[40];
    char marca[30];
    struct data *validade;
    struct estoque *prox;
}estoque;


data *inserir_validade(data *validade, int dia, int mes, int ano , int qtd)
{
    data *new = (data*)malloc(sizeof(data));

    if (new == NULL)
    {
        printf("Produto cheio\n");
        return validade;
    }
    else
    {
        if (validade == NULL)
        {
          
            new->dia = dia;
            new->mes = mes;
            new->ano = ano;
            new->qtd += qtd; /*acrescentando ao que já tinha*/
            new->prox = NULL;
            validade = new;
            return validade;
        }
        else
        {
            data *aux;
            aux = validade; 
           
            while ((aux->prox != NULL) && (aux->dia > dia) && (aux->mes > mes) && (aux->ano > ano))
            {
                aux = aux->prox;
            }

           if (aux->prox == NULL)
            {
              
                if (aux->ano > ano)
                {
                   
                    new->dia = aux->dia;
                    new->ano = aux->ano;
                    new->mes = aux->mes;
                    new->qtd = aux->qtd;
                    new->prox = aux->prox;
                    aux->dia = dia;
                    aux->ano = ano;
                    aux->mes= mes;
                    aux->qtd = qtd;
                    aux->prox = new;
                } 
                else if (aux->ano == ano)
                {
                    if (aux->mes > mes) /*ok*/
                    {
                       
                        new->dia = aux->dia;
                        new->ano = aux->ano;
                        new->mes = aux->mes;
                        new->qtd = aux->qtd;
                        new->prox = aux->prox;
                        aux->dia = dia;
                        aux->ano = ano;
                        aux->mes= mes;
                        aux->qtd = qtd;
                        aux->prox = new;
                    }
                    else if (aux->mes == mes)
                    {
                        if (aux->dia > dia) /*ok*/
                        {
                            new->dia = aux->dia;
                            new->ano = aux->ano;
                            new->mes = aux->mes;
                            new->qtd = aux->qtd;
                            new->prox = aux->prox;
                            aux->dia = dia;
                            aux->ano = ano;
                            aux->mes= mes;
                            aux->qtd = qtd;
                            aux->prox = new;

                        }
                        else if(aux->dia == dia)
                        {
                            aux->qtd += qtd; /*validades com o msm dia*/
                        }
                        else
                        {
                        
                            new->dia = aux->dia;
                            new->ano = new->ano;
                            new->mes = new->mes;
                            new->qtd = new->qtd;
                            new->prox = aux->prox;
                            aux->dia = dia;
                            aux->ano = ano;
                            aux->mes = mes;
                            aux->qtd = qtd;
                            aux->prox = new;
                        }
                        
                    }
                    else
                    {
                     
                        new->prox = aux->prox;
                        new->ano = ano;
                        new->mes = mes;
                        new->dia = dia;
                        new->qtd = aux->qtd;

                        aux->prox = new;
                        new->ano = ano;
                        new->mes = mes;
                        new->dia = dia;
                        new->qtd = qtd;
                    }
                    
                }
                else /*quando o ano é maior */ /*ok*/
                {   
                 
                        new->prox = aux->prox;
                        new->ano = ano;
                        new->mes = mes;
                        new->dia = dia;
                        new->qtd = aux->qtd;

                        aux->prox = new;
                        new->ano = ano;
                        new->mes = mes;
                        new->dia = dia;
                        new->qtd = qtd;
                   
                }
                    
                return validade;
            }
            else
            {
               
                if (aux->ano > ano)
                {
                 
                    new->dia = aux->dia;
                    new->ano = aux->ano;
                    new->mes = aux->mes;
                    new->qtd = aux->qtd;
                    new->prox = aux->prox;
                    aux->dia = dia;
                    aux->ano = ano;
                    aux->mes= mes;
                    aux->qtd = qtd;
                    aux->prox = new;    
                }
                else if (aux->ano == ano)
                {
                    if (aux->mes > mes)
                    {
                     
                        new->dia = aux->dia;
                        new->ano = aux->ano;
                        new->mes = aux->mes;
                        new->qtd = aux->qtd;
                        new->prox = aux->prox;
                        aux->dia = dia;
                        aux->ano = ano;
                        aux->mes= mes;
                        aux->qtd = qtd;
                        aux->prox = new;
                    }
                    else if (aux->mes == mes)
                    {
                        if (aux->dia > dia)
                        {
                      
                            new->dia = aux->dia;
                            new->ano = aux->ano;
                            new->mes = aux->mes;
                            new->qtd = aux->qtd;
                            new->prox = aux->prox;
                            aux->dia = dia;
                            aux->ano = ano;
                            aux->mes= mes;
                            aux->qtd = qtd;
                            aux->prox = new;
                        }
                        else if(aux->dia == dia)
                        {
                            aux->qtd += qtd;
                        }
                        else
                        {  
                       
                            new->prox = aux->prox;
                            new->ano = ano;
                            new->mes = mes;
                            new->dia = dia;
                            new->qtd = aux->qtd;

                            aux->prox = new;
                            new->ano = ano;
                            new->mes = mes;
                            new->dia = dia;
                            new->qtd = qtd;
                        }
                    }
                    else /*concertar*/
                    {
                     
                     
                        new->prox = aux->prox;
                        new->ano = ano;
                        new->mes = mes;
                        new->dia = dia;
                        new->qtd = aux->qtd;

                        aux->prox = new;
                        new->ano = ano;
                        new->mes = mes;
                        new->dia = dia;
                        new->qtd = qtd;
                                            
                    }
                }
                else /*mesmo algoritimo de cima*/
                {       
                    
                    new->prox = aux->prox;
                    new->ano = ano;
                    new->mes = mes;
                    new->dia = dia;
                    new->qtd = aux->qtd;

                    aux->prox = new;
                    new->ano = ano;
                    new->mes = mes;
                    new->dia = dia;
                    new->qtd = qtd;          
                }
                return validade;
            }       
        }

    }
}

estoque *criar_produto(estoque *produto, estoque *aux, estoque *head)
{
            
    printf("###########################################\n");
    int cod, dia, mes, ano, qtd;
    char desc[40], marca[30];
    printf("Digite o codigo do produto: ");
    scanf("%d", &cod);
    getchar();
    printf("Digite a descrição do produto: ");
    scanf("%s", desc);
    printf("Digite a marca do produto: ");
    scanf("%s", marca);
    printf("Digite a data de validade do produto em numeros:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    printf("Mês: ");
    scanf("%d", &mes);
    printf("Ano: ");
    scanf("%d", &ano);           
    printf("Digite a quantidade do produto: ");
    scanf("%d", &qtd);

    estoque *new;
    new = (estoque*) malloc(sizeof(estoque));
    if (new == NULL) printf("Não foi possivel alocar memória\n");
    else
    {   
        if (produto == NULL) /*insere 1 elemento*/
        {
            new->codigo = cod;
            strcpy(new->descricao, desc);
            strcpy(new->marca, marca); 
            new->validade = inserir_validade(new->validade, dia, mes, ano, qtd);
            new->prox = NULL;
            produto = new;
            return produto;
        }
        else
        {
            new->validade = NULL;
            estoque *aux = produto;
            while (aux->prox != NULL && cod > aux->codigo)
            { 
                aux = aux->prox;
            }
            if (aux->prox == NULL) /*O numero a inserir é maior que todos */ 
            {   
                if (cod > aux->codigo)/*ok*/
                {
                    new->prox = NULL;
                    new->codigo = cod;
                    strcpy(new->descricao, desc);
                    strcpy(new->marca, marca);
                    new->validade = inserir_validade(new->validade, dia, mes, ano, qtd);
                    aux->prox = new;         
                }
                else
                {   
                    if (aux->codigo == cod)
                    {                         
                    
                        new->codigo = aux->codigo; 
                        new->validade = aux->validade;
                        aux->validade = inserir_validade(new->validade, dia, mes, ano, qtd);
                        aux->prox = NULL;

                    }
                    else{
                        new->codigo = aux->codigo;
                        new->validade = aux->validade;
                        strcpy(new->marca, aux->marca);
                        strcpy(new->descricao, aux->descricao);
                        new->prox = aux->prox;
                        aux->codigo = cod;
                        strcpy(aux->marca, marca);
                        strcpy(aux->descricao, desc);
                        aux->validade = inserir_validade(new->validade, dia, mes, ano, qtd);
                        aux->prox = new;
                    }
                }

            }
           else 
            {   
                if (aux->codigo == cod)
                {
                    new->codigo = aux->codigo; 
                    new->validade = aux->validade;
                    aux->validade = inserir_validade(new->validade, dia, mes, ano, qtd);
                    aux->prox = NULL;
                }
                else{
                    new->codigo = aux->codigo;
                    new->validade = aux->validade;
                    strcpy(new->marca, aux->marca);
                    strcpy(new->descricao, aux->descricao);
                    new->prox = aux->prox;
                    aux->codigo = cod;
                    strcpy(aux->marca, marca);
                    strcpy(aux->descricao, desc);
                    aux->validade = inserir_validade(new->validade, dia, mes, ano, qtd);
                    aux->prox = new;
                }          
            }
            return produto; 
        }
    }    
}

void quantidade(estoque *aux)
{
    if (aux == NULL) return;
    else
    {
        printf("----------------- Produto %d ---------------- \n", aux->codigo);
        data *data_aux = aux->validade;
        while (data_aux != NULL)
        { 
            printf("*****************************************\n");
            printf("Com validade: %d/%d/%d\n", data_aux->dia, data_aux->mes, data_aux->ano);
            printf("Existe %d desse produto\n", data_aux->qtd);
            data_aux = data_aux->prox;
            printf("*****************************************\n");
        }
        printf("-----------------------------------------\n");
        aux= aux->prox;
        quantidade(aux);
    }

} /*função para ver quantos produtos tem*/

void imprimir(estoque *aux)
{ 
    if (aux == NULL) return;
    else
    {
        printf("-----------------------------------------\n");
        printf("Código: %d\n", aux->codigo);
        printf("Descrição: %s\n", aux->descricao);
        printf("Marca: %s\n", aux->marca);
        data *data_aux = aux->validade;
        while (data_aux != NULL)
        { 
            printf("*****************************************\n");
            printf("Validade: %d/%d/%d\n", data_aux->dia, data_aux->mes, data_aux->ano);
            printf("Quantidade: %d\n", data_aux->qtd);
            data_aux = data_aux->prox;
            printf("*****************************************\n");
        }
        printf("-----------------------------------------\n");
        aux= aux->prox;
        imprimir(aux);
    }

}

void retirando(estoque *aux, int codigo, int qtd)
{
    if (aux == NULL) return;
    else
    {
        data *data_aux = aux->validade;
        data *aux1 = NULL; 

        if (codigo == aux->codigo)
        {
            data_aux->qtd -= qtd;    
            if (data_aux->qtd < 0) /*retirando as datas por ordem de validade*/
            {
                qtd = (data_aux->qtd*-1);

                aux1 = data_aux->prox;
                aux->validade = NULL;
                free(aux->validade);
                aux->validade = aux1;
                   
                printf("---------------------\n");
                while (qtd > 0 && aux1 != NULL)
                {
                    aux1->qtd -= qtd;
                
                    qtd = (aux1->qtd*-1);
                    aux1 = aux1->prox;
                }

                printf("---------------------\n");
                         
                aux1 = data_aux->prox;
                aux->validade = NULL;
                free(aux->validade);
                aux->validade = aux1;

                if (aux->validade  == NULL)
                {
                    
                    printf("-> Desculpe sem produto suficiente no estoque\n");
                    printf("->Faltou %d produtos\n", qtd);
                    printf("****************************************\n\n");
                }
                else
                {
                    aux1 = data_aux->prox;
                    aux->validade = NULL;
                    free(aux->validade);
                    aux->validade = aux1;
                    printf("------------ PRODUTO RETIRADO 1 ---------\n");
                    printf("****************************************\n\n");
                }      
            }
            else{
                
                if (data_aux->qtd == 0)
                {
                    aux1 = data_aux->prox;
                    aux->validade = NULL;
                    free(aux->validade);
                    aux->validade = aux1;
                }
                printf("------------ PRODUTO RETIRADO ---------\n");
                printf("****************************************\n\n");
            }
            
        }
        else printf("--------- PRODUTO INEXISTENTE -------------\n");

            aux1 = data_aux->prox;
            aux->validade = NULL;
            free(aux->validade);
            aux->validade = aux1;

        aux= aux->prox;
        retirando(aux, codigo, qtd);
    }
}

int menu(estoque *head,  estoque *elem, estoque *aux, int o)
{
    printf("-------------------- Sistema de gerenciamento de estoque --------------------\n");
    printf("\n----------------- Digite a operação que deseja realizar -------------------\n");
    printf("[0] Finalizar\n[1] Criar o estoque\n[2] Retirar produtos\n[3] Consultar produtos\n[4] Total de produtos\n");
    scanf("%d", &o);
    
    if (o != 0)
    {  
        printf("Por favor aguarde.....\n\n");
        if (o == 1)
        {
            int n;
            estoque *aux;
            aux = criar_produto(elem, aux, head);    
            head = aux;
            elem = head;
            printf("------------ PRODUTO INSERIDO ------------\n\n\n");                      
        }
        else if (o == 2)
        {
            int qtd_retira, cod_retirar;
            printf("Código do produto: ");
            scanf("%d", &cod_retirar);
            printf("Quantidade: ");
            scanf("%d", &qtd_retira);
            estoque *aux = head;
            retirando(aux, cod_retirar, qtd_retira);
           
        }
        else if (o == 3)
        {
            estoque *aux = head;
            imprimir(aux);
        }
        else if (o == 4)
        {
            estoque *aux = head;
            quantidade(aux);
        }
        return menu(head, elem, aux,  o);
    }else printf("Finalizando....\n");
}
int main()
{
    estoque *head = NULL, *elem = NULL, *aux = NULL;
  
    int o = 0; 
  
    menu(head, elem, aux, o);

    return 0;
}
