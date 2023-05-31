#include <iostream>
#include <memory>
#include <sstream>

using namespace std;

#ifdef LOCAL_LAUNCH
#include <experimental/filesystem>
#include <fstream>
namespace fs = std::experimental::filesystem;
#endif

enum class CMD {
  ADD_LEFT = 1,
  ADD_RIGHT = 2,
  GET_LEFT = 3,
  GET_RIGHT = 4
};

template<class T>
struct Node {
  Node() :value{} {}
  T value;
  shared_ptr<Node<T>> next;
  shared_ptr<Node<T>> prev;
};

template<class T>
class List {
public:
  List() : _begin(new Node<T>), _end(_begin) {}

  void push_back(T value) {
    shared_ptr<Node<T>> newNode(new Node<T>);
    newNode->value = value;
    newNode->next = _end;
    newNode->prev = _end->prev;
    if (newNode->prev) {
      newNode->prev->next = newNode;
    }
    _end->prev = newNode;
  }

  void push_front(T value) {
    shared_ptr<Node<T>> newNode(new Node<T>);
    _begin->prev = newNode;
    newNode->value = value;
    newNode->next = _begin;
    newNode->prev = nullptr;
    _begin = newNode;
  }

  void pop_front() {
    _begin = _begin->next;
    _begin->prev = nullptr;
  }

  void pop_back() {
    if (_end->prev->prev) {
      _end->prev = _end->prev->prev;
      _end->prev->next = _end;
    }
    else {
      _end->prev = nullptr;
    }
  }

  T front() {
    return _begin->value;
  }

  T back() {
    return _end->prev->value;
  }
private:
  shared_ptr<Node<T>> _begin;
  shared_ptr<Node<T>> _end;
};

int main() {
#ifdef LOCAL_LAUNCH
  fstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  string str;
  List<int> list;

  while (getline(cin, str)) {
    stringstream query(str);
    int input, value;
    query >> input;
    CMD cmd = static_cast<CMD>(input);

    switch (cmd) {
    case CMD::ADD_LEFT:
      query >> value;
      list.push_front(value);
      break;
    case CMD::ADD_RIGHT:
      query >> value;
      list.push_back(value);
      break;
    case CMD::GET_LEFT:
      cout << list.front() << endl;
      list.pop_front();
      break;
    case CMD::GET_RIGHT:
      cout << list.back() << endl;
      list.pop_back();
      break;
    default:
      break;
    }
  }
}