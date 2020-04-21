#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int **CrearMatriz(int ancho, int alto){
  int** Matriz;
  Matriz = (int**)malloc(sizeof(int)*ancho);
  for(int i = 0; i<ancho; i++){
    Matriz[i] = (int*)malloc(sizeof(int) * alto); //
  }

  return Matriz;
}

void RellenarConRandom(int **matriz, int tam_filas, int tam_columnas){
  //matriz[0][0] // *(*(matriz+0)+0)
  
  for(int i=0; i<tam_columnas; i++){
    for(int j=0; j<tam_filas; j++){
      //*(*(matriz+i)+j) = 20+rand()%30;
      matriz[i][j] =  20+rand()%30;
    }
  }
}

void Imprimir(int **matriz, int tam_filas, int tam_columnas){
  for(int i=0; i<tam_columnas; i++){
    for(int j=0; j<tam_filas; j++){
      printf("%d\t", *(*(matriz+i)+j) );
    }
    printf("\n");
  }
}
int **sumarMatriz(int **matriz, int tam_filas, int tam_columnas,int **matriz2){
  int **ma3 = CrearMatriz(tam_filas, tam_columnas);
  for(int i=0; i<tam_columnas; i++){
    for(int j=0; j<tam_filas; j++){
      ma3[i][j] = matriz[i][j] + matriz2 [i][j];
    }
  }
  return ma3;
} 
int main(void) {



  int **M1;
  int **M2;



  srand(time(NULL));
  M1 = CrearMatriz(2, 2);
  M2 = CrearMatriz(2, 2);

  RellenarConRandom(M1, 2, 2);
  RellenarConRandom(M2, 2, 2);

  // Mostrar Matrices
  printf("\n\nMatriz 1\n\n");
  Imprimir(M1, 2, 2);
  printf("\n\nMatriz 2\n\n");
  Imprimir(M2, 2, 2);


  // Sumar
  int **sumMatriz = sumarMatriz(M1, 2, 2, M2);
  
  
  printf("\n\nMatriz sumada\n\n");
  Imprimir(sumMatriz,2,2);
 printf("\n");
 


  free(M1);
  free(M2);
  free(sumMatriz);


  return 0;
}