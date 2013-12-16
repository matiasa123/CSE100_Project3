/*
 * Jonathan Agustin
 * jAgustin
 * CSE 100 - Baden (Section A00)
 * PID: A08532463
 * Spring 2013      
 */    
#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>


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
   */ // TODO - DONE
  BSTNode<Data>* successor() {
	BSTNode<Data>* currentNode = this;
	//cout << "the current node is: " << currentNode->data << endl;
	//exit immediately if null case is true
	if(currentNode == nullptr)
	{
		return nullptr;
	}		
  	//case where right child exists
  	if(currentNode->right != nullptr)
  	{
		//from the node under investigation, we want 
		//to go to the right child in an inorder traversal
		//for correctedness of traversal
		currentNode = currentNode->right;

		//now traverse through the left path
		//ALL the way down, travelling through LEFT edges
		while(currentNode->left != nullptr)
		{
			//keep reassigning the left nodes to currentNode
			currentNode = currentNode->left;
		}
		//after no left node exists, return the node
		//this is the leftmost leaf
		return currentNode;
  	}
	//case where right child does not exist, we must go up the tree
	//"if-statement" guarentees the non-existence of right child
	
	//cout << "the parent node is: " << currentNode->parent->data << endl;
	else{
		BSTNode<Data>* parentNode = this->parent;
		
		//keep traversing
		while(parentNode != nullptr)
		{
			
			if(parentNode->left == currentNode)
			{
				//found a parent node with a right child
				return parentNode;
			}
			
			//reassign for next loop
			currentNode = parentNode;
			parentNode = parentNode->parent;
			
		}
		
	}
	//no successor exists, default to nullptr
	return nullptr;
  }
}; 

/** Overload operator<< to insert a BSTNode's fields in an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
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
