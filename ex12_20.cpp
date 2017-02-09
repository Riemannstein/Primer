#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include "StrBlob.h"
#include "StrBlobPtr.h"

int main(){
	std::ifstream ifs("./README.md");
	StrBlob blob;
	for (std::string str; std::getline(ifs,str);)
		blob.push_back(str);
	for (StrBlobPtr pbeg(blob.begin()),pend(blob.end()); pbeg != pend; pbeg.incr())
		std::cout << pbeg.deref() << std::endl;
	
	return 0;
}
