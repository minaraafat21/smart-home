#ifndef LSTD_TYPES_H
#define LSTD_TYPES_H

typedef unsigned long   int     u32;
typedef unsigned short  int     u16;
typedef unsigned        char    u8;

typedef signed long     int     s32;
typedef signed short    int     s16;
typedef signed          char    s8;

typedef                int      size_t;

typedef float                   f32;
typedef double                  f64;

#ifdef NULL
#undef NULL
#endif 

#define NULL              ((void*)0)

#define __IO	volatile

#endif /*LSTD_TYPES_H*/
