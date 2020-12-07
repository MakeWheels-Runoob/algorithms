#ifndef STRUCTS_STACK_H_
#define STRUCTS_STACK_H_
#include "__basic.h"
namespace sce {
    template <class dT>
    class stack {
        private:
        node *_head;
        uint64_t _len;
    public:
        stack();
        stack(dT data);
        stack(dT data[]);
        stack(stack s);
        ~stack();

        void push(dT data);
        auto pop(bool is_return=false);
        dT top();

        bool empty();
        uint64_t size();
        void clean();
        void as_array(dT array[]);

        const stack &operator=(const stack &s);
        bool operator==(const stack &s) const;
    };
} /* namespace sce */
#endif
 