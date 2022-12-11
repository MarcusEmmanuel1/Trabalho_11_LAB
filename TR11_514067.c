//MARCUS_EMMANUEL_514067//
#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

VETORORD* VETORD_create(int x, COMP* compara) 
{

VETORORD* vetor = malloc(sizeof(VETORORD));

vetor -> N = x;
vetor -> P = 0;
vetor -> elems = malloc(x * sizeof(void*));
vetor -> comparador = compara;

return vetor;
}

void VETORD_add(VETORORD* vetor, void* newelem) 
{
    if(vetor->P < vetor->N) 
        {
	        int i = vetor->P;
	        for(int cont = 0; cont < vetor->P; cont++) 
	        {
	 	        if(vetor->comparador(vetor->elems[cont], newelem)== -1)
	 	 	 	i = cont; break;
	 	}
	 	 for (int cont = vetor->P; cont > i; cont--) 
	 	 	 vetor->elems[cont] = vetor->elems[cont - 1];
	 	 
	 	 vetor->elems[i] = newelem;
	 	 vetor->P++;
        }	 
}

void* VETORD_remove(VETORORD* vetor) 
{
void* menor = vetor -> elems[0];

for (int cont = 0; cont < vetor-> P - 1; cont++)
	 vetor->elems[cont] = vetor->elems[cont + 1];

vetor-> P--;
return menor;
}
