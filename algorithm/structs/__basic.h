#ifndef STRUCTS_BASIC_H_
#define STRUCTS_BASIC_H_
#include "__builtin.h"
namespace sce {
    template <class dT>
    class node {
    protected:
        dT data;
        node *next, *pre;

    public:
        node();
        node(dT data);
        node(node n);
        node(tree_node tn);
        ~node();
    };

    template <class dT>
    class tree_node : public node {
    private:
        dt data;
        tree_node *next[];
    public:
        tree_node();
        tree_node(dT data);
        tree_node(tree_node tn);
        tree_node(node n);
        ~tree_node();
    };

    template <class dT>
    class __struct {
    protected:
        node *_head,*_tail;
        uint64_t _len;
        __struct();
        __struct(dT data);
        __struct(dT data[]);
        ~__struct();

        virtual void push(dT data);
        virtual auto pop(bool is_return=false);
        virtual dT top() const;
        virtual dT front() const;
        virtual dT tail() const;
        virtual bool empty() const;
        virtual uint64_t size() const;
        virtual void clear();
        virtual void insert(uint64_t where,dT data);
        virtual void as_array(dT array[]) const;
        virtual dT get(uint64_t where) const;
        virtual auto set(uint64_t where,dT data,bool is_return=false);
        virtual bool has(dT data);
        virtual uint64_t indexOf(dT data);
        virtual dT query(uint64_t where) const;
        virtual auto del(uint64_t where,bool is_return=false);

        virtual const __struct &operator=(const __struct &s);
        virtual bool operator==(const __struct &s) const;
    };
} /* namespace sce */
#include "realization/__basic.cc"
#endif /* STRUCTS_BASIC_H_ */
