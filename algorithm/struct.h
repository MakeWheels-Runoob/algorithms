#ifndef ALGORTHMS_STRUCT_H_
#define ALGORTHMS_STRUCT_H_
#include "structs/graph.h"
#include "structs/list.h"
#include "structs/queue.h"
#include "structs/stack.h"
#include "structs/tree.h"

namespace sce // structure
{
    typedef sce::stack stack_t;
    using queue_t = sce::queue;
    using list_t = sce::list;
    using BList_t = sce::bidirectionalList;
    using CList_t = sce::circularList;
    using BCList_t = sce::bidirectionalCircularList;
    using tree_t = sce::tree;
    using graph_t = sce::graph;
} // namespace sce
#endif
