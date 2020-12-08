#ifndef STRUCTS_BUILTIN_H_
#define STRUCTS_BUILTIN_H_
namespace sce{
    enum error{
        NODE=0,
        STACK=5,
        QUEUE,
        LIST,
        TREE=10,
        GRAPH
    };
    typedef signed char int8_t;
    typedef short int16_t;
    typedef int int32_t;
    typedef long long int64_t;
    typedef char uint8_t;
    typedef unsigned short uint16_t;
    typedef unsigned int uint32_t;
    typedef unsigned long long uint64_t;
    const uint64_t MAX_SIZE=1e15;
    const uint64_t MAX_NODE=1e10;
    const uint64_t MAX_EDGE=1e12;
}
#endif
