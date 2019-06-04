#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    Menu();
    getch();
    return 0;
}


void Menu(){
    int resp;
    char termos1[2]="01";
    char termos2[8]="01234567";
    char termos3[16]="0123456789abcdefABCDEF";
    char numero[20];
    int numDez;
    int num;
    do{


        system("cls");
        printf("-----------------------         Conversão de Bases       -----------------------\n\n");
        printf("                            1_ Converter de 2 para  8                            \n");
        printf("                            2_ Converter de 2 para  10                            \n");
        printf("                            3_ Converter de 2 para  16                            \n");
        printf("                            4_ Converter de 8 para  10                            \n");
        printf("                            5_ Converter de 16 para 10                            \n");
        printf("                            6_ Converter de 10 para 2                            \n");
        printf("                            7_ Converter de 10 para 8                            \n");
        printf("                            8_ Converter de 10 para 16                           \n");
        printf("                                     0_Sair                                      \n");
        printf("Escolha uma opção:  ");
        scanf("%d",&resp);

        switch(resp){
            case 1:
                printf("Digite o valor:   ");
                scanf("%s",&numero);
                if(checarValores(numero,termos1) == 1){
                    doisParaN(8,numero);
                }
                else{
                    printf("Somente valores entre 0 e 1 !");
                }
                printf("\n");
                system("pause");
                break;
            case 2:
                printf("Digite o valor:   ");
                scanf("%s",&numero);
                if(checarValores(numero,termos1) == 1){
                    nParaDez(2,numero);
                }
                else{
                    printf("Somente valores entre 0 e 1 !");
                }
                printf("\n");
                system("pause");
                break;
            case 3:
                printf("Digite o valor:   ");
                scanf("%s",&numero);
                if(checarValores(numero,termos1) == 1){
                    doisParaN(16,numero);
                }
                else{
                    printf("Somente valores entre 0 e 1 !");
                }
                printf("\n");
                system("pause");
                break;
            case 4:
                printf("Digite o valor:   ");
                scanf("%s",&numero);
                if(checarValores(numero,termos2) == 1){
                    nParaDez(8,numero);
                }
                else{
                    printf("Somente valores entre 0 e 7 !");
                }
                printf("\n");
                system("pause");
                break;
            case 5:
                printf("Digite o valor:   ");
                scanf("%s",&numero);
                if(checarValores(numero,termos3) == 1){
                    nParaDez(16,numero);
                }
                else{
                    printf("Somente valores entre 0 e 9 e letras como [a,b,c,d,e,f] !");
                }
                printf("\n");
                system("pause");
                break;
            case 6:
                printf("Digite o valor:   ");
                scanf("%d",&numDez);
                dezParaN(2,numDez);
                printf("\n");
                system("pause");
                break;
            case 7:
                printf("Digite o valor:   ");
                scanf("%d",&numDez);
                dezParaN(8,numDez);
                printf("\n");
                system("pause");
                break;
            case 8:
                printf("Digite o valor:   ");
                scanf("%d",&numDez);
                dezParaN(16,numDez);
                printf("\n");
                system("pause");
                break;
            case 0:
                printf("Até a próxima\n");
                system("pause");
                break;
            default:
                printf("ERROR\n");
                break;
        }
    }while(resp!=0);
}

//Analise e checagem dos valores inseridos pelo usuário
int checarValores(char* vetor, char *termos){
    int i,j,cont,result;
    result = 1;
    for(i=0;i< strlen(vetor);i++){
        cont = 0;
        for( j=0 ; j< strlen(termos) ; j++ )
        {
            if( vetor[i] != termos[j] )
            {
                cont++;
            }
        }
        if( cont>=strlen(termos))
        {
            result=0;
        }
    }
    if( result==0 )
    {
        return 0;

    }else
    {
        return 1;
    }
}


// 2 - 8 - 16 para 10
int nParaDez(int base,char bi[]){
    int soma,expoente,potencia,size,num,i;
    expoente=0;
    potencia=0;
    soma=0;
    num=0;
    //Tamanho do vetor
    size=strlen(bi);
    if(base==16)
    {
            for( i=size-1;i>=0;i--)
            {
                //elevando cada posicao
                potencia = pow( base , expoente );
                //Trocando os valores strings por valores inteiros;
                if(bi[i]=='A' || bi[i]=='a')
                {
                    num = 10;
                }else if(bi[i]=='B' || bi[i]=='b')
                {
                    num = 11;
                }else if(bi[i]=='C' || bi[i]=='c')
                {
                    num = 12;
                }else if(bi[i]=='D' || bi[i]=='d')
                {
                    num = 13;
                }else if(bi[i]=='E' || bi[i]=='e')
                {
                    num = 14;
                }else if(bi[i]=='F' || bi[i]=='f')
                {
                    num = 15 ;
                }else{num = bi[i]-'0';}
                //Somatória
                soma = soma + num*potencia;
                //somando ao expoente
                expoente++;
            }
    }
    else
    {
        for(  i=size-1 ; i>=0 ; i-- ){
            potencia = pow(base,expoente);
            //de string para int
            num  = bi[i]-'0';
            soma = soma + num*potencia;
            expoente++;
        }
    }
    //print
    printf("O resultado na conversão desejada é: %d",soma);
}


