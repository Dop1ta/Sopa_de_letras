#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>

#define n 100

void Aleatorio();
void Datos();

char M[n][n] = {0}; //matriz
char Palabras[n][n]; //guarda las palabras
int tam[n];//tamaño de las palabras
int nu; //nxn
int k; //cantidad de palabras
float save[20]; //guarda las coordenadas de las palabras //////////////////////////revisar
int contador1=0;
int v2=0;
int v3;

void contador();
void horizontal();
void vertical();
void Diagonal_1();
void Diagonal_2();
 

int main(){
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
    for( int o=0 ; o<k ; o++ ){
        for( int m=0 ; m<n ; m++ ){
            printf("%c",Palabras[o][m]);
        }
        printf("\n");
    }    

    contador();

    for( v3=0 ; v3<k ; v3++){   
        numero = rand() % (3+1);
        printf("%d\n",numero);
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
    //system("cls");

    
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
            M[i][j]=  'a' + rand() % (('z' - 'a') + 1);
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
    int con1=0; //cuenta las palabras hacia adelante
    int i,j; //indices del for
    int x,y; // coordenadas de la palabra 
    while( 1 ){
      x = rand() % (nu+1);   //tamaño x de nu que es de la matriz 
      y = rand() % (nu+1);   //tamaño y de nu que es de la matriz
      printf("%d %d\n",x,y);  
        while( y<nu ){ //verifica el tamaño de la parte de la matriz
            y++;
            con1++;
        }
            if( con1>=tam[v2] ){
                v2++;
                ss=0;
                for( int i=(y-con1-1) ; i<nu ; i++){
                    if(M[x][i]==0){
                        M[x][i]=Palabras[v3][ss];
                        printf("%c",Palabras[v3][ss]);
                    }
                    ss++;
                }
                contador1++;
                save[contador1] = y/10;
                save[contador1] += x;
                break;    
            }  
        if( (y-con1)>=tam[v2] ){
            v2++;
            ss=0;
            for( int j=(y-con1) ; j>-1 ; j--){
                if(M[x][j]==0 ){
                    M[x][j]=Palabras[v3][ss];
                    printf("%c",Palabras[v3][ss]);
                }
                ss++;
            }
            contador1++;
            save[contador1] = y/10;
            save[contador1] += x;
            break;
        }
    }
}// revisar condiciones de entrada a las variables de posicion
void vertical(){
    int ss; 
    int con2;
    int i,j; //indices del for
    int x,y; // coordenadas de la palabra 
    while( i<nu || j<nu ){
      x = rand() % (nu+1);   //tamaño x de nu que es de la matriz 
      y = rand() % (nu+1);   //tamaño y de nu que es de la matriz
      printf("%d %d\n",x,y);  
        while( x<nu ){
            x++;
            con2++;
        }
            if( con2>=tam[v2] ){
                v2++;
                for( int i=(x-con2) ; i<nu ; i++){
                    if(M[i][y]==0){
                        M[i][y]=Palabras[v3][ss];
                        printf("%c",Palabras[v3][ss]);
                    }
                    ss++;
                }
                contador1++;
                save[contador1] = y/10;
                save[contador1] += x;
                break;
            }  
        if( (x-con2)>=tam[v2] ){
            v2++;
            for( int j=x ; j>-1 ; j--){
                if(M[j][y]==0 ){
                    M[j][y]=Palabras[v3][ss];
                    printf("%c",Palabras[v3][ss]);
                }
                ss++;
            }
            contador1++;
            save[contador1] = y/10;
            save[contador1] += x;
            break;
        }
    }
}
void Diagonal_1(){
    int ss;
    v2++;
    int con1=0;
    int i,j; //indices del for
    int x,y; // coordenadas de la palabra 
    while( 1 ){
        x = rand() % (nu+1);   //tamaño x de nu que es de la matriz 
        y = rand() % (nu+1);   //tamaño y de nu que es de la matriz
        printf("%d %d\n",x,y);
        while( y<nu ){
            y++;
            x++;
            con1++;
        }
        if( con1>=tam[v2] ){ //diagonal izquierda normal
        v2++;
            for( i=(y-con1),j=(x-con1) ; i<con1 ; i++,j++){
                if(M[i][j]==0){
                    M[i][j]==Palabras[v3][ss];
                    printf("%c",Palabras[v3][ss]);
                }
                ss++;
            }
            contador1++;
            save[contador1] = y/10;
            save[contador1] += x;
            break;
        }
        if( (y-con1)>=tam[v2] ){ //diagonal izquierda alreves
        v2++;
            for( i=(y-con1),j=(x-con1) ; j>=0 ; i--,j--){
                if(M[i][j]==0){
                    M[i][j]==Palabras[v3][ss];
                    printf("%c",Palabras[v3][ss]);
                }
                ss++;
            }
            contador1++;
            save[contador1] = y/10;
            save[contador1] += x;
            break;            
        }
    }
}
void Diagonal_2(){
    int ss;
    v2++;
    int con1=0;
    int i,j; //indices del for
    int x,y; // coordenadas de la palabra 
    while( 1 ){
        x = rand() % (nu+1);   //tamaño x de nu que es de la matriz 
        y = rand() % (nu+1);   //tamaño y de nu que es de la matriz
        printf("%d %d\n",x,y);
        while(y<nu){
            y++;
            x++;
            con1++;
        }
        if( con1>=tam[v2] ){ //diagonal izquierda normal
        v2++;
            for( i=(y-con1),j=(x-con1) ; i<con1 ; i--,j++){
                if(M[i][j]==0){
                    M[i][j]==Palabras[v3][ss];
                    printf("%c",Palabras[v3][ss]);
                }
                ss++;
            }
            contador1++;
            save[contador1] = y/10;
            save[contador1] += x;
            break;
        }
        if( (y-con1)>=tam[v2] ){ //diagonal izquierda alreves
        v2++;
            for( i=(y-con1),j=(x-con1) ; i<nu ; i++,j--){
                if(M[i][j]==0){
                    M[i][j]==Palabras[v3][n];
                    printf("%c",Palabras[v3][n]);
                }
                ss++;
            }
            contador1++;
            save[contador1] = y/10;
            save[contador1] += x;            
            break;
        }
    }
}