//ICC II - RadixSort
//Gabriel Amlmeida Gonçalves - 9292761
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tam;
int maior;

void main()
{
int i;
clock_t init, end;
int *vet;

FILE* arq = fopen("tempoRadix.txt","wt");

   // aloca vetor com tamanhos comecando em 500 e incrementando de 200 em 200
   for (tam = 5000; NULL != (vet = malloc(tam * sizeof(int) )) ; tam = tam+500)
   {
   		if(tam>15000) break;
   		
      // preenche  vetor com numeros aleatorios
      printf("Tamanho do vetor: %d \n", tam );
      
      for (i = 0; i < tam; i++)
      {
         vet[i] = rand() % 10000;
      }
      //printf("FEITO RAND");
      
      maior = vet[0];
		for(i=1;i<tam;i++)
		{
			if(maior<vet[i])
				maior=vet[i];
		}
	//	printf("\nmaior: %d\n", maior);
			
      // conta o tempo decorrido em micro segundos
      init = clock();
      radixsort(vet,tam);
      end = clock();
      end = (end - init) / (CLOCKS_PER_SEC / 1000);
	/*	for(i=0;i<tam;i++)
			printf("%d ", vet[i]); 
		*/
      // mostra o tempo decorrido
      printf("\tTempo decorrido (1/1000 s): %ld\n", end);
		fprintf(arq,"%d\n",end);
    // libera o vetor
      free(vet);
      
      //system("pause");
   }

}

void radixsort(int vet[], int tam)
{
	int i;
	int divide=1;
	int *aux=malloc(tam*sizeof(int));
	
	for(i=0;i<tam;i++)
		aux[i]=0;

	while((maior/divide)>0)
	{
		int *b=malloc(4*tam*sizeof(int));
		
		for(i=0;i<tam;i++)
			b[(vet[i]/divide) %10]++;
		for(i=1;i<tam;i++)
			b[i]=b[i]+b[i-1];
		for(i=tam;i>=0;i--)
		{
			aux[b[(vet[i]/divide) %10]] = vet[i];
			b[(vet[i]/divide) %10]--;
		}
		for(i=0;i<tam;i++)
			vet[i]=aux[i];
			
		divide=divide*10;
	}
	free(aux);
}
	
	
	
