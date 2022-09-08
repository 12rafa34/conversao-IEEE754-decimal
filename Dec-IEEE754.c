#include <stdio.h>
#include <locale.h>

// estrutura do Ieee 754 em um typedef
typedef union{
    float f;
    struct{
        unsigned int mantissa : 23; // mantissa // unsigned para manter sem sinal + ou -
        unsigned int exponente : 8; // expoente // unsigned para manter sem sinal + ou -
        unsigned int sinal : 1;     // sinal // unsigned para manter sem sinal + ou -
    } ieee;
} Ieee754_padrao_flutuante;

void decimal_para_binario(int y, int max);            // função
void impressao_pronta(Ieee754_padrao_flutuante good); // função

main(){
    setlocale(LC_ALL, "Portuguese"); // tirar bugs de acentos

    float num;
    printf("-----------------------------------\n   DECIMAL ----> BINÁRIO IEE-754 \n___________\n");

    printf("Insira o número flutuante: ");
    scanf("%f", &num); // entrada de número float

    Ieee754_padrao_flutuante good; // conversão

    good.f = num;
    impressao_pronta(good);
}

// imprimir o máximo de números binários de acordo com a quantidade de bits
void decimal_para_binario(int y, int max){
    int num[32]; // armazenar números binários em 32 bits
    int x = 0;
    while (y > 0){
        num[x] = y % 2;
        y = y / 2;
        x++;
    }
    for (int i = 1; i <= (max - x); i++){
        printf("0");
    }
    for (int j = x - 1; j >= 0; j--){
        printf("%d", num[j]);
    }
}

// imprimir o ieee754 pronto
void impressao_pronta(Ieee754_padrao_flutuante good){
    printf("%d | ", good.ieee.sinal);             // imprimir sinal // divisória para manter código limpo
    decimal_para_binario(good.ieee.exponente, 8); // imprimir expoente
    printf(" | ");                                // divisória para manter código limpo
    decimal_para_binario(good.ieee.mantissa, 23); // imprimir mantissa
    printf("\n");
}
