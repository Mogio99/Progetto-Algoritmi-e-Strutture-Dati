#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "edit_distance_dyn.h"

int min(int s1, int s2)
{
    if(s1 < s2){
        return s1;
    }else {
        return s2;
    }
}
int edit_distance_dyn(char* s1, char* s2, int long_s1, int long_s2)
{
    int dp[long_s1 + 1][long_s2 + 1];
 

    for (int i = 0; i <= long_s1; i++) {
        for (int j = 0; j <= long_s2; j++) {

            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i; 

            else if (s1[i - 1] == s2[j - 1] || s1[i-1]+32==s2[j-1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
        }
    }
 
    return dp[long_s1][long_s2];
}

int edit_distance(char* s1, char* s2, int long_s1, int long_s2)
{
    if (long_s1 == 0){
        return long_s2;
    }
    if(long_s2 == 0){
        return long_s1;
    }

    if(s1[long_s1-1] == s2[long_s2-1] || s1[long_s1 -1]+32 == s2[long_s2 -1]){
        return edit_distance(s1,s2,long_s1-1,long_s2-1);
    }

    return 1 + min(edit_distance(s1,s2,long_s1,long_s2-1),//insert
                       edit_distance(s1,s2,long_s1-1,long_s2));//remove
    
}

void control(record_p** record_array_s1, record_p** record_array_s2, int count_s1, int count_s2, int dyn)
{
    FILE *fx;
    if(dyn == 1){
        fx = fopen("../text/mosse_dyn.txt","wa");
    }else {
        fx = fopen("../text/mosse.txt","wa");
    }
    
    for(int mat_s1 = 0; mat_s1 < count_s1 ; mat_s1++){
        int i = 10;
       for(int mat_s2 = 0; mat_s2 < count_s2 && i > 0 ; mat_s2++){

            char *s1 = record_array_s1[mat_s1]->string;
            char *s2 = record_array_s2[mat_s2]->string;
            if(dyn == 1){
                record_array_s2[mat_s2]->mosse = edit_distance_dyn(s1, s2,(int) strlen(s1),(int)strlen(s2));
            }else {
                record_array_s2[mat_s2]->mosse = edit_distance(s1, s2,(int) strlen(s1),(int)strlen(s2));
            }
            if(record_array_s2[mat_s2]->mosse <= 2 && record_array_s2[mat_s2]->mosse >= 0){
                fprintf(fx,"<s1: %s , s2: %s> -> mosse %d \n", record_array_s1[mat_s1]->string, record_array_s2[mat_s2]->string, record_array_s2[mat_s2]->mosse);
            }
            i = record_array_s2[mat_s2]->mosse;
       }
       
    }
    fclose(fx);
}