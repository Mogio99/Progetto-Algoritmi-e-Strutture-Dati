#ifndef EDIT_DISTANCE_DYN_H
#define EDIT_DISTANCE_DYN_H

/**
 * @param string indica la parola dove viene applicato l'edit_distance
 * @param mosse indica il numero di mosse fatte dall'edit_distance 
 *              remove e insert
*/
typedef struct record 
{
    int mosse;
    char* string;

}record_p;

/**
 * funzione dove viene risolto l'edit_distance dinamico tra i parametri
 * @param stringa1 parola da correggere del file correctme
 * @param stringa2 parola da confrontare del vocabolario
 * @param length1 numero di caratteri che compongono la stringa1
 * @param length2 numero di caratteri che compongono la stringa2
*/
int edit_distance_dyn(char*, char*, int, int);

/**
 * funzione dove viene risolto l'edit_distance tra i parametri
 * @param stringa1 parola da correggere del file correctme
 * @param stringa2 parola da confrontare del file dictionary
 * @param length1 numero di caratteri che compongono la stringa1
 * @param length2 numero di caratteri che compongono la stringa2
*/
int edit_distance(char* s1, char* s2, int , int );

/**
 * funzione control si utilizza per gestire l'applicazione dell'edit
 * distance dinamico oppure no e gestisce il confronto tra i p
 * @param record_array_s1 array di stringhe del file da correggere
 * @param record_array_s2 parola da confrontare del vocabolario
 * @param count_s1 numero di parole contenute nel file del correctme
 * @param count_s2 numero di parole che compongono il file dictionary
*/
void control(record_p**, record_p**, int, int, int);


#endif