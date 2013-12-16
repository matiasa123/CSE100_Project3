#include <iostream>

int main()
{ 
   char i = 0;
   for(int j = 0; j < 256; j++)
   {
      std::cout << j << ": " << i <<std::endl;
      i++;
   }
}
