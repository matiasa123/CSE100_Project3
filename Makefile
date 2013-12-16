

CC=g++
CXXFLAGS=-std=c++11 -O2 -g
LDFLAGS=-g

all: compress uncompress

compress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o

uncompress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o 

HCTree.o: BitInputStream.hpp BitOutputStream.hpp HCNode.o HCTree.hpp HCTree.cpp

HCTree_solo.o: HCNode.o HCTree.hpp HCTree.cpp

HCNode.o: HCNode.hpp HCNode.cpp

HCNode: HCNode.o
	g++ $(CXXFLAGS) -o $@ HCNode_Tester.cpp HCNode.o

HCTree: HCTree.hpp HCTree.cpp HCNode.o
	g++ $(CXXFLAGS) -o $@ HCTree_Test.cpp HCTree.cpp HCTree.hpp HCNode.o

Prior_Q: HCTree.hpp HCTree.cpp HCNode.o 
	g++ $(CXXFLAGS) -o pq priority_q_test.cpp HCTree.hpp HCTree.cpp HCNode.o 

Compress: compress.cpp HCTree.hpp HCTree.cpp HCNode.o BitOutputStream.cpp BitOutputStream.hpp BitInputStream.cpp BitInputStream.hpp
	g++ $(CXXFLAGS) -o compress compress.cpp HCTree.hpp HCTree.cpp HCNode.o BitOutputStream.cpp BitOutputStream.hpp BitInputStream.cpp BitInputStream.hpp

Uncompress: uncompress.cpp HCTree.hpp HCTree.cpp HCNode.o BitOutputStream.cpp BitOutputStream.hpp BitInputStream.cpp BitInputStream.hpp
	g++ $(CXXFLAGS) -o uncompress uncompress.cpp HCTree.hpp HCTree.cpp HCNode.o BitOutputStream.cpp BitOutputStream.hpp BitInputStream.cpp BitInputStream.hpp

InputStream: BitInputStream.o InputStream.cpp HCTree.hpp HCTree.cpp HCNode.o
	g++ $(CXXFLAGS) -o InputStream BitInputStream.o InputStream.cpp HCTree.cpp HCTree.hpp HCNode.o

OutputStream: BitOutputStream.o OutputStream.cpp HCTree.hpp HCTree.cpp HCNode.o
	g++ $(CXXFLAGS) -o OutputStream BitOutputStream.o OutputStream.cpp HCTree.cpp HCTree.hpp HCNode.o

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp

clean:
	rm -f compress uncompress *.o core*

purify:
	prep purify
	purify -cache-dir=$HOME g++ compress.cpp BitOutputStream.cpp BitInputStream.cpp HCTree.cpp HCNode.cpp -o compress

	purify -cache-dir=$HOME g++ uncompress.cpp BitOutputStream.cpp BitInputStream.cpp HCTree.cpp HCNode.cpp -o uncompress
