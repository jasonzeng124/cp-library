#include <vector>


struct DSU
{
        int n; std::vector<int> up;

        DSU(int n) : n(n), up(n, -1) {}

        DSU() : DSU(0) {}

        void resize(int n) {
                this->n = n;
                up.resize(n);
                up.assign(n, -1);
        }

        int find(int x) {
                if(up[x] < 0) return x;
                return up[x] = find(up[x]);
        }

        void unite(int x, int y) {
                x = find(x); y = find(y);
                if(x == y) return;
                if(-up[x] < -up[y]) std::swap(x,y);
                up[x] += up[y]; up[y] = x;
                n--;
        }

        int size(int x) {
                return -up[find(x)];
        }

        std::vector<int> comps() {
                std::vector<int> c;
                for(int i=0;i<(int)up.size();i++) if(up[i]<0) c.push_back(i);
                return c;
        }
};
