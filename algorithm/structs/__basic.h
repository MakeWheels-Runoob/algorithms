#ifndef STRUCTS_BASIC_H_
#define STRUCTS_BASIC_H_
#include "__builtin.h"

#include <string>
namespace sce {
    template <typename dT>
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

    template <typename dT>
    class tree_node : public node {
    private:
        dt data;
        tree_node *next[], *pre;
        size_t length;

    public:
        tree_node();
        tree_node(dT data);
        tree_node(tree_node tn);
        tree_node(node n);
        ~tree_node();

        bool is_root() const;
        bool has_next() const;
    };

    template <typename dT>
    class BTree_node : public tree_node {
    private:
        dT data;
        BTree_node *left, *right, *pre;
        size_t height;
        int64_t balance_factor;
    public:
        static void balance(BTree_node *n,BTree_node *p,BTree_node *g);
        static bool itsLeftsonOfParent(BTree_node *node);

        BTree_node();
        BTree_node(dT data);
        BTree_node(tree_node tn);
        BTree_node(node n);
        ~BTree_node();

        bool is_root() const;
        bool has_next() const;
    };

    template <typename dT>
    class __struct {
    protected:
        node *_head, *_tail;
        size_t _len;
        __struct();
        __struct(dT data);
        __struct(dT data[]);
        ~__struct();

        virtual void push(dT data);
        virtual auto pop(bool is_return = false);
        virtual dT top() const;
        virtual dT front() const;
        virtual dT tail() const;
        virtual bool empty() const;
        virtual size_t size() const;
        virtual void clear();
        virtual void insert(size_t where, dT data);
        virtual void as_array(dT array[]) const;
        virtual dT get(size_t where) const;
        virtual auto set(size_t where, dT data, bool is_return = false);
        virtual bool has(dT data);
        virtual size_t indexOf(dT data);
        virtual dT query(size_t where) const;
        virtual auto remove(size_t where, bool is_return = false);
        virtual std::string toString() const;

        virtual const __struct &operator=(const __struct &s);
        virtual bool operator==(const __struct &s) const;
    };

    template <typename dT>
    bool cmp(dT a,dT b) {
        return a < b;
    }
} /* namespace sce */
#include "realization/__basic.cc"
#endif /* STRUCTS_BASIC_H_ */
