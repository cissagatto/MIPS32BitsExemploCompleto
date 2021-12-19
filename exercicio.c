#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int som=0, med=0, a=0, b=0, d=0, op=0, i=0;
int g[];
int f[15] = {-17, 14,10, -19, 9, -7, -14, -8, 0, -13, 6, -10, -4, 18, 15};
int c[15] = {-9, 19, -11, -8, -19, 14, 3, 13, 11, 9, -16, -15, 4, 2, -1};
int e[15] = {8, 4, -3, 9, 18, 7, -12, 6, -6, -20, 5, -13, 16, 20, -4};

void se_simples(int a, int b, int c[], int e[]){
	if(a==b){
		a = b + c[0];
		a = (a || b); // OR
		e[0] = a;
		printf("\na é igual a b");
        printf("\na: %d", a);
        printf("\ne[0]: %d", e[0]);
	}

	printf("\na não é igual a b");
}

void se_composto(int a, int b, int d, int e[]){
	if (a != b) {
		e[0] = d+b;
		e[1] = (d && b); // AND
        printf("\na não é igual a b");
        printf("\ne[0]: %d", e[0]);
        printf("\ne[1]: %d", e[1]);
	} else {
		e[0] = d-b;
		e[1] = d+b;
		printf("\na é igual a b");
        printf("\ne[0]: %d", e[0]);
        printf("\ne[1]: %d", e[0]);
	}
}

void loop_for(int f[]){
    for(i=0; i<10; i++) {
        som = f[i] + som;
    }
    printf("\nSoma: %d", som);
}

void loop_while(int g[]){  
    i = 0;
    while(i <= 5){
		printf("\ng[%d] =  %d", i, g[i]);
		i = i + 1;
	}	
}

void matriz(int h[][]){
    linha = 1;
    coluna = 1;
    for(linha=0; i<2; linha++){
        for(coluna=0; coluna<2; coluna++){
            if(i==j){
                soma += matriz[i][j];
            }
        }
    }
}

int fib(){                                          
    
} 

int main() {

    printf(" \n Digite o valor da variável a: ");
    scanf("%d", &a);
    printf(" \n Digite o valor da variável b: ");
    scanf("%d", &b);
    printf(" \n Digite o valor da variável d: ");
    scanf("%d", &d);

    printf(" \n Escolha uma das opções abaixo: ");
    printf(" \n 1. Soma ");
    printf(" \n 2. Media ");
    printf(" \n 3. Teste 1 ");
    printf(" \n 4. Teste 2 ");
    printf(" \n 5. Teste 3 ");

    printf(" \n Digite o número da opção desejada: ");
    scanf("%d", &op);

	switch (op) {
        case 1:
            printf(" \n Opção selecionada: 1 - IF SIMPLES");
    	    if_simples(a, b, c, e);
            break;
        case 2:
            printf(" \n Opção selecionada: 2 - IF COMPOSTO");
            if_composto(a, b, d, e);
            break;
        case 3:
            printf(" \n Opção selecionada: 3 - FOR");
            loop_for(f);
            break;
        case 4:
            printf(" \n Opção selecionada: 4 - WHILE");
            loop_while(g)
            break;
        case 5:
            printf(" \n Opção selecionada: 5 - MATRIZ");
            matriz(h)
            break;
	case 6:
            printf(" \n Opção selecionada: 5 - RECURSÃO");
            fib()
            break;
        default:
            printf(" \n Você digitou uma opção inválida!");
    }

    return 0;
}

