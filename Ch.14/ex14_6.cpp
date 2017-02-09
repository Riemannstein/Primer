#include "ex14_2.h"

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}
