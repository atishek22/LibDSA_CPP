/**@file binary_search_tree.hpp
 * @brief Binary Search Tree (Unbalanced)
 * @details Generic Binary Search Tree Data structure class  
 * @author atishek22 <kumaratishek22@gmail.com>
 * @date Jul 2021
 * @warning Not thread safe
 */
#ifndef DATA_STRUCTURES_BINARY_SEARCH_TREE_HPP
#define DATA_STRUCTURES_BINARY_SEARCH_TREE_HPP

#include<iostream>

#include"../../Utils/comparable.hpp"

/**@brief Generic Binary Tree class
 * @details Generic Unbalanced Binary Search Tree implementation
 *
 * @tparam Val Data Type of the element to be stored. \b See @ref Comparable
 * @warning Not thread safe
 */
template<Comparable Val>
class BST {

  const int NUM_CHILDREN = 2;
  const int LEFT = 0;
  const int RIGHT = 1;

  class Node {
    public:
    Val data;
    Node* child[NUM_CHILDREN];

    Node(Val data, Node* left = nullptr, Node* right = nullptr) {
      this->data = data;
      child[LEFT] = left;
      child[RIGHT] = right;
    }

    bool operator==(const Node& other) {
      return this->data == other;
    }

    bool operator>(const Node& other) {
      return this->data > other;
    }
  };

};

#endif //DATA_STRUCTURES_BINARY_SEARCH_TREE_HPP
