#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cdu_deze(char numero[], int size_int) /*Dezenas*/
{   
   if (numero[size_int-1] == '2')
   {
        if (numero[size_int] == '0')
         printf("vinte");    
        else
         printf("vinte e ");        
   }
   if (numero[size_int-1] == '3')
   {
        if (numero[size_int] == '0')
         printf("trinta");    
        else
         printf("trinta e ");
   }
   if (numero[size_int-1] == '4')
   {
        if (numero[size_int] == '0')
         printf("Quarenta");    
        else
         printf("quarenta e ");
   }
    if (numero[size_int-1] == '5')
   {
        if (numero[size_int] == '0')
         printf("cinquenta");    
        else
         printf("cinquenta e ");
   }
    if (numero[size_int-1] == '6')
   {
        if (numero[size_int] == '0')
         printf("sessenta");    
        else
         printf("Sessenta e ");
   }
    if (numero[size_int-1] == '7')
   {
        if (numero[size_int] == '0')
         printf("Setenta");    
        else
         printf("setenta e ");
        
   }
    if (numero[size_int-1] == '8')
   {
        if (numero[size_int] == '0')
         printf("oitenta");    
        else
         printf("oitenta e ");
   }
    if (numero[size_int-1] == '9')
   {
        if (numero[size_int] == '0')
         printf("Noventa");    
        else
         printf("noventa e ");
   }
}

