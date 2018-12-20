
#ifndef __RANDOMIZED_BINARY_SEARCH_TREE_NODE__
#define __RANDOMIZED_BINARY_SEARCH_TREE_NODE__

// #define DETAILEDEXPLANATION

#include <iostream>
#include <utility>
#include <random>
#include <chrono>

template <class Type>
class RandomizedBinarySearchTreeNode {
public:
    RandomizedBinarySearchTreeNode(const Type &value, RandomizedBinarySearchTreeNode *left, RandomizedBinarySearchTreeNode *right);
    
    RandomizedBinarySearchTreeNode<Type> *insert(const Type &value);
    RandomizedBinarySearchTreeNode<Type> *remove(const Type &value);
    
    void display_like_list();
    void display_like_tree();

    ~RandomizedBinarySearchTreeNode();
private:
    RandomizedBinarySearchTreeNode<Type> *rotate_left();
    RandomizedBinarySearchTreeNode<Type> *rotate_right();

    RandomizedBinarySearchTreeNode<Type> *insert_like_root(const Type& value);
    static RandomizedBinarySearchTreeNode<Type> *merge(RandomizedBinarySearchTreeNode<Type> *that, RandomizedBinarySearchTreeNode<Type> *other);
    
    void size_update();
    std::size_t size() const;

    void _display_like_list();
    void _display_like_tree(std::size_t depth);

    /* 
        (!) members only (!) 
    */
    static std::default_random_engine m_generator; 
    Type m_value;
    RandomizedBinarySearchTreeNode<Type> *m_left;
    RandomizedBinarySearchTreeNode<Type> *m_right;
    std::size_t m_size;
};

template <class Type>
std::default_random_engine RandomizedBinarySearchTreeNode<Type>::m_generator = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());

template <class Type>
RandomizedBinarySearchTreeNode<Type>::RandomizedBinarySearchTreeNode(const Type &value, RandomizedBinarySearchTreeNode<Type> *left, RandomizedBinarySearchTreeNode<Type> *right)
    : m_value(value), m_left(left), m_right(right) 
{
    size_update();
}

template <class Type>
std::size_t RandomizedBinarySearchTreeNode<Type>::size() const
{
    return m_size;
}

template <class Type>
void RandomizedBinarySearchTreeNode<Type>::size_update()
{
    m_size = 1 + (m_left ? m_left->size() : 0) + (m_right ? m_right->size() : 0);
}

template <class Type>
void RandomizedBinarySearchTreeNode<Type>::display_like_list()
{
    std::cout << "[ ";
    _display_like_list();
    std::cout << "]";
    std::cout << std::endl;
}

template <class Type>
void RandomizedBinarySearchTreeNode<Type>::_display_like_list()
{
    if (m_left)
        m_left->_display_like_list();
    std::cout << m_value << " ";
    if (m_right)
        m_right->_display_like_list();
}

template <class Type>
void RandomizedBinarySearchTreeNode<Type>::display_like_tree()
{
    _display_like_tree(0);
}

template <class Type>
void RandomizedBinarySearchTreeNode<Type>::_display_like_tree(std::size_t depth)
{
    if (m_right)
        m_right->_display_like_tree(depth + 1);
    for (std::size_t i = 0; i < depth; ++i)
        std::cout << '\t';
    std::cout << m_value << std::endl;
    if (m_left)
        m_left->_display_like_tree(depth + 1);
}

template <class Type>
RandomizedBinarySearchTreeNode<Type> *RandomizedBinarySearchTreeNode<Type>::rotate_left()
{
    auto p_right = m_right;
    if (!p_right)
        return this;
    m_right = p_right->m_left;
    p_right->m_left = this;
    p_right->m_size = m_size;
    size_update();
    return p_right;
}

template <class Type>
RandomizedBinarySearchTreeNode<Type> *RandomizedBinarySearchTreeNode<Type>::rotate_right()
{
    auto p_left = m_left;
    if (!p_left) 
        return this; 
	m_left = p_left->m_right; 
	p_left->m_right = this;
    p_left->m_size = m_size;
    size_update();
	return p_left; 
}

template <class Type>
RandomizedBinarySearchTreeNode<Type> *RandomizedBinarySearchTreeNode<Type>::insert_like_root(const Type& value)
{
    if (value < m_value) {
        if (m_left)
            m_left = m_left->insert_like_root(value);
        else
            m_left = new RandomizedBinarySearchTreeNode<Type>(value, nullptr, nullptr);
        return rotate_right();
    }
    if (value > m_value) {
        if (m_right)
            m_right = m_right->insert_like_root(value);
        else
            m_right = new RandomizedBinarySearchTreeNode<Type>(value, nullptr, nullptr);
        return rotate_left();
    }
    return this;
}

template <class Type>
RandomizedBinarySearchTreeNode<Type> *RandomizedBinarySearchTreeNode<Type>::insert(const Type& value)
{
    if (m_generator() % (m_size + 1) == 0)
        return insert_like_root(value);
    if (value < m_value) {
        if (m_left)
            m_left = m_left->insert(value);
        else
            m_left = new RandomizedBinarySearchTreeNode<Type>(value, nullptr, nullptr);
    }
    if (value > m_value) {
        if (m_right)
            m_right = m_right->insert(value);
        else
            m_right = new RandomizedBinarySearchTreeNode<Type>(value, nullptr, nullptr);
    }
    size_update();
    return this;
}

template <class Type>
RandomizedBinarySearchTreeNode<Type> *RandomizedBinarySearchTreeNode<Type>::merge(RandomizedBinarySearchTreeNode<Type> *that, RandomizedBinarySearchTreeNode<Type> *other)
{
    if (!that)
        return other;
    if (!other)
        return that;
	if (m_generator() % (that->m_size + other->m_size) < that->m_size) {
        #ifdef DETAILEDEXPLANATION
            std::cout << "randomly selected left subtree: " << that->m_value << std::endl;
        #endif
        that->m_right = merge(that->m_right, other);
        that->size_update();
        return that;
    } else {
        #ifdef DETAILEDEXPLANATION
            std::cout << "randomly selected right subtree: " << other->m_value << std::endl;
        #endif
        other->m_left = merge(that, other->m_left);
        other->size_update();
		return other; 
	}
}

template <class Type>
RandomizedBinarySearchTreeNode<Type> *RandomizedBinarySearchTreeNode<Type>::remove(const Type &value)
{
    #ifdef DETAILEDEXPLANATION
        std::cout << "current value: " << m_value << std::endl;
    #endif
	if (value == m_value) {
        #ifdef DETAILEDEXPLANATION
            std::cout << "current value equal removal value - time to merge" << std::endl;
        #endif
        auto new_root = merge(m_left, m_right);
		m_left = m_right = nullptr;
        delete this;
        return new_root;
	}
	if (value < m_value && m_left) {
        #ifdef DETAILEDEXPLANATION
            std::cout << "removal value less then current value - turn to the left" << std::endl;
        #endif
        m_left = m_left->remove(value); 
    }
        
	if (value > m_value && m_right) {
        #ifdef DETAILEDEXPLANATION
            std::cout << "removal value greater then current value - turn to the right" << std::endl;
        #endif
        m_right = m_right->remove(value); 
    }
	return this; 
}

template <class Type>
RandomizedBinarySearchTreeNode<Type>::~RandomizedBinarySearchTreeNode()
{
    if (m_left)
        delete m_left;
    if (m_right)
        delete m_right;
}

#endif