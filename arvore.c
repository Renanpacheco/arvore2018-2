#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int valor; 
	struct nodo * dir, * esq;
};

/* Inicializa uma árvore
 * @param entradas número de valores iniciais
 * @param valores vetor com valores a serem inseridos
 * @return raiz da árvore ou NULL se erro
 */ 
struct nodo * inicializa_arvore(int entradas, int * valores);

/* Insere nodo em uma árvore se a chave ainda não existir, sempre como uma folha
 * @param raiz raiz da árvore
 * @param valor o que será inserido 
 * @return raiz da árvore
 */ 
struct nodo * insere_nodo(struct nodo * raiz, int valor);

/* Remove nodo em uma árvore se existir, dando prioridade à subárvore esquerda para novo nodo raiz
 * @param raiz raiz da árvore
 * @param valor o que será removido 
 * @return raiz da árvore
 */ 
struct nodo * remove_nodo(struct nodo * raiz, int valor);

/* Altura de uma árvore
 * @param raiz raiz da árvore
 * @return altura da árvore
 */
int altura(struct nodo * raiz);

/* Consulta se nodo existe
 * @param raiz raiz da árvore 
 * @param valor chave a ser buscada
 * @return ponteiro para nodo, ou NULL se inexistente
 */
struct nodo * busca(struct nodo * raiz, int valor);

/* Descobre se uma árvore está balanceada
 * @param raiz da árvore
 * @return diferença das alturas das subárvores
 */
int balanceada(struct nodo * raiz);


/* Número de elementos em uma árvore 
 * @param raiz raiz da árvore
 * @return número de elementos da árvore 
 */
int numero_elementos(struct nodo * raiz);

/* Percorre a árvore em abrangência 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int abrangencia(struct nodo * raiz, int * resultado);

/* Percorre a árvore de forma pré-fixada 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int prefix(struct nodo * raiz, int * resultado);

/* Percorre a árvore de forma pós-fixada 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int postfix(struct nodo * raiz, int * resultado);

/* Percorre a árvore de forma infix 
 * @param raiz raiz da árvore
 * @param resultado vetor onde será armazenado o percurso (já deve estar alocado)
 * @return número atual de elementos no vetor
 */
int infix(struct nodo * raiz, int * resultado);

/* Imprime na stdio os valores de um caminhamento com um espaço entre cada valor, 
 * máximo de 10 valores por linha
 * @param valores vetor com valores a serem impressos
 * @param tamanho número de entradas no vetor de valores
 */
void imprime(int * valores, int tamanho);

/* Remove todos os nodos
 * @param raiz da árvore
 */
void remove_todos(struct nodo * raiz);

int main(){
	return 0;
}

/* Inicializa uma árvore
 * @param entradas número de valores iniciais
 * @param valores vetor com valores a serem inseridos
 * @return raiz da árvore ou NULL se erro
 */ 
 //@param entradas quantos valores terei
struct nodo * inicializa_arvore(int entradas, int * valores){
	int i;
	struct nodo *aux;
	
	if(!valores){
		//return criar_nodo(valores);
		return NULL;
	}else{
		aux=malloc(sizeof(struct nodo));
		for(i=0;i<entradas;i++){
			aux=insere_nodo(valores,valores[i]);
			valores++;
		}		
	}	
	return aux;	
}

struct nodo * criar_nodo(int val){
	struct nodo *aux;
	
	aux=malloc(sizeof(struct nodo));
	aux->valor=val;
	aux->dir=NULL;
	aux->esq=NULL;
	
	return aux;	
}

/* Insere nodo em uma árvore se a chave ainda não existir, sempre como uma folha
 * @param raiz raiz da árvore
 * @param valor o que será inserido 
 * @return raiz da árvore
 */ 
struct nodo * insere_nodo(struct nodo * raiz, int valor){
	
	if(raiz==NULL){
		return criar_nodo(valor);		
	}else{
		if(valor>raiz->valor){
			raiz->dir=insere_nodo(raiz->dir,valor);
		}else{
			if(valor<raiz->valor){
				raiz->dir=insere_nodo(raiz->esq,valor);
			}/*else{
				return raiz;
			}*/
		}
		return raiz;
	}
	
}

/* Consulta se nodo existe
 * @param raiz raiz da árvore 
 * @param valor chave a ser buscada
 * @return ponteiro para nodo, ou NULL se inexistente
 */
struct nodo * busca(struct nodo * raiz, int valor){
	
	if(raiz==NULL){
		return NULL;
	}else{
		if(raiz->valor==valor){
			return raiz;
		}else{
			if(raiz->valor>valor){
				return raiz->dir;
			}else{
				
				return raiz->esq;
			}
			
		}
		
	}
	
}

/* Altura de uma árvore
 * @param raiz raiz da árvore
 * @return altura da árvore
 */
int altura(struct nodo * raiz){
	int alt_esq,alt_dir;//guardar os valores das arvores esquerda e direita
	if(/*(raiz->dir==NULL && raiz->esq==NULL) ||*/ raiz==NULL){
		return 0;
	}else{
		if(raiz->dir==NULL && raiz->esq==NULL){
			return 1;
		}else{
			alt_esq=altura(raiz->esq);
			alt_dir=altura(raiz->dir);
			return alt_esq-alt_dir;
		}
		
		
	}
	
	
}
