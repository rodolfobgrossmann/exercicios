#include <stdio.h>

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize);

int main()
{
    int difficulty[] = {2, 4, 6, 8, 10};
    int profit[] = {10, 20, 30, 40, 50};
    int worker[] = {4, 5, 6, 11};
    
    int difficultySize = sizeof(difficulty) / sizeof(difficulty[0]);
    int profitSize = sizeof(profit) / sizeof(profit[0]);
    int workerSize = sizeof(worker) / sizeof(worker[0]);
    
    int maxProfit = maxProfitAssignment(difficulty, difficultySize, profit, profitSize, worker, workerSize);
    
    printf("O lucro máximo atribuído é: %d\n", maxProfit);
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    int flag = 0;
    int accu = 0, aux=0, pAnt;
    int i, j = 0;
    for(j = 0; j<workerSize; j++){
        pAnt = 0;
        for(i = 0; i < difficultySize ; i++){
            if(worker[j] >= difficulty[i] && profit[i] >= pAnt){
                aux = i;
                flag = 1;
                pAnt = profit[i];
            }
        }
        if (flag == 1){
            accu += profit[aux];
            flag = 0;
        }
    }
    return accu;
}
