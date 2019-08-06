#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>

#define n 100

void Aleatorio();
void Datos();

char M[n][n] = {0}; //matriz
int nu; //nxn
int k; //cantidad de palabras

struct Empire_State{ //alamacena las palabras (vector de estructura)
    char palabras[20];
};

void horizontal( struct Empire_State V1);
void vertical( struct Empire_State V1);
void Diagonal_1( struct Empire_State V1);
void Diagonal_2( struct Empire_State V1);

void contador(struct Empire_State);   

int main(){
    Datos(); //funcion que pide numeros

    struct Empire_State V[k];

    printf("ingrese las palabras");
    for( int i=0 ; i<k ; i++)
       scanf("%s",V[i].palabras);

    system("cls");


    return 0;
}

void Datos(){// pide los valores de las variables globales
    printf("nxn=");
    scanf("%d",&nu); //hasta donde va a llegar la matriz

    printf("ingrese el numero de palabras");    
    scanf("%d",&k); //cantidad del vector de la struct
    
    Aleatorio(); //llama a aleatorio para que llene la matriz con letras
} 
void Aleatorio(){ //se encarga de regenar la matriz hasta el nxn = nu, ingresado por el usuario
    srand(time(NULL));
    int i,j;
    for( i=0 ; i<nu ; i++)
        for( j=0 ; j<nu ; j++ )
            M[i][j]=  'a' + rand() % (('z' - 'a') + 1);

}
void contador(){
    int numero;
    srand(time(NULL));
    numero = rand() % (3+1);
    if( numero==0 ){ //horizontal
        horizontal();
    }
    if( numero==1 ){ //vertical
        vertical();
    }
    if( numero==2 ){ //primera diagonal
        Diagonal_1();
    }
    if( numero==3 ){//segunda diagonal
        Diagonal_2();
    }
}
void horizontal( struct Empire_State V1 ){
    int x,y;
    int contador;
    srand(time(NULL));
    x = rand() % (nu+1);
    y = rand() % (nu+1);

    while( y<=nu ){
        y++;
    }
    if( nu-y>= ){
         
    }
    y=0;
    while( y<=0){
        y--;
    }
    if(  )
}