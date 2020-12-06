#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*NOTA BENE, aggiungere a capo a fondo del file per riconoscere ultima sequenza e non fare il break dell'EOF immediatamente*/

int main(){
    char lista_risposte[144];
    int indice_lista_risposte=0;
    int i=0;
    int j=0;
    int k=0;
    int numero_persone=0;
    int risposte_positive=0;
    int lettere_saltate=0;
    char ch = '0';   
    int controllo_linea_vuota=0;  
    FILE *fp;
    fp = fopen("filetestogiorno6.txt", "r"); // read mode
        
    while(1) {
        ch = fgetc(fp);
        if(ch== EOF)break;
        if(!(ch=='\n' && controllo_linea_vuota==1)){      
          if(ch=='\n'){ 
                controllo_linea_vuota++;
                numero_persone++;
            }
          else {
              lista_risposte[indice_lista_risposte]=ch;
              controllo_linea_vuota=0;
              indice_lista_risposte++;
          }
        
        }
        else{       
            lista_risposte[indice_lista_risposte]='\0';        
            for(i = 0; i < indice_lista_risposte; i++){
                for(j = i + 1; lista_risposte[j] != '\0'; j++){ 		            
                    if(lista_risposte[j] == lista_risposte[i]){  
                        for(k = j; lista_risposte[k] != '\0'; k++){	
                            lista_risposte[k] = lista_risposte[k + 1];                           
                        }
                        j--;
                        lettere_saltate++;
                    }
                }
                if((lettere_saltate+1)==numero_persone)risposte_positive++;
                lettere_saltate=0;
            }
            
            
            
            indice_lista_risposte=0;
            numero_persone=0;
        }                              
           
        
        
    
    }
    printf("%d\n",risposte_positive);
    system("pause");
    return 0;
}


