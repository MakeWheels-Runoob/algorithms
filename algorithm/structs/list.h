#ifndef STRUCTS_LIST_H_
#define STRUCTS_LIST_H_
#include "__basic.h"
namespace sce {
  template <typename dT>
  class list : public __struct {
   private:
    node *_head, *_tail;
    size_t _len;

   public:
    list();
    list(dT data);
    list(dT data[]);
    list(list s);
    ~list();

    void insert(size_t where, dT data);
    dT get(size_t where) const;
    auto del(size_t where, bool is_return = false);

    bool empty() const;
    size_t size() const;
    void clean();
    void as_array(dT array[]) const;
    std::string toString() const;

    const list &operator=(const list &s);
    bool operator==(const list &s) const;
  };

  template <typename dT>
  class Clist : public __struct {
   private:
    node *_head, *_tail;
    size_t _len;

   public:
    Clist();
    Clist(dT data);
    Clist(dT data[]);
    Clist(list s);
    ~Clist();

    void insert(size_t where, dT data);
    dT get(size_t where) const;
    auto del(size_t where, bool is_return = false);

    bool empty() const;
    size_t size() const;
    void clear();
    void as_array(dT array[]) const;
    std::string toString() const;

    const list &operator=(const list &s);
    bool operator==(const list &s) const;
  };
} /* namespace sce */
#include "realization/list.cc"
#endif /* STRUCTS_LIST_H_ */
