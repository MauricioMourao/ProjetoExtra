#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]){

	int thread_count = strtol(argv[1], NULL, 10);

	int i, j;
	int m[5][5] = {{5, 9, 3, 7, 1}, {4, 8, 2, 6, 3}, {3, 1, 1, 7, 8}, {9, 3, 4, 8, 9}, {4, 6, 2, 1, 6}}; //Matriz
	int v[5] = {5, 7, 4, 6, 8}; //Vetor
	int r[5] = {0}; //Resultado
	
	printf("Thread em uso:\n");
	# pragma omp parallel for num_threads(thread_count) //Pragma com for
	
	for (i = 0; i < 5; i++){
		r[i] = 0;
		for (j = 0; j < 5; j++){
			r[i] += m[i][j] * v[j];
		}
		int my_rank = omp_get_thread_num(); //não consegui criar my_rank nem thread_count antes, portanto ela é criada diversas vezes no for
		int thread_count = omp_get_num_threads();
		printf("Thread %d de %d\n", my_rank, thread_count); //Mostra qual thread está sendo usada
	};
	
	printf("\nMatriz:\n");
	for (i=0; i<5; i++){ //Printa a Matriz
		for(j=0; j<5; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}

	printf("\nVetor:\n");
	for (i=0; i<5; i++){ //Printa o Vetor
		printf("%d\n", v[i]);
	}

	printf("\nResultado:\n");
	for (i=0; i<5; i++){ //Printa o Resultado
		printf("%d\n", r[i]);
	}
	
	return 0;
}
