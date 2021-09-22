/* Stack.h : Defines the Stack class. */

#pragma once
#include "typedef.h"
// Stack class
struct Stack
{
    u32 max_length; // Maximum length of the stack
    u32 item_size;  // Size of each item
    u32 count;      // Number of items in the stack
    u8 *data;       // Pointer to the stack data
};
// Stack constructor
typedef struct
{
    void (*init)(struct Stack *list, u32 max_length, u32 item_size, void *buf); // Initialize the stack
    bool (*push)(struct Stack *list, void *item);                               // Push an item onto the stack
    bool (*pop)(struct Stack *list, void *item);                                // Pop an item from the stack
    bool (*peek)(struct Stack *list, void *item);                               // Peek at the top item on the stack
    void (*clear)(struct Stack *list);                                          // Clear the stack
    u32 (*size)(struct Stack *list);                                            // Get the size of the stack
} StackOps;                                                                     // Stack operations
extern StackOps stack_ops;                                                      // Stack operations
