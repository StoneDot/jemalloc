/*
 * Hyper-threaded CPUs may need a special instruction inside spin loops in
 * order to yield to another virtual CPU.
 */
#ifdef _MSC_VER
#undef CPU_SPINWAIT
#define CPU_SPINWAIT __asm pause
#endif
