#include "HCTree.hpp"
#include "HCNode.hpp"
#include <stdlib.h>

extern std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp> prior_q;

int main()
{
   HCTree caketimer;
 
   std::vector<int> freqs(10);
 
   for(int i = 0; i < 10; i++)
   {
      freqs[i] = i; 
   }

   std::cout << "Freqs Size:" << freqs.size() << std::endl;

   caketimer.build(freqs); 

   std::cout << "priority_queue Size: " << prior_q.size() << std::endl;

   HCNode* point = prior_q.top();

   std::cout << "Root: " << *point << std::endl;
   std::cout << "Left Child: " << *(point->c0) << std::endl;
   std::cout << "Right Child: " << *(point->c1) << std::endl;
    
   caketimer.print();
   return 0;
}
