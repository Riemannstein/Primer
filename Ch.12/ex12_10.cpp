#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "Pointer has reference count " << ptr.use_count() << endl;
	return;
}

int main(){
	shared_ptr<int> p(new int(42));
	cout << "Reference count before calling process: " 
		<< p.use_count() << endl;  
	process(shared_ptr<int>(p));
	cout << "Reference count after calling process: " 
		<< p.use_count() << endl;  
	return 0;
}