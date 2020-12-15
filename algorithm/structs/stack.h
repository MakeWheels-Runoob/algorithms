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
    static const std::string type = "stack";
    stack();
    stack(dT data);
    stack(dT data[]);
    stack(stack s);
    stack(MStack s);
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
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, stack<dT> s);
  template <typename dT>
  std::istream &operator>>(std::istream &in, stack<dT> s);

  template <typename dT>
  class MStack : public stack {
   private:
    node *_head;
    size_t _len;
    comparator<dT> cmp;

   public:
    static const std::string type = "MStack";
    MStack(comparator<dT> cmp);
    MStack(dT data, comparator<dT> cmp);
    MStack(dT data[], comparator<dT> cmp);
    MStack(MStack s);
    MStack(stack s, comparator<dT> cmp);
    ~MStack();

    void push(dT data);
    auto pop(bool is_return = false);
    dT top() const;

    bool empty() const;
    size_t size() const;
    void clear();
    void as_array(dT array[]);
    std::string toString() const;

    const MStack &operator=(const MStack &s);
    bool operator==(const MStack &s) const;
  };
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, MStack<dT> s);
  template <typename dT>
  std::istream &operator>>(std::istream &in, MStack<dT> s);
} /* namespace sce */
#include "realization/stack.cc"
#endif /* STRUCTS_STACK_H_ */
