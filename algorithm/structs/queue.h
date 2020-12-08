#ifndef STRUCTS_QUEUE_H_
#define STRUCTS_QUEUE_H_
#include "__basic.h"
namespace sce {
    template <class dT>
    class queue : public __struct {
    private:
        node *_head, *_tail;
        uint64_t _len;

    public:
        queue();
        queue(dT data);
        queue(dT data[]);
        queue(queue s);
        ~queue();

        void push(dT data);
        auto pop(bool is_return = false);
        dT front();
        dT tail();

        bool empty();
        uint64_t size();
        void clean();
        void as_array(dT array[]);

        const queue &operator=(const queue &s);
        bool operator==(const queue &s) const;
    };
} // namespace sce
#endif /* STRUCTS_QUEUE_H_ */
