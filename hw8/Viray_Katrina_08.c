#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int filename(char *ptr);

int main() {
    char name[200], chunkid[4], format[4], subchunk1id[4];
    char *ptr = name;
    int check = 0;
    unsigned int chunksize, samplerate, subchunk1size, byterate;
    unsigned short int audioformat, numchannels, blockalign, samplebits;

    FILE *fp;
    check = filename(ptr);
    fp = fopen(ptr,"r+b");

    while ((check == 0) || (fp == NULL)) 
    {
        if(fp==NULL) printf("File doesn't exist. Please enter another name:\n");
        check = filename(ptr);
        fp = fopen(ptr,"r+b");
    }

    fread(chunkid, 4,1,fp);
    printf("%.4s\n",chunkid);

    fread(&chunksize,4,1,fp);
    printf("%d\n",chunksize);

    fread(&format,4,1,fp);
    printf("%d\n",format);

    fread(&subchunk1id,4,1,fp);
    printf("%d\n",subchunk1id);

    fread(&subchunk1size,4,1,fp);
    printf("%d\n",subchunk1size);

    fread(&audioformat,2,1,fp);
    printf("%d\n",audioformat);

    fread(&numchannels,2,1,fp);
    printf("%d\n",numchannels);

    fread(&samplerate,4,1,fp);
    printf("%d\n",samplerate);

    fread(&byterate,4,1,fp);
    printf("%d\n",byterate);

    fread(&blockalign,2,1,fp);
    printf("%d\n",blockalign);

    fread(&samplebits,2,1,fp);
    printf("%d\n",samplebits);
    
    samplerate = samplerate/2;
    fseek(fp,+24,SEEK_SET);
    fwrite(&samplerate,4,1,fp);

    byterate = byterate/2;
    fwrite(&byterate,4,1,fp);

    blockalign = blockalign/2;
    fwrite(&blockalign,2,1,fp);

    fclose(fp);
    return 0;
}

int filename(char *ptr){
    printf("Please enter the file name:\n");
    gets(ptr);
    char check1 = strstr(ptr, ".wav");
    char check2 = strstr(ptr, ".WAV");
    
    if (check1 == NULL || check2 == NULL){
        printf("your file extension is not wav or WAV\n");
        return 0;
    }
    else
        return 1;
}
