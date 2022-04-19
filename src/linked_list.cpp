#include "assignment/linked_list.hpp"

#include <utility>  // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    Node* previous = nullptr;
    Node* curr = front_;
    back_ = front_;

    while (curr != nullptr) {
      Node* next = curr->next;
      (*curr).next = previous;

      previous = curr;
      curr = next;
    }
    front_ = previous;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr) {
      back_ = front_;
      front_ = prev;
      return;
    }
    Node* cur = curr->next;
    curr->next = prev;
    reverse_recursive_helper(cur, curr);
  }

}  // namespace assignment
