#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size_t tmp_size;
    void *tmp_ptr;
   
    if (ptr == NULL) {
	    return malloc(size);
    }

    tmp_size = malloc_size(ptr);
    if (size <= tmp_size) {
	    return ptr;
    }

    tmp_ptr = malloc(size);
    mx_memcpy(tmp_ptr, ptr, tmp_size);
    free(ptr);

    return tmp_ptr;
}

