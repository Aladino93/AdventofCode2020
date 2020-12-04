#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char ch = '0';
    char passaporto[120];
    int indice_passaporto=0;
    int cambio_passaporto=0;
    int byr=0;
    int iyr=0;
    int eyr=0;
    int hgt=0;
    int hcl=0;
    int ecl=0;
    int pid=0;
    int i=0;
    int password_corrette=0;
    FILE *fp;

    fp = fopen("filetestogiorno4.txt", "r"); // read mode
        
    while(1) {
        ch = fgetc(fp);
        if(ch== EOF)break;
        if(!(cambio_passaporto==1 && ch=='\n')){      
            passaporto[indice_passaporto]=ch;  /* NOTA: si potrebbero scrivere solo le lettere e scartare il resto per accelerare il for successivo*/          
            indice_passaporto++;
            if(ch=='\n')cambio_passaporto=1;
            else cambio_passaporto=0;
            }
        else
        {   
            for(i=0;i<indice_passaporto-3;i++)
            {
                if (passaporto[i]=='b' && passaporto[i+1]=='y' && passaporto[i+2]=='r'&& passaporto[i+3]==':')
                {
                    byr=1;
                }
                if (passaporto[i]=='i' && passaporto[i+1]=='y' && passaporto[i+2]=='r' && passaporto[i+3]==':')
                {
                    iyr=1;
                }
                if (passaporto[i]=='e' && passaporto[i+1]=='y' && passaporto[i+2]=='r' && passaporto[i+3]==':')
                {
                    eyr=1;
                }
                if (passaporto[i]=='h' && passaporto[i+1]=='g' && passaporto[i+2]=='t' && passaporto[i+3]==':')
                {
                    hgt=1;
                }
                if (passaporto[i]=='h' && passaporto[i+1]=='c' && passaporto[i+2]=='l' && passaporto[i+3]==':')
                {
                    hcl=1;
                }
                if (passaporto[i]=='e' && passaporto[i+1]=='c' && passaporto[i+2]=='l' && passaporto[i+3]==':')
                {
                    ecl=1;
                }
                if (passaporto[i]=='p' && passaporto[i+1]=='i' && passaporto[i+2]=='d' && passaporto[i+3]==':')
                {
                    pid=1;
                }                                
            }
            if(byr==1 && iyr==1 && eyr==1 && hgt==1 && hcl==1 && ecl==1 && pid==1)password_corrette++;
            byr=0;
            iyr=0;
            eyr=0;
            hgt=0;
            hcl=0;
            ecl=0;
            pid=0;
            cambio_passaporto=0;
            indice_passaporto=0; 
        }
        
    
    }
    printf("%d",password_corrette);
    system("pause");
    return 0;
}


