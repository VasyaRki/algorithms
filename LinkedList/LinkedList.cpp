#include <vector>
using namespace std;

template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    ~LinkedList()
    {
        if (head != nullptr)
        {
            for (Node* it = head; it->next != nullptr;)
            {
                Node* tmp_it = it->next;
                delete it;
                it = tmp_it;
            }
        }
    }

    void PushFront(const T& value)
    {
        Node* tmpHead = head;
        head = new Node{value, tmpHead}; 
    }

    void InsertAfter(Node* node, const T& value) {
        if (node->next == nullptr)
        {
            node->next = new Node{ value, nullptr };
        }
        else {
            Node* tmpNode = node->next;
            node->next = new Node{ value, tmpNode };
        }
    }

    void RemoveAfter(Node* node)
    {
        if (node->next != nullptr)
        {
            Node* deleteNode = node->next;
            if (deleteNode->next == nullptr)
                node->next = nullptr;
            else
                node->next = deleteNode->next;
            delete deleteNode;
        }
    }

    void PopFront() {
        if (head != nullptr)
        {
            Node* deleteNode = head;
            if (head->next != nullptr)
                head = head->next;
            else head = nullptr;
            delete deleteNode;
        }
    }

    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }

private:
        Node * head = nullptr;
};

template <typename T>
vector<T> ToVector(const LinkedList<T>& list) {
  vector<T> result;
  for (auto node = list.GetHead(); node; node = node->next) {
    result.push_back(node->value);
  }
  return result;
}
