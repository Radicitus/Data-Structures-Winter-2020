#ifndef __PROJ_THREE_AVL_HPP
#define __PROJ_THREE_AVL_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <vector>

class ElementNotFoundException : public RuntimeException 
{
public:
	ElementNotFoundException(const std::string & err) : RuntimeException(err) {}
};

template <typename Key, typename Value>
struct avlNode{
    Key k;
    Value v;
    unsigned int height = 0;
    struct avlNode<Key,Value> * parent = NULL;
    struct avlNode<Key,Value> * right = NULL;
    struct avlNode<Key,Value> * left = NULL;
};

template<typename Key, typename Value>
class MyAVLTree
{
private:

    int s;
	// fill in private member data here
	// If you need to declare private functions, do so here too.

public:
	MyAVLTree();
    avlNode<Key,Value> * head;
	// In general, a copy constructor and assignment operator
	// are good things to have.
	// For this quarter, I am not requiring these. 
	//	MyAVLTree(const MyAVLTree & st);
	//	MyAVLTree & operator=(const MyAVLTree & st);


	// The destructor is, however, required. 
	~MyAVLTree() {
	    avlNode<Key,Value> * currentNode = head;
	}

	// size() returns the number of distinct keys in the tree.
	size_t size() const noexcept;

	// isEmpty() returns true if and only if the tree has no values in it. 
	bool isEmpty() const noexcept;

	// contains() returns true if and only if there
	//  is a (key, value) pair in the tree
	//	that has the given key as its key.
	bool contains(const Key & k) const; 

	// find returns the value associated with the given key
	// If !contains(k), this will throw an ElementNotFoundException
	// There needs to be a version for const and non-const MyAVLTrees.
	Value & find(const Key & k);
	const Value & find(const Key & k) const;

	// Inserts the given key-value pair into 
	// the tree and performs the AVL re-balance
	// operation, as described in lecture. 
	// If the key already exists in the tree, 
	// you may do as you please (no test cases in
	// the grading script will deal with this situation)
	void insert(const Key & k, const Value & v);

	// The following three functions all return
	// the set of keys in the tree as a standard vector.
	// Each returns them in a different order.
	std::vector<Key> inOrder(avlNode<Key,Value> * node) const;
	std::vector<Key> preOrder(avlNode<Key,Value> * node) const;
	std::vector<Key> postOrder(avlNode<Key,Value> * node) const;


};


template<typename Key, typename Value>
MyAVLTree<Key,Value>::MyAVLTree() {
    head = NULL;
    s = 0;
}

template<typename Key, typename Value>
size_t MyAVLTree<Key, Value>::size() const noexcept
{
	return s;
}

template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::isEmpty() const noexcept
{
    return size() == 0;
}


template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::contains(const Key &k) const
{
	avlNode<Key,Value> * currentNode = head;
    while(true) {
        if(currentNode == NULL) { return false; }
        if (currentNode->k == k) { return true; }
        if (currentNode->k > k) {
                currentNode = currentNode->left;
        } else {
                currentNode = currentNode->right;
        }
    }
}



template<typename Key, typename Value>
Value & MyAVLTree<Key, Value>::find(const Key & k)
{
	Value v;
	return v; // not only a stub, but a terrible idea.
}

template<typename Key, typename Value>
const Value & MyAVLTree<Key, Value>::find(const Key & k) const
{
	Value v;
	return v; // not only a stub, but a terrible idea.
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insert(const Key & k, const Value & v)
{
	avlNode<Key,Value> * currentNode = head;
	auto * nodeToAdd = new avlNode<Key, Value>;
	nodeToAdd->k = k;
	nodeToAdd->v = v;

	if (head == NULL) {
        head = nodeToAdd;
        s++;
        return;
    }
	while(true) {

	    if (currentNode->k == k) {
	        currentNode->v = v;
	        return;
	    } else if (currentNode->k > k) {
	        if (currentNode->left == NULL) {
	            currentNode->left = nodeToAdd;
                s++;
	            return;
	        } else {
	            currentNode = currentNode->left;
	        }
	    } else {
	        if (currentNode->right == NULL) {
	            currentNode->right = nodeToAdd;
                s++;
	            return;
	        } else {
	            currentNode = currentNode->right;
	        }
	    }
	}
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::inOrder(avlNode<Key,Value> * node) const
{
	std::vector<Key> v;

	if (node == NULL) { return v; }

	std::vector<Key> recV;

    if (node->left != NULL) {
        recV = MyAVLTree::inOrder(node->left);
        v.insert(std::end(v), std::begin(recV), std::end(recV));
    }

    v.push_back(node->k);

    if (node->right != NULL) {
        recV = MyAVLTree::inOrder(node->right);
        v.insert(std::end(v), std::begin(recV), std::end(recV));
    }

    return v;

}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::preOrder(avlNode<Key,Value> * node) const
{
    std::vector<Key> v;

    if (node == NULL) { return v; }

    v.push_back(node->k);

    std::vector<Key> recV;

    if (node->left != NULL) {
        recV = MyAVLTree::inOrder(node->left);
        v.insert(std::end(v), std::begin(recV), std::end(recV));
    }

    if (node->right != NULL) {
        recV = MyAVLTree::inOrder(node->right);
        v.insert(std::end(v), std::begin(recV), std::end(recV));
    }

    return v;

}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::postOrder(avlNode<Key,Value> * node) const
{
    std::vector<Key> v;

    if (node == NULL) { return v; }

    std::vector<Key> recV;

    if (node->left != NULL) {
        recV = MyAVLTree::inOrder(node->left);
        v.insert(std::end(v), std::begin(recV), std::end(recV));
    }

    if (node->right != NULL) {
        recV = MyAVLTree::inOrder(node->right);
        v.insert(std::end(v), std::begin(recV), std::end(recV));
    }

    v.push_back(node->k);

    return v;

}







#endif 