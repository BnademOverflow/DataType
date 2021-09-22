/* Stack is a simple stack implementation. */

#include "libs/stack.h"

// get_current_address - returns the current address of the stack
static inline void *get_current_address(struct Stack *l)
{
    return l->data + l->count * l->item_size; // return the current address
}

// list_init - initializes a stack
void list_init(struct Stack *list, u32 max_length, u32 item_size, void *buf)
{
    list->max_length = max_length; // set the max length
    list->count = 0;               // set the count to 0
    list->data = buf;              // set the data to the buffer
    list->item_size = item_size;   // set the item size
}
// list_push - pushes an item onto the stack
bool list_push(struct Stack *list, void *item)
{
    if (list->count == list->max_length) // if the stack is full
    {
        return FALSE; // return false
    }
    memcpy(get_current_address(list), item, list->item_size); // copy the item to the current address
    list->count++;                                            // increment the count
}
// list_pop - pops an item off the stack
bool list_pop(struct Stack *list, void *item)
{
    if (list->count == 0) // if the stack is empty
    {
        return FALSE; // return false
    }
    list->count--;                                            // decrement the count
    memcpy(item, get_current_address(list), list->item_size); // copy the item from the current address
}
// list_peek - peeks at the top of the stack
bool list_peek(struct Stack *list, void *item)
{
    if (list->count == 0) // if the stack is empty
    {
        return FALSE; // return false
    }
    memcpy(item, get_current_address(list), list->item_size); // copy the item from the current address
}
// list_clear - clears the stack
void list_clear(struct Stack *list)
{
    memset(list, 0, sizeof(struct Stack)); // clear the stack
}
// list_size - returns the size of the stack
u32 list_size(struct Stack *list)
{
    return list->count; // return the count
}
// stackops - stack operations
StackOps stack_ops = {
    .init = list_init,   // set the init function
    .push = list_push,   // set the push function
    .pop = list_pop,     // set the pop function
    .clear = list_clear, // set the clear function
    .peek = list_peek,   // set the peek function
    .size = list_size,   // set the size function
};