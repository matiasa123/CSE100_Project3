#include <iostream>
#include <stdlib.h>
#include "BitInputStream.hpp"
#include "HCTree.hpp"
#include <fstream>
#include <string.h>
#include <sstream>

int main(int argc, char *argv[])
{
   char in;
   std::vector<int> freqs(256, 0);

   std::ifstream ifs("Test.txt", std::ios::binary);
   std::string buffer((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
   std::stringstream ss(buffer);

   BitInputStream stream(ss);

   int efe;
   //int efe = stream.readBit();
   while(efe != -1)
   {
      //std::cout << efe << std::endl;
      efe = stream.readInt();
      //std::cout << stream.readByte() << std::endl;
   }

   /**while(!ss.eof())
   {
      std::cout << ss.get() << std::endl;
   }**/

   /**char f = 0;
   for(int i = 0; i < 256; i++)
   {
      std::cout << (int) f << ": " << f << std::endl; 
      f++;
   }**/
 
   /**char blank;
 
   for(int i = 0; i < 8; i++)
   {
      blank |= (((char)stream.readBit()) << i);
      std::cout << blank << std::endl;
   }**/
   
   
   //int temp = stream.readBit();
   //std::string s = std::to_string(temp); 

   //std::cout << temp << std::endl;

   //std::cout << s << std::endl;

   /**HCTree* tree;
   tree = new HCTree();

   inFile >> in;

   while(!inFile.eof())
   {
      std::cout << in << std::endl; 
      freqs[in]++;
      inFile >> in;
   }**/


   //inFile.close();

   //delete tree;
   
   return 0;
}
