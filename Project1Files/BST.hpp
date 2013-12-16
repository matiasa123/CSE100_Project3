/*
 * Jonathan Agustin
 * jAgustin
 * CSE 100 - Baden (Section A00)
 * PID: A08532463
 * Spring 2013
 *
*/
#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <utility> // for std::pair

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
   */ // TODO - DONE
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
   */ // TODO - DONE
  virtual std::pair<iterator,bool> insert(const Data& item) {
	
	//tree is empty
	if(root == nullptr)
	{
		//create a new node to add to the tree
                BSTNode<Data> *newnode = new BSTNode<Data>(item);
                
		//increase size because we're adding to the tree
		isize++;

		//assign the root (because one does not exist)
		root = newnode;

		//iterator to newnode
                iterator itr(newnode);

		//return TRUE because we're adding to the tree
                std::pair<iterator,bool> p = make_pair(itr,true);
                return p;
	}
	//element already existed
        else if(root->data == item) 
	{
                iterator itr(root);
                std::pair<iterator,bool> p = make_pair(itr,false);
                return p;
        }
	
	//generalize the root to be the current node
	BSTNode<Data> *currNode = root;

	while (1)
	{
		//must go in left subtree
		if(item < currNode->data )
		{
			//no node exists, so add a new one
			if(currNode->left == nullptr)
			{
				BSTNode<Data> *newnode = new BSTNode<Data>(item);
				currNode->left = newnode;
				newnode->parent = currNode;
				isize++;
				iterator itr(currNode->left);
				std::pair<iterator,bool> p = make_pair(itr, true);
				return p;	
			}else{
				//keep traversing until a node does not exist
				currNode = currNode->left;	
			}
		}
		
		//must go in right subtree
		else if( item > currNode->data )
		{
			if(currNode->right == nullptr)
			{
				//same as first "if" case
				BSTNode<Data> *newnode = new BSTNode<Data>(item);
				currNode->right = newnode;
				newnode->parent = currNode;
				isize++;
				iterator itr(currNode->right);
				std::pair<iterator,bool> p = make_pair(itr, true);
				return p;
			}else{
				currNode = currNode->right;
			}
		}
		else
		{
			//paranoid case, nullptr iterator
			iterator itr(nullptr);
			std::pair<iterator,bool> p = make_pair(itr, false);
			return p;
		}

	}
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ // TODO - DONE
  iterator find(const Data& item) const {
	
	//start with the root
	BSTNode<Data>* currNode = root;

	//empty tree, return end()
	if (root == nullptr)
	{
		return end();
	}
	//not nullptr
	else 
	{
		//keep looking until no nodes exist (until nullptr)
		while( currNode != nullptr)
		{
			//3 cases where <, >, == 
			
			//found it
			if(item == currNode->data)
			{
				return typename BST<Data>::iterator(currNode);
			}

			//go down left tree
			else if(item < currNode->data)
			{
				if(currNode->left == nullptr)
				{
					//not found :(
					return end();
				}
				//reassignment for next iteration
				currNode = currNode->left;
			}

			//go down right tree
			else if(item > currNode->data)
			{
				if(currNode->right == nullptr)
				{
					//not found
					return end();
				}
				//reassignment for next iteration
				currNode = currNode->right;
			}
			
		}
	}

	return end();

  }
  

  
  /** Return the number of items currently in the BST.
   */ // TODO - DONE
  unsigned int size() const {
	return isize; //isize keeps track of size
  }

  /** Remove all elements from this BST, and destroy them,
   *  leaving this BST with a size of 0.
   */ // TODO - DONE
  void clear() {
	//destroy is a private method
	destroy(root);
	isize = 0; 
 }

  /** Return true if the BST is empty, else false.
   */ // TODO - DONE
  bool empty() const {
	
	if (isize == 0)
	{
		return true;
	}
	if(root == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO - DONE
  iterator begin() const {
	//create a new node
	BSTNode<Data> *currNode;

	//initialize the node
	currNode = root;

	//decide whether there's anything to traverse
	if (currNode != nullptr)
	{
		while(currNode->left != nullptr)
		{
			//keep going left until you can't go no more
			currNode = currNode->left;
		}
	}
	//this is the first intem in the BST
	return typename BST<Data>::iterator(currNode);
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(nullptr);
  }

 private:

        static void destroy(BSTNode<Data>* subtree_node)
        {
                if(subtree_node != nullptr)
                {
                        destroy(subtree_node->left);
                        destroy(subtree_node->right);
    	                delete subtree_node;         
                }

        }
  

 };


#endif //BST_HP
