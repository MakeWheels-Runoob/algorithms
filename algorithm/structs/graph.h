#ifndef STRUCTS_GRAPH_H_
#define STRUCTS_GRAPH_H_
#include "__basic.h"
namespace sce {
  template <typename dT>
  class point : public __struct {
   private:
    dT data;
    size_t in_degree, out_degree, degree;
    size_t index;

   public:
    point();
    point(dT data);
    ~point();

    const point &operator=(const point &p);
    bool operator==(const point &p) const;
  };

  template <typename eT, typename dT = double>
  class edge : public __struct {
   private:
    point<eT> *from, *to;
    size_t index;
    dT dis;

   public:
    edge();
    edge(point *f, point *s, dT dis);
    ~edge();
    static edge add(point *f, point *s);
    void setTo(point *to);
    point getTo() const;
    void setFrom(point *to);
    point getFrom() const;

    const point &operator=(const point &p);
    bool operator==(const point &p) const;
  };

  template <typename eT, typename dT = double>
  class graph : public __struct {
   private:
    size_t cntOfPoint;
    size_t cntOfEdge;
    point<eT> p[];
    edge<eT, dT> e[];

   public:
    graph();
    graph(point p[], edge e[]);
    graph(graph g);
    ~graph();

    void createPoint(eT data);
    void createPoint();
    void createEdge(size_t from, size_t to, dT dis);
    void createEdge(point *from, point *to, dT dis);
    void createEdge(dT dis);

    point getPoint(size_t index) const;
    void setPoint(size_t index, eT data);
    edge getEdge(size_t index) const;
    void setEdge(size_t index, dT dis);

    void removePoint(size_t index);
    void removeEdge(size_t index);

    const graph &operator=(const graph &p);
    bool operator==(const graph &p) const;
  };
} // namespace sce
#endif
