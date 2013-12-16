#include <iostream>
#include "HCNode.hpp"
#include <stdlib.h>

#define TEST_NO 200

int main()
{
   /**char fa = 1;
   char la = 2;
   char ka = 3; 
  
   HCNode test_fake(0, fa, nullptr, nullptr, nullptr);
   HCNode test_lake(1, la, nullptr, nullptr, nullptr);
   HCNode test_kake(2, ka, nullptr, nullptr, nullptr);

   std::cout << test_fake << std::endl;
   std::cout << test_lake << std::endl;
   std::cout << test_kake << std::endl;
   
   std::cout << (test_fake < test_lake) << std::endl;//1
   std::cout << (test_fake < test_kake) << std::endl;//1
   std::cout << (test_lake < test_fake) << std::endl;//0
   std::cout << (test_lake < test_kake) << std::endl;//1
   std::cout << (test_kake < test_fake) << std::endl;//0
   std::cout << (test_kake < test_lake) << std::endl;//0
   **/ 

   std::cout << "-----Testing for the nullptr case-------" << std::endl;
    
   for(int i = 0; i < TEST_NO; i++)
   {
      char j, k;
      int pri_j, pri_k;
      j     = (char)(rand()%256);
      k     = (char)(rand()%256);
      pri_j = rand();
      pri_k = rand();
      HCNode test_j(pri_j, j, nullptr, nullptr, nullptr);
      HCNode test_k(pri_k, k, nullptr, nullptr, nullptr);
     
      std::cout << test_j << std::endl;
      std::cout << test_k << std::endl;

      if((*test_j.c0 < *test_k.c1) != false)
      {
         std::cout << "1st Nullptr Test FAILED EYO" << std::endl;
         break;
      }
      
      if((*(test_k.c0) < test_j) != false)
      {
         std::cout << "2nd Nullptr TEST FAILED EYO" << std::endl;
         break;
      }
      
      if((test_k < *test_j.c0) != false)
      {
         std::cout << "3rd Nullptr TEST FAILED EYO" << std::endl;
         break;
      } 

   }

   /**for(int i = 0; i < TEST_NO; i++)
   {
      char j, k ;
      int pri_j, pri_k;
      j     = (char)(rand()%256);
      k     = (char)(rand()%256);
      pri_j = rand();
      pri_k = rand();
      HCNode test_j(pri_j, j, nullptr, nullptr, nullptr);
      HCNode test_k(pri_k, k, nullptr, nullptr, nullptr);
     
      std::cout << test_j << std::endl;
      std::cout << test_k << std::endl;
      std::cout << "test_j < test_k: " << (test_j < test_k) << std::endl; 

      if((test_j < test_k) != (pri_j < pri_k))
      {
         std::cout << "Test Failed EYO" << std::endl;
         break;
      }
      if((test_k < test_j) != (pri_k < pri_j))
      {
         std::cout << "Test Failed EYO" << std::endl;
         break;
      }
   }**/
}
