#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int i = 0, j = 0, k = 0, counter = 0, repeat = 0, size = 5, max_count = 1;
    char * str_array = (char *) malloc(size*sizeof(char));
    memset(str_array, 0x00, size);
    
    while(s[i] != '\0'){
        for(j = 0; j < counter; j++){
            printf("%c", str_array[j]);
            if(str_array[j] == s[i]){
                repeat = 1;
                break;
            }
        }    
        printf("\nRepeat: %d\n",repeat);
        if (repeat == 1){
            if(max_count < counter)
                max_count = counter;
            printf("j: %d ",j);
            printf("Counter: %d\n",counter);
            repeat = 0;
            counter -= j;
            for(k = 0; k < counter - 1; k++)
                str_array[k] = str_array[++j];
            str_array[k] = s[i];
        }else{
            if(counter + 1 > size){
                size *= 2;
                str_array = (char *) realloc(str_array, size * sizeof(char));
            }          
            str_array[counter] = s[i];
            counter++;
        }      
        i++;
    }
    if(max_count < counter)
        max_count = counter;
    if(s[0] == '\0'){
        return 0;
    }
    return max_count;
}



int main(){
    char * s = "dvdf";

    int a = lengthOfLongestSubstring(s);
    printf("\n%d", a);
    
    //printf("%c", s[2]);
}