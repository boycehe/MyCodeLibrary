//
//  he_question.c
//  C
//
//  Created by heboyce on 2020/6/7.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include "he_question.h"

bool isValidBrackets(char * s){
    if(s == NULL) return false;
    int index = 0;
    int top = 0;
    int mallocLen = 100;
    char *stack = (char *)calloc(mallocLen,sizeof(char));
    while(s[index] != '\0'){
        if(top >= mallocLen){
            mallocLen += 100;
            stack = (char*)realloc(stack,mallocLen);
        }
        switch(s[index]){
            case '(':
            case '{':
            case '[':
                stack[top] = s[index];
                top++;
                index++;
                continue;
            case ')':
                if(top<=0 || stack[top-1] != '(') return false;
                top--;
                index++;
                continue;
            case '}':
                if(top<=0 || stack[top-1] != '{') return false;
                top--;
                index++;
                continue;
            case ']':
                if(top<=0 || stack[top-1] != '[') return false;
                top--;
                index++;
                continue;
            default:
                return false;
                break;
        }
    }

    free(stack);
    return top != 0?false:true;
}

char * removeOuterParentheses(char * S){
    return NULL;
}