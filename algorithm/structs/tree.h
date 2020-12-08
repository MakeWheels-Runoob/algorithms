#ifndef STRUCTS_TREE_H
#define STRUCTS_TREE_H
#include "__basic.h"
namespace sce {
    template <class dT>
    class tree {
    private:
        tree_node *root;
        uint64_t len,height,dim;
        static void delete_node(node *n);
    public:
        tree(uint64_t dim=2);
        tree(dT data,uint64_t dim=2);
        tree(dT data[],uint64_t mode[],uint64_t dim=2);
        tree(tree t);
        ~tree();

        void insert(dT data,uint64_t mode[]);
        auto del(uint64_t mode[],bool is_return=false);
        dT query(uint64_t mode[]) const;

        bool empty() const;
        uint64_t size() const;
        uint64_t height() const;
        uint64_t dimensions() const;
        void clean();

        const tree &operator=(const tree &t);
        bool operator==(const tree &t) const;
    };
}
#endif
