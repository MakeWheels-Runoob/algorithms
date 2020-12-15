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
    queue(deque s);
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
  std::ostream &operator<<(std::ostream &out, queue<dT> s);
  template <typename dT>
  std::istream &operator>>(std::istream &in, queue<dT> s);

  template <typename dT>
  class deque : public queue {
   private:
    node *_head, *_tail;
    size_t _len;

   public:
    deque();
    deque(dT data);
    deque(dT data[]);
    deque(deque s);
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

    const deque &operator=(const deque &s);
    bool operator==(const deque &s) const;
  };
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, deque<dT> s);
  template <typename dT>
  std::istream &operator>>(std::istream &in, deque<dT> s);

  template <typename dT>
  class MQueue : public queue {
   protected:
    node *_head, *_tail;
    size_t _len;
    comparator<dT> cmp;

   public:
    MQueue(comparator<dT> cmp);
    MQueue(dT data, comparator<dT> cmp);
    MQueue(dT data[], comparator<dT> cmp);
    MQueue(queue s, comparator<dT> cmp);
    MQueue(deque s, comparator<dT> cmp);
    MQueue(MQueue s);
    MQueue(MDeque s);
    ~MQueue();

    void push(dT data);
    auto pop(bool is_return = false);
    dT front();
    dT tail();

    bool empty();
    size_t size();
    void clear();
    void as_array(dT array[]);
    std::string toString() const;

    const MQueue &operator=(const MQueue &s);
    bool operator==(const MQueue &s) const;
  };
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, MQueue<dT> s);
  template <typename dT>
  std::istream &operator>>(std::istream &in, MQueue<dT> s);

  template <typename dT>
  class MDeque : public deque {
   private:
    node *_head, *_tail;
    size_t _len;
    comparator<dT> cmp;

   public:
    MDeque(comparator<dT> cmp);
    MDeque(dT data, comparator<dT> cmp);
    MDeque(dT data[], comparator<dT> cmp);
    MDeque(deque s, comparator<dT> cmp);
    MDeque(queue s, comparator<dT> cmp);
    MDeque(MQueue s);
    MDeque(MDeque s);
    ~MDeque();

    void push(dT data, bool is_front = true);
    auto pop(bool is_return = false, bool is_front = false);
    dT front();
    dT tail();

    bool empty();
    size_t size();
    void clear();
    void as_array(dT array[]);
    std::string toString() const;

    const deque &operator=(const deque &s);
    bool operator==(const deque &s) const;
  };
  template <typename dT>
  std::ostream &operator<<(std::ostream &out, deque<dT> s);
  template <typename dT>
  std::istream &operator>>(std::istream &in, deque<dT> s);
} // namespace sce
#include "realization/queue.cc"
#endif /* STRUCTS_QUEUE_H_ */
