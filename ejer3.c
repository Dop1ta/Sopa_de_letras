#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>

#define n 100

void Aleatorio();
void Datos();
void casos();

char M[n][n] = {0}; //matriz
int nu; //nxn
int k; //cantidad de palabras
float save[20]; //guarda las coordenadas de las palabras
int contador=0;
int v2=0;

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
void casos(){
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
    v2++; //struct
    int con1=0; //cuenta las palabras hacia adelante
    int i,j; //indices del for
    int x,y; // coordenadas de la palabra 
    srand(time(NULL));
    while( i<nu || j<nu ){
      x = rand() % (nu+1);   //tamaño x de nu que es de la matriz 
      y = rand() % (nu+1);   //tamaño y de nu que es de la matriz

        while( y<nu ){ //verifica el tamaño de la parte de la matriz
            y++;
            con1++;
        }
            if( con1>=(strlen(V1[v2]->palabras)-1) ){
                for( int i=(y-con1) ; i<nu ; i++){
                    if(M[x][i]==0){
                        M[x][i]=V1[v2]->palabras;
                    }
                }
                if( i<nu || j<nu ){
                    contador++;
                    save[contador] = y/10;
                    save[contador] += x;
                }
            }  
        if( y>=(strlen(V1[v2]->palabras)-1) ){
            for( int j=(y-con1) ; j>-1 ; j--){
                if(M[x][j]==0 || M[x][j]==V1[v2]->palabras){
                    M[x][j]=V1[v2]->palabras;
                }
            }
            if( i<nu || j<nu ){
                contador++;
                save[contador] = y/10;
                save[contador] += x;
            }
        }
    }
}

void vertical( struct Empire_State V1 ){
    v2++;
    int con2;
    int i,j; //indices del for
    int x,y; // coordenadas de la palabra 
    srand(time(NULL));
    while( i<nu || j<nu ){
      x = rand() % (nu+1);   //tamaño x de nu que es de la matriz 
      y = rand() % (nu+1);   //tamaño y de nu que es de la matriz

        while( x<nu ){
            x++;
            con2++;
        }
            if( con2>=(strlen(V1[v2]->palabras)-1) ){
                for( int i=(x-con2) ; i<nu ; i++){
                    if(M[i][y]==0){
                        M[i][y]=V1[v2]->palabras;
                    }
                }
                if( i<nu || j<nu ){
                    contador++;
                    save[contador] = y/10;
                    save[contador] += x;
                }
            }  
        if( x>=(strlen(V1[v2]->palabras)-1) ){
            for( int j=x ; j>-1 ; j--){
                if(M[j][y]==0 || M[x][j]==V1[v2]->palabras){
                    M[j][y]=V1[v2]->palabras;
                }
            }
            if( i<nu || j<nu ){
                contador++;
                save[contador] = y/10;
                save[contador] += x;
            }
        }
    }
}
void Diagonal_1( struct Empire_State V1 ){
    v2++;
    int con1=0;
    int i,j; //indices del for
    int x,y; // coordenadas de la palabra 
    srand(time(NULL));  
    while( i<nu || j<nu ){
        x = rand() % (nu+1);   //tamaño x de nu que es de la matriz 
        y = rand() % (nu+1);   //tamaño y de nu que es de la matriz
        
        while(y<nu){
            y++;
            x++;
            con1++;
        }
        if( con1>=(strlen(V1[v2]->palabras)-1) ){ //diagonal izquierda normal
            for( i=(y-con1),j=(x-con1) ; i<con1 ; i++,j++){
                if(M[i][j]==0){
                    M[i][j]==V1[v2]->palabras;
                }
            }
            if( i<nu || j<nu ){
                contador++;
                save[contador] = y/10;
                save[contador] += x;
            }
        }
        if( (y-con1)>(strlen(V1[v2]->palabras)-1) ){ //diagonal izquierda alreves
            for( i=(y-con1),j=(x-con1) ; i<con1 ; i--,j--){
                if(M[i][j]==0){
                    M[i][j]==V1[v2]->palabras;
                }
            }
            if( i<nu || j<nu ){
                contador++;
                save[contador] = y/10;
                save[contador] += x;
            }            
        }
    }
}
