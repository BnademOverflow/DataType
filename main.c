#include "libs/test_queue.h"
#include "libs/test_stack.h"

// main function
int main(int argc, char **argv)
{
    if (test_cq() == TRUE) // test cq
    {
        puts("Queue Test Passed."); // print success
    }
    else // test failed
    {
        puts("Queue Test Failed."); // print failure
    }
    puts("Test stack:");     // print test stack
    if (test_list() == TRUE) // test list
    {
        puts("Stack Test Passed"); // print success
    }
    else // test failed
    {
        puts("Stack test Failed"); // print failure
    }
    return 0; // return
}