//2 para N
int doisParaN(int bas,char bi[]){
    int expoente= 0;
    int soma=0;
    int potencia=0;
    //Divisor determina as casas
    int i,size,divisor;
    // pegando o tamanho do array
    size=strlen(bi);

    // fazendo com que o numero fique completo para transformalo
    char binario2[20];
    if(bas == 8){
        // numero que me diz quando eu falta no vetor para ser completado
        divisor=3;
        //fazendo com que o completando o numero para que possa convertê-lo sem problemas para transformalo
        if(size%divisor==2){
            //incrementando o resto que falta no novo array
             binario2[0]='0';
            //acrescentando os numeros do outro array
            for( i=0;i<=size;i++){
                binario2[i+1]=bi[i];
            }
            size= strlen(binario2);
            TransformaBase(binario2,size,soma,potencia,expoente,divisor);
        }else if(size%divisor==1){
            char zero='0';
            //incrementando o resto que falta no novo array
            binario2[0]='0';
            binario2[1]='0';
            //acrescentando os numeros do outro array
            for(i=0;i<=size+1;i++){
                binario2[i+2]=bi[i];
            }
            size= strlen(binario2);
            TransformaBase(binario2,size,soma,potencia,expoente,divisor);

        }else{
            TransformaBase(bi,size,soma,potencia,expoente,divisor);
        }

    }
    if(bas == 16){
        divisor=4;
        if(size%divisor==3){
            //incrementando o resto que falta no novo array
             binario2[0]='0';
            //acrescentando os numeros do outro array
            for( i=0;i<=size;i++){
                binario2[i+1]=bi[i];
            }
            //pegando o tamanho do novo vetor
            size= strlen(binario2);
            TransformaBase(binario2,size,soma,potencia,expoente,divisor);
        }else if(size%divisor==2){
            binario2[0]='0';
            binario2[1]='0';
            //acrescentando os numeros do outro array
            for( i=0;i<=size;i++){
                // esse + mais dois significa da onde o array deve começar a ser preenchido devido ao acrescimo das casas 0
                binario2[i+2]=bi[i];
            }
            size= strlen(binario2);
            TransformaBase(binario2,size,soma,potencia,expoente,divisor);
        }else if(size%divisor==1){
            char zero='0';
            binario2[0]='0';
            binario2[1]='0';
            binario2[2]='0';
            //acrescentando os numeros do outro array
            for( i=0;i<=size+1;i++){
                binario2[i+3]=bi[i];
            }
            size= strlen(binario2);
            TransformaBase(binario2,size,soma,potencia,expoente,divisor);

        }else{
            TransformaBase(bi,size,soma,potencia,expoente,divisor);

        }
    }
}

int TransformaBase(char bi[20],int size,int soma,int potencia,int expoente,int divisor){
    //Converte os valores, é chamado pelo outro método, o qual é responsável por instanciar a trasformação
    //variaveis para inverter o resultado
    int casas=size/divisor;
    int resul[casas];
    int i,co,contador,num;
    contador=0;
    // tenho que começar do maior para o menor
    printf("O resultado na conversão desejada é: ");

    for( i=size-1 ; i>=0 ; i--)
    {
        // calculo da potencia de dois
        potencia = pow(2,expoente);
        // transfomrmando o valor string em inteiro para multiplicar
        num = bi[i] - '0';
        // executando a soma e a multiplicação
        soma += num*potencia;
        // variavel de controle encrementando o expoente
        expoente++;
        contador++;
        if( contador == divisor )
        {
            resul[casas-1]=soma;
            casas--;
            soma=0;
            contador=0;
            expoente=0;
        }
    }
    casas=size/divisor;
    for( co=0;co<=casas-1;co++){
        // impressão das letras do caso de ser hexadecimal
        if(resul[co] == 10)
        {
            printf("A");
        }else if(resul[co] == 11)
        {
            printf("B");
        }else if(resul[co] == 12)
        {
            printf("C");
        }else if(resul[co] == 13)
        {
            printf("D");
        }else if(resul[co] == 14)
        {
            printf("E");
        }else if(resul[co] == 15)
        {
            printf("F");
        }else
        {
            //caso não seja letra ele imprime normalmente
            printf("%d",resul[co]);
        }
    }
    return 0;
}


// 10 para N
int dezParaN(int bas,int num){
    // 10 to 2
    int resto,divisao,contador,base;
    base=bas;
    //dita a quantidade de vezes que o while roda= variavel de controle
    divisao=num;
    // array
    int arraynum[15];
    contador=0;
    while(divisao>0){
        //resto a ser recolhido
        resto=divisao%base;
        //contagem de voltas que o while faz
        contador++;
        //preenchendo o vetor com o valor do resto
        arraynum[contador]=resto;
        //divide do numero pela base
        divisao=divisao/base;
    }
    printf("O resultado na conversão desejada é: ");
    // Impressão dos valores adiquiridos
    // pego o vetor ao contrario, subtraindo-o do tamanho total
    for(contador;contador>0;contador--){
            if(base==16){
                //Substitui os numeros maiores que 9 por seus respctivos indices alfabéticos
                if(arraynum[contador] == 10){
                    printf("A");
                }else if(arraynum[contador] == 11){
                    printf("B");
                }else if(arraynum[contador] == 12){
                    printf("C");
                }else if(arraynum[contador] == 13){
                    printf("D");
                }else if(arraynum[contador] == 14){
                    printf("E");
                }else if(arraynum[contador] == 15){
                    printf("F");
                }
                else{
                    //caso não seja letra
                    printf("%d",arraynum[contador]);
                }
            }else{
                // caso não seja base 16
                printf("%d",arraynum[contador]);
            }
    }
}







