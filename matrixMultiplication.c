#include <stdio.h>

int main(){
    int i, j, k, barisMat1 = 3 , kolomMat1 = 4, barisMat2 = 4, kolomMat2 = 3, total = 0;
    int matriksSiji[10][10], matriksLoro[10][10], hasilKali[10][10];

    printf("Masukin matriks (3 x 4) tod : \n");
    for (i = 0; i < barisMat1; i++){
        for (j = 0; j < kolomMat1; j++){
            scanf("%d", &matriksSiji[i][j]);
        }
    }
    printf("Masukin matriks (4 x 3) tod : \n");
 
    for (i = 0; i < barisMat2; i++){
        for (j = 0; j < kolomMat2; j++){
            scanf("%d", &matriksLoro[i][j] );
        }
    }
    //proses perkalian
    for (i = 0; i < barisMat1; i++){
        for (j = 0; j < kolomMat2; j++){
            for (k = 0; k < barisMat2; k++){
            total = total + matriksSiji[i][k] * matriksLoro[k][j];
            }
        hasilKali[i][j] = total;
        total = 0;
        }
    }
 
    printf("Hasil perkaliannya gini tod : \n"); 
    for (i = 0; i < barisMat1; i++){
        for (j = 0; j < kolomMat2; j++){
            printf("%d ", hasilKali[i][j] );
        }
        printf("\n");
    }
  return 0;
}
