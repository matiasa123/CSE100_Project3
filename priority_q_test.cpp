#include <stdlib.h>
#include "HCTree.hpp"
#include "HCNode.hpp"

int main()
{
    char pri_i, pri_j, pri_k;
    int i, j, k;
    pri_i = 1;
    pri_j = 3;
    pri_k = 2;
    j = 12;
    i = 4;
    k = 1;

    std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp> pq;

    HCNode* node1 = new HCNode(pri_j, j, nullptr, nullptr, nullptr);
    HCNode* node2 = new HCNode(pri_i, i, nullptr, nullptr, nullptr);
    HCNode* node3 = new HCNode(pri_k, k, nullptr, nullptr, nullptr);

    pq.push(node1);
    pq.push(node2);
    pq.push(node3);

    std::cout << "Begin Test: " << std::endl;
    for(int f = 0; 0 < pq.size(); f++)
    {
       std::cout << *(pq.top()) << std::endl;  
       pq.pop(); 
    }

    delete node1;
    delete node2;
    delete node3;
    
    return 0;
}
