#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include <string.h>

#define n 100

void Aleatorio();
void Datos();

char M[n][n] = {0}; //matriz
char Palabras[n][n]; //guarda las palabras
int tam[n];//tamaño de las palabras
int nu; //nxn
int k; //cantidad de palabras
int contador1=0;
int v3;
int tmx[10],tmy[10];

void contador();
void horizontal();
void vertical();
void Diagonal();
 
int main(){
    int co2=0;
    int time0;
    int time1;
    int fallos=0;
    int correcto=0;
    int numero;
    char pal[20];
    srand(time(NULL));
    Datos(); //funcion que pide numeros
    printf("ingrese las palabras\n");

    for(int i=0 ; i<k ; i++ ){
        scanf("%s",&pal);
        for( int j=0 ; j<n,pal[j]!='\0' ; j++ ){
            Palabras[i][j]= pal[j];
        }
    }

    contador();

    for( v3=0 ; v3<k ; v3++){   
        numero = rand() % (2+1);
        if( numero==0 ){ //horizontal
            horizontal();
        }
        if( numero==1 ){ //vertical
            vertical();
        }
        if( numero==2 ){ //primera diagonal
            Diagonal();
        }
    }

    system("cls"); 

    for( int i=0 ; i<nu ; i++){
        for( int j=0 ; j<nu ; j++){
            printf("[%c]",M[i][j]);
        }
        printf("\n");
    }
    time0 = time(NULL);
    do{
        printf("\ningrese la palabra\n");
        scanf("%s",&pal);

        co2=0;

        for( int i=0 ; i<k ; i++){
            if( strlen(pal)==tam[i] && M[tmx[i]][tmy[i]]==Palabras[i][0] ){
                printf("correcto\n");
                correcto++;
                co2++;
                printf("%d,%d\n",tmx[i],tmy[i]);
            }
        }
        if( co2==0 ){
            fallos++;
        }
        if( fallos>3 ){
            time1=time(NULL);
            printf("perdiste!!!!\n%d",time1-time0);         
            return 0;
        }    
    }while( correcto<k );
    time1=time(NULL);
    printf("\nGanaste\n%d",time1-time0);

    return 0;

}

void Datos(){// pide los valores de las variables globales
    printf("nxn=\n");
    scanf("%d",&nu); //hasta donde va a llegar la matriz

    printf("ingrese el numero de palabras\n");    
    scanf("%d",&k); //cantidad del vector de la struct
    
    Aleatorio(); //llama a aleatorio para que llene la matriz con letras
} 
void Aleatorio(){ //se encarga de regenar la matriz hasta el nxn = nu, ingresado por el usuario
    srand(time(NULL));
    int i,j;
    for( i=0 ; i<nu ; i++){
        for( j=0 ; j<nu ; j++ ){
            M[i][j]=  (rand()%26)+97;
        }
    }
}
void contador(){
    int i,p;
    for( i=0 ; i<k ; i++ ){
        for( p=0 ; Palabras[i][p]!='\0' ; p++ ){
        }
        tam[i]=p;
    }
}
void horizontal(){
    int ss;
    int con1; //cuenta las palabras hacia adelante
    int x,y; // coordenadas de la palabra 
    while( 1 ){
      x = rand() % nu;   //tamaño x de nu que es de la matriz 
      y = rand() % nu;   //tamaño y de nu que es de la matriz
      con1=0;
        while( y<nu ){ //verifica el tamaño de la parte de la matriz
            y++;
            con1++;
        }
            if( con1>=tam[v3] ){
                ss=0;
                tmx[v3]=x;
                tmy[v3]=(y-con1);
                for( int i=(y-con1) ; Palabras[v3][ss]!='\0' ; i++){
                        M[x][i]=Palabras[v3][ss];
                    ss++;
                }
                break;    
            }  
        if( (nu-con1)>=tam[v3] ){
            ss=0;
            tmx[v3]=x;
            tmy[v3]=(y-con1);
            for( int j=(y-con1) ; Palabras[v3][ss]!='\0' ; j--){
                    M[x][j]=Palabras[v3][ss];
                ss++;
            }
            break;
        }
    }
}
void vertical(){
    int ss; 
    int con2;
    int x,y; // coordenadas de la palabra 
    while( 1 ){
      x = rand() % nu;   //tamaño x de nu que es de la matriz 
      y = rand() % nu;   //tamaño y de nu que es de la matriz
      con2=0; 
        while( x<nu ){
            x++;
            con2++;
        }
            if( con2>=tam[v3] ){
                ss=0;
                tmx[v3]=(x-con2);
                tmy[v3]=(y);
                for( int i=(x-con2) ; Palabras[v3][ss]!='\0' ; i++){
                        M[i][y]=Palabras[v3][ss];
                    ss++;
                }
                break;
            }  
        if( (nu-con2)>=tam[v3] ){
            tmx[v3]=(x-con2);
            tmy[v3]=(y);            
            ss=0;
            for( int j=(x-con2) ; Palabras[v3][ss]!='\0' ; j--){
                    M[j][y]=Palabras[v3][ss];
                ss++;
            }
            break;
        }
    }
}
void Diagonal(){
    int ss;
    int con1;
    int j;
    int x,y; // coordenadas de la palabra 
    while( 1 ){
        x = rand() % nu;   //tamaño x de nu que es de la matriz 
        y = rand() % nu;   //tamaño y de nu que es de la matriz
        con1=0;
        while( x<=nu ){
            y++;
            x++;
            con1++;
        }
        if( con1>=tam[v3] ){ //diagonal izquierda normal
            ss=0;
            tmx[v3]=(x-con1);
            tmy[v3]=(y-con1);
            for( int i=(y-con1),j=(x-con1) ; Palabras[v3][ss]!='\0' ; i++,j++){
                    M[j][i]=Palabras[v3][ss];
                ss++;
            }
            break;
        }
        if( (x-con1)>=tam[v3] ){ //diagonal izquierda alreves
            ss=0;
            tmx[v3]=(x-con1);
            tmy[v3]=(y-con1);
            for( int i=(y-con1), j=(x-con1) ; Palabras[v3][ss]!='\0' ; i--,j--){
                    M[j][i]=Palabras[v3][ss];
                ss++;
            }
            break;            
        }
    }
}
