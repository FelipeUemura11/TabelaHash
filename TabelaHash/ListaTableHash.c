#include<stdio.h>
#include<stdlib.h>
#define tam 19

// LISTA ENCADEADA
// >> Numero de elementos: 10 <<
// >> Tamanho do vetor: 15 x 2 = 20 -> numero primo mais proximo: 19 <<

typedef struct no{
    int chave;
    struct no *prox;
}No;

typedef struct{
    No *inicio;
    int tamanho;
}Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tamanho = 0;
}

void addLista(Lista *l, int valor){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->chave = valor;
        novo->prox = l->inicio;
        l->inicio = novo;
        l->tamanho++; 
    }else{
        printf("Erro ao alocar memoria\n");
    }
}

int searchLista(Lista *l, int valor){
    No *aux = l->inicio;
    while(aux && aux->chave != valor){
        aux = aux->prox;
    }
    if(aux){
        return aux->chave;
    }
    return 0;
}

void listar(Lista *l){
    No *aux = l->inicio;
    printf("Tam: %d", l->tamanho);
    while(aux){
        printf("[%d] ", aux->chave);
        aux = aux->prox;
    }
}

void criarVetor(Lista vet[]){
    int i;
    for(i = 0; i < tam; i++){
        inicializarLista(&vet[i]); // inicializa o vetor com 0 para indicar posicao vazia no vetor;
    }
}

int funcaoHash(int chave){
    return chave % tam;
}

void add(Lista vet[], int elemento){
    int indice = funcaoHash(elemento);
    addLista(&vet[indice], elemento);
    // Enquanto a posicao indice for diferente de 0, vai ler a proxima posicao ate achar uma posicao vazia
}

int search(Lista vet[], int chave){
    int indice = funcaoHash(chave);
    // Enquanto a posicao indice for diferente de 0, vai ler a proxima posicao ate achar uma posicao vazia
    printf("Indice gerado: %d", indice);
    return searchLista(&vet[indice], chave);
    return 0;
}

void list(Lista vet[]){
    int i;
    for(i = 0; i < tam; i++){
        printf("%2d = ",i);
        listar(&vet[i]);
        printf("\n");
    }
}

int main(){

    Lista vetor[tam];
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