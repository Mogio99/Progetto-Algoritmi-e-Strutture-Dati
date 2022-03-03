#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "merg_sort.h"

typedef struct record
{
    int id_field_0;
    char* string_field_1;
    int integer_field_2;
    double float_field_3;

}record_p;

unsigned long num_line(const char *file_name)
{   
    FILE *fp;
    unsigned long count = 0;
    int ch; 

    fp = fopen(file_name,"r");
    while ((ch = getc(fp))!=EOF){
        if(ch == '\n'){
            count ++;
        }else if(ch == '\0'){
            count --;
        }
    }
    fclose(fp);
    return count;
}

int compare_int (void*val_1, void*val_2, int answ)
{
	
    int rec1_val1 = (*(record_p*)val_1).integer_field_2;
    int rec2_val2 = (*(record_p*)val_2).integer_field_2;

    if(answ == 1){
        if(rec1_val1 < rec2_val2){
            return(1);
        }else if (rec1_val1 == rec2_val2){
            return(-1);
        }
        return(0);
    } else {
        if(rec1_val1 < rec2_val2){
            return(0);
        }else if (rec1_val1 == rec2_val2){
            return(-1);
        }
        return(1);
    }
}


int compare_string(void* val_1, void* val_2, int answ){
	
    char* rec1_val1 = (*(record_p*)val_1).string_field_1;
    char* rec2_val2 = (*(record_p*)val_2).string_field_1;
    
    if(answ == 1){
        if(strcmp(rec1_val1, rec2_val2) < 0){
            return(1);
        }
        return(0);
    }else {
        if(strcmp(rec1_val1, rec2_val2) < 0){
            return(0);
        }
        return(1);
    }
}

int compare_float (void* val_1, void* val_2, int answ)
{
	
    float rec1_val1 =(float) (*(record_p*)val_1).float_field_3;
    float rec2_val2 =(float) (*(record_p*)val_2).float_field_3;

    if(answ == 1){
        if(rec1_val1 < rec2_val2){
            return(1);
        }else if(rec1_val1 == rec2_val2){
            return(-1);
        }
        return(0);
    }else{
        if(rec1_val1 < rec2_val2){
            return(0);
        }else if(rec1_val1 == rec2_val2){
            return(-1);
        }
        return(1);
    }
}

static void load_array(const char* file_name,record_p** array,unsigned long MAX_CAPACITY)
{
    
	char *read_line_p;
    char buffer[1024];
    int buf_size = 1024;
    int count = 0;
    FILE *fp;

    printf("\nLOADING DATA FROM FILE \n");
    fp = fopen(file_name,"r");
    if(fp == NULL){
        printf("main: unable to open the file");
        exit(EXIT_FAILURE);
    }
	
    while((fgets(buffer,buf_size,fp) != NULL && (unsigned long)count < MAX_CAPACITY)){

        read_line_p = malloc((strlen(buffer)+1)*sizeof(char));

        strcpy(read_line_p,buffer);
        char *id_in_read_line_p = strtok(read_line_p,",");
        char *string_in_read_line_p = strtok(NULL,",");
        char *integer_in_read_line_p = strtok(NULL,",");
        char *float_in_read_line_p = strtok(NULL,",");
        char *string_field = malloc((strlen(string_in_read_line_p)+1)*sizeof(char));
    
        strcpy(string_field,string_in_read_line_p);
        int id_field = atoi(id_in_read_line_p);
        int integer_field = atoi(integer_in_read_line_p);
        float float_field = (float)atof(float_in_read_line_p); 
        array[count] = (record_p*) malloc(sizeof(record_p));
		
        if(string_field == NULL){
            fprintf(stderr,"main: unable allocate memory for the read record");
            exit(EXIT_FAILURE);
        }
		
        array[count]->id_field_0 = id_field;
        array[count]->string_field_1 = string_field;
        array[count]->integer_field_2 = integer_field;
        array[count]->float_field_3 = float_field;
        count++;
        free(read_line_p);
    }
	
    fclose(fp);
    printf("\nData loaded\n");
}

