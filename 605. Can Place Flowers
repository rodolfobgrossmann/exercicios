bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i;
    int contaflor = 0;
    int vetor[flowerbedSize];
    for( i = 0 ; i < flowerbedSize; i++ ){ //copia flowerbed
        vetor[i] = flowerbed[i];
    }
    if (flowerbedSize == 1){
        if ((flowerbed[0] == 1) && (n >= flowerbed[0]) ) return false;
        else if ((flowerbed[0] == 0) && (n > 1) ) return false;
        else return true;
    }else{

        for( i = 0 ; i < flowerbedSize ; i++ ){
            if ( (i != 0) && (i != flowerbedSize - 1 ) && (flowerbed[i] == 0) ){ 
                if( ( vetor[i-1] + vetor[i+1] ) == 0 ){                  
                    vetor[i] = 1;  
                    contaflor++;                                               
                }
            }else if ( (i == 0) && ( ( vetor[i] + vetor[i+1] ) == 0) ){ 
                vetor[i] = 1;   
                contaflor++;                                                 
            }else if ( i == ( flowerbedSize - 1) && ( vetor[i] + vetor[i-1] ) == 0 ){
                vetor[i] = 1;
                contaflor++;                                                    
            }
        }
    }
    if (contaflor >= n){
        return true;
    }else {
        return false;
    }
}
