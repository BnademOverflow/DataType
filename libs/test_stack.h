#pragma once
#include "stack.h"

// Test the stack
typedef struct
{
    char s[10]; // The stack
    int a;      // The stack size
} Item;         // The stack item
// test_list : test the stack
bool test_list()
{
    struct Stack stack;                                  // The stack
    Item i1 = {"stack", 3};                              // The stack item
    Item i2 = {"nice", 10};                              // The stack item
    Item i;                                              // The stack item
    const int list_len = 10;                             // The stack size
    Item buf[list_len];                                  // The stack buffer
    stack_ops.init(&stack, list_len, sizeof(Item), buf); // Initialize the stack
    stack_ops.push(&stack, &i1);                         // Push the stack item
    stack_ops.push(&stack, &i2);                         // Push the stack item

    puts("LIST TEST START...");                              // Print a message
    printf("PUSH, STACK SIZE:%d\n", stack_ops.size(&stack)); // Print the stack size
    if (stack_ops.size(&stack) != 2)                         // Check the stack size
    {
        return FALSE; // Return an error
    }
    stack_ops.pop(&stack, &i);                              // Pop the stack item
    printf("POP, STACK SIZE:%d\n", stack_ops.size(&stack)); // Print the stack size
    if (strcmp((void *)i.s, "nice") != 0)                   // Check the stack item
    {
        return FALSE; // Return an error
    }
    stack_ops.peek(&stack, &i);  // Peek the stack item
    printf("PEEK, a:%d\n", i.a); // Print the stack item
    if (i.a != 10)               // Check the stack item
    {
        return FALSE; // Return an error
    }
    stack_ops.pop(&stack, &i);              // Pop the stack item
    if (stack_ops.pop(&stack, &i) != FALSE) // Pop the stack item
    {
        return FALSE; // Return an error
    }
    stack_ops.push(&stack, &i1);                              // Push the stack item
    stack_ops.clear(&stack);                                  // Clear the stack
    printf("CLEAR, STACK SIZE:%d\n", stack_ops.size(&stack)); // Print the stack size
    if (stack_ops.size(&stack) != 0)                          // Check the stack size
    {
        return FALSE; // Return an error
    }
    return TRUE; // Return no error
}