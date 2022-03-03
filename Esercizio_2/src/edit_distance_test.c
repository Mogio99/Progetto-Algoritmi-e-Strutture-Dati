#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "edit_distance_dyn.h"
	
void setUp(){}
void tearDown(){}	

void test_edit_distance(){
	char *s1, *s2;
	
	s1 = "cavallo";
	s2 = "vassallo";
	
	TEST_ASSERT_EQUAL(5, edit_distance(s1, s2,(int) strlen(s1),(int)strlen(s2)));
}
	
void test_edit_distance_null_string(){
	char *s1, *s2;
	
	s1 = "cavallo";
	s2 = NULL;
	
	TEST_ASSERT_EQUAL(7, edit_distance(s1, s2,(int) strlen(s1),0));
}	

void test_edit_distance_empty(){
	char *s1, *s2;
	
	s1 = "";
	s2 = "";
	
	TEST_ASSERT_EQUAL(0, edit_distance(s1, s2,(int) strlen(s1),(int)strlen(s2)));
}

void test_edit_distance_empty_string(){
	char *s1, *s2;
	
	s1 = "verde";
	s2 = "";
	
	TEST_ASSERT_EQUAL(5, edit_distance(s1, s2,(int) strlen(s1),(int)strlen(s2)));
}

void test_edit_distance_equals(){
	char *s1, *s2;
	
	s1 = "vino";
	s2 = "vino";
	
	TEST_ASSERT_EQUAL(0, edit_distance(s1, s2,(int) strlen(s1),(int)strlen(s2)));
}

void test_edit_distance_dyn(){
	char *s1, *s2;
	
	s1 = "cavallo";
	s2 = "vassallo";
	
	TEST_ASSERT_EQUAL(5, edit_distance_dyn(s1, s2,(int) strlen(s1),(int)strlen(s2)));
}

void test_edit_distance_dyn_null_string(){
	char *s1, *s2;
	
	s1 = "cavallo";
	s2 = NULL;
	
	TEST_ASSERT_EQUAL(7, edit_distance_dyn(s1, s2,(int) strlen(s1),0));
}	

void test_edit_distance_dyn_empty(){
	char *s1, *s2;
	
	s1 = "";
	s2 = "";
	
	TEST_ASSERT_EQUAL(0, edit_distance_dyn(s1, s2,(int) strlen(s1),(int)strlen(s2)));
}

void test_edit_distance_dyn_empty_string(){
	char *s1, *s2;
	
	s1 = "verde";
	s2 = "";
	
	TEST_ASSERT_EQUAL(5, edit_distance_dyn(s1, s2,(int) strlen(s1),(int)strlen(s2)));
}

void test_edit_distance_dyn_equals(){
	char *s1, *s2;
	
	s1 = "vino";
	s2 = "vino";
	
	TEST_ASSERT_EQUAL(0, edit_distance_dyn(s1, s2,(int) strlen(s1),(int)strlen(s2)));
}
	
int main() {
	UNITY_BEGIN();
	
	RUN_TEST(test_edit_distance);
	RUN_TEST(test_edit_distance_null_string);
	RUN_TEST(test_edit_distance_empty);
	RUN_TEST(test_edit_distance_empty_string);
	RUN_TEST(test_edit_distance_equals);
	
	RUN_TEST(test_edit_distance_dyn);
	RUN_TEST(test_edit_distance_dyn_null_string);
	RUN_TEST(test_edit_distance_dyn_empty);
	RUN_TEST(test_edit_distance_dyn_empty_string);
	RUN_TEST(test_edit_distance_dyn_equals);
	
	UNITY_END();
}