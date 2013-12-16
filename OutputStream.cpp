#include <iostream>
#include <stdlib.h>
#include "BitOutputStream.hpp"
#include "HCTree.hpp"
#include <fstream>
#include <string.h>
#include <sstream>

int main(int argc, char *argv[])
{
   char in;
   std::vector<int> freqs(256, 0);

   std::ofstream ofs("Testwrite.txt", std::ios::binary);

   BitOutputStream stream(ofs);

   int efe = 'f';
   int gee = 'g';
   int eme = 'm';
   int ene = 'n';

   int toget = efe;
   toget |= (gee << 8);
   toget |= (eme << 16);
   toget |= (ene << 24);
   stream.writeInt(toget);

   /**char f[8];
   for(int i = 0; i < 8; i++)
   {
     f[i] = (efe >> i) & 1;
     stream.writeBit(f[i]);
   }**/  

   /**stream.writeBit(0);
   stream.writeBit(1);
   stream.writeBit(1);
   stream.writeBit(0);
   stream.writeBit(0);
   stream.writeBit(1);
   stream.writeBit(1);
   stream.writeBit(0);
 
   stream.writeBit(1);
   stream.writeBit(1);
   stream.writeBit(1);
   stream.writeBit(0);
   stream.writeBit(0);
   stream.writeBit(1);
   stream.writeBit(1);
   stream.writeBit(0);
   
   stream.writeBit(0);**/ 
 
   //stream.writeByte(efe);
   //stream.writeByte(eme);
   //stream.writeByte(ene);

   /**char r = 0;
   for(int i = 0; i < 256; i++)
   {
      std::cout << (int) r << ": " << r << std::endl; 
      r++;
   }**/
 
   return 0;
}
