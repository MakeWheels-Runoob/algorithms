#ifdef __cplusplus
namespace sce {
    template <class dT>
    class node {
    protected:
        dT data;
        node *next, *pre;

    public:
        node();
        node(dT data);
    };
    typedef sce::node<signed char> int8_node_t;
    typedef sce::node<short> int16_node_t;
    typedef sce::node<int> int32_node_t;
    typedef sce::node<long long> int64_node_t;
    typedef sce::node<char> uint8_node_t;
    typedef sce::node<unsigned short> uint16_node_t;
    typedef sce::node<unsigned int> uint32_node_t;
    typedef sce::node<unsigned long long> uint64_node_t;
} // namespace sce
#else
struct sce_node {
    auto data;
    node *next, *pre;
    node();
    node(auto data);
};
typedef sce_node node_t;
#endif
