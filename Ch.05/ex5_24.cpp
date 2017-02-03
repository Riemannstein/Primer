#include <iostream>
using namespace std;
int main(){
	int i,j;
	while (cin >> i >> j ){
		if (j ==0)
			throw runtime_error("The divisor must be nonzero!");
		cout << i/j << endl;
	}
	return 0;
}
