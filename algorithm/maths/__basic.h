#ifndef MATH_BASIC_H
#define MATH_BASIC_H
#include "__builtin.h"
namespace math {
  template <typename rT,typename pT=rT, typename qT=rT>
  class functor {
   protected:
    virtual rT operator()(pT a, qT b);
   public:
    functor();
    functor()
  };
} // namespace math
#endif
