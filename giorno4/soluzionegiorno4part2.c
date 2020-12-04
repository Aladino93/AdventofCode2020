#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char ch = '0';
    char passaporto[120]="00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    int passaporto_linea=0;
    int indice_passaporto=0;
    int cambio_passaporto=0;
    int byr=0;
    int anno_byr=0;
    int iyr=0;
    int anno_iyr=0;
    int eyr=0;
    int anno_eyr=0;
    int hgt=0;
    int altezza=0;
    int hcl=0;
    int ecl=0;
    int pid=0;
    int i=0;
    int password_corrette=0;
    FILE *fp;

    fp = fopen("filetestogiorno4.txt", "r"); // read mode
        
    while(1) {
        ch = fgetc(fp);
        if(ch=='\n')passaporto_linea++;
        if(ch== EOF)break;
        if(!(cambio_passaporto==1 && ch=='\n')){      
            passaporto[indice_passaporto]=ch;         
            indice_passaporto++;
            if(ch=='\n')cambio_passaporto=1;
            else cambio_passaporto=0;
            }
        else
        {   
            for(i=0;i<indice_passaporto-2;i++)
            {
                if (passaporto[i]=='b' && passaporto[i+1]=='y' && passaporto[i+2]=='r'&& passaporto[i+3]==':' && (passaporto[i+8]==' ' || passaporto[i+8]=='\n'))
                {
                    anno_byr=(passaporto[i+4]-'0')*1000 + (passaporto[i+5]-'0')*100 + (passaporto[i+6]-'0')*10 +(passaporto[i+7]-'0');
                    if(anno_byr>=1920 && anno_byr<=2002)byr=1;
                }

                if (passaporto[i]=='i' && passaporto[i+1]=='y' && passaporto[i+2]=='r' && passaporto[i+3]==':' && (passaporto[i+8]==' ' || passaporto[i+8]=='\n'))
                {
                    anno_iyr=(passaporto[i+4]-'0')*1000 + (passaporto[i+5]-'0')*100 + (passaporto[i+6]-'0')*10 +(passaporto[i+7]-'0');
                    if(anno_iyr>=2010 && anno_iyr<=2020)iyr=1;
                }

                if (passaporto[i]=='e' && passaporto[i+1]=='y' && passaporto[i+2]=='r' && passaporto[i+3]==':' && (passaporto[i+8]==' ' || passaporto[i+8]=='\n') )
                {
                    anno_eyr=(passaporto[i+4]-'0')*1000 + (passaporto[i+5]-'0')*100 + (passaporto[i+6]-'0')*10 +(passaporto[i+7]-'0');
                     if(anno_eyr>=2020 && anno_eyr<=2030)eyr=1;
                }

                if (passaporto[i]=='h' && passaporto[i+1]=='g' && passaporto[i+2]=='t' && passaporto[i+3]==':')
                {
                    if(passaporto[i+7]=='c' && passaporto[i+8]=='m' && (passaporto[i+9]==' ' || passaporto[i+9]=='\n')){
                       altezza=(passaporto[i+4]-'0')*100 + (passaporto[i+5]-'0')*10 +(passaporto[i+6]-'0');
                       if(altezza>=150 && altezza<=193)hgt=1;
                    }
                    if(passaporto[i+6]=='i' && passaporto[i+7]=='n' && (passaporto[i+8]==' ' || passaporto[i+8]=='\n')){
                        altezza=(passaporto[i+4]-'0')*10 +(passaporto[i+5]-'0');
                        if(altezza>=59 && altezza<=76)hgt=1;
                    }
                }



                if (passaporto[i]=='h' && passaporto[i+1]=='c' && passaporto[i+2]=='l' && passaporto[i+3]==':' && passaporto[i+4]=='#'  && (passaporto[i+11]==' ' || passaporto[i+11]=='\n'))
                {
                    if((passaporto[i+5]>='a' && passaporto[i+5]<='f') || (passaporto[i+5]>='0' && passaporto[i+5]<='9'))
                        if((passaporto[i+6]>='a' && passaporto[i+6]<='f') || (passaporto[i+6]>='0' && passaporto[i+6]<='9'))
                            if((passaporto[i+7]>='a' && passaporto[i+7]<='f') || (passaporto[i+7]>='0' && passaporto[i+7]<='9'))
                                if((passaporto[i+8]>='a' && passaporto[i+8]<='f') || (passaporto[i+8]>='0' && passaporto[i+8]<='9'))
                                    if((passaporto[i+9]>='a' && passaporto[i+9]<='f') || (passaporto[i+9]>='0' && passaporto[i+9]<='9'))
                                        if((passaporto[i+10]>='a' && passaporto[i+10]<='f') || (passaporto[i+10]>='0' && passaporto[i+10]<='9'))hcl=1;           
                }
                if (passaporto[i]=='e' && passaporto[i+1]=='c' && passaporto[i+2]=='l' && passaporto[i+3]==':' && (passaporto[i+7]==' ' || passaporto[i+7]=='\n'))
                {
                    if(passaporto[i+4]=='a' && passaporto[i+5]=='m' && passaporto[i+6]=='b' )ecl=1;
                    if(passaporto[i+4]=='b' && passaporto[i+5]=='l' && passaporto[i+6]=='u' )ecl=1;
                    if(passaporto[i+4]=='b' && passaporto[i+5]=='r' && passaporto[i+6]=='n' )ecl=1;
                    if(passaporto[i+4]=='g' && passaporto[i+5]=='r' && passaporto[i+6]=='y' )ecl=1;
                    if(passaporto[i+4]=='g' && passaporto[i+5]=='r' && passaporto[i+6]=='n' )ecl=1;
                    if(passaporto[i+4]=='h' && passaporto[i+5]=='z' && passaporto[i+6]=='l' )ecl=1;
                    if(passaporto[i+4]=='o' && passaporto[i+5]=='t' && passaporto[i+6]=='h' )ecl=1;
                }
                if (passaporto[i]=='p' && passaporto[i+1]=='i' && passaporto[i+2]=='d' && passaporto[i+3]==':' && (passaporto[i+13]==' ' || passaporto[i+13]=='\n'))
                {
                    if((passaporto[i+4]>='0' && passaporto[i+4]<='9'))
                        if((passaporto[i+5]>='0' && passaporto[i+5]<='9'))
                            if((passaporto[i+6]>='0' && passaporto[i+6]<='9'))
                                if((passaporto[i+7]>='0' && passaporto[i+7]<='9'))
                                    if((passaporto[i+8]>='0' && passaporto[i+8]<='9'))
                                        if((passaporto[i+9]>='0' && passaporto[i+9]<='9'))
                                            if((passaporto[i+10]>='0' && passaporto[i+10]<='9'))
                                                if((passaporto[i+11]>='0' && passaporto[i+11]<='9'))
                                                    if((passaporto[i+12]>='0' && passaporto[i+12]<='9'))pid=1;                    
                }                                
            }
            if(byr==1 && iyr==1 && eyr==1 && hgt==1 && hcl==1 && ecl==1 && pid==1){password_corrette++;printf("%d\n",passaporto_linea);}
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
    printf("%d\n",password_corrette);
    system("pause");
    return 0;
}


