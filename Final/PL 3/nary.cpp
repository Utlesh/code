#include <iostream>
#include <vector>

enum locate_t {
    EQUAL,
    LEFT,
    RIGHT
};

int
nary_search(const std::vector<int>& a, int const key, int const N) {
    std::vector<int>      mid(N + 1);
    std::vector<locate_t> locate(N + 2);

    locate[0]     = RIGHT;
    locate[N + 1] = LEFT;

    int lo  = 0;
    int hi  = a.size() - 1;
    int pos = -1;

    while(lo <= hi && pos == -1) {
        mid[0] = lo - 1;
        
        double const step = (hi - lo + 1) / (N + 1);

        for(int i = 1; i <= N; i++) {
            int const offset = step * i + (i - 1);
            int const lmid   = mid[i] = lo + static_cast<int>(offset);

            if(lmid <= hi) {
                if(a[lmid] > key) {
                    locate[i] = LEFT;
                }
                else if(a[lmid] < key) {
                    locate[i] = RIGHT;
                }
                else {
                    locate[i] = EQUAL;
                    pos = lmid;
                }
            }
            else {
                mid[i] = hi + 1;
                locate[i] = LEFT;
            }
        }
        for(int i = 1; i <= N; i++) {
            if(locate[i] != locate[i-1]) {
                lo = mid[i - 1] + 1;
                hi = mid[i]     - 1;
            }
        }
        if(locate[N] != locate[N+1]) {
            lo = mid[N] + 1;
        }
    }
    return pos;
}

int main() {
    const int N = 3; 
    std::vector<int> array(10);
    
    std::cout << "[ ";
    for(std::size_t i = 0; i < array.size(); i++) {
        array[i] = i * 2;
        
        std::cout << array[i] << "(" << i << ") ";
    }
    std::cout << "]" << std::endl;


    std::cout << "for 10: " << nary_search(array, 10, N) << std::endl;
    std::cout << "for 11: " << nary_search(array, 11, N) << std::endl;
}
