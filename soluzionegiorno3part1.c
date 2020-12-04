#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch = 'b';
    char lista_segni[31];
    int indice_lista=0;
    int numero_alberi=0;
    int indice=0;
    FILE *fp;

    fp = fopen("filetestogiorno3.txt", "r"); // read mode
        
    while(ch != EOF) {
    ch = fgetc(fp);
    if(ch !='\n' && ch != EOF)
    {
        lista_segni[indice_lista]=ch;
        indice_lista++;
    }
    else{
    if(lista_segni[indice]=='#'){numero_alberi++; printf("%c\n",lista_segni[indice]);} 
    else printf("%c\n",lista_segni[indice]) ;
    indice=indice+3;
    if (indice>30)indice=indice-31;
    indice_lista=0;
    } 
    }

    printf("%d\n", numero_alberi);

    system("pause");
    return 0;
}


