#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/* Insere nodo em uma árvore se a chave ainda não existir, sempre como uma folha
 * @param raiz raiz da árvore
 * @param valor o que será inserido 
 * @return raiz da árvore
 */ 
struct nodo * insere_nodo(struct nodo * raiz, int valor){

    if (raiz->valor==valor){
        printf("cheguei valor igual");
        return raiz;
    }else if(raiz==NULL){
        printf("sem malloc");
        raiz= malloc(sizeof(struct nodo));
        printf("fiz malloc");
        raiz->valor=valor;
        
        raiz->dir=NULL;
        raiz->esq=NULL;
        //*raiz->esq=NULL;
        return raiz;
    }else{
        if (valor>raiz->valor){
            raiz=insere_nodo(raiz->dir,valor);
            return raiz;
        }else{
            raiz=insere_nodo(raiz->esq,valor);
            return raiz;
        }
    }
}

struct nodo * criar_arvore(struct nodo *raiz, int valor){
    raiz=malloc(sizeof(struct nodo));
    raiz->valor=valor;
    raiz->dir=NULL;
    raiz->esq=NULL;
    raiz->balanceamento=0;
    return raiz;
}
/* Inicializa uma árvore
 * @param entradas número de valores iniciais
 * @param valores vetor com valores a serem inseridos
 * @return raiz da árvore ou NULL se erro
 */ 
struct nodo * inicializa_arvore(int entradas, int * valores){
    int i=0;
    struct nodo *raiz=NULL;
    //struct nodo *raiz_temp=raiz;
    struct nodo *manter_raiz=NULL;
    int aux;    

    if((entradas<=0)|| (valores==NULL)){
        return NULL;
    }else{
        raiz=criar_arvore(raiz,*valores);
        
        for(i=1;i<entradas;i++){
            aux=*valores;
            raiz=insere_nodo(manter_raiz , aux);
            valores++;
            }

        }
        return raiz;
}
/* Remove nodo em uma árvore se existir, dando prioridade à subárvore esquerda para novo nodo raiz
 * @param raiz raiz da árvore
 * @param valor o que será removido 
 * @return raiz da árvore
 */ 

struct nodo * remove_nodo(struct nodo * raiz, int valor){
    printf("%d",valor);
    return raiz;
}

/* Altura de uma árvore
 * @param raiz raiz da árvore
 * @return altura da árvore
 */
int altura(struct nodo * raiz){
    printf("%p",raiz);
    return 0;
}

/* Consulta se nodo existe
 * @param raiz raiz da árvore 
 * @param valor chave a ser buscada
 * @return ponteiro para nodo, ou NULL se inexistente
 */
struct nodo * busca(struct nodo * raiz, int valor){
    printf("%d",valor);
    return raiz;
}

/* Descobre se uma árvore está balanceada
 * @param raiz da árvore
 * @return diferença das alturas das subárvores
 */
int balanceada(struct nodo * raiz){
    printf("%p",raiz);
    return 0;
}


/* Número de elementos em uma árvore 
 * @param raiz raiz da árvore
 * @return número de elementos da árvore 
 */
int numero_elementos(struct nodo * raiz){
    printf("%p",raiz);
    return 0;
}

/* Percorre a árvore em abrangência 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int abrangencia(struct nodo * raiz, int * resultado){
    printf("%p",raiz);
    return *resultado;
}

/* Percorre a árvore de forma pré-fixada 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int prefix(struct nodo * raiz, int * resultado){
    printf("%p",raiz);
    return *resultado;
}

/* Percorre a árvore de forma pós-fixada 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int postfix(struct nodo * raiz, int * resultado){
    printf("%p",raiz);
    return *resultado;
}

/* Percorre a árvore de forma infix 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int infix(struct nodo * raiz, int * resultado){
    printf("%p",raiz);
    return *resultado;
}

/* Imprime na stdio os valores de um caminhamento com um espaço entre cada valor, 
 * máximo de 10 valores por linha
 * @param valores vetor com valores a serem impressos
 * @param tamanho número de entradas no vetor de valores
 */
void imprime(int * valores, int tamanho){
    printf("%p %d",valores,tamanho);

}

/* Remove todos os nodos
 * @param raiz da árvore
 */
void remove_todos(struct nodo * raiz){
    printf("%p",raiz);

}