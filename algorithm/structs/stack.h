#ifndef STRUCTS_STACK_H_
#define STRUCTS_STACK_H_
#include "__basic.h"
namespace sce {
    template <typename dT>
    class stack : public __struct {
    private:
        node *_head;
        size_t _len;

    public:
        stack();
        stack(dT data);
        stack(dT data[]);
        stack(stack s);
        ~stack();

        void push(dT data);
        auto pop(bool is_return = false);
        dT top() const;

        bool empty() const;
        size_t size() const;
        void clear();
        void as_array(dT array[]);
        std::string toString() const;

        const stack &operator=(const stack &s);
        bool operator==(const stack &s) const;
    };
} /* namespace sce */
#include "realization/stack.cc"
#endif /* STRUCTS_STACK_H_ */
