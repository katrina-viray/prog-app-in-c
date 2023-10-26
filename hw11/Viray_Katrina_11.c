#include <stdio.h>

int decode(char c)
{
    if((c >= 33) && (c <= 71))
        return c;
    else
        return -1;
}

int main() {
    FILE *fin, *fout;

    fin = fopen("input1.txt","r");
    fout = fopen("output.txt","w");

    char c; // char to read in from file in
    int num, f; // ASCII rep of the char, flag for switch statements

    while(fscanf(fin,"%c", &c) != EOF){
        num = decode(c);
        if(num!= -1){
            if (c > 32 && c < 59){
                f = 1;
            }
            else if (c > 58 && c < 69){
                f = 2;
            }
            else if(c == 69){
                f = 3;
            }
            else if(c == 70){
                f = 4;
            }
            else if (c == 71){
                f = 5;
            }
            switch(f){
                case 1: // lowercase letters
                    num = c + 64;
                    fprintf(fout,"%c", num);
                    break;
                case 2: // numbers
                    num = c - 11;
                    fprintf(fout,"%c",num);
                    break;
                case 3: // blank space
                    num = 32;
                    fprintf(fout,"%c",num);
                    break;
                case 4: // period
                    num = 46;
                    fprintf(fout,"%c",num);
                    break;
                case 5: // newline
                    fprintf(fout,"\n");
                    break;
            }
        }
    }
    fclose(fin);
    fclose(fout);
}
