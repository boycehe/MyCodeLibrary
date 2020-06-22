//
//  he_question.c
//  C
//
//  Created by heboyce on 2020/6/7.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include "he_stack_question.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
/*
 char * removeOuterParentheses(char * S){
    int cnt = 0,k = 0;
    for(int i = 0;i < strlen(S);i++){
        if(S[i] == '('){
            if(cnt != 0) S[k++] = S[i];
            cnt ++;
        }
        if(S[i] == ')'){
            cnt--;
            if(cnt != 0) S[k++] = S[i];
        }
    }
    S[k] = '\0';
    return S;
}
 */

char * removeOuterParentheses(char * s){
    if (s == NULL) return NULL;
    int index = 0;
    int top = 0;
    int tmpTop = 0;
    int mallocLen = 100;
    char *stack  = (char *)calloc(mallocLen,sizeof(char));
    char *result = (char *)calloc(mallocLen,sizeof(char));

    while (s[index] != '\0'){
        if (mallocLen < index){
            mallocLen += 100;
            stack  = realloc(stack,mallocLen);
            result = realloc(result,mallocLen);
        }
        if (s[index] == '('){
            if (top != 0){
                result[tmpTop] = s[index];
                tmpTop++;
            }
            stack[top] = s[index];
            top++;
        } else if ((s[index] == ')' && top > 0 && stack[top-1] == '(')){
            if (top != 1){
                result[tmpTop] = s[index];
                tmpTop++;
            }
            top--;
        }else{
            free(stack);
            free(result);
            return NULL;
        }
        index++;
    }
    free(stack);
    return result;
}