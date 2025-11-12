/* Glue functionality for standard C code trying to run on MicroPython
 * Standard C code expects libc to be linked in, and we're not doing that
 * instead, we're providing linkable addresses that forward to MicroPython's
 * exported function table 'mp_fun_table' 
 */

#include <unistd.h>
#include "py/dynruntime.h"
#include "libmad/config.h"

/*
void *malloc(size_t n) {
  void *ptr = m_malloc(n);
  return ptr;
}

// yes yes, the memory's already cleared by m_malloc
void *calloc(size_t n, size_t m) {
  void *ptr = m_malloc(n * m);
  return ptr;
}

void free(void *ptr) {
  m_free(ptr);
}
*/

#ifndef NDEBUG
void panic(char *);
void __assert_func(const char *file, int line, const char *func, const char *failedexpr) {
  mp_fun_table.raise_msg(
    mp_fun_table.load_global(MP_QSTR_AssertionError),
    "Assertion Failed");
  panic("Assertion Failed");
}
#endif
void *memcpy(void *dst, const void *src, size_t n) {
  return mp_fun_table.memmove_(dst, src, n);
}

void *memmove(void *dest, const void *src, size_t n) {
  return mp_fun_table.memmove_(dest, src, n);
}

void *memset(void *s, int c, size_t n) {
  return mp_fun_table.memset_(s, c, n);
}

int sprintf(char *str, const char *format, ...) {
  // shouldn't use sprintf anyways, but it's annoying not to have a snprintf() to work with
  return 0;
}
