#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define assentos 5

typedef struct {
    int tamanho;         //tamanho da fileira das cadeiras
    int menorCadeira;    //numero minimo da cadeira disponível       
    bool *cadeiras;      //apontará para uma lista de cadeiras
                         //representadas por flags para indicar se estão ocupadas ou não
} SeatManager;

SeatManager* seatManagerCreate(int n);
int seatManagerReserve(SeatManager* obj);
void seatManagerUnreserve(SeatManager* obj, int seatNumber);
void seatManagerFree(SeatManager* obj);

int main()
{
    SeatManager *obj = seatManagerCreate(assentos);
    seatManagerReserve(obj);
    seatManagerReserve(obj);
    seatManagerUnreserve(obj,2);
    seatManagerReserve(obj);
    seatManagerReserve(obj);
    seatManagerReserve(obj);
    seatManagerReserve(obj);
    seatManagerUnreserve(obj,5);
    for(int i = 1; i <= assentos; i++){
        printf("cadeira %d está ", i);
        if(obj->cadeiras[i] == 0){
            printf("livre.\n");
        }else printf("reservada.\n");
        
    }
}


SeatManager* seatManagerCreate(int n) {
    //inicialização do malloc e do calloc
    SeatManager *obj = malloc(sizeof(SeatManager)); //inicia o SeatManager
    if (obj == NULL){
        printf("Memória indisponível");
        exit(1);
    }
    obj->cadeiras = calloc( (n+1) , sizeof(bool));//inicia as cadeiras com 0 em todas, por isso usar calloc
    if (obj->cadeiras == NULL){
        printf("Memória indisponível");
        exit(1);
    }
    obj->menorCadeira = 1; //como obj foi com malloc, devemos inserir os dados, para não pegar lixo
    obj->tamanho = (n+1);  // **n+1 para não utilizar o indice 0**
    return obj; //retorna o obj, já que a função é do tipo SeatManager, indicando o tipo do retorno como struct
}

int seatManagerReserve(SeatManager* obj) {
    //mostra a cadeira de menor numero que não está reservada, reserva e retorna o número
    int x;                         //marcador pra cadeira mínima
    x = obj->menorCadeira;         //pega o número da cadeira para usar como índice nos ponteiros bool
    (obj->cadeiras)[x] = true;     //marca como reservada a cadeira de numero x
    while(obj->menorCadeira < obj->tamanho && obj->cadeiras[obj->menorCadeira] == true){
        obj->menorCadeira++;       //enquanto o numero da menorCadeira está dentro do possivel da lista
                                   //e essa cadeira estiver ocupada, encrementa o numero de menorCadeira
    }
    return x;
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    obj->cadeiras[seatNumber] = false;   //tira a reserva dessa cadeira
    if (obj->menorCadeira > seatNumber ){//checa se seatNumber é menor que a atual cadeiraMenor
        obj->menorCadeira = seatNumber;  //se for, atribui seatNumber para cadeiraMenor
    }

}

void seatManagerFree(SeatManager* obj) {
    free(obj->cadeiras); //free na lista de cadeiras
    obj->cadeiras = NULL;//evitar ponteiros soltos
    free(obj);           //free no obj SeatManager
    obj = NULL;          //novamente, evitando ponteiros soltos
}
