#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//codice leggermente modificato da reddit

int cerca_numero(long long int vettore[], int indice);



    

int main () {
    long long int numero_target=50047984;
    long long int somma_contigua=0;
    
    int primavolta=0;
    long long int vettore_numeri [1000]={0};
    int c = 0, i = 0, j=0, total = 0, n, passed[10000], passedCounter = 0;
    char ch;
  
    FILE *f = fopen ("filetestogiorno9.txt", "r");
    
    //dopo aver chiuso il file lo riapro per rimettermi all'inizio (potevo usare rewind???)
    i=0;
    while(1){
        ch = fgetc(f);
        if(ch=='\n'){
                primavolta=0;
                i++;}
        else{
            if(primavolta)vettore_numeri[i]=ch-'0'+(vettore_numeri[i]*10);
            else {vettore_numeri[i]=ch-'0';
                    primavolta=1;}
        }
        if(ch==EOF)break;
    }
    for(i=0;i<542;i++){
        somma_contigua=vettore_numeri[i];
        for(j=i+1;j<543;j++){
            somma_contigua=somma_contigua+vettore_numeri[j];
            if(somma_contigua==numero_target){
                printf("il primo estremo è %d il secondo è %d\n",i+1,j+1);
            }
        }
    }
    
    system("pause");
    return 0;
}


int cerca_numero(long long int vettore[], int indice)
{
    int n=0;
    int i=0;
    int j=0;
    int indici[2];
    int flag=0;
    int risultato=0;
    int complemento=0;
    for (i=0;i<24;i++){
        for(j=i+1;j<25;j++){
            if((vettore[indice-25+i]+vettore[indice-25+j])==vettore[indice])return 1; //sono stato pigro e ho fatto la ricerca del max e min su excel
            
        }
    }
    return 0;
}
