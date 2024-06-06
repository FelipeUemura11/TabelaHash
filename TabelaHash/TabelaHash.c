#include <stdio.h>
#include <stdlib.h>

#define M 19 // numero primo mais proximo de u vetor de 20 elementos
// Pessoa
typedef struct{
    int matricula;
    char nome[45];
}Pessoa;
// No
typedef struct no{
    Pessoa pessoa;
    struct no *proximo;
} No;
// Lista
typedef struct {
    No *inicio;
    int tam;
}Lista;
// vetor de posicoes da lista
Lista *tabela[M];

Pessoa criarPessoa(){
    Pessoa p;
    printf(" >> Digite o nome da pessoa: ");
    scanf(" %*c", &p.nome); // limpar buffer
    fgets(p.nome, 45, stdin);
    printf(" >> Digite a matricula: ");
    scanf("%d", &p.matricula);
    return p;
}

void imprimirPessoa(Pessoa p){
    printf("\tNome: %s\tMatricula: %d\n", p.nome, p.matricula);
}
// >>> INICIO DAS FUNCOES DE LISTA <<<

// Criar lista vazia, retornando seu endereco de memoria(&);
Lista* criarLista(){
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

void inserirInicio(Pessoa p, Lista *lista){
    No *no = malloc(sizeof(No));
    no->pessoa = p;

    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

No* buscarNo(int mat, No *inicio){
    while(inicio != NULL){
        if(inicio->pessoa.matricula == mat){
            return inicio;
        }else{
            inicio = inicio->proximo;
        }
    }
    return NULL;
}


void imprimirLista(No *inicio){
    while(inicio != NULL){
        imprimirPessoa(inicio->pessoa);
        inicio = inicio->proximo;
    }
}

void inicializar(){
    int i;
    for(i = 0; i < M; i++){
        tabela[i] = criarLista();
    }
}
// Busca pelo Hash
int funcaoHash(int mat){
    return mat % M;
}

void inserirTabela(){
    Pessoa pes = criarPessoa();
    int indice = funcaoHash(pes.matricula);
    inserirInicio(pes, tabela[indice]);
}

// Busca uma pessoa

Pessoa* buscarPessoaTabela(int mat){
    int indice = funcaoHash(mat);
    No *no = buscarNo(mat, tabela[indice]->inicio);
    if(no != NULL){
        return &no->pessoa;
    }else{
        return NULL;
    }
}

// Imprimir tabela

void imprimirTabela(){

    int i;

    printf("\n >>> TABELA <<< \n");
    
    for(i = 0; i < M; i++){
        printf("[%d] Tamanho da Lista: %d\n", i, tabela[i]->tam);
        imprimirLista(tabela[i]->inicio);
    }
    printf("\n >>> TABELA <<< \n");

}
int main(){

    int opcao = 0, mat;
    Pessoa *p;

    // Criar lista para cada posicao da tabela
    inicializar();

    do{
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf(" >>> [1] Inserir Usuario <<<\n");
        printf(" >>> [2] Buscar Usuario <<<\n");
        printf(" >>> [3] Imprimir Usuarios <<<\n");
        printf(" >>> [4] Sair do programa <<<\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

        printf(" >>> Informe uma das opcoes: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                inserirTabela();
                break;
            case 2:
                printf("Informe a matricula: ");
                scanf("%d", &mat);

                p = buscarPessoaTabela(mat);
                if(p != NULL){
                    printf("Pessoa encontrada!\n");
                    printf("Matricula: %d\n", p->matricula);
                    printf("Nome: %s\n", p->nome);
                }else{
                    printf("Pessoa encontrada!\n");
                }
                break;
            case 3:
                imprimirTabela();
                break;
            case 4:
                break;
            default:
                printf("Opcao Invalida! Tenten novamente...");
                break;
        }

    }while(opcao != 4);

    return 0;
}