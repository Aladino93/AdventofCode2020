#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char ch = '0'; 
    int riga=0;
    int colonna=0;
    int rigacolonna_maggiore=0;
    int rigacolonna=0;
    FILE *fp;
    fp = fopen("filetestogiorno5.txt", "r"); // read mode
        
    while(1) {
        ch = fgetc(fp);
        if(ch== EOF)break;
        if(ch!='\n'){      
            if(ch=='B'){
                riga=riga<<1;
                riga=riga+1;
            }
            if(ch=='F'){
                riga=riga<<1;
            }
            if(ch=='R'){
                colonna=colonna<<1;
                colonna=colonna+1;
            }
            if(ch=='L'){
                colonna=colonna<<1;
            }
        }
        else{
            rigacolonna=riga*8+colonna;
            if(rigacolonna>rigacolonna_maggiore)rigacolonna_maggiore=rigacolonna;
            riga=0;
            colonna=0;

        }                              
           
        
        
    
    }
    printf("%d\n",rigacolonna_maggiore);
    system("pause");
    return 0;
}


