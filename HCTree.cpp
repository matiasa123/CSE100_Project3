// Jonathan Agustin <jagustin@ucsd.edu>, Matias Altman <mhaltman@ucsd.edu>


#include <stdlib.h>
#include "HCTree.hpp"
#include "HCNode.hpp"

std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp> prior_q;
void PrintNode(HCNode* node);

void HCTree::encode(byte symbol, BitOutputStream& out) const
{
   HCNode* curr_node = leaves[symbol];
   
   if(root == nullptr)
   {
      std::cout << "root is null" << std::endl;
      return;   
   }


   std::vector<bool> tracker;
   //std::cout << "Beginning of While loop" << std::endl;
   while(curr_node->p != nullptr)
   {
      HCNode* parent_node = curr_node->p;
      if(comp(parent_node->c0, curr_node))
      {
         //std::cout << "0" << std::endl;
         //out.writeBit(0);
         tracker.push_back(0);
      }   
      else
      {
         //std::cout << "1" << std::endl;
         //out.writeBit(1); 
         tracker.push_back(1);
      }
      curr_node = curr_node->p;
   }

   while(tracker.size() != 0)
   {
      if(tracker.back())
         out.writeBit(1);
      else 
         out.writeBit(0);
      tracker.pop_back();
   }
}

int HCTree::decode(BitInputStream& in) const
{
        
	HCNode* node = root;
	int bit;
	
	//keep traversing the tree until max bits or until
	//a leaf is evaluated
	while ((node->c0 != nullptr) || (node->c1 != nullptr))
	{
		bit = in.readBit();
                //std::cout << "Bit Value: " << bit << std::endl;
		if(bit == -1)
                {
                   //std::cout << "Inside the HCTree decode() method - returning -1"  << std::endl; 
                   return -1;
                }
		else if (bit)
                {
                   //std::cout << "1" << std::endl; 
                   node = node->c1;
                }
		else 
                {
                   //std::cout << "0" << std::endl; 
                   node = node->c0;
                }
	}
        //std::cout << "found a leaf: " << node->symbol << std::endl;

        return node->symbol;
}

//building the tree
void HCTree::build(const vector<int>& freqs)
{
   char zero = 0;
 
   //add leaves to priority queue 
   //priority_queue<HCNode> prior_q;  	
   //std::cout << "First For Loop" << std::endl;

   //std::cout << "Freqs Size: " << freqs.size() << std::endl; 

   for(int i = 0; i < freqs.size(); i++)
   {
      //std::cout << i << ": " << freqs[i] << std::endl;	
      if(freqs[i] != 0)
      {
	 //create a new node for every frequency
	 //question: where is leaves[] defined??
         //std::cout << freqs[i] << " pushed to priority queue" << std::endl;

         HCNode* node = new HCNode(freqs[i], ((char)i), nullptr, nullptr, nullptr);
         leaves[i] = node; 
	 prior_q.push(node);	
      }
   }

   //std::cout << "First For Loop End" << std::endl;
	//create a new node and start connecting node-pairs in terms of lowest priority
	//AND then add that new node to the priority queue. Keep doing this until no node
	//pairs exist

	//but first check if there are any nodes in the queue
	//

    //std::cout << "Solo Heap Conditional" << std::endl;
    if(prior_q.size() == 1)
    {
       HCNode* child = prior_q.top();
       prior_q.pop();
       HCNode* parent = new HCNode(child->count, zero, child, nullptr, nullptr);
       prior_q.push(parent);
    }
    //std::cout << "Solo Heap Conditional End" << std::endl;
 
    //std::cout << "Priority Queue Size: " << prior_q.size() << std::endl;
	
    while(prior_q.size() > 1)
    {
       //std::cout << "While loop 2 Iteration" << std::endl;
   	
       HCNode* node_child1 = prior_q.top();
 
       //std::cout << "Pop 1 " << *node_child1 << std::endl;
   
       prior_q.pop();
       HCNode* node_child2 = prior_q.top();
       
       //std::cout << "Pop 2 " << *node_child2 << std::endl;


       prior_q.pop();
       HCNode* p_node = new HCNode(((node_child1->count)+(node_child2->count)), zero, node_child1, node_child2, nullptr);
       node_child1->p = p_node;
       node_child2->p = p_node;

       prior_q.push(p_node);
    }

    root = prior_q.top();
}

void HCTree::print()
{
   PrintNode(root);
}

void PrintNode(HCNode* node)
{
   if(node != nullptr)
   {
      std::cout << node << " " << node->count << " " << node->symbol << " " << node->c0 << " " << node->c1 << " " << node->p << std::endl; 
      PrintNode(node->c0);
      PrintNode(node->c1);
   }
}

static void destroy(HCNode* node)
{
   if(node != nullptr)
   {
      destroy(node->c0);
      destroy(node->c1);
      delete node;
   }
}

HCTree::~HCTree()
{
   if(root != nullptr)
   {
      destroy(root);
   }
}
