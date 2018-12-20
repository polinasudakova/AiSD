
#ifndef __RANDOMIZED_BINARY_SEARCH_TREE__
#define __RANDOMIZED_BINARY_SEARCH_TREE__

#include "randomized_binary_search_tree_node.hpp"

template <class Type>
class RandomizedBinarySearchTree {
public:
    RandomizedBinarySearchTree();

    void insert(const Type &value);
    void remove(const Type &value);

    void display_like_list();
    void display_like_tree();

    ~RandomizedBinarySearchTree();
private:
    RandomizedBinarySearchTreeNode<Type>* m_root;
};

template <class Type> 
RandomizedBinarySearchTree<Type>::RandomizedBinarySearchTree() 
    : m_root(nullptr) 
{
}

template <class Type>
void RandomizedBinarySearchTree<Type>::insert(const Type &value)
{
    if (m_root)
        m_root = m_root->insert(value);
    else
        m_root = new RandomizedBinarySearchTreeNode<Type>(value, nullptr, nullptr);
}

template <class Type>
void RandomizedBinarySearchTree<Type>::remove(const Type &value)
{
    if (m_root)
        m_root = m_root->remove(value);
}

template <class Type>
void RandomizedBinarySearchTree<Type>::display_like_list()
{
    if (m_root)
        m_root->display_like_list();
}

template <class Type>
void RandomizedBinarySearchTree<Type>::display_like_tree()
{
    if (m_root)
        m_root->display_like_tree();
}

template <class Type> 
RandomizedBinarySearchTree<Type>::~RandomizedBinarySearchTree()
{
    if (m_root)
        delete m_root;
}

#endif