/**
 * funzione che dealloca completamente la memoria dall'array 
 * @param free_array memoria dedicata all'array che deve essere
 * deallocato
 * @param len indica la grandezza di quanto è stata allocata 
 * la memoria
*/
void free_memory(void** free_array, unsigned long len)
{
	
    unsigned long count;

    for(count = 0;count <= len; count++){
        free(free_array[count]);
    }
	
    free(free_array);
}

/**
 * funzione per l'ordinamento dell'array in base al field integer
 * @param file_name il file dove viene estratto l'array
 * @param count è il numero di righe del file, quindi di quanto deve essere
 * allocata la memoria per l'array.
 * 
*/
void ordered_integer_field(const char* file_name,unsigned long count)
{

    static clock_t start_time, end_time;
    record_p** record_array;

    record_array = (record_p**) malloc (sizeof(record_p*)*count);
    load_array(file_name,record_array,count);
    int answ = merge_sort_answ();
    start_time = clock();
    merge_sort((void**)record_array,0,count-1,compare_int, answ);
    end_time = clock();
    printf("--->ARRAY ORDERED INTEGER %4.5f seconds<--- \n",(double)(end_time-start_time)/(double)CLOCKS_PER_SEC);
    
    free_memory((void**)record_array,count);
    
} 

/**
 * funzione per l'ordinamento dell'array in base al field string
 * @param file_name il file dove viene estratto l'array
 * @param count è il numero di righe del file, quindi di quanto deve essere
 * allocata la memoria per l'array.
 * 
*/
void ordered_string_field(const char* file_name,unsigned long count)
{
	
    static clock_t start_time, end_time;
    record_p** record_array;

    record_array = (record_p**) malloc (sizeof(record_p*)*count);
    load_array(file_name,record_array,count);
    int answ = merge_sort_answ();
    start_time = clock();
    merge_sort((void**)record_array,0,count-1,compare_string, answ);
    end_time=clock();
    printf("--->ARRAY ORDERED STRING %4.5f seconds<---\n",(double)(end_time-start_time)/(double)CLOCKS_PER_SEC);

    free_memory((void**)record_array,count);
}

/**
 * funzione per l'ordinamento dell'array in base al field float
 * @param file_name il file dove viene estratto l'array
 * @param count è il numero di righe del file, quindi di quanto deve essere
 * allocata la memoria per l'array.
 * 
*/
void ordered_float_field(const char* file_name,unsigned long count )
{
	static clock_t start_time, end_time;
    record_p** record_array;

    record_array = (record_p**) malloc (sizeof(record_p*)*count);
    load_array(file_name,record_array,count);
    int answ = merge_sort_answ();
    start_time = clock();
    merge_sort((void**)record_array,0,count-1,compare_float, answ);
    end_time = clock();
    printf("--->ARRAY ORDERED FLOAT %4.5f seconds<--- \n",(double)(end_time-start_time)/(double)CLOCKS_PER_SEC);
    
    free_memory((void**)record_array,count);
}

int main(int argc, char const *argv[]){
	
    unsigned long count;

    if(argc < 2){
        fprintf(stderr,"file not exist \n");
        exit(EXIT_FAILURE);
    }

    count = num_line(argv[1]);
    
    printf("il numero di righe: %ld\n", count);
    printf("\n<<<ORDERED FIELD STRING>>>\n");
    ordered_string_field(argv[1],count);
    printf("\n------>TERMINATE ORDERED FIELD STRING<------\n");
    printf("\n<<<ORDERED FIELD FLOAT>>>\n");
    ordered_float_field(argv[1],count);
    printf("\n------>TERMINATE ORDERED FIELD FLOAT<------\n");
    printf("\n<<<ORDERED FIELD INTEGER>>>\n");
    ordered_integer_field(argv[1],count);
    printf("\n------>TERMINATE ORDERED FIELD INTEGER<------\n");

}
