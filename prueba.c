#include<stdio.h> 
#include<time.h> 
int main() {     
time_t inicio, fin;  
inicio=time(NULL);  
char m[20][20],b;  
int i,j;     
b='a';       
for (i=0;i<20;i++)     
	for (j=0;j<20;j++)       
		m[i][j]=b+rand()%26;      

	for (i=0;i<20;i++){     
        for (j=0;j<20;j++)         
        printf("%c",m[i][j]);      
            printf("\n");    
}     
    printf("\nDependiendo cuanto te demores en revisar la matriz y leer este mensaje");     
    printf("\nsera el tiempo de ejecución de tu programa");    
    printf("\npresiona enter......");    
    scanf("%c",&b);  
    fin=time(NULL);  
    printf("\nTIEMPO UTILIZADO: %f",difftime(fin,inicio)); 
    return 0;
} 
 

 while(1){
            lento();
                if(digitalRead(2)==HIGH){
                    while(1){
                        apagado();
                        if(digitalRead(2)==HIGH) break;
                   }        
                }

            if( digitalRead(3) == HIGH ){
                while(1){
                intermedio();
                    if(digitalRead(2)==HIGH){
                        while(1){
                            apagado();
                            if(digitalRead(2)==HIGH) break;
                        }        
                    }
                
                    if( digitalRead(3) == HIGH ){
                        while(1){
                           rapido();
                                if(digitalRead(2)==HIGH){
                                    while(1){
                                        apagado();
                                        if(digitalRead(2)==HIGH) break;
                                    }        
                                }
            
                        }
                    }
                }
            }
        }
    }
 