#include <vector>

using namespace std;
template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
    vector<ForwardIterator> elements;
    for (ForwardIterator it = first; it != last; ++it) {
        if (pred(*it))
            elements.push_back(it);
    }
    if (elements.empty()) return last;
    ForwardIterator max = elements[0];
    for (int i = 1; i < elements.size(); ++i)
    {
        if (*max < *elements[i])
            max = elements[i];
    }
    return max;

}
