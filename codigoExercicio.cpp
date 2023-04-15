#include <iostream>

struct Pilha{
    int topo;
    int capa;
    float *pElem;
};

void criarPilha(struct Pilha *p, int c){
    p->topo = -1;
    p->capa = c;
    p->pElem = (float*) malloc (c * sizeof(float));
}

int estaVazia(struct Pilha *p){
    if(p-> topo == -1)
        return 1;
    else
        return 0;
}

int estaCheia(struct Pilha *p){
    if(p->topo == p->capa - 1)
        return 1;
    else
        return 0;
}

void empilhar(struct Pilha *p, float v){
    p->topo++;
    p->pElem [p->topo] = v;
}

float desempilhar(struct Pilha *p){
    float aux = p->pElem [p->topo];
    p->topo--;
    return aux;
}

float retornaTopo(struct Pilha *p){
    return p->pElem [p->topo];
}

int main() {
    std::cout << "Gereciamento de Pilha!";
    
    struct Pilha minhaPilha;
	int capacidade, op;
	float valor;
	
	printf("\nInforme a capacidade da pilha: ");
	scanf("%d", &capacidade);

	criarPilha(&minhaPilha, capacidade);
	
	while(1){
		printf("\n1 - Empilhar (push)");
		printf("\n2 - Desempilhar (pop)");
		printf("\n3 - Mostrar o topo");
		printf("\n4 - Sair\n");
		
		printf("\nSelecione uma opção: ");
	    scanf("%d", &op);
	    
	    switch(op){
			case 1:
				if(estaCheia(&minhaPilha) == 1){
					printf("\nPilha Cheia!\n");
				}
				else{
					printf("\nInforme o valor: ");
					scanf("%f", &valor);
					printf("\n");
					empilhar(&minhaPilha, valor);
				}
			break;
			
			case 2:
				if(estaVazia(&minhaPilha) == 1){
					printf("\nPilha Vazia!\n");
				}
				else{
					valor = desempilhar(&minhaPilha);
					printf("\n%.1f Desempilhando!\n", valor);
				}
			break;
			
			case 3:
				if(estaVazia(&minhaPilha) == 1){
					printf("\nPilha Vazia!\n");
				}
				else{
					valor = retornaTopo(&minhaPilha);
					printf("\nTopo: %.1f\n", valor);
					printf("\n");
				}
			break;
			
			case 4:
			    goto exit_loop;
				
			default: printf("\nOpção invalida!\n");
		}
	}
	exit_loop: ;
    printf("\nAplicação finalizada!");
    return 0;
}