#ifndef HELPER
#define HELPER

#define DLOG(fmt, ...) do { \
        printf("%s(%d) -> "fmt, __func__, __LINE__, __VA_ARGS__); \
    } while (0);

#define DMSG(message) do { \
        printf("%s(%d) -> "message, __func__, __LINE__); \
    } while (0);


#endif // HELPER

