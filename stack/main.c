#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "stack.h"

void test_push() {
    Stack s;
    CreateStack(&s);

    Push(10, &s);
    Push(20, &s);
    Push(30, &s);

    assert(s.top->entry == 30); // top should be 30
    assert(s.top->next->entry == 20); // 2nd element should be 20
    assert(s.top->next->next->entry == 10); // 3rd element should be 10
}

void test_pop() {
    Stack s;
    CreateStack(&s);

    Push(10, &s);
    Push(20, &s);
    Push(30, &s);

    StackEntry popped_element;
    Pop(&popped_element, &s);

    assert(popped_element == 30); // popped element should be 30
    assert(s.top->entry == 20); // top should be 20
    assert(s.top->next->entry == 10); // 2nd element should be 10
}

void test_stack_empty() {
    Stack s;
    CreateStack(&s);

    assert(StackEmpty(&s)); // stack should be empty

    Push(10, &s);

    assert(!StackEmpty(&s)); // stack should not be empty
}

void test_find_min() {
    Stack s;
    CreateStack(&s);
    Push(5, &s);
    Push(3, &s);
    Push(7, &s);
    
    assert(FindMin(&s) == 3);
    Pop(&s.top->entry, &s);
    assert(FindMin(&s) == 3);
    Pop(&s.top->entry, &s);
    assert(FindMin(&s) == 5);
    Pop(&s.top->entry, &s);
    
   
}

void test_clear_stack() {
    Stack s;
    CreateStack(&s);
    Push(5, &s);
    Push(3, &s);
    Push(7, &s);
    ClearStack(&s);
    assert(StackEmpty(&s));
}

void test_peek() {
    Stack s;
    CreateStack(&s);
    Push(5, &s);
    Push(3, &s);
    Push(7, &s);
    assert(Peek(&s) == 7);
}

void test_destroy_stack() {
    Stack s;
    CreateStack(&s);
    Push(5, &s);
    Push(3, &s);
    Push(7, &s);
    DestroyStack(&s);
    assert(s.Size == 0);
    assert(s.top == NULL);
}

void test_FirstElementAdded() {
    Stack s;
    CreateStack(&s);
    Push(10, &s);
    Push(20, &s);
    Push(30, &s);
    assert(FirstElementAdded(&s) == 10);
    Push(40, &s);
    assert(FirstElementAdded(&s) == 10);
    DestroyStack(&s);
}

void test_CopyStack() {
    // Create a stack with some elements
    Stack s1;
    CreateStack(&s1);
    Push(1, &s1);
    Push(2, &s1);
    Push(3, &s1);
    
    // Create another stack to copy into
    Stack s2;
    CreateStack(&s2);
    
    // Copy s1 into s2 using the function being tested
    CopyStack(&s1, &s2);
    
    // Check if the elements in s1 and s2 are the same
    StackNode* node1 = s1.top;
    StackNode* node2 = s2.top;
    while (node1 != NULL && node2 != NULL) {
        assert(node1->entry == node2->entry);
        node1 = node1->next;
        node2 = node2->next;
    }
    
    // Check if both stacks have the same size
    assert(StackSize(&s1) == StackSize(&s2));
    
    // Clean up
    ClearStack(&s1);
    ClearStack(&s2);
}


int main() {
  test_push();
  test_destroy_stack();
  test_clear_stack();
  test_pop();
  test_find_min();
  test_peek();
  test_stack_empty();
  test_FirstElementAdded();
  test_CopyStack();
   

    printf("All tests passed successfully.\n");
    return 0;
}
