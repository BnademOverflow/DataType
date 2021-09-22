# DataType

## Abstract realization: `void*` (null pointer) conversion method

This technique makes use of the feature of null pointer without data type in C language, which can be cast to realize the abstraction of any data type.

Take the structure array circular queue as an example, the declaration is as follows:

```c
typedef struct {
 uint32_t head;
 uint32_t tail;
 uint32_t count; /*real item counts*/
 uint32_t size; /*queue max size*/
    uint32_t item_size; /*item each size in bytes*/
 uint8_t * buf; /*storage place*/
}CircleQueue;
CircleQueue *queue_create(uint32_t item_size, uint32_t size);
bool queue_push(CircleQueue *q, void *element);
bool queue_pop(CircleQueue *q, void *element);
bool queue_peek(CircleQueue *q, void *element);
```

We complete the initialization of the stack through `list_init`. When using it, we declare an empty Stack, and then pass it into `list_init` as the first parameter. At the same time, we pass in the maximum capacity of the stack, the size of the object, and the cache where the object is located to complete the initialization.

```c
typedef struct{
    char s[10];
    int a;
}Item;
int test()
{
    const int list_len=10; /*max size*/
    Item buf[list_len]; /*buffer*/
    struct Stack stack;
    list_init(&stack, list_len, sizeof(Item), buf); /*init*/
}
```

The above code demonstrates the initialization process, and other operations are similar to the previous chapter.

So far we have realized the complete **abstract data type** and **all static memory abstract data type**.

### Unification of abstract data operation interface

For an abstract data structure, there will be a series of corresponding operation methods (functions), but the user layer does not necessarily know the exact function name, so the user must refer to the header file to call it. A more scientific method is that we will need The operations provided to the user are centrally defined in a structure, which is a bit like the interface definition in a high-level language. The user calls through a unified interface, which is more convenient. Taking Stack as an example, the interface declaration is as follows:

```c
typedef struct{
    void (*init)(struct Stack *list, u32 max_length, u32 item_size, void * buf);
    bool (*push)(struct Stack *list, void *item);
    bool (*pop)(struct Stack *list, void *item);
    bool (*peek)(struct Stack *list, void *item);
    void (*clear)(struct Stack *list);
    u32 (*size)(struct Stack *list);
}StackOps;
extern StackOps stack_ops;
```

The user makes a unified call through stackops, and the calling process is as follows:

```c
struct Stack stack;
Item i1={"stack",3};
Item i2={"nice",10};
const int list_len=10;
Item buf[list_len];
stack_ops.init(&stack, list_len, sizeof(Item), buf);
stack_ops.push(&stack, &i1);
stack_ops.push(&stack, &i2);
```

## Reference

- <https://stackoverflow.com/questions/5551427/generic-data-type-in-c-void>
- <http://cs.boisestate.edu/~amit/teaching/253/handouts/07-c-generic-coding-handout.pdf>
- <https://iafisher.com/blog/2020/06/type-safe-generics-in-c>
- <https://constantsmatter.com/posts/generic-ds-c/>
