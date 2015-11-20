/**********************************************
*                                             *
*  RAFAEL DORNELAS GOBBI - PUC MG - AED 2     *
*                                             *
* CALCULAR CUSTO DE COMPARAÇÕES:              *
* BOLHA, INSERÇÃO, SELEÇÃO, QUICKSORT         *
*               09/2014                       *
***********************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

/* ALGORITIMO DE COMPARAÇÃO BOLHA */
int bolha(int vet[],int tam)
{
    int aux,cont=0;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=0; j<tam-i-1; j++)
        {
            cont++;
            if(vet[j]>vet[j+1])
            {
                aux=vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;


            }
        }
    }
    return cont;
}

/* ALGORITIMO DE COMPARAÇÃO SELEÇÃO */
int selecao(int vet[],int tam)
{
    int aux,cont=0,minimo;
    for(int i=0; i<tam-1; i++)
    {
        minimo=i;
        for(int j=i+1; j<tam; j++)
        {
            cont++;
            if(vet[j]<vet[minimo])
            {
                minimo=j;
            }
        }
        aux=vet[i];
        vet[i]=vet[minimo];
        vet[minimo]=aux;
    }
    return cont;
}
/* ALGORITIMO DE COMPARAÇÃO INSERCAO */
int insercao(int vet[],int tam)
{
    int sentinela, j,cont=0;
    for(int i=2; i<=tam-1; i++)
    {
        sentinela=vet[i];
        vet[0]=sentinela;
        j=i-1;
        if(sentinela>=vet[j])
            cont++;
        while(sentinela<vet[j])
        {

            vet[j+1]=vet[j];
            j--;
            cont++;

        }
        vet[j+1]=sentinela;
    }
    return cont;
}

/* ALGORITIMO DE COMPARAÇÃO QUICKSORT */
void quicksort(int vet[], int esquerda , int direita,int &cont)
{
    int temp, pivo;
    int i, j;
    i = esquerda;
    j = direita;
    pivo = vet[(esquerda + direita) / 2];

    while(i <= j)
    {

        while(vet[i]< pivo && i < direita)
        {
            i++;
            cont++;
        }
        while(vet[j] > pivo && j > esquerda)
        {
            j--;
            cont++;
        }
        if(i <= j)
        {
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            i++;
            j--;
        }
    }

    if(j > esquerda)
    {
        quicksort(vet, esquerda , j,cont);
    }
    if(i < direita)
    {
        quicksort(vet, i, direita,cont) ;
    }

}

/* PREENCHENDO VETOR CRESCENTE. OBS: TAMANHO É REFERENCIADO VIA MAIN */
int *vetorcrescente(int tam)
{
    int *vet=(int*)malloc(tam*sizeof(int));
    for(int i=0; i<tam; i++)
    {
        vet[i]=i;
    }
    return vet;
}

/* PREENCHENDO VETOR DECRESCENTE. OBS: TAMANHO É REFERENCIADO VIA MAIN */
int *vetordecrescente(int tam)
{
    int *vet=(int*)malloc(tam*sizeof(int));
    int cont=0;
    for(int i=tam; i>0; i--)
    {
        vet[cont]=i;
        cont++;


    }
    return vet;
}
/* PREENCHENDO VETOR ALEATORIO RAND/SRAND. OBS: TAMANHO É REFERENCIADO VIA MAIN */
int *vetoraleatorio(int tam)
{
    srand(time(NULL));
    int *vet=(int*)malloc(tam*sizeof(int));
    for(int i=0; i<tam; i++)
    {
        vet[i]=rand()%999;
    }
    return vet;
}

/* LIBERANDO E EVITANDO VAZAMENTO DE MEMORIA */
void libera_memoria(int *p)
{
    free(p);
}

using namespace std;

