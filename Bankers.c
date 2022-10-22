#include <stdio.h>
#include <stdlib.h>

int isSufficient(int need[], int available[], int n){
    int sufficient = 1;
    for (int i = 0; i < n; i++){
         if(available[i]<need[i]) {
            sufficient = 0;
            break;
         }
    }
    return sufficient;
}

int main(){
    int row, col;
    printf("Enter Number of Processes: ");
    scanf("%d", &row);
    printf("Enter Number of Resources: ");
    scanf("%d", &col);

    int max[row][col], allocation[row][col], need[row][col], available[col];
    
    for (int i = 0; i < row; i++){
        printf("Enter Max Values for Process %d:\n", i+1);
        for (int j = 0; j < col; j++) scanf("%d", &max[i][j]);
    }

    printf("\n");

    for (int i = 0; i < row; i++){
        printf("Enter Allocation Values for Process %d:\n", i+1);
        for (int j = 0; j < col; j++) scanf("%d", &max[i][j]);
    }

    printf("\n");

    printf("Enter Available Resources\n");
    for (int i = 0; i < col; i++) scanf("%d", &available[i]);
    
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int safestate[row];
    int completed[row];
    int safeprocesses = 0;
    int solveable;
    do{
        solveable = -1;
        for (int i = 0; i < row; i++){
            if(completed[i]!=1){
                if(isSufficient(need[i], available, row)){
                    solveable = 1;
                    safestate[safeprocesses] = i;
                    safeprocesses++;
                    completed[i] = 1;
                    for (int j = 0; j < row; j++){
                        available[j] += allocation[i][j];
                    }
                }
            }
        } 
    }while(safeprocesses!=row && solveable!=-1);

    if(safeprocesses!=row) printf("Not Safe");
    else {
        for (int i = 0; i < row; i++){
            printf("%d ", safestate[i]);  
        }
    }
    return 0;
}
