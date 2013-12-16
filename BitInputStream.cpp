// Jonathan Agustin <jagustin@ucsd.edu>, Matias Altman <mhaltman@ucsd.edu>

#include "BitInputStream.hpp"
#include <iostream>
#include <stdlib.h>

int BitInputStream::readBit()
{
   //printBuffer();
   //std::cout << "bufi: " << bufi  << std::endl;
   if(!in.good())
   {      
        //printBuffer();
	return -1;
   }
   else if(bufi == 8)
   {
     buf = in.get();
     //printBuffer();

     //std::cout << "buffer value:" << buf << " " << (int) buf << std::endl;
 
     bufi = 1;
     return ((buf >> 7) & 1);
   }
   else
   {
       bufi++;
       return ((buf >> (8-bufi)) & 1);
      
   } 
}

int BitInputStream::readByte()
{
  return in.get(); 
}

void BitInputStream::printBuffer()
{
   for(int i = 0; i < 8; i++)
   {
      std::cout << (((buf << i) & 128) >> 7);
   }
   
   std::cout << std::endl;
}

int BitInputStream::readInt()
{
   int byte1 = in.get();
   int byte2 = in.get();
   int byte3 = in.get();
   int byte4 = in.get();

   int out = byte1;
   out |= (byte2 << 8);
   out |= (byte3 << 16);
   out |= (byte4 << 24);

   return out; 
}

