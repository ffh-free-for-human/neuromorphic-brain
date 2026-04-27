#include <iostream>

void main()
{
#ifdef DEBUG
  std::cout << "Debug mode ON\n";
#endif // DEBUG


  int x;
  std::cin >> x;
  std::cout << x;
}