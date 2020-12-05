#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char ch = '0'; 
    int posti[1024]= {0};
    int riga=0;
    int colonna=0;
    int rigacolonna=0;
    int i=0;
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
            posti[rigacolonna]=1;
            riga=0;
            colonna=0;

        }                              
              
    }
    for(i=0;i<1024;i++)
    {
        if(posti[i]==0)printf("posto vacante=%d\n",i);
    }
   
    system("pause");
    return 0;
}


