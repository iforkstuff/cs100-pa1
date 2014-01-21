#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>
#include <iomanip>

/** Authors:
 *  Jason Lo, jalo
 *  Patrick Traynor, ptraynor
 */

/** This class template defines a node type for the BST container.
 *  Note that all members are public. So, the BST implementation should
 *  take care not to expose any BSTNode objects.
 */
template<typename Data>
class BSTNode {

public:

  /** Member variables. */
  BSTNode<Data>* parent;
  BSTNode<Data>* left;
  BSTNode<Data>* right;

  const Data data;  // the const Data in this node
  int info;  // variable used in advanced algorithms 

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d): data(d) {
    left = right = parent = nullptr;
  }

  /** Return the inorder successor of this BSTNode in a BST,
   *  or nullptr if none.
   *  PRECONDITION: this BSTNode is a node in a BST.
   *  POSTCONDITION:  the BST is unchanged.
   *  RETURNS: the BSTNode that is the inorder successor of this BSTNode,
   *  or nullptr if there is none.
   */
  BSTNode<Data> * successor() const {
    // if I have right child, 
    // either it or its leftmost descendent is the successor
    if (right != nullptr)     {
      BSTNode<Data> * leftmost = right;

      while ((leftmost->left) != nullptr) {
        // descend until we don't have any more leftmost children
        leftmost = leftmost->left;
      }

      return leftmost;
    }

    // if I don't have a right child, then my successor is the
    // nearest ancestor of which i am a left child of,
    // which very well may be my parent
    if (parent == null) return nullptr;

    if (parent->left == this) return parent;
    
    BSTNode<Data> * travParent = parent->parent;
    BSTNode<Data> * travChild = parent;

    while (travParent != nullptr) {
      if ((travParent->left) == travChild) {
        return travParent;
      }

      travChild = travParent;
      travParent = travParent->parent;
    }

    // one of two things are true:
    // * i am the only node in the tree
    // * i and all of my parents are right-children, and therefore
    //   i am the last node of an in-order traversal of this tree
    
    return nullptr;
  }

}; // class BSTNode

/** Overload operator<< to insert a BSTNode's fields in an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream & stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; i:" << std::setw(10) << n.info;   // its info field
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
