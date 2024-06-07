#include <stdio.h>
#include <stdlib.h>

#define tamanho 19 // numero primo mais proximo de u vetor de 20 elementos
// Usuario
typedef struct{
    int id;
    char nome[45];
}Usuario;
// No
typedef struct no{
    Usuario usuario;
    struct no *proximo;
} No;
// Lista
typedef struct {
    No *inicio;
    int tam;
}Lista;
// vetor de posicoes da lista
Lista *tabela[tamanho];

Usuario criarUsuario(){
    Usuario p;
    printf(" >> Digite o nome da Usuario: ");
    scanf(" %*c", &p.nome); // limpar buffer
    fgets(p.nome, 45, stdin);
    printf(" >> Digite a id: ");
    scanf("%d", &p.id);
    return p;
}

void imprimirUsuario(Usuario p){
    printf("\tNome: %s\tid: %d\n", p.nome, p.id);
}
// >>> INICIO DAS FUNCOES DE LISTA <<<

// Criar lista vazia, retornando seu endereco de memoria(&);
Lista* criarLista(){
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

void inserirInicio(Usuario p, Lista *lista){
    No *no = malloc(sizeof(No));
    no->usuario = p;

    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

No* buscarNo(int mat, No *inicio){
    while(inicio != NULL){
        if(inicio->usuario.id == mat){
            return inicio;
        }else{
            inicio = inicio->proximo;
        }
    }
    return NULL;
}


void imprimirLista(No *inicio){
    while(inicio != NULL){
        imprimirUsuario(inicio->usuario);
        inicio = inicio->proximo;
    }
}

void inicializar(){
    int i;
    for(i = 0; i < tamanho; i++){
        tabela[i] = criarLista();
    }
}
// Busca pelo Hash
int funcaoHash(int mat){
    return mat % tamanho;
}

void inserirTabela(){
    Usuario pes = criarUsuario();
    int indice = funcaoHash(pes.id);
    inserirInicio(pes, tabela[indice]);
}

// Busca uma Usuario

Usuario* buscarUsuarioTabela(int mat){
    int indice = funcaoHash(mat);
    No *no = buscarNo(mat, tabela[indice]->inicio);
    if(no != NULL){
        return &no->usuario;
    }else{
        return NULL;
    }
}

// Imprimir tabela

void imprimirTabela(){

    int i;

    printf("\n >>> TABELA <<< \n");
    
    for(i = 0; i < tamanho; i++){
        printf("[%d] Tamanho da Lista: %d\n", i, tabela[i]->tam);
        imprimirLista(tabela[i]->inicio);
    }
    printf("\n >>> TABELA <<< \n");

}
int main(){

    int opcao = 0, mat;
    Usuario *p;

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
                printf("Informe a id: ");
                scanf("%d", &mat);

                p = buscarUsuarioTabela(mat);
                if(p != NULL){
                    printf("Usuario encontrada!\n");
                    printf("id: %d\n", p->id);
                    printf("Nome: %s\n", p->nome);
                }else{
                    printf("Usuario encontrada!\n");
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
