#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

unsigned char * converteToBin(int numero){
    int bits = 128;
    unsigned char * numbin = (unsigned char *)malloc((9)*sizeof(unsigned char));
    
    
    while(bits>1){

        if(numero>bits){

            if(bits == 128){

                strcpy(numbin,"1");
            }else{

                strcat(numbin,"1");
                
            }
            numero = numero - bits;
            
        }else{
            if(bits == 128){
                strcpy(numbin,"0");


            }else{
                /* code */

                strcat(numbin,"0");

            }
            
        }
        bits = bits/2;


    }
            if(numero>bits){

            if(bits == 128){

                strcpy(numbin,"1");
            }else{

                strcat(numbin,"1");
                
            }
            numero = numero - bits;
            
        }else{
            if(bits == 128){
                strcpy(numbin,"0");


            }else{
                /* code */

                strcat(numbin,"0");

            }
        }
  

return numbin;


}


int main(){
    
    FILE *arq1;
    FILE *arq2;
    FILE *arq3;
    int i,valor,constante,repeticao;
    uint8_t * numero_bin;
    arq1 = fopen("arquivoaleatorio.dat","wb");
    arq2 = fopen("arquivorestrito.dat","wb");
    arq3 = fopen("arquivonaoaleatorio.dat","wb");
    constante = 1310750;

    for( i = 0; i<1310750;i++){

       numero_bin = converteToBin(rand()%255);
       fwrite(numero_bin,sizeof(unsigned char),8,arq1);
       numero_bin = converteToBin(rand()%25);
       fwrite(numero_bin,sizeof(unsigned char),8,arq2);
             
    }
    while(constante>0){

       valor =  rand()%100;
       repeticao = rand()%10;
       numero_bin = converteToBin(valor);
       while(repeticao>0){

        fwrite(numero_bin,sizeof(unsigned char),8,arq3);
        repeticao = repeticao -1;
       
       }

       constante = constante - repeticao;
        
    }


return 0;

}