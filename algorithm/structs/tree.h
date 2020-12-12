#ifndef STRUCTS_TREE_H
#define STRUCTS_TREE_H
#include "__basic.h"
namespace sce {
    template <typename dT>
    class tree {
    private:
        tree_node *root;
        size_t len, height, dim;
        static void delete_node(node *n);

    public:
        tree(size_t dim = 2);
        tree(dT data, size_t dim = 2);
        tree(dT data[], size_t mode[], size_t dim = 2);
        tree(tree t);
        ~tree();

        void insert(dT data, size_t mode[]);
        auto del(size_t mode[], bool is_return = false);
        dT query(size_t mode[]) const;

        bool empty() const;
        size_t size() const;
        size_t height() const;
        size_t dimensions() const;
        void clear();
        std::string toString() const;

        const tree &operator=(const tree &t);
        bool operator==(const tree &t) const;

        void traversal(dT to[], int8_t mode = 1);
    };

    template <typename dT, bool (*sortFunction)(dT, dT) = cmp>
    class BSTree : public tree {
    private:
        BTree_node *root;
        size_t height, len;

    public:
        BSTree();
        BSTree(dT data);
        BSTree(dT data[], int mode[]);
        BSTree(BSTree t);
        BSTree(tree t);
        BSTree(AVLTree t);
        BSTree(RBTree t);

        void insert(dT data, int mode[]);
        auto del(int mode[], bool is_return = false);
        dT query(int mode[]) const;

        bool empty() const;
        size_t size() const;
        size_t height() const;
        size_t dimensions() const;
        void clear();
        std::string toString() const;

        const tree &operator=(const tree &t);
        bool operator==(const tree &t) const;

        void traversal(dT to[], int8_t mode = 1);
    };

    template <typename dT>
    class AVLTree : public BSTree {
    private:
    };

    template <typename dT>
    class BTree {};

    template <typename dT>
    class RBTree : public BTree, public BSTree {};

    template <typename dT>
    class HuffmanTree {};
} // namespace sce
#include "realization/tree.cc"
#endif