int cdu_uni(char numero[], int atual) /*unidades*/
{   
    if (numero[atual] == '0') printf("zero");
    
    if (numero[atual] == '1') printf("um");
    
    if (numero[atual] == '2') printf("dois");
    
    if (numero[atual] == '3') printf("treis");
    
    if (numero[atual] == '4') printf("quatro");
    
    if (numero[atual] == '5') printf("cinco");
    
    if (numero[atual] == '6') printf("seis");
    
    if (numero[atual] == '7') printf("sete");
    
    if (numero[atual] == '8') printf("oito");

    if (numero[atual] == '9') printf("nove");
}
int cdu_ex(char numero[], int atual) /* 10 e 20*/
{   
    if (numero[atual] == '0') printf("dez");
    
    if (numero[atual] == '1') printf("onze");    
    
    if (numero[atual] == '2') printf("doze");
    
    if (numero[atual] == '3')  printf("treze");

    if (numero[atual] == '4') printf("quartoze");
    
    if (numero[atual] == '5') printf("quinze");
    
    if (numero[atual] == '6') printf("dezesseis");
    
    if (numero[atual] == '7') printf("dezessete");
    
    if (numero[atual] == '8') printf("dezoito");
    
    if (numero[atual] == '9') printf("dezenove");
    
}
int cdu_cent(char numero[], int size_int)
{
    if (numero[size_int-2] == '1')
    {
        if ((numero[size_int-1] == '0') && (numero[size_int] == '0'))
         printf("cem");    
        else printf("cento e ");     
    }
    if (numero[size_int-2] == '2')
    {
        if ((numero[size_int-1] == '0') && (numero[size_int] == '0'))
          printf("duzentos");       
        else printf("duzentos e ");
    }
   if (numero[size_int-2] == '3')
   {
        if ((numero[size_int-1] == '0') && (numero[size_int] == '0'))
          printf("trezentos");        
        else printf("trezentos e ");
   }
   if (numero[size_int-2] == '4')
   {
        if ((numero[size_int-1] == '0') && (numero[size_int] == '0'))
          printf("quatrocentos");        
        else printf("quatrocentos e ");
   }
    if (numero[size_int-2] == '5')
   {
        if ((numero[size_int-1] == '0') && (numero[size_int] == '0'))
          printf("quinhentos"); 
        else printf("quinhentos e ");
   }
    if (numero[size_int-2] == '6')
   {
        if ((numero[size_int-1] == '0') && (numero[size_int] == '0'))
         printf("seiscentos");        
        else printf("seiscentos e ");
   }
    if (numero[size_int-2] == '7')
   {
        if ((numero[size_int-1] == '0') && (numero[size_int] == '0'))
          printf("setecentos");       
        else printf("setecentos e ");
   }
    if (numero[size_int-2] == '8')
   {
        if ((numero[size_int-1] == '0') && (numero[size_int] == '0'))
          printf("oitocentos");
        else printf("oitocentos e ");
   }
    if (numero[size_int-2] == '9')
   {
        if ((numero[size_int-1] == '0') && (numero[size_int] == '0'))
          printf("novecentos"); 
        else printf("novecentos e ");
   }
}
int cdu_mil(char numero[], int size_int)
{
    
    if (size_int == 3) /*mil com uma casa*/
    {
        if ((numero[size_int-3] == '1') &&  (numero[size_int-2]) =='0' &&  (numero[size_int-1] == '0'))
          printf("mil");
        else 
        {       
            printf("%c\n", numero[size_int-2]);
            if ((numero[size_int-3] == '1'))  
            {
                if ((numero[size_int-1] == '0') )
                {
                    printf("mil e ");
                }
                else printf("mil ");
            }
            else{
                cdu_uni(numero, size_int-3);
                if ((numero[size_int-1] == '0') && (numero[size_int-2] != '0'))
                {
                    printf(" mil e ");
                }
                else printf(" mil "); 
            }
          
            cdu_cent(numero, size_int);
          
           if (numero[size_int-1] == '1')
              cdu_ex(numero, size_int);
            else 
            {
                cdu_deze(numero, size_int);
                if ((numero[size_int-1] != '0') && (numero[size_int-2] != '0') && (numero[size_int] != '0')) /*numeros seguidos de 0*/
                cdu_uni(numero, size_int);       
            }
        }
    }  
    else if (size_int == 4) /*mil com 2 casas*/
    {
        if ((numero[size_int-1] == '0') &&  ((numero[size_int-2]) =='0') &&  (numero[size_int] == '0'))
        {
           if (numero[size_int-4] == '1') /*entre 10 e 20*/
            {
                cdu_ex(numero, size_int-3);
                printf(" mil");
            }
            else 
            { 
               if (numero[size_int-3] == '0')
               {
                    cdu_deze(numero, size_int-3);       
                    printf(" Mil");
               }
               else
               {
                    cdu_deze(numero, size_int-3);      
                    cdu_uni(numero, size_int-3);
                    printf(" mil");    
               }
               
            } 
        }
        else 
        {       
            if (numero[size_int-4] == '1') /*entre 10 e 20*/
            {
                cdu_ex(numero, size_int-3);
                printf(" mil ");
            }
            else 
            { 
               if (numero[size_int-3] == '0')
               {
                    cdu_deze(numero, size_int-3);       
                    printf(" Mil e");
               }
               else
               {
                    cdu_deze(numero, size_int-3);      
                    cdu_uni(numero, size_int-3);
                    printf(" mil ");    
               }
               
            } 

            cdu_cent(numero, size_int);
            if (numero[size_int-1] == '1')
              cdu_ex(numero, size_int);
            else 
            {
                cdu_deze(numero, size_int);
                if ((numero[size_int-1] != '0') && (numero[size_int-2] != '0') && (numero[size_int] != '0')) /*numeros seguidos de 0*/
                cdu_uni(numero, size_int);   
            }           
        }
    }
    else if ((size_int == 5) || (size_int == 6) || (size_int == 7) || (size_int == 8)) /*mil na centena*/
    {
        if ((numero[size_int-1] =='0') && (numero[size_int-2] = '0') && (numero[size_int] == '0')) 
        {
            cdu_cent(numero, size_int-3);
            if (numero[size_int-4] == '1')
                cdu_ex(numero, size_int-3);
            else 
            {
                if (numero[size_int-3] == '0')
                    cdu_deze(numero, size_int-3);     
                else
                {
                    cdu_deze(numero, size_int-3);
                    cdu_uni(numero, size_int-3);
                }
            }       
            printf(" mil ");
        }
        else
        {
            cdu_cent(numero, size_int-3);
            if (numero[size_int-4] == '1')
                cdu_ex(numero, size_int-3);
            else 
            {
                cdu_deze(numero, size_int-3);
                if (numero[size_int-3] != '0') cdu_uni(numero, size_int-3);
            }       
            printf(" mil ");

            cdu_cent(numero, size_int);
            if (numero[size_int-1] == '1')
              cdu_ex(numero, size_int);
            else 
            {
                cdu_deze(numero,size_int);
                if (numero[size_int] != '0')  cdu_uni(numero, size_int);
            }  
        }
    } 
     
}
int cdu_milhao(char numero[], int size_int)
{
    if (size_int == 6) /*unidade_milhao*/
    {
        //printf("%c\n", numero[size_int-6]);
       if ((numero[size_int-5] == '0')  && (numero[size_int-3] == '0') && (numero[size_int-4] == '0') && (numero[size_int-2] == '0') && (numero[size_int-1] == '0') && (numero[size_int] == '0'))
        {
            cdu_uni(numero, size_int-6);
            if (numero[size_int-6] == '1')
              printf(" milhão ");
            else printf(" milhões ");
        }
        else
        {
            cdu_uni(numero, size_int-6);   /*primeira casa do milhão*/
            if (numero[size_int-6] == '1')
            {
                printf(" milhão ");
            }
            else printf(" milhões ");  
            cdu_mil(numero, size_int);       
        }
    }
    else if (size_int == 7) /*dezena de milhão*/
    {
        if (numero[size_int-7] == '1') 
        {
            cdu_ex(numero, size_int-6);
            printf(" milhões ");
        }
        else{
            cdu_deze(numero, size_int-6);
            if (numero[size_int-6] != '0') cdu_uni(numero, size_int-6);
            printf(" milhões ");
        }
        cdu_mil(numero, size_int);
    }
    else if (size_int == 8) /*centena de milhão*/
    {
       
        if ((numero[size_int] == '0')  && (numero[size_int-1] == '0') && (numero[size_int-2] == '0') && (numero[size_int-3] == '0')&& (numero[size_int-4] == '0') && (numero[size_int-5] == '0'))
        {
             //printf("atual: %c\n", numero[size_int-6]);
            cdu_cent(numero, size_int-6);
            if (numero[size_int-7] == '1') /*intervalo do 10 ao 20*/
                cdu_ex(numero, size_int-6);        
            else 
            {
                cdu_deze(numero, size_int-6);
                if (numero[size_int-6] != '0') cdu_uni(numero, size_int-6);      
            }
            printf(" milhões ");
        }
        else
        {        
            cdu_cent(numero, size_int-6);
            if (numero[size_int-7] == '1') /*intervalo do 10 ao 20*/
                cdu_ex(numero, size_int-6);        
            else 
            {
                cdu_deze(numero, size_int-6);
                if (numero[size_int-6] != '0') cdu_uni(numero, size_int-6);      
            }
            printf(" milhões ");
            cdu_mil(numero, size_int);
        }   
    }   
}
int contar_classe(char numero[], int i, int size_int)
{
   //printf("%d\n", size_int);
   if (size_int >= 3) /*mil e milhao*/
   {          
      // printf("%d\n", size_int);  
        if (size_int < 6)
        {
            cdu_mil(numero, size_int);  /*mil*/
        }
        else if(size_int >= 6)
        {
            cdu_milhao(numero,size_int); /*milhao*/
        }     
   }
   else
   {
       if ((size_int % 3) == 0) 
    {   
        if(size_int == 0) /*unidade*/
        {
            cdu_uni(numero, size_int);
        }     
    }
    if ((size_int % 3) == 1) 
    {   
        if ((numero[size_int-1] == '1'))/*intervalo entre 10 e 20*/ 
        {
            cdu_ex(numero, size_int);
        }
        if (numero[size_int-1] == '2')  /*intervalo 20 e 30*/
        {
            cdu_deze(numero, size_int);             
            if(numero[size_int] != '0') cdu_uni(numero, size_int);
        }
        if (numero[size_int-1] == '3')  /*intervalo 30 e 40*/
        {
            cdu_deze(numero, size_int);             
            if(numero[size_int] != '0') cdu_uni(numero, size_int);
        }
        if (numero[size_int-1] == '4')  /*intervalo 40 e 50*/
        {
            cdu_deze(numero, size_int);             
            if(numero[size_int] != '0') cdu_uni(numero, size_int);
        }
        if (numero[size_int-1] == '5')  /*intervalo 50 e 60*/
        {
           cdu_deze(numero, size_int);             
            if(numero[size_int] != '0') cdu_uni(numero, size_int);
        }
        if (numero[size_int-1] == '6')  /*intervalo 60 e 70*/
        {
            cdu_deze(numero, size_int);             
            if(numero[size_int] != '0') cdu_uni(numero, size_int);
        }
        if (numero[size_int-1] == '7')  /*intervalo 70 e 80*/
        {
            cdu_deze(numero, size_int);             
            if(numero[size_int] != '0') cdu_uni(numero, size_int);
        }
        if (numero[size_int-1] == '8')  /*intervalo 80 e 90*/
        {
            cdu_deze(numero, size_int);             
            if(numero[size_int] != '0') cdu_uni(numero, size_int);
        }
        if (numero[size_int-1] == '9')  /*intervalo 90 e 100*/
        {
            cdu_deze(numero, size_int);             
            if(numero[size_int] != '0') cdu_uni(numero, size_int);
        }
    }
if ((size_int % 3) == 2) 
    {   
        if ((numero[size_int-2] == '1'))/*intervalo entre 100 e 200*/ 
        {
            if (numero[size_int-1] == '0' && numero[size_int] == '0')
            {
                cdu_cent(numero, size_int);
            }
            else
            {
                cdu_cent(numero, size_int);
                if (numero[size_int-1] == '1')
                {
                    cdu_ex(numero, size_int);    
                }
                else{
                    cdu_deze(numero, size_int);             
                    if(numero[size_int] != '0') cdu_uni(numero, size_int);    
                }
            } 
        }
        if (numero[size_int-2] == '2')  /*intervalo 20 e 30*/
        {
            if (numero[size_int-1] == '0' && numero[size_int] == '0')
            {
                cdu_cent(numero, size_int);
            }
            else
            {
                cdu_cent(numero, size_int);
                if (numero[size_int-1] == '1')
                {
                    cdu_ex(numero, size_int);    
                }
                else{
                   cdu_deze(numero, size_int);             
                    if(numero[size_int] != '0') cdu_uni(numero, size_int);   
                }
            }
        }
        if (numero[size_int-2] == '3')  /*intervalo 30 e 40*/
        {
            if (numero[size_int-1] == '0' && numero[size_int] == '0')
            {
                cdu_cent(numero, size_int);
            }
            else
            {
                cdu_cent(numero, size_int);
                if (numero[size_int-1] == '1')
                {
                    cdu_ex(numero, size_int);    
                }
                else{
                    cdu_deze(numero, size_int);             
                    if(numero[size_int] != '0') cdu_uni(numero, size_int);    
                }
            }
        }
        if (numero[size_int-2] == '4')  /*intervalo 40 e 50*/
        {
            if (numero[size_int-1] == '0' && numero[size_int] == '0')
            {
                cdu_cent(numero, size_int);
            }
            else
            {
                cdu_cent(numero, size_int);
                if (numero[size_int-1] == '1')
                {
                    cdu_ex(numero, size_int);    
                }
                else{
                   cdu_deze(numero, size_int);             
                    if(numero[size_int] != '0') cdu_uni(numero, size_int);    
                }
            }
        }
        if (numero[size_int-2] == '5')  /*intervalo 50 e 60*/
        {  
            if (numero[size_int-1] == '0' && numero[size_int] == '0')
            {
                cdu_cent(numero, size_int);
            }
            else
            {
                cdu_cent(numero, size_int);
                if (numero[size_int-1] == '1')
                {
                    cdu_ex(numero, size_int);    
                }
                else{
                    cdu_deze(numero, size_int);             
                    if(numero[size_int] != '0') cdu_uni(numero, size_int);    
                }
            }
        }
        if (numero[size_int-2] == '6')  /*intervalo 60 e 70*/
        {   
            if (numero[size_int-1] == '0' && numero[size_int] == '0')
            {
                cdu_cent(numero, size_int);
            }
            else
            {
                cdu_cent(numero, size_int);
                if (numero[size_int-1] == '1')
                {
                    cdu_ex(numero, size_int);    
                }
                else{
                 cdu_deze(numero, size_int);             
                    if(numero[size_int] != '0') cdu_uni(numero, size_int);    
                }
            }
        }  
        if (numero[size_int-2] == '7')  /*intervalo 70 e 80*/
        {
            if (numero[size_int-1] == '0' && numero[size_int] == '0')
            {
                cdu_cent(numero, size_int);
            }
            else
            {
                cdu_cent(numero, size_int);
                if (numero[size_int-1] == '1')
                {
                    cdu_ex(numero, size_int);    
                }
                else{
                    cdu_deze(numero, size_int);             
                    if(numero[size_int] != '0') cdu_uni(numero, size_int);   
                }
            }
        }
        if (numero[size_int-2] == '8')  /*intervalo 80 e 90*/
        {
            if (numero[size_int-1] == '0' && numero[size_int] == '0')
            {
                cdu_cent(numero, size_int);
            }
            else
            {
                cdu_cent(numero, size_int);
                if (numero[size_int-1] == '1')
                {
                    cdu_ex(numero, size_int);    
                }
                else{
                    cdu_deze(numero, size_int);             
                    if(numero[size_int] != '0') cdu_uni(numero, size_int);    
                }
            }
        }
        if (numero[size_int-2] == '9')  /*intervalo 90 e 100*/
        {
            if (numero[size_int-1] == '0' && numero[size_int] == '0')
            {
                cdu_cent(numero, size_int);
            }
            else
            {
                cdu_cent(numero, size_int);
                if (numero[size_int-1] == '1')
                {
                    cdu_ex(numero, size_int);    
                }
                else{
                    cdu_deze(numero, size_int);             
                    if(numero[size_int] != '0') cdu_uni(numero, size_int);    
                }
            }
        }
    }
   }
   
    

}
/*################################################################################################################*/
int verificar_valido(char numero[100], int size, int i, int natu, int inteiro, int real, int erro, int mais)
{
    if (i <= size)
    {
        if (i == size) /*cond parada*/
        {  
           //printf("real: %d erro: %d inteiro: %d natu: %d mais: %d\n", real, erro, inteiro, natu, mais);
           if (real == 1)
            return 1;
           else if (((real > 1) || (erro > 0)) && ((mais == 0) && (inteiro == 0)))
           {
               return 0;   
           }
           else if (inteiro > 0)
           {
             return 1;
           }
           else return 1;                           
        }
        else
        {
          if ((numero[0] == '+') || (numero[0] == '-'))
          { 
              if (numero[0] == '+') /* pode ser natural */
                mais += 1;
              else inteiro += 1;
          }
          if ((numero[i] < '0')  ||  (numero[i] > '9'))
          {
              if (numero[i] == '.' || numero[i] == ',')
                real += 1;
              else erro += 1;
          }        
          else natu += 1;
           
        return verificar_valido(numero, size, i+1, natu, inteiro, real, erro, mais);
        }
    }
}
/*######################################################################################################################*/
int main()
{
    char numero[100]; 
    int conv_number, virgula, ind_vig;
    char matriz_exte[10][20];
    printf("Digite o número: ");
    scanf("%[^\n]", numero);
    int n = strlen(numero);
    int valido = verificar_valido(numero, n, 0, 0, 0, 0, 0, 0); /*verificando se a syntaxe está ok*/
       
    if(valido == 1) /*é um número válido*/
    {   
        if (numero[0] == '+') 
           {
               for (int i = 1; i < n; i++)
               {
                   numero[i-1] = numero[i];
               }
               n -= 1;     
           }
           else if (numero[0] == '-')
           { 
               for (int i = 1; i < n; i++)
               {
                   numero[i-1] = numero[i];
               }
               n -= 1;
               printf("menos ");
           }
        for (int i = 0; i < n; i++)
        {
            if((numero[i] == '.') || (numero[i] == ',')) 
            {
                virgula +=1;
                ind_vig = i;

                if ((numero[0]) == '+')
                {
                    contar_classe(numero, 0, i-2); /*numero fracionario antes*/
                }
                else contar_classe(numero, 0, i-1); /*numero fracionario antes*/
            }          
        } 
        if (virgula > 0)
        {
            printf(" ponto ");  
            for (int i = ind_vig; i < n; i++)
            {
                cdu_uni(numero, i);
                printf(" ");               
            }
            printf("\n");   
        }
        else
        {
           contar_classe(numero, 0, n-1);
           printf("\n");
        }
    }
    else printf("Wrong syntaxe!\n");
    return 0;
}
