#ifndef STRUCTS_QUEUE_H_
#define STRUCTS_QUEUE_H_
#include "__basic.h"
namespace sce {
    template <typename dT>
    class queue : public __struct {
    protected:
        node *_head, *_tail;
        size_t _len;

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
        size_t size();
        void clear();
        void as_array(dT array[]);
        std::string toString() const;

        const queue &operator=(const queue &s);
        bool operator==(const queue &s) const;
    };

    template <typename dT>
    class deque : public queue {
    private:
        node *_head, *_tail;
        size_t _len;

    public:
        deque();
        deque(dT data);
        deque(dT data[]);
        deque(queue s);
        ~deque();

        void push(dT data, bool is_front = true);
        auto pop(bool is_return = false, bool is_front = false);
        dT front();
        dT tail();

        bool empty();
        size_t size();
        void clear();
        void as_array(dT array[]);
        std::string toString() const;

        const queue &operator=(const queue &s);
        bool operator==(const queue &s) const;
    };
} // namespace sce
#include "realization/queue.cc"
#endif /* STRUCTS_QUEUE_H_ */
