#include <iostream>
#include <string>
#include <regex>

int main ()
{
  std::cmatch m;

  std::regex_match ( "(75, 180)", m, std::regex("([0123456789])(.*)") );

  for (unsigned i=0; i<m.size(); ++i) {
    std::cout << "match " << i << ": " << m[i];
    std::cout << " (with a length of " << m[i].length() << ")\n";
  }

  return 0;
}