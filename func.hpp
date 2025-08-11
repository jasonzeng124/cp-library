struct func_add {
        template<typename T>
        T operator()(T a, T b) const {
                return a + b;
        }
};
struct func_min {
        template<typename T>
        T operator()(T a, T b) const {
                return min(a, b);
        }
};
struct func_max {
        template<typename T>
        T operator()(T a, T b) const {
                return max(a, b);
        }
};
