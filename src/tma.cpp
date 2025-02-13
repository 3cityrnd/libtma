#include <iostream>

#ifdef LOGGING
#define show_trace(x) std::cout << "[tma-trace]: " <<  x << std::endl;
#define show_error(x) std::cout << "[tma-error]: " <<  x << std::endl;
#else
#define show_trace(x) 
#define show_error(x) 
#endif

namespace c10 {

    void *alloc_cpu(size_t nbytes)  {


    constexpr size_t BLK_SIZE = 16;
    size_t nbytes_align = (nbytes + BLK_SIZE - 1) / BLK_SIZE * BLK_SIZE;
    void *ptr;

    if(posix_memalign(&ptr, 64, nbytes_align) != 0) {
        show_error("torch-alloc-cpu posix_memaling error " <<  nbytes_align);
        ptr = nullptr;
     }

       show_trace("torch-alloc-cpu required=[" << nbytes << "] return=[" << nbytes_align << "] bytes ptr="<< ptr);

       return ptr;
 
    }

 /*    
    void free_cpu(void *data) {

          free(data);
    }
*/

} 
