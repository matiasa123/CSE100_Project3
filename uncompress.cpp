// Jonathan Agustin <jagustin@ucsd.edu>, Matias Altman <mhaltman@ucsd.edu>

#include <iostream>
#include <fstream>
#include "HCTree.hpp"
#include "HCNode.hpp"
#include "BitOutputStream.hpp"
#include <vector>

unsigned int read_header(std::vector<int>& freqs, BitInputStream in)
{
   int size       = in.readByte();
   unsigned int charlength     = in.readInt();

   //std::cout << "charlength: " << charlength << std::endl;  
 
   for(int i = 0; i < size; i++)
   {
      int index = in.readByte();
      //std::cout << index << ": ";
      freqs[index] = in.readInt();
      //std::cout << freqs[index] <<std::endl;
   }

   return charlength;
}

int main(int argc, char* argv[])
{
   //std::cout << "Section 1 " << std::endl;
   std::vector<int> freqs(256, 0);
   HCTree hTree;  
   int charlength = 0;

   std::string inFile = argv[1];
   std::string outFile = argv[2];
   
   std::ifstream in;
   std::ofstream out;

   in.open(inFile, ios::binary);

   long sizeOfFile;
   in.seekg(0, ios::end);
   sizeOfFile = in.tellg();
   in.seekg(0, ios::beg);
   if(sizeOfFile == 0)
   {
      std::cout<<"blank file...try again!!!"<<endl;
      std::ofstream empty;
      empty.open(outFile, ios::binary);
      empty.close();
      return 0;
   }

   out.open(outFile, ios::binary);

   BitInputStream bitInStream(in);
   BitOutputStream bitOutStream(out);

   //std::cout << "Section 2 " << std::endl;

   unsigned int fuckyou = read_header(freqs, in);


   /**for(int i = 0; i < freqs.size(); i++)
   {
      std::cout << i << " " << freqs[i] <<std::endl;
   }**/
 
   //std::cout << "Build Tree" << std::endl;
   hTree.build(freqs);

   //std::cout << "Section 3 " << std::endl;

   //std::cout << "returned char length: " << fuckyou << std::endl;
   int symbol = hTree.decode(bitInStream); 
   for(unsigned int j = 0; j < fuckyou; j++) 
   {
      //std::cout << "returned char length: " << fuckyou << std::endl;
      //std::cout << (char) symbol << std::endl;
      bitOutStream.writeByte(symbol);
      symbol = hTree.decode(bitInStream);
   }

   in.close();
   out.close();

   return 0;
}
