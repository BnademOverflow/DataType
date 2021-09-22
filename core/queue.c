/* Queue is a first-in, first-out data structure */

#include "libs/queue.h"

// Queue_Init
void queue_init(u32 length, u32 item_size, struct CircleQueue *q, void *data)
{
    q->length = length;       // length of queue
    q->item_size = item_size; // size of each item
    q->tail = 0;              // tail of queue
    q->head = 0;              // head of queue
    q->count = 0;             // count of items in queue
    q->data = data;           // pointer to data
}

static inline void *get_item_addr(const struct CircleQueue *q, u32 index)
{
    return q->data + index * q->item_size; // get address of item
}

// Queue_Clear - Clear the queue
void queue_clear(struct CircleQueue *q)
{
    memset(q->data, 0, q->length * q->item_size); // memset data to 0
    q->tail = 0;                                  // reset tail
    q->head = 0;                                  // reset head
    q->count = 0;                                 // reset count
}

// Queue_push - Push an item into the queue
bool queue_push(struct CircleQueue *q, const void *item)
{
    memcpy(get_item_addr(q, q->tail), item, q->item_size); // copy item to tail
    q->tail++;                                             // increment tail
    if (q->tail >= q->length)                              // if tail is at end of queue
    {
        q->tail = 0; // reset tail
    }
    if (q->count == q->length) /*full*/
    {
        q->head = q->tail; // reset head
    }
    else
    {
        q->count++; // increment count
    }
    return TRUE;
}

// Queue_pop - Pop an item from the queue
bool queue_pop(struct CircleQueue *q, void *item) // pop item from queue
{
    if (q->count == 0) // if queue is empty
    {
        return FALSE; // return false
    }
    memcpy(item, get_item_addr(q, q->head), q->item_size); // copy item from head
    q->head++;                                             // increment head
    if (q->head >= q->length)                              // if head is at end of queue
    {
        q->head = 0; // reset head
    }
    q->count--;  // decrement count
    return TRUE; // return true
}

// Queue_peek - Peek an item from the queue
bool queue_peek(const struct CircleQueue *q, void *item) // peek item from queue
{
    if (q->count == 0) // if queue is empty
    {
        return FALSE; // return false
    }
    memcpy(item, get_item_addr(q, q->head), q->item_size); // copy item from head
    return TRUE;                                           // return true
}

u32 queue_size(const struct CircleQueue *q) // get size of queue
{
    return q->count; // return count
}

// Queue_serialize - Serialize the queue
void queue_serialize(const struct CircleQueue *q, u8 *out, u32 *len) // serialize queue
{
    memcpy(out, (u8 *)q, sizeof(struct CircleQueue) - 4);                            // copy queue
    memcpy(out + sizeof(struct CircleQueue) - 4, q->data, q->length * q->item_size); // copy data
    *len = sizeof(struct CircleQueue) - 4 + q->length * q->item_size;                // set length
}

// Queue_deserialize - Deserialize the queue
void queue_deserialize(struct CircleQueue *q, void *data, u8 *in) // deserialize queue
{
    memcpy((u8 *)q, in, sizeof(struct CircleQueue) - 4);                         // copy queue
    q->data = data;                                                              // set data
    memcpy(data, in + sizeof(struct CircleQueue) - 4, q->length * q->item_size); // copy data
}
CircleQueueOps circle_queue_ops = {
    // circle queue ops
    .init = queue_init,              // init
    .clear = queue_clear,            // clear
    .inqueue = queue_push,           // inqueue
    .dequeue = queue_pop,            // dequeue
    .peek = queue_peek,              // peek
    .size = queue_size,              // size
    .serialize = queue_serialize,    // serialize
    .deserialize = queue_deserialize // deserialize

};