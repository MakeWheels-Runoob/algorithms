#ifndef STRUCTS_DYNAMIC_H
#define STRUCTS_DYNAMIC_H
#include "__basic.h"
namespace sce {
  template <typename dT>
  class DArray : public __struct {
   private:
    size_t size;
    dT data[];
    static const size_t DEFAULT_CAPACITY = 10;
    static const int NOT_FIND_DATA = -1;

   public:
    DArray();
    DArray(size_t capacity);
    DArray(dT data[]);
    DArray(DArray array);
    ~DArray();

    void add(dT data);
    void insert(dT data, size_t index);
    void clear();
    auto remove(size_t index, bool is_return = false);
    size_t indexOf(dT data) const;
    size_t size() const;
    dT get(size_t where) const;
    void set(size_t where, dT data);

    bool empty() const;
    bool has(dT data) const;
    std::string toString() const;

    const DArray &operator=(const DArray &array);
    bool operator==(const DArray &array) const;
  };
} // namespace sce
#endif
