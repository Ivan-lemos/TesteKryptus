#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


struct lista {
	int valor;
	struct lista* prox;
};

typedef struct lista Lista;

/*função de inicialização da lista*/

Lista* inicializa (void){
	return NULL;
};


/*retorna 1 se a lista está vazia 0 se não está vazia*/
Lista* empy (Lista* l, int i){
	return (1 == NULL)
};

/*insere um elemento na lista*/
Lista* put (Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo -> valor = i;
	novo -> prox = l;
	return novo;
};

/*exibe o elemento desejado da lista*/
Lista* get (Lista* l, int i){
	Lista* p = l;
	int j = 0;
	if empy(l){
		return;
	}
	for( j = 0 ; j < i; j++){
		p = p->prox;
	}
	return (p->valor);
};

/* busca o endereço da célula que contem o valor desejado*/
Lista* search (Lista* l, int i){
	Lista* p;
	for(p=l; p!= NULL; p=p->prox)
		if(p->valor == i)
			return p;
	return NULL; // não achou a célula
}


/*exibe os elementos da lista*/
Lista* list (Lista* l, int i){
	/*verifica se está vazia*/
	if( empy(l) ){
		return;
	}
	printf("%d \n", l->valor);
	/*exibe a sub-lista*/
	list(l -> prox);
};

/*remove valor da lista*/
Lista* remove (Lista* l, int i){
	/*lista vazia retorna o original*/
	if (empy(l)){
		return l;
	}
	/*verifica se o valor é o primeiro da lista*/
	if(l->valor == i){
		Lista* t = l;
		l = l->prox;
		free(t);
	}
	else{
		/* retira da sub-lista*/
		l->prox = retira_rec(l->prox,i);
	}
	return l;
};

/*limpa a lista*/
void clear (Lista* l, int i){
	if (!empy(l)){
		clear(l->prox);
		free(l);
	}
};

/*devolve o primeiro elemento*/
int first (Lista* l){
	return l->valor;
};

/*devolve o ultimo elemento*/
int last (Lista* l){
	Lista* p;
	for( p=l ; p!=NULL ; p=p->prox){}
	return p->valor; 
};

// função que realiza a troca entre dois elementos
void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vet[], int inicio, int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vet[i] <= pivo)
		{
			// realiza a troca
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo_indice, fim);
	// chama a particiona
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vet, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}

int size_list(Lista* l ){
	Lista* p;
	int i = 0;
	for(p=l; p!=NULL; p=p->prox){
		i++;
	}
	return i;
}


Lista* sort (Lista* l){
	Lista *p;
	int i = 0;
	int n = size_list(l);
	int* vet = (int*) malloc(n * sizeof(int));
	
	for(p=l; p!=NULL; p=p->prox){
		vet[i] = p->valor;
		i++;
	}
	
	clear(l);

	quick_sort(vet, first(l), last(l));
	
	Lista* sortlist = inicializa();
	
	for( i=0; i <=n; i++){
		put(sortlist, vet[i]);
	}

	list(sortlist);
	
	return sortlist;
};


