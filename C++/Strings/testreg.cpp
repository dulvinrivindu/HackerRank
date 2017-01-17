#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main ()
{
	  string s ("<tag1 value = \"HelloWorld\">");
	  smatch m;
	  regex e ("tag\\d*");   // matches words beginning by "sub"

	  cout << "Target sequence: " << s << endl;
	  cout << "Regular expression: /\\b(sub)([^ ]*)/" << endl;
	  cout << "The following matches and submatches were found:" << endl;

	  while (regex_search (s,m,e)) {
	 	for (auto x:m) std::cout << x << " ";
	    	cout << std::endl;
		     	s = m.suffix().str();
	  }

	  return 0;
}
