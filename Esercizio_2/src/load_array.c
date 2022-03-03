#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "edit_distance_dyn.h"

/**
 * la funzione num_line restituisce il numero di righe del file 
 * @file dove contare le righe
*/
int num_line(const char* file_name)
{   
    int count;
    int ch;
    FILE *fp;

    count = 0;
    fp = fopen(file_name,"r");

    if(fp == NULL){
        printf("File not exist\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp))!=EOF)
    {
        if(ch == ' '){
            count ++;
        }else if(ch == '\n'){
            count ++;
        }
        
    }
    return count;
}
void load_array(record_p** array, int max_capacity,const char* file_name)
{

	char *read_line_p;
    char buffer[1024];
    int buf_size = 1024;
    int count = 0;
    FILE *fp;

    fp=fopen(file_name,"r");
    if( fp == NULL) {
        fprintf(stderr,"file not exits ");
        exit(EXIT_FAILURE);
    }
    while((fgets(buffer,buf_size,fp) != NULL && count < max_capacity)){
        
        read_line_p = malloc((strlen(buffer)+1)*sizeof(char));
        strcpy(read_line_p,buffer);
        char *string_in_read_line_p = strtok(read_line_p,"\n");
    
        char *string_field = malloc((strlen(string_in_read_line_p)+1)*sizeof(char));

        strcpy(string_field,string_in_read_line_p);
        array[count] = (record_p*) malloc(sizeof(record_p));
        if(string_field == NULL){
            fprintf(stderr,"main: unable allocate memory for the read record");
            exit(EXIT_FAILURE);
        }
        array[count]->string= string_field;
        count++;
        free(read_line_p);

    }

    fclose(fp);
    printf("\nData loaded\n");
	
}
/**
 * funzione utilizzata per creare un nuovo file .txt, converte frasi di lungezza variabile 
 * con punteggiatur in un file text.txt dove per ogni riga ci sarà una sola parola. 
 * Esempio : in una frase da 50 parole, convertendo nel file text.txt ci saranno 50 riga e non 
 * sarà presente la punteggiatura.
 * 
 * @file passare il file che si vuole convertire
*/
const char* riempimento(const char* file_name)
{
    
    int ch;
    int ult;
    FILE *fp;
    FILE *fd;
    const char* new_text = "../text/text.txt";

    fp = fopen(file_name,"r");
    if(fp == NULL){
        printf("File not exist\n");
        exit(EXIT_FAILURE);
    }
    
    fd = fopen(new_text,"wa");
  
    while ((ch = getc(fp))!= EOF){
        
        if((ch >= 'A' && ch <= 'Z')||( ch >= 'a' && ch <= 'z')){
            fprintf(fd,"%c",ch);
        }else if((ch == ' ' && ult != ' ' )|| (ch == '\n')){
            fprintf(fd,"\n");
        }
        ult = ch;
    }

    fclose(fp);
    fclose(fd);
    return(new_text);
}

void create_array(const char *file_text, const char* file_dict)
{
    
    int countS1, countS2;
    static clock_t start_time, end_time;
   
    file_text = riempimento(file_text);
    countS1 = num_line(file_text);
    printf("\n<<<Lettura del testo da correggere  %d>>>\n",countS1);
    record_p** record_array_s1;
    record_array_s1 = (record_p **) malloc(sizeof(record_p*)*(unsigned long)countS1);
    load_array(record_array_s1,countS1,file_text);

    countS2 = num_line(file_dict);
    
    //creazione dell'array vocabolario da confrotare con l'array da trovare parole simili
    printf("<<<Riempimento array di termini del vocabolario  %d>>>\n", countS2);
    record_p** record_array_s2;
    record_array_s2 = (record_p **) malloc(sizeof(record_p*)*(unsigned long)countS2);
    load_array(record_array_s2, countS2, file_dict);
    printf("\n>>>START EDIT DISTANCE DYN<<< \n");
    start_time = clock();
    control(record_array_s1,record_array_s2,(int) countS1,(int) countS2, 1);
    end_time = clock();
    
    printf("\n>>>TERMINATO CONTROL  %4.5f seconds<<< \n",(double)(end_time-start_time)/(double)CLOCKS_PER_SEC);

    printf("\n>>>START EDIT DISTANCE<<< \n");
    start_time = clock();
    control(record_array_s1,record_array_s2,(int) countS1,(int) countS2, 0);
    end_time = clock();
    
    printf("\n>>>TERMINATO CONTROL  %4.5f seconds<<< \n",(double)(end_time-start_time)/(double)CLOCKS_PER_SEC);


    free(record_array_s2);
    free(record_array_s1);
  
}
int main(int argc, const char *argv[])
{  
  
    if(argv[1] == NULL ){
        fprintf(stderr,"file correctme not exist \n");
        exit(EXIT_FAILURE);
    }
    if(argv[2] == NULL){
        fprintf(stderr, "file dictionary not exist \n");
        exit(EXIT_FAILURE);
    }
    if(argc < 2){
        fprintf(stderr,"il file da correggere non esiste");
        exit(EXIT_FAILURE);
    }
    
    create_array(argv[1],argv[2]);
}