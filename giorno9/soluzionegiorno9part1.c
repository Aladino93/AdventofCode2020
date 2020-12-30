#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//codice leggermente modificato da reddit

int cerca_numero(long long int vettore[], int indice);



    

int main () {
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
    i=26; 
    while (cerca_numero(vettore_numeri,i)!=0)i++;
    printf("%d\n",i);
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
            if((vettore[indice-25+i]+vettore[indice-25+j])==vettore[indice])return 1;
        }
    }
    return 0;
}
