#include <iostream>
#include <vector>


using namespace std;

auto make_dyanamically(){
	return new vector<int>;
}

auto populate(vector<int>* vec){
	for (int i; cout << "Please input an integer value", cin >> i);
		vec->push_back(i));
	return vec;
}

auto print(vector<int>* vec){
	for(auto i : *vec)
		cout << i << " ";
	return cout; 
}

int main(){
	vector<int> vec = populate(make_dyanamically());
	delete vec;
	return 0;
}


