#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char ch = '0';    
    int riga=0;
    int numero_maggiore=0;
    
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
                riga=riga<<1;
                riga=riga+1;
            }
            if(ch=='L'){
                riga=riga<<1;
            }
        }
        else{
            
            if (riga>numero_maggiore)numero_maggiore=riga;
            riga=0;
        }                              
              
    }
   
    printf("%d\n",numero_maggiore);
    system("pause");
    return 0;
}


