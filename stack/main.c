#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "stack.h"



void test_Matching_parentheses() {
   StackEntry valid_str[] = {"[(125){....}]"};
    int result = Matching_parentheses(valid_str);
    assert(result == 1);
    printf("test 1 complete with valid str\n");
    
    // Test with an invalid string missing closing parenthesis
    StackEntry invalid_str[] = {'(', '[', ']', '(', ')', '{', '}' ,')', '(', '[', ']', '\0'};
    assert(Matching_parentheses(invalid_str) == 0);
    printf("test 2 complete with invalid str\n");
    
    // Test with an invalid string with mismatched parenthesis
    StackEntry invalid_str2[] = {"([]{))"};
    assert(Matching_parentheses(invalid_str2) == 0);
    printf("test 3 complete with invalid str with mismatched parenthesis\n");
    
    // Test with an empty string
    StackEntry empty_str[] = {};
    assert(Matching_parentheses(empty_str) == 1);
    printf("test 4 complete with empty str\n");
}







int main() {
 
  test_Matching_parentheses();
  
    return 0;
}
