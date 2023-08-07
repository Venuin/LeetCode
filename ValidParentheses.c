#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValid(char * s){
    int sLength = strlen(s);
    
    if(sLength % 2 == 1)
        return 0;
    else{
        int i = 0, count = -1, open[sLength];
        for(i = 0; i < sLength; i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                count++;
                open[count] = s[i];
            }
            else{
                if(count == -1)
                    return 0;
                else if(open[count] == '{' && s[i] != '}')
                    return 0;
                else if(open[count] == '[' && s[i] != ']')
                    return 0;
                else if(open[count] == '(' && s[i] != ')')
                    return 0;
                else{
                    count--;
                }
            }
        }
        if(count > -1)
            return 0;
        return 1;
    }
}


int main(){
    char * s = "([])";
    int result = isValid(s);
    printf("%d", result);
}