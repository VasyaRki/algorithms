#include <algorithm>
#include <numeric>
using namespace std;

template <typename T>
void Swap(T* first, T* second){
    T tmp = *first;
    *first = *second;;
    *second = tmp;
}

template <typename T>
void SortPointers(vector<T*>& pointers){
    sort(pointers.begin(), pointers.end(), 
        [](T* l, T* r) { return *l < *r; });
}


template <typename T>
void ReversedCopy(T* source, size_t count, T* destination)
{
    if (destination >= (source + count) || (destination + count) <= source)
        reverse_copy(source, source + count, destination);
    else if(source < destination)
    {
        //       s
        //      |1|2|3|4|5|6|7|
        //        |1|2|3|4|5|6|7|
        for(size_t i = 0; source + i < destination; i++)
        {
            *(destination + count - i - 1) = *(source + i);
        }
        reverse(destination, source + count);
    } else {
        //       s
        //      |1|2|3|4|5|6|7|
        //  |6|7| | | | | |
        for(size_t i = 0; destination + i < source; i++){
            *(destination + i) = *(source + count - i - 1);
        }
        reverse(source, destination + count);
    }
}
