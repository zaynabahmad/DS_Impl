
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


/**
 * Checks whether the given string of parentheses()[]{} has matching pairs
 * of opening and closing symbols.
 *
 * 
 * @param ptr a pointer to the string
 * @return 1 if the string is well-formed, and 0 otherwise.
 */
int Matching_parentheses(StackEntry *ptr ){
    Stack s;
    CreateStack(&s);
    
    while(*ptr != '\0' ){
        if(*ptr=='('|| *ptr =='['|| *ptr =='{'){
            Push(*ptr,&s);
            
        }
        else if(*ptr==')'||*ptr==']'||*ptr=='}'){
            if(s.top==NULL){
                printf("Error: the string is started with a closed paranetheses.\n");  // report error 
                return 0;
            }
            else if ((*ptr == ')' && s.top->entry != '(') || 
                       (*ptr == ']' && s.top->entry != '[') ||
                       (*ptr == '}' && s.top->entry != '{')) {
                printf("Error: Parentheses, brackets, or braces not matching.\n");   //report error 
                return 0; 
            } 
            else {
                Pop(&s.top->entry, &s);
            }}
                    ptr++;
                
        }

        if (s.top != NULL) {
        printf("Error: The string ends with an unclosed parenthesis.\n"); // report error
        return 0;
    }
    
    return 1 ;
}
