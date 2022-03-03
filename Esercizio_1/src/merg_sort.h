#ifndef MERGE_SORT_H
#define MERGE_SORT_H

/**
 * typedef compare function tre parametri
 * @param val_1 di tipo void 
 * @param val_2 di tipo void 
 * @param answ 
 * in base ad answ si può ordinare l'array
 * in modo non decrescente o decrescente.
 * Ordina i field della struct record, grazie al compare
 * posso scegliere come ordinare se per intero, stringa, float.
*/
typedef int (*CompareFunc)(void*, void*,  int);

/**
 * struct dei record array da ordinare in base ai field contenuti in ogni
 * singolo array
 * @param id_field_0 tipo intero, non viene considerato nell'ordinamento
 * @param string_field_1 field string
 * @param integer_field_2 field integer
 * @param float_field_3 field float 
*/





void merge_sort(void** , unsigned long, unsigned long, CompareFunc, int);

/**
* funzione utilizzate per scegliere se ordinare l'array in 
* ordine decrescente o non decrescente
*/
int merge_sort_answ();




#endif 