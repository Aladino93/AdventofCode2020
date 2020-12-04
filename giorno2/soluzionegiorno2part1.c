#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch;
    char chiave;
    char linea[40];
    int contatore_linea=0;
    int ricerca_chiave=0;
    int contatore_ricorrenze=0;
    int numero_chiavi_esatte=0;
    int minimo=0;
    int massimo=0;
    int termina_while=0;
    FILE *fp;
    fp = fopen("filetestogiorno2.txt", "r"); // read mode
    do{
        ch = fgetc(fp);
        if(ch!= '\n' && ch!= EOF){
            linea[contatore_linea]=ch;
            contatore_linea++;
            
        }
        else{
            if(linea[2] == '-') minimo=(linea[0]-'0')*10 + linea[1]-'0';
            else minimo=linea[0]-'0';
            if(linea[2] != '-' && linea[3]==' ')    {massimo= linea[2]-'0'                     ; chiave=linea[4];}
            if(linea[2] != '-' && linea[3]!=' ')    {massimo= (linea[2]-'0')*10+ linea[3]-'0'  ; chiave=linea[5];}
            if(linea[2] == '-' )                    {massimo= (linea[3]-'0')*10+ linea[4]-'0'  ; chiave=linea[6];}
            while(ricerca_chiave < contatore_linea){
                if (chiave==linea[ricerca_chiave])contatore_ricorrenze++; /* NOTA che in questo modo anche la chiave viene contata e andrà sottratta*/
                ricerca_chiave++;
            }
            contatore_ricorrenze--;
            if(contatore_ricorrenze>=minimo && contatore_ricorrenze<=massimo)numero_chiavi_esatte++;

            massimo=0;
            minimo=0;
            chiave=0;
            contatore_ricorrenze=0 ;     
            ricerca_chiave=0;
            contatore_linea=0;
        }
        
    }while(ch != EOF);
    printf("%d\n",numero_chiavi_esatte); /* risp = 564*/

    fclose(fp);
    system("pause");
    return 0;
    
}


