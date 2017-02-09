#include <iostream>

class if_then_else
{
public:
	int operator()(const bool& first, const int& second, const int& thrid) const {
		if (first == true)
			return second;
		else
			return thrid;
	}
};

int main(){
	bool first;
	int second;
	int third;
	std::cin >> first >> second >> third;
	if_then_else i_t_e;
	std::cout << i_t_e(first,second,third) << std::endl;
	return 0;
} 
