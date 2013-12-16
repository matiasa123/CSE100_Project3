// Jonathan Agustin <jagustin@ucsd.edu>, Matias Altman <mhaltman@ucsd.edu>

#include "HCNode.hpp"
#include <iostream>

/** Less-than comparison, so HCNodes will work in std::priority_queue
 *  We want small counts to have high priority.
 *  And we want to break ties deterministically.
 **/
bool HCNode::operator<(const HCNode& other)
{
  if((this == nullptr) || (&other==nullptr))
  {
     if(this != nullptr)
        return true;
     else 
        return false;
  }
  else
  {
     return (this->count > other.count);
  }
}

bool comp(HCNode* one, HCNode* other)
{
  if((one != nullptr) && (other != nullptr))
  {
     return ((one->symbol == other->symbol) && (one->count == other->count));
  }
  else if(one == nullptr && other == nullptr)
     return true;
  else
     return false;
}
