#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
#include <locale.h>

main(){

    setlocale(LC_ALL, "Portuguese");

    char expt[8];
    int mant[23], not, i, j, sin;
    float X, Y, Soma=0, Num;

    printf("-------------------------------------------\n    BINÁRIO IEE-754  ---->  DECIMAL\n");
    printf("__________________________________________\n");
    printf("\nInsira um número binário seguindo o padrão iee-754:\n");
    printf("Sinal(MSB)= ");
    scanf("%d",&sin);  //Leitura do Sinal
    printf("Expoente= ");
    fseek(stdin, 0, SEEK_END);
    gets(expt);  //Leitura do Expoente em vetor de char
    printf("Mantissa(Um algarismo por vez)=\n");
    for(i=0; i<=22; i++){
        scanf("%d", &mant[i]);  //Leitura da Mantissa em forma de vetor de inteiro
    }
    printf("\nMantissa digitada: ");
    for(i=0; i<=22; i++){
        printf("%d ", mant[i]);
    }

    X = strtol(expt, NULL, 2);  //Tranformação do expoente: char--> binário ---> decimal
    not = X - 127;  //Descobrimento da notação

    for(i=0; i<=22; i++){
        for(j=-1; j>=-23; j--){
            Y = mant[i]*pow(2,j);
            i++;
            Soma = Soma + Y;  //Tranfomação da mantissa em decimal(como se todos seus componentes estivessem antes da vírgula)
        }
    }

    Soma = Soma +1;  //Acréscimo de um na mantissa em decimal
    Soma = Soma*(pow(2,not));  //Primeiro uso da fórmula

    Num = (pow(-1,sin))*Soma;  //Segundo uso da fórmula e obtenção de resultado

    printf("\n\nEm decimal, o número digitado equivale a aproximadamente %f\n\n", Num);
}
