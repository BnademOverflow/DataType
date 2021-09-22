#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;   // 1 byte
typedef unsigned short u16; // 2 bytes
typedef unsigned long u32;  // 4 bytes

#ifndef bool     // bool is a reserved keyword in c++
typedef u8 bool; // 1 byte
#endif           // bool
#ifndef NULL     // NULL is a reserved keyword in c++
#define NULL (0) // 0 is a reserved keyword in c++
#endif           // NULL
#define TRUE 1   // 1 is a reserved keyword in c++
#define FALSE 0  // 0 is a reserved keyword in c++