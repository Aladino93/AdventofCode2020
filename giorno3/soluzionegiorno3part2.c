#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch = 'b';
    long long numero_alberi_tot;
    char lista_segni[31];
    int riga_alternata=0;
    int indice_lista=0;
    long long numero_alberi1=0;
    long long numero_alberi2=0;
    long long numero_alberi3=0;
    long long numero_alberi4=0;
    long long numero_alberi5=0;
    int indice1=0;
    int indice2=0;
    int indice3=0;
    int indice4=0;
    int indice5=0;
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
    if(lista_segni[indice1]=='#')                       numero_alberi1++;
    if(lista_segni[indice2]=='#')                       numero_alberi2++;
    if(lista_segni[indice3]=='#')                       numero_alberi3++;
    if(lista_segni[indice4]=='#')                       numero_alberi4++;
    if(lista_segni[indice5]=='#' && riga_alternata==0)  numero_alberi5++;

  
    
    indice1=indice1+1;
    if (indice1>30)indice1=indice1-31;
    indice2=indice2+3;
    if (indice2>30)indice2=indice2-31;
    indice3=indice3+5;
    if (indice3>30)indice3=indice3-31;
    indice4=indice4+7;
    if (indice4>30)indice4=indice4-31;
    if (riga_alternata==0)indice5=indice5+1;
    if (indice5>30)indice5=indice5-31;
    
    if (riga_alternata==0)riga_alternata++;
    else riga_alternata--;
    indice_lista=0;
    } 
    }
    numero_alberi_tot=numero_alberi1   *numero_alberi2;
    numero_alberi_tot=numero_alberi_tot*numero_alberi3;
    numero_alberi_tot=numero_alberi_tot*numero_alberi4;
    numero_alberi_tot=numero_alberi_tot*numero_alberi5;
    printf("%d %d %d %d %d\n",numero_alberi1,numero_alberi2,numero_alberi3,numero_alberi4,numero_alberi5 );
    printf("%lld\n",numero_alberi_tot );

    system("pause");
    return 0;
}


