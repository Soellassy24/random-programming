#include <stdio.h>
#include <string.h>

int main(){
    //p1count = ()
    //p2count = {}
    //p3count = []
    int p1count = 0, p2count = 0, p3count = 0, length;
    char input[100];

    printf("Input the parenthesis : ");
    scanf("%s", input);
    length = strlen(input);
    for (int i = 0; i <= length; i++){
        if (input[i] == '('){
            p1count++;
        }
        if (input[i] == '{'){
            p2count++;
        }
        if(input[i] == '['){
            p3count++;
        }

        if (input[i] == '('){
            if (input[i+1] == '{'){
                if (input[i+2] == ')' && input[i+2] == ']'){
                    printf("FALSE");
                    return 0;
                }else{
                    continue;
                }   
            }else if (input[i+1] == '['){
                if (input[i+2] == ')' && input[i++] == '}'){
                    printf("FALSE");
                    return 0;
                }else{
                    continue;
                }
            }else if (input[i+1] == '('){
                continue;
            }else{
                printf("FALSE");
                return 0;
            }
        }else if (input[i] == '{'){
            if (input[i+1] == '('){
                if (input[i+2] == '}' && input[i+2] == ']'){
                    printf("FALSE");
                    return 0;
                }else{
                    continue;
                }   
            }else if (input[i+1] == '['){
                if (input[i+2] == '}' && input[i++] == ')'){
                    printf("FALSE");
                    return 0;
                }else{
                    continue;
                }
            }else if (input[i+1] == '{'){
                continue;
            }else{
                printf("FALSE");
                return 0;
            }
        }else if (input[i] == '['){
            if (input[i+1] == '('){
                if (input[i+2] == '}' && input[i+2] == ']'){
                    printf("FALSE");
                    return 0;
                }else{
                    continue;
                }   
            }else if (input[i+1] == '{'){
                if (input[i+2] == ']' && input[i++] == ')'){
                    printf("FALSE");
                    return 0;
                }else{
                    continue;
                }
            }else if (input[i+1] == '['){
                continue;
            }else{
                printf("FALSE");
                return 0;
            }
        }
        if (input[i] == ')'){
            p1count--;
        }
        if (input[i] == '}'){
            p2count--;
        }
        if(input[i] == ']'){
            p3count--;
        }
    }
    if ((p1count != 0) || (p2count != 0) || (p3count != 0)){
        printf("FALSE");
    }else{
        printf("TRUE");
    }
    return 0;
}
    
