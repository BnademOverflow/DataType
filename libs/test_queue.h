#pragma once
#include "queue.h"

typedef struct
{
    char *s;                 // string
    void (*action)(char *s); // function pointer
} Sd;                        // struct definition
static void action(char *s)  // function definition
{
    printf("do action:%s\n", s); // print string
}
bool test_cq(void) // function definition
{
    struct CircleQueue q1;                                // struct definition
    const int slen = 10;                                  // constant definition
    Sd s1_buf[slen];                                      // array definition
    circle_queue_ops.init(slen, sizeof(Sd), &q1, s1_buf); // init queue
    Sd s1 = {"hello", action};                            // struct definition
    Sd s2 = {"queue", action};                            // struct definition

    puts("CIRCLE QUEUE TEST START...");                      // print string
    circle_queue_ops.inqueue(&q1, &s1);                      // inqueue
    circle_queue_ops.inqueue(&q1, &s2);                      // inqueue
    printf("INIT, Q size:%d\n", circle_queue_ops.size(&q1)); // print string
    if (circle_queue_ops.size(&q1) != 2)                     // if
    {
        return FALSE; // return
    }
    Sd ss;                                                  // struct definition
    circle_queue_ops.dequeue(&q1, &ss);                     // dequeue
    printf("POP, Q size:%d\n", circle_queue_ops.size(&q1)); // print string
    ss.action(ss.s);                                        // call function
    if (strcmp(ss.s, "hello") != 0)                         // if
    {
        return FALSE; // return
    }
    circle_queue_ops.peek(&q1, &ss);                         // peek
    printf("PEEK, Q size:%d\n", circle_queue_ops.size(&q1)); // print string
    if (strcmp(ss.s, "queue") != 0)                          // if
    {
        return FALSE; // return
    }
    if (circle_queue_ops.size(&q1) != 1) // if
    {
        return FALSE; // return
    }
    circle_queue_ops.dequeue(&q1, &ss);                     // dequeue
    printf("POP, Q size:%d\n", circle_queue_ops.size(&q1)); // print string
    ss.action(ss.s);                                        // call function
    if (circle_queue_ops.dequeue(&q1, &ss) != FALSE)        // if
    {
        return FALSE; // return
    }
    circle_queue_ops.inqueue(&q1, &s1);                       // inqueue
    circle_queue_ops.clear(&q1);                              // clear
    printf("CLEAR, Q size:%d\n", circle_queue_ops.size(&q1)); // print string
    if (circle_queue_ops.size(&q1) != 0)                      // if
    {
        return FALSE; // return
    }
    return TRUE; // return
}