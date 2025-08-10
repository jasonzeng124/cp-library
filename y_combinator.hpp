#include <functional>

template<class F>
struct y_combinator {
        const F f;

        y_combinator(F&& f) : f(f) {}

        template<class ...Args>
        decltype(auto) operator() (Args&&... a) const {
                return f(*this, std::forward<Args>(a)...);
        };

};
