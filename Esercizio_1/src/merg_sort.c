#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merg_sort.h"


void merge(void** ordered_array,unsigned long left, unsigned long center, unsigned long right, CompareFunc compare, int answ)
{
    unsigned long merge_left = left;
    unsigned long merge_right = center + 1;
    unsigned long count = 0;
    unsigned long size_merge_array = right-left+1;
    void** merge_array;
    
    merge_array = (void**)malloc(sizeof(void*)*size_merge_array);
    if(merge_array == NULL){
        printf("merge_array è NULL");
    }
   
    while(merge_left <= center && merge_right <= right){
        
        if(compare(ordered_array[merge_left],ordered_array[merge_right],answ)==1){
            
            merge_array[count] = ordered_array[merge_left];
            merge_left++;
        
        }else{
            
            merge_array[count] = ordered_array[merge_right];
            merge_right++;

        }
        count++;
    }

    while(merge_left <= center){

        merge_array[count] = ordered_array[merge_left];
        count++;
        merge_left++;
    
    }

    while(merge_right <= right){

        merge_array[count] = ordered_array[merge_right];
        count++;
        merge_right++;

    }

    for(count = left; count <= right; count++){
        ordered_array[count] = merge_array[count - left];
    }
    free(merge_array);

}
unsigned long binary_search(void** ordered_array, void* insert_loc, unsigned long low, unsigned long high, CompareFunc compare, int answ)
{
   
    if(high <= low){
   
        return((compare(insert_loc,ordered_array[low],answ) == 0) ? (low + 1):low);
    }
    unsigned long mid = (low + high)/2;
  
    if(compare(insert_loc,ordered_array[mid],answ) == -1){
   
        return mid+1;
    }
    if(compare(insert_loc,ordered_array[mid],answ) == 0){

        return binary_search(ordered_array, insert_loc, mid+1, high, compare,answ);
    }
    return binary_search(ordered_array, insert_loc, low, mid, compare,answ);
}
void insertion_sort(void ** array, unsigned long left,unsigned long right, CompareFunc compare,  int answ)
{
    
    unsigned long count,bin,high;
    void* inser_loc;

    for(count = left+1; count <= right; count++){
      
        high = (count - 1);
        inser_loc = array[count];
        bin = binary_search(array, inser_loc, 0,high, compare,answ);
       
        while((int)high >= 0 && high >= bin ){
            array[high + 1] = array[high];
            high = high - 1;
        }
        array[high+1] = inser_loc;
    }
}
/**
 * la funzione merge sort viene utilizzata per appliccare l'algoritmo merge
 * richiede 5 parametri:
 * @param array da ordinare
 * @param left il limite sinistro dell'array
 * @param right il limite destra dell'array
 * @param compre indica se dobbiamo ordinare int,double o string 
 * @param answ valore untilizzato per ordinare in modo non-decrescente o decrescente 
 * 
*/
void merge_sort(void** array, unsigned long left, unsigned long right, CompareFunc compare,int answ)
{
    unsigned long center = 0;
    unsigned long k = 1000;


    if ((right+left)<= k){
        insertion_sort(array,left,right,compare,answ);
    }else if(left < right){
        center = (left + right)/2;
        merge_sort(array,left, center,compare,answ);
        merge_sort(array,center+1,right,compare,answ);
        merge(array,left,center, right,compare,answ);
    }
}
int merge_sort_answ()
{
    int answ ;

    printf("sceglie come ordinare gli array\n");
    printf("1 -> non decrescente \n");
    printf("2 -> decrescente \n");
    
    scanf("%d",&answ);
    return answ;
    
}