/* PRINCIPAL */
int main()
{
    int menu = 0, menu2 = 0, tamanho = 0, conta = 0;
    int *vetor;

    LARGE_INTEGER tempoInicial, tempoFinal, freq; // PARA TEMPO
    double tempoTotal; // PARA O TEMPO



    printf(" \n\n                ***********************************************\n");
    printf("                *                                             *\n");
    printf("                *           ALGORITIMOS DE ORDENACAO          *\n");
    printf("                *                                             *\n");
    printf("                *                 RAFAEL GOBBI                *\n");
    printf("                *            TRABALHO I- AED II LAB           *\n");
    printf("                *       PROF: MARK ALAN MADE IN KOREAN        *\n");
    printf("                *********************************************** \n\n");
    printf("                SELECIONE OPCAO: \n\n");
    printf("\t\t 1 > BOLHA;\n\t\t 2 > SELECAO;\n\t\t 3 > INSERCAO;\n \t\t 4 > QUICKSORT;  ");
    scanf("%d",&menu);
    system("cls");

    /* COMECANDO TODAS COMPARAÇÕES */

    switch(menu)
    {
    case 1: /*  =============================================================================
                                             BOLHA
                ============================================================================= */
    {
        printf(" \n\t\t[B O L H A ] Digite o tamanho do vetor: ");
        scanf("%d",&tamanho);
        printf("\n\n");

        vetor=vetorcrescente(tamanho); /* RECEBE TAMANHO E PASSA PARA A FUNC. VETORCRESCENTE
                                       PARA CALCULAR O TAMANHO DO VETOR E PREENCHER OS NUMEROS */

        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);

        /* CONTAGEM DE TEMPO; O VALOR QUE FOI INICIADO A FUNCAO EXEMPLO: 00:00:10
        GUARDA ESSE VALOR.
        INICIA OUTRA VARIAVEL LOGO APÓS O FIM DA FUNÇÃO, EX: 00:00:50
        FAZ OS CALCULOS FINAL - INICIAL */


        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ CRESCENTE ] e de %d.\n",bolha(vetor,tamanho)); /* MANDA PRO
                                                                                                    BOLHA COMPARAR */

        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

       libera_memoria(vetor);

        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t \n\n", tempoTotal );
        system ("pause");

        // FAZ O MESMO PROCESSO ACIMA PORÉM PARA VETOR DECRESCENTE
        vetor=vetordecrescente(tamanho);
        printf("\n\n");

        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);

        QueryPerformanceCounter(&tempoInicial);

        printf("\n\n \t\t O numero de comparacoes [ DECRESCENTE ] e de %d.\n",bolha(vetor,tamanho));

       QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);

        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t.\n\n", tempoTotal);
        system ("pause");

        // VETOR ALEATORIO
        vetor=vetoraleatorio(tamanho);
        printf("\n\n");

        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);

        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO

        printf("\n\n \t\t O numero de comparacoes [ ALEATORIO ] e de %d t.\n",bolha(vetor,tamanho));

        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);

        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t.\n\n", tempoTotal);
        system ("pause");


        break;

    }
    case 2:
    {
        /*  =============================================================================
                                             SELEÇÃO
            ============================================================================= */

        printf(" \n\t\t[S E L E C A O] Digite o tamanho do vetor: ");
        scanf("%d",&tamanho);

        vetor=vetorcrescente(tamanho);
        printf("\n\n");

        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);

        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ CRESCENTE ] e de %d.\n",selecao(vetor,tamanho));


       QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);
        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t.\n\n", tempoTotal);
        system ("pause");

        vetor=vetordecrescente(tamanho);

        printf("\n\n");
        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);

        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ DECRESCENTE ] e de %d.\n",selecao(vetor,tamanho));

        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;


        libera_memoria(vetor);
        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t.\n\n", tempoTotal);
        system ("pause");

        vetor=vetoraleatorio(tamanho);
        printf("\n\n");

        for(int ta=0; ta<tamanho; ta++)
                printf(" | %d",vetor[ta]);

        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ ALEATORIO ] e de %d.\n",selecao(vetor,tamanho));

        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);
        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t.\n\n", tempoTotal);
        system ("pause");

        break;
    }
    case 3:
    {
        /*  =============================================================================
                                             INSERÇÃO
            ============================================================================= */

        printf(" \n\t\t[I N S E R C A O] Digite o tamanho do vetor: ");
        scanf("%d",&tamanho);
        vetor=vetorcrescente(tamanho+1);
        printf("\n\n");
        for(int ta=0; ta<tamanho; ta++)
        {

            printf(" | %d",vetor[ta]);

        }
        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ CRESCENTE ] e de %d.\n",insercao(vetor,tamanho+1));

        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);
        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t. \n\n", tempoTotal);
        system ("pause");

        vetor=vetordecrescente(tamanho+1);
        printf("\n\n");

        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);

        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ DECRESCENTE ] e de %d.\n",insercao(vetor,tamanho+1));


        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);
        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t. \n\n", tempoTotal);
        system ("pause");

        vetor=vetoraleatorio(tamanho+1);
        printf("\n\n");

        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);

        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ ALEATORIO ] e de %d.\n",insercao(vetor,tamanho+1));

        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);
        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t.\n\n", tempoTotal);
        system ("pause");

        break;
    }
    case 4:
    {
            /*  =============================================================================
                                            QUICKSORT
                ============================================================================= */
        printf(" \n\t\t[Q U I C K S O R T] Digite o tamanho do vetor: ");
        scanf("%d",&tamanho);

        vetor=vetorcrescente(tamanho);
        quicksort(vetor,0,tamanho-1,conta);
        printf("\n\n");

        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);


        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ CRESCENTE ] e de %d.\n",conta);

        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);
        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t.\n\n", tempoTotal);
        system ("pause");

        vetor=vetordecrescente(tamanho);

        quicksort(vetor,0,tamanho-1,conta);
        printf("\n\n");
        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);

        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ DECRESCENTE ] e de %d.\n",conta);

        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);
        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t.\n\n", tempoTotal);
        system ("pause");

        vetor=vetoraleatorio(tamanho);

        quicksort(vetor,0,tamanho-1,conta);
        printf("\n\n");

        for(int ta=0; ta<tamanho; ta++)
            printf(" | %d",vetor[ta]);

        QueryPerformanceCounter(&tempoInicial); // FAZ CALCULO INICIAL DO TEMPO DE EXECUÇÃO DA FUNÇÃO
        printf("\n\n \t\t O numero de comparacoes [ ALEATORIO ] e de %d.\n",conta);

        QueryPerformanceCounter(&tempoFinal); // CALCULO FINAL DO TEMPO
            QueryPerformanceFrequency(&freq);
                tempoTotal = (double)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;

        libera_memoria(vetor);

        printf("\n\n \t\t O Tempo aproximadamente de execucao e de: %lf t. \n\n", tempoTotal);
        system ("pause");


        break;
    }
    default:
    {
        main();
    }
    }
    return 0;
}
