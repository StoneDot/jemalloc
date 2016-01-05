#ifdef _MSC_VER
/*
 * Define overrides for non-standard allocator-related functions if they are
 * present on the system.
 */
#undef JEMALLOC_OVERRIDE_MEMALIGN
#undef JEMALLOC_OVERRIDE_VALLOC
#define	JEMALLOC_OVERRIDE_MEMALIGN
#define	JEMALLOC_OVERRIDE_VALLOC

/* sizeof(void *) == 2^LG_SIZEOF_PTR. */
#undef LG_SIZEOF_PTR
#if defined(_WIN32) || defined(_M_IX86)
#  define LG_SIZEOF_PTR       2
#elif defined(_WIN64) || defined(_M_X64)
#  define LG_SIZEOF_PTR       3
#endif

#endif
