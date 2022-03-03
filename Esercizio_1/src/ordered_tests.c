#include <stdlib.h>
#include "unity.h"
#include "merg_sort.h"
#include "string.h"

static int* new_int(int n) {
  int* res = (int*) malloc(sizeof(int));
  *res = n;

  return res;
}

static char* new_char(char n) {
  char* res = (char*) malloc(sizeof(char));
  *res = n;

  return res;
}

static float* new_float(float n) {
  float* res = (float*) malloc(sizeof(float));
  *res = n;

  return res;
}

int compare_int (void*val_1, void*val_2, int answ)
{
	
    int rec1_val1 = (*(int*)val_1);
    int rec2_val2 = (*(int*)val_2);

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

int compare_float (void* val_1, void* val_2, int answ)
{
	
    float rec1_val1 = (*(float*)val_1);
    float rec2_val2 = (*(float*)val_2);

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
void setUp(){}

void tearDown(){}

void test_array_int_disordered(){
  int ** array;
  array = malloc(sizeof(int *)*3);
  array[0] = new_int(3);
  array[1] = new_int(7);
  array[2] = new_int(2);

  TEST_ASSERT_EQUAL(3, * (int *)array[0]);
  TEST_ASSERT_EQUAL(7, * (int *)array[1]);
  TEST_ASSERT_EQUAL(2, * (int *)array[2]);

  merge_sort((void**)array, 0, 2, compare_int,1);

  TEST_ASSERT_EQUAL(2, * (int *)array[0]);
  TEST_ASSERT_EQUAL(3, * (int *)array[1]);
  TEST_ASSERT_EQUAL(7, * (int *)array[2]);

  free(array);
}

void test_cresc_int_array(){
  int ** array;
  array = malloc(sizeof(int *)*9);
  array[0] = new_int(3);
  array[1] = new_int(4);
  array[2] = new_int(5);
  array[3] = new_int(7);
  array[4] = new_int(6);
  array[5] = new_int(9);
  array[6] = new_int(2);
  array[7] = new_int(1);
  array[8] = new_int(8);

  merge_sort((void**)array, 0, 8, compare_int,1);

  TEST_ASSERT_EQUAL(1, * (int *) array[0]);
  TEST_ASSERT_EQUAL(2, * (int *) array[1]);
  TEST_ASSERT_EQUAL(3, * (int *) array[2]);
  TEST_ASSERT_EQUAL(4, * (int *) array[3]);
  TEST_ASSERT_EQUAL(5, * (int *) array[4]);
  TEST_ASSERT_EQUAL(6, * (int *) array[5]);
  TEST_ASSERT_EQUAL(7, * (int *) array[6]);
  TEST_ASSERT_EQUAL(8, * (int *) array[7]);
  TEST_ASSERT_EQUAL(9, * (int *) array[8]);

  free(array);
}

void test_desc_int_array(){
  int ** array;
  array = malloc(sizeof(int *)*9);
  array[0] = new_int(3);
  array[1] = new_int(4);
  array[2] = new_int(5);
  array[3] = new_int(7);
  array[4] = new_int(6);
  array[5] = new_int(9);
  array[6] = new_int(2);
  array[7] = new_int(1);
  array[8] = new_int(8);

  merge_sort((void**)array, 0, 8, compare_int,2);

  
  TEST_ASSERT_EQUAL(1, * (int *) array[8]);
  TEST_ASSERT_EQUAL(2, * (int *) array[7]);
  TEST_ASSERT_EQUAL(3, * (int *) array[6]);
  TEST_ASSERT_EQUAL(4, * (int *) array[5]);
  TEST_ASSERT_EQUAL(5, * (int *) array[4]);
  TEST_ASSERT_EQUAL(6, * (int *) array[3]);
  TEST_ASSERT_EQUAL(7, * (int *) array[2]);
  TEST_ASSERT_EQUAL(8, * (int *) array[1]);
  TEST_ASSERT_EQUAL(9, * (int *) array[0]);
  free(array);
}



void test_array_int_equals(){
  int ** array;
  array = malloc(sizeof(int *)*3);
  array[0] = new_int(3);
  array[1] = new_int(3);
  array[2] = new_int(3);
  
  merge_sort((void**)array, 0, 2, compare_int,1);

  TEST_ASSERT_EQUAL(3, * (int *)array[0]);
  TEST_ASSERT_EQUAL(3, * (int *)array[1]);
  TEST_ASSERT_EQUAL(3, * (int *)array[2]);
  
  free(array);
}

void test_array_float_disordered(){
  float ** array;
  array = malloc(sizeof(float *)*3);
  array[0] = new_float(3.4f);
  array[1] = new_float(7.2f);
  array[2] = new_float(2.9f);

  TEST_ASSERT_EQUAL(3.4f, * (float *)array[0]);
  TEST_ASSERT_EQUAL(7.2f, * (float *)array[1]);
  TEST_ASSERT_EQUAL(2.9f, * (float *)array[2]);

  merge_sort((void**)array, 0, 2, compare_float,1);

  TEST_ASSERT_EQUAL(2.9f, * (float *)array[0]);
  TEST_ASSERT_EQUAL(3.4f, * (float *)array[1]);
  TEST_ASSERT_EQUAL(7.2f, * (float *)array[2]);

  free(array);
}

void test_array_char(){
  char ** a;
  a = malloc(sizeof(char *)*3);
  a[0] = new_char('C');
  a[1] = new_char('O');
  a[2] = new_char('A');
  
  merge_sort((void**)a, 0, 2, compare_int,1);

  TEST_ASSERT_EQUAL('A',* (char *)a[0]);
  TEST_ASSERT_EQUAL('C',* (char *)a[1]);
  TEST_ASSERT_EQUAL('O',* (char *)a[2]);

  free(a);
}

void test_empty_array(){
  char ** a = NULL;

  merge_sort((void**)a, 0, 0, compare_int,1);

  TEST_ASSERT_EQUAL(NULL, a);
}

int main(){
  UNITY_BEGIN();

  RUN_TEST(test_array_int_disordered);
  RUN_TEST(test_cresc_int_array);
  RUN_TEST(test_desc_int_array);
  RUN_TEST(test_array_char);
  RUN_TEST(test_array_int_equals);
  RUN_TEST(test_empty_array);
  RUN_TEST(test_array_float_disordered);

  UNITY_END();

}
