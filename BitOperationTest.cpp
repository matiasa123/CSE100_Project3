#include <iostream>

int main()
{
  char val = 0; 
  std::cout << "0: " << val << std::endl;
 
  val |= 1;

  std::cout << "(0 |= 1): " << (int)val << std::endl;

  return 0;
}
