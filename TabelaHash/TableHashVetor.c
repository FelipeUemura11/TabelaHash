#include<stdio.h>
#include<stdlib.h>
#define tam 19

// >> Numero de elementos: 10 <<
// >> Tamanho do vetor: 15 x 2 = 20 -> numero primo mais proximo: 19 <<

void criarVetor(int vet[]){
    int i;
    for(i = 0; i < tam; i++){
        vet[i] = 0; // inicializa o vetor com 0 para indicar posicao vazia no vetor;
    }
}

int funcaoHash(int chave){
    return chave % tam;
}

void add(int vet[], int elemento){
    int indice = funcaoHash(elemento);
    // Enquanto a posicao indice for diferente de 0, vai ler a proxima posicao ate achar uma posicao vazia
    while(vet[indice] != 0){
        indice = funcaoHash(indice + 1);
    }
    vet[indice] = elemento; // posicao da tabela recebe o elemento
}

int search(int vet[], int chave){
    int indice = funcaoHash(chave);
    // Enquanto a posicao indice for diferente de 0, vai ler a proxima posicao ate achar uma posicao vazia
    while(vet[indice] != 0){
        if(vet[indice] == chave){
            return vet[indice]; //  retorna o valor da posicao
        }else{
            indice = funcaoHash(indice + 1); //  le a proxima posicao
        }
    }
    return 0;
}

void list(int vet[]){
    int i;
    for(i = 0; i < tam; i++){
        printf("posicao[%d] = %d\n", i, vet[i]);
    }
}

int main(){

    int vetor[tam];
    int opcao = -1;
    int elemento;
    int resultado;

    criarVetor(vetor);

    do{
        printf("\n=========== TABELA HASH ===========");
        printf("\n>         1. Adicionar            <");
        printf("\n>         2. Buscar               <");
        printf("\n>         3. Listar               <");
        printf("\n>         0. Sair                 <");

        printf("\n>> Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf(" >> Digite o elemento a ser adicionado: ");
                scanf("%d", &elemento);
                add(vetor, elemento);
                break;
            case 2:
                printf(" >> Digite o elemento a ser buscado: ");
                scanf("%d", &elemento);

                resultado = search(vetor, elemento);

                if(resultado != 0){
                    printf("\n >> Elemento [%d] encontrado! << ", resultado);
                }else{
                    printf("\n >> Elemento [%d] nao encontrado! << ", elemento);
                }
                break;
            case 3:
                list(vetor);
                break;
            case 0:
                break;
            default:
                printf("------------------------------------");
                printf("\n >> Opcao invalida, Tente enovamente! << \n");
                break;
        }
    }while(opcao != 0);

    printf("\nSaindo do programa...");

    return 0;
}