#include "ex14_2.h"

using namespace std;

istream & operator>>(istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if(is)
		item.revenue = item.units_sold*price;
	else 
		item = Sales_data();
	return is;
}