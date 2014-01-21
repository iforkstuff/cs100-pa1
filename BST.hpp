#ifndef BST_HPP
#define BST_HPP

#include <utility> // for std::pair
#include "BSTNode.hpp"
#include "BSTIterator.hpp"

/** Authors:
 * 	Jason Lo, jalo
 * 	Patrick Traynor, ptraynor
 */

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or nullptr if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

public:

  /** iterator is an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0)  {
  }

  /** Default destructor.
   *  It is virtual, to allow appropriate destruction of subclass objects.
   *  Delete every node in this BST.
   */
  virtual ~BST() {
    clear();
  }

  /** Insert a Data item in the BST.
   *  Return a pair, with the pair's first member set to an
   *  iterator pointing to either the newly inserted element
   *  or to the equivalent element already in the set.
   *  The pair's second element is set to true
   *  if a new element was inserted or false if an
   *  equivalent element already existed.
   */ // TODO
  virtual std::pair<iterator,bool> insert(const Data& item) {

  }

  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ // TODO
  iterator find(const Data& item) const {

  }
  
  /** Return the number of items currently in the BST.
   */
  unsigned int size() const {
    return isize;
  }

  /** Remove all elements from this BST, and destroy them,
   *  leaving this BST with a size of 0.
   */
  void clear() {
    
    // "clearing" a node first clears its left and right children,
    // then deletes itself.

    clearNode(root);
  }

  /** Return true if the BST is empty, else false.
   */
  bool empty() const {
    return isize == 0;
  }

  /** Return an iterator pointing to the first item in the BST.
   */
  iterator begin() const {
    // the first node of an in-order traversal is the leftmost
    // descendant

    BSTNode<Data> * first = root;

    while (first != nullptr)
    {
      first = first->left;
    }

    return typename BST<Data>::iterator(first);
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(nullptr);
  }

private:

  /** Helper function for clear().
   */
  void clearNode(BSTNode<Data> * node) {

    if (node->left != nullptr) clearNode(node->left);

    if (node->right != nullptr) clearNode(node->right);

    delete node;
  }


}; // class BST

#endif //BST_HPP
