#include <iostream>
#include <vector>
#include <memory>


using namespace std;

shared_ptr<vector<int>> make_with_shared_ptr(){
	return make_shared<vector<int>>(); 
}

auto populate(shared_ptr<vector<int>> pvec){
	for(int i; cout << "Please enter an integer", cin >> *p.push_back(i);)
	return pvec;
}

auto print(shared_ptr<vector<int>> pvec) -> ostream& {
	for (auto i : *pvec)
		cout << *i << " ";
	return cout;	
}

int main(){
	auto vec = populate(make_with_shared_ptr);
	print(vec) << endl;
	return 0;
}

