// Jonathan Agustin <jagustin@ucsd.edu>, Matias Altman <mhaltman@ucsd.edu>

#include <stdlib.h>
#include <iostream>
#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"
#include "HCNode.hpp"
#include <vector>
#include <fstream>
#include "HCTree.hpp"

void write_header(std::vector<int> freqs, BitOutputStream out)
{
    int size = 0;
    int char_length = 0;
    for(int i = 0; i < freqs.size(); i++)
    {
        if(freqs[i])
        {
            size++;
            char_length += freqs[i];
        }
    }
    out.writeByte(size);
    out.writeInt(char_length);
    
    for(int i = 0; i < freqs.size(); i++)
    {
        if(freqs[i])
        {
            out.writeByte(i);
            out.writeInt(freqs[i]);
        }
    }
}

/**
 *Compress a file using Huffman code
 *The first argument: infile name
 *The second argument: outfile name
 **/
int main(int argc, char *argv[])
{
   HCTree hTree;
    
   //variable for number of characters
   int numChars;

   if(argc < 2)
   {
     std::cout << "Error: Too Few Arguments" << std::endl;
     return 1;
   }

   //store the contents of the first file into inFile
   std::string inFile = argv[1];

   //store the contents of the second file into outFile
   std::string outFile = argv[2];

   //std::cout << "Section1" << std::endl;

   //create instream
   std::ifstream in;
  
   //create outstream
   std::ofstream out;
   
   //open infile
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

   //open outfile
   out.open(outFile, ios::binary);
    
   //put the instream into bitinputstream
   BitInputStream bitInStream(in);

   BitOutputStream bitOutStream(out);

   //std::cout << "Section2" << std::endl;

   int total, count, index;

   //variable to hold frequency
   std::vector<int> freqs(256,0);
   int symb = bitInStream.readByte();
   while(symb != -1)
   {
      //std::cout << (char) symb << std::endl;

      freqs[symb]++;
      symb = bitInStream.readByte();
   }
   
   //std::cout << "Section3" << std::endl;


   /**for(int i = 0; i < freqs.size(); i++)
   {
      if(freqs[i])
         std::cout << freqs[i] <<std::endl;
   }**/

   hTree.build(freqs);

   //std::cout << "Writing Header" << std::endl;

   write_header(freqs, bitOutStream);
   
   //std::cout << "Files closed" << std::endl;
   in.close();
   in.open(inFile, ios::binary);

   //std::cout << "Section4" << std::endl;
 
   /**HCNode node1(1, 'r', nullptr, nullptr, nullptr);
   HCNode node2(1, 'r', nullptr, nullptr, nullptr);
   HCNode node3(2, 'a', nullptr, nullptr, nullptr);
   HCNode node4(3, 'a', nullptr, nullptr, nullptr);**/

   //std::cout << "node1 == node2: " << (comp(&node1,&node2)) << std::endl; 
   //std::cout << "node1 == node1: " << (comp(&node1,&node1)) << std::endl; 
   //std::cout << "node2 == node3: " << (comp(&node2,&node3)) << std::endl; 
   //std::cout << "node3 == node4: " << (comp(&node3,&node4)) << std::endl; 
 
   //hTree.print();

   //char cake = 'a';

   //hTree.encode(cake, bitOutStream);
 
 
   symb = bitInStream.readByte();
   while(symb != -1)
   {
      //std::cout << (char) symb << std::endl;
      hTree.encode(symb, bitOutStream); 

      symb = bitInStream.readByte();
   }
   bitOutStream.flush();

   in.close();
   out.close();

   /**std::cout << "Encoding has Finished" << std::endl;

   std::ifstream in2;
  
   //create outstream
   std::ofstream out2;
   
   //open infile
   in2.open(outFile, ios::binary);

   //open outfile
   out2.open("FinalOutput.txt", ios::binary);
    
   //put the instream into bitinputstream
   BitInputStream bitInStream2(in2);

   BitOutputStream bitOutStream2(out2);

   char symbol = hTree.decode(bitInStream2); 
   while(symbol != -1)
   {
      //std::cout << (char) symbol << std::endl;
      symbol = hTree.decode(bitInStream2); 
   }
   
   in2.close();
   out2.close();**/
   return 0;
}


