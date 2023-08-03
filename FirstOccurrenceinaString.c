#include <stdio.h>
#include <stdlib.h>

int strStr(char * haystack, char * needle){
    int i = 0, match = 0;
    int lengthofNeedle = 0;
    while(needle[lengthofNeedle] != '\0') lengthofNeedle++;
    while(haystack[i] != '\0'){
        if(haystack[i] == needle[match]){
            match++;
            if(match == lengthofNeedle)
                return i - lengthofNeedle + 1;
        }
        else{
            if(match > 0){
                i -= match;
                match = 0;
            }
        }
        i++;
    }
    return -1;
}

int main(){
    char * haystack, * needle;
    haystack = "mississippi";
    needle = "issip";
    int result = strStr(haystack, needle);
    printf("%d", result);

}