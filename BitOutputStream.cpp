// Jonathan Agustin <jagustin@ucsd.edu>, Matias Altman <mhaltman@ucsd.edu>

#include "BitOutputStream.hpp"
#include <iostream>
#include <stdlib.h>


void BitOutputStream::writeBit(int bit)
{
   if(bufi == 8)
   {
     //std::cout << "buffer value:" << buf << " " << (int) buf << std::endl; 
     flush();
     buf |= ((bit << 7));

     //buf |= (bit & 1);
     bufi = 1;
   }
   else
   {
       //std::cout << ((bit & 1) << bufi) << std::endl;
       bufi++;
       buf |= ((bit & 1 ) << (8 - bufi));
   } 
}

void BitOutputStream::writeByte(int b)
{
  out.put(b); 
}

void BitOutputStream::writeInt(int i)
{
   char a = (i & 255);
   char b = ((i >> 8) & (255));
   char c = ((i >> 16) & (255));
   char d = ((i >> 24) & (255));
 
   out.put(a);
   out.put(b);
   out.put(c);
   out.put(d);
}


void BitOutputStream::printBuffer()
{
   for(int i = 0; i < 8; i++)
   {
      std::cout << (((buf << i) & 128) >> 7);
   }
   
   std::cout << std::endl;
}

void BitOutputStream::flush()
{
   //std::cout << "buf" <<(int)buf << ": "  << buf << std::endl;
   //printBuffer(); 
   //std::cout << "Flush Called" << std::endl;
   out.put(buf);
   buf = 0;
   //std::cout << "buf after flush: " <<(int)buf << buf << std::endl;
}

