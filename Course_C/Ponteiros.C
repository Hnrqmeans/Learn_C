#include <stdio.h>
#include <stdlib.h>

//função display, recebe um inteiro e um ponteiro para inteiro, exibe valor do inteiro e o valor apontado pelo ponteiro.
void display (int var, int *ptr);
void update (int *p);

int main ()
{
    int var = 15;
    int *ptr;

    ptr = &var;

    //chamo a função display, passando o valor de var e o ponteiro ptr, antes de modificar o valor apontado por ptr para 73.
    //ponteiro ptr aponta para var, então o valor apontado por ptr é o valor de var, que é 15.
    printf("**************************************\n");
    display(var, ptr);    
    printf("**************************************\n");     

    //      | VAR  |      |      | PTR  |      |      |
    //      | 15   |      |      | 8001 |      |      |
    // 8000 | 8001 | 8002 | 8003 | 8004 | 8005 | 8006 |

    //Modificando o valor apontado por ptr.
    // *ptr = 73;
    
    //recebe o endereço de var em Hex.
    update(&var);

    //Conteudo atualizado.
    display(var, ptr);

    printf("**************************************\n");
    printf("Conteudo de var =  %d\n", var);           
    printf("endereco de var = %p\n", &var);           
    printf("conteudo apontado por ptr = %d\n", *ptr); 
    printf("endereco apontado por prt = %p\n", ptr);  
    printf("endereco de ptr = %p\n", &ptr);        
    printf("**************************************\n");   

    //      | VAR  |      |      | PTR  |      |      |
    //      | 73   |      |      | 8001 |      |      |
    // 8000 | 8001 | 8002 | 8003 | 8004 | 8005 | 8006 |

    //OU Se usar o update(&var); que é "*p = *p+1;"
    //      | VAR  |      |      | PTR  |      |      |
    //      | 16   |      |      | 8001 |      |      |
    // 8000 | 8001 | 8002 | 8003 | 8004 | 8005 | 8006 |

    printf("\n\nEnd.");
    while(1);
    return 0;

}//end main

void display (int var, int *ptr)
{
    printf("Conteudo de var =  %d\n", var);           //15
    printf("endereco de var = %p\n", &var);           //Endereço de var
    printf("conteudo apontado por ptr = %d\n", *ptr); //15
    printf("endereco apontado por prt = %p\n", ptr);  //Endereço de var
    printf("endereco de ptr = %p\n", &ptr);           //Endereço de ptr
}

//p  -> guarda o endereço recebido.
//*p -> acessa o valor armazenado no endereço.
void update (int *p)
{
    *p = *p+1;
}

/*
    %p especificador para imprimir endereços em C en HEX.
    %d imprimir inteiros em C.
****************************************************************************************
    *prt : o apontado por ptr, ou seja, o valor armazenado em var, que ptr aponta.
     ptr : o endereço armazenado em ptr, ou seja, o endereço de var, que
    &prt : o endereço de ptr, ou seja, onde ptr está armazenado na memória.
*/

