#include <queue>
#include <deque>
using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate() {
        if (released.empty())
            allotted.push_back(new T);
        else {
            allotted.push_back(released.front());
            released.pop();
        }
        return allotted.back();
    }

    T* TryAllocate() {
        if (released.empty())
            return nullptr;
        allotted.push_back(released.front());
        released.pop();
        return allotted.back();
    }

    void Deallocate(T* object) {
        auto it = find(allotted.begin(), allotted.end(), object);
        if (it == allotted.end())
            throw std::invalid_argument("Deallocate");
        released.push(*it);
        allotted.erase(it);
    }

    ~ObjectPool() {
        while (!released.empty()) {
            T* ptr = released.front();
            delete ptr;
            released.pop();
        }
        while (!allotted.empty()) {
            T* ptr = allotted.front();
            delete ptr;
            allotted.pop_front();
            
        }
    }

private:
    queue<T*> released;
    deque<T*> allotted; 
};
