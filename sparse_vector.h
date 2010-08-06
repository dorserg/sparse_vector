#include <vector>

using namespace std;

/**
 * This data structure is basically a vector, items of which require no
 * initialization. An item is initialized to default value the first time
 * it's accessed. Clearing of all values takes O(1) time.
 *
 * It's handy for use cases when you have to frequently perform such
 * operations on a big array:
 * 1) initialize a few items in it
 * 2) clear all items
 */
template <class T>
class sparse_vector {
private:
    vector<T> a;
    vector<int> sparse, dense;
    int def;
    int n;
public:
    sparse_vector(int size, T def_val=0) {
        a = vector<T>(size);
        dense = sparse = vector<int>(size);
        n = 0;
        def = def_val;
    }
    T& operator[](int i) {
        if (!(sparse[i]<n && sparse[i]>=0 && dense[sparse[i]]==i)) {
            sparse[i]=n;
            dense[n]=i;
            ++n;
            a[i]=def;
        }
        return a[i];
    }
    void clear() { n=0; }
    int size() { return a.size(); }
    int initialized() { return n; }
};

