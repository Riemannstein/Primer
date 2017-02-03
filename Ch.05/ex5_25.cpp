#include <iostream>
#include <stdexcept>
using namespace std;
int main(){
	int i,j;
	cin >> i >> j; 
	try {
		cout << i/j << endl;
	} catch(runtime_error err){
		cout << err.what() << "\n Try again? Enter y or n" << endl;
		char c;
		cin >> c;
		if (!cin || c== 'n')
			return 1;
		cin >> j;
	}
	return 0;
}
