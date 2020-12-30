#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//codice leggermente modificato da reddit
char getInstruction (char *s, char acc, char nop, char jmp);
int getValue (char *s);
bool verify (int *counter, int val);

int main (){
    
    int c = 0, i = 0, total = 0, n, passed[10000], passedCounter = 0;
    char ch;
    char phrase[100];
    char acc = 'a', nop = 'n', jmp = 'j', toDo;
    bool secondCycle = false;
    FILE *f = fopen ("filetestogiorno8.txt", "r");

    if (f  == NULL){
        printf ("file error\n");
        return 0;
    }
    for (int j=0; j<10000; j++) passed[j] = -1;
    //conto il numero di righe nel file
    while(1){
        ch = fgetc(f);
        if(ch==EOF)break;
        if(ch=='\n')c++;
    }
    fclose (f);
    //dopo aver chiuso il file lo riapro per rimettermi all'inizio (potevo usare rewind???)
    f = fopen ("filetestogiorno8.txt", "r");
    char **s = (char **)malloc(c*sizeof(char *)); 
    for(i=0;i<626;i++){
        s[i] = (char *)malloc(30*sizeof(char));
        fgets (s[i], 100, f);
        printf ("%s", s[i]);
       
    }
    fclose (f);

    //inizio algoritmo

    i = 0;
    while (secondCycle == false && passedCounter < 10000 ){
        toDo = getInstruction (s[i], acc, nop, jmp); //leggo l'istruzione e la trasforma in lettera singola
        //printf ("i: %d - total: %d\n", i, total);
        switch (toDo){
            case 'a':
                n = getValue (s[i]);
                total += n;
                passed[passedCounter] = i;
                passedCounter++;
                i++;
                break;
            case 'n':
                passed[passedCounter] = i;
                passedCounter++;
                i++;
                break;
            case 'j':
                n = getValue (s[i]);
                passed[passedCounter] = i;
                passedCounter++;
                i += n;
                break;
        }
        if (verify (passed, i) == true)
            secondCycle = true;
    }
    printf ("\nvalue: %d\n", total);

    for (i=0; i<c; i++)
        free (s[i]);
    free (s);
    
    system("pause");
    return 0;
}


char getInstruction (char *s, char acc, char nop, char jmp){
    int i = 0;
    if (s[0] == acc)
        return 'a';
    else if (s[0] == nop)
        return 'n';
    else
        return 'j';
}

int getValue (char *s){
    int i = 0, n;
    while (i < strlen (s) && (s[i] != '+' && s[i] != '-')){
        i++;
    }
    if (s[i] == '+'){
        n = atoi (&s[i+1]);
        //printf ("value: %d\n", n);
        return n;
    }
    else
        n = atoi (&s[i+1]);
        //printf ("value: %d\n", n*(-1));
        return (n*(-1));
}

bool verify (int *counter, int val){
    int i = 0;
    while (i < 10000 && counter[i] != -1){
        if (counter[i] == val)
            return true;
        i++;
    }
    return false;
}
