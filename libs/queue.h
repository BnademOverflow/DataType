/* Queue.h : Defines the Queue class. */
#ifndef CIRCLE_QUEUE_H
#define CIRCLE_QUEUE_H

#include "typedef.h"

// CircleQueue : Defines the CircleQueue
struct CircleQueue
{
    u32 head;      // The head of the queue
    u32 tail;      // The tail of the queue
    u32 length;    // The length of the queue
    u32 item_size; // The size of the item
    u32 count;     // The count of the queue
    u8 *data;      // The data of the queue
};
// Struct : CircleQueue
typedef struct
{
    void (*init)(u32 length, u32 item_size, struct CircleQueue *q, void *data); // Initialize the queue
    void (*clear)(struct CircleQueue *q);                                       // Clear the queue
    bool (*inqueue)(struct CircleQueue *q, void *item);                         // Inqueue the item
    bool (*dequeue)(struct CircleQueue *q, void *item);                         // Dequeue the item
    bool (*peek)(const struct CircleQueue *q, void *item);                      // Peek the item
    u32 (*size)(const struct CircleQueue *q);                                   // Get the size of the queue
    void (*serialize)(const struct CircleQueue *q, u8 *out, u32 *len);          // Serialize the queue
    void (*deserialize)(struct CircleQueue *q, void *data, u8 *in);             // Deserialize the queue
} CircleQueueOps;                                                               // CircleQueue operations
extern CircleQueueOps circle_queue_ops;                                         // CircleQueue operations
#endif                                                                          // CIRCLE_QUEUE_H
