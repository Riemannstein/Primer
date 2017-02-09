#include "ex12_19.h"
#include <fstream>
#include <iostream>


int main(){
	std::ifstream ifs("./README");
	StrBlob blob;
	for (std::string str; std::getline(ifs,str);)
		blob.push_back(str);
	for (StrBlobPtr pbeg(blob.begin()),pend(blob.end()); pbeg != pend; pbeg.incr())
		std::cout << pbeg.deref() << std::endl;
	return 0;
}
