//ICC II - Count Sort
//Gabriel Almeida Gonçalves - 9292761
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tam;

void main()
{
int i;
clock_t init, end;
int *vet;
int *b;
int maior;

FILE *arq=fopen("tamanho.txt","wt");
FILE *arq2=fopen("tempoCount.txt","wt");

   // aloca vetor com tamanhos comecando em 500 e incrementando de 200 em 200
   for (tam = 5000; NULL != (vet = malloc(tam * sizeof(int) )) ; tam = tam+500)
   {
   		if(tam>15000) break;
   	
   		b = malloc(tam*sizeof(int));
   		
      // preenche  vetor com numeros aleatorios
      printf("Tamanho do vetor: %d \n", tam );
      fprintf(arq,"%d\n",tam);
	   
      for (i = 0; i < tam; i++)
      {
         vet[i] = rand() % 10000;
      }
      //printf("FEITO RAND");
      
      maior = vet[0];
		for(i=1;i<tam;i++)
		{
			if(vet[i]>maior)
				maior = vet[i];
		}
	//	printf("\nmaior: %d\n", maior);
			
      // conta o tempo decorrido em micro segundos
      init = clock();
      countsort(vet,b,maior);
      end = clock();
      end = (end - init) / (CLOCKS_PER_SEC / 1000);
		/*for(i=0;i<tam;i++)
			printf("%d ", b[i]); 
		*/
      // mostra o tempo decorrido
      printf("\tTempo decorrido (1/1000 s): %ld\n", end);
		fprintf(arq2,"%d\n",end);
    // libera o vetor
      free(vet);
      free(b);
      //system("pause");
   }

}


void countsort (int vet[], int b[], int maior)
{
	int *c=malloc(10000*sizeof(int));
	int i; int j;
	
	for(i=0;i<maior;i++)
		c[i]=0;
	
	for(j=0;j<tam;j++)
		c[vet[j]] = c[vet[j]]+1;
		
	for(i=1;i<maior;i++)
		c[i] = c[i] + c[i-1];
		
	for(j=tam;j>=0;j--)
	{
		b[c[vet[j]]] = vet[j];
		c[vet[j]] = c[vet[j]]-1;
	}
	free(c);
}
	
