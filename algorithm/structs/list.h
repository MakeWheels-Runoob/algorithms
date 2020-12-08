#ifndef STRUCTS_LIST_H_
#define STRUCTS_LIST_H_
#include "__basic.h"
namespace sce {
    template <class dT>
    class list : public __struct {
    private:
        node *_head, *_tail;
        uint64_t _len;

    public:
        list();
        list(dT data);
        list(dT data[]);
        list(list s);
        ~list();

        void insert(uint64_t where,dT data);
        dT query(uint64_t where) const;
        auto del(uint64_t where,bool is_return=false);

        bool empty() const;
        uint64_t size() const;
        void clean();
        void as_array(dT array[]) const;

        const list &operator=(const list &s);
        bool operator==(const list &s) const;
    };

    template <class dT>
    class Clist : public __struct {
    private:
        node *_head, *_tail;
        uint64_t _len;

    public:
        Clist();
        Clist(dT data);
        Clist(dT data[]);
        Clist(list s);
        ~Clist();

        void insert(uint64_t where,dT data);
        dT query(uint64_t where) const;
        auto del(uint64_t where,bool is_return=false);

        bool empty() const;
        uint64_t size() const;
        void clean();
        void as_array(dT array[]) const;

        const list &operator=(const list &s);
        bool operator==(const list &s) const;
    };
} /* namespace sce */
#endif /* STRUCTS_LIST_H_ */
