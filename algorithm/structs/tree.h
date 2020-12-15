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
    static const std::string type = "tree";
    tree(size_t dim = 2);
    tree(dT data, size_t dim = 2);
    tree(dT data[], size_t mode[], size_t dim = 2);
    tree(tree t);
    ~tree();

    void insert(dT data, size_t mode[]);
    auto del(size_t mode[], bool is_return = false);
    dT get(size_t mode[]) const;

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
  std::ostream &operator<<(std::ostream &out, tree<dT> s);
  template <typename dT>
  std::istream &operator>>(std::istream &in, tree<dT> s);

  template <typename dT>
  class BSTree : public tree {
   protected:
    BTree_node *root;
    size_t height, size;
    comparator<dT> cmp;

   public:
    static const std::string type = "BSTree";
    BSTree(comparator<dT> cmp);
    BSTree(dT data, comparator<dT> cmp);
    BSTree(dT data[], int mode[], comparator<dT> cmp);
    BSTree(BSTree t);
    BSTree(tree t, comparator<dT> cmp);
    BSTree(AVLTree t);
    BSTree(RBTree t);

    void insert(dT data);
    auto del(dT data);
    dT get(int mode[]) const;
    void set(int mode[]) const;
    bool has(dT data) const;
    void where(dT data, int ans[]) const;

    bool empty() const;
    size_t size() const;
    size_t height() const;
    size_t dimensions() const;
    void clear();
    std::string toString(int8_t mode = 0) const;

    const tree &operator=(const tree &t);
    bool operator==(const tree &t) const;

    void traversal(dT to[], int8_t mode = 1);
  };
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, BSTree<dT> s);

  template <typename dT>
  class AVLTree : public BSTree {
   private:
   public:
    static const std::string type = "AVLTree";
  };
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, AVLTree<dT> s);

  template <typename dT>
  class BTree {};
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, BTree<dT> s);

  template <typename dT>
  class RBTree : public AVLTree {};
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, RBTree<dT> s);

  template <typename dT>
  class huffmanTree {};
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, huffmanTree<dT> s);

  class trieTree {};
  std::ostream &operator<<(std::ostream &out, trieTree s);
} // namespace sce
#include "realization/tree.cc"
#endif
