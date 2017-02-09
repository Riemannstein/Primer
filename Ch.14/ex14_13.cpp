#include "ex14_13.h"

using namespace std;

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

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

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs; // Copy data from lhs to sum
	sum += rhs; // add rhs into sum
	return sum;
	
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data minus = lhs; // Copy data from lhs to minus
	minus -= rhs; // subtract rhs from minus
	return minus;
} 

Sales_data & Sales_data::operator-=(const Sales_data & rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
}

Sales_data & Sales_data::operator+=(const Sales_data & rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
}
