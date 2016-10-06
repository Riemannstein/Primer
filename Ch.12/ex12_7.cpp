#include <iostream>
#include <vector>
#include <memory>

using namespace std;

auto make_with_shared_ptr(){
	return make_shared<vector<int>>();
}

auto populate(shared_ptr<vector<int>> vec){
	for (int i; cout << "Please Enter:\n", cin >> i; vec->push_back(i));
	return vec;
}

auto print(shared_ptr<vector<int>> vec) -> ostream& {
	for (auto i : *vec)
		cout << i << " ";
	return cout;
}

int main(){
	auto vec = populate(make_with_shared_ptr());
	print(vec) << endl;
	
	return 0;
}
