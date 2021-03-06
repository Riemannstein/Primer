#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include "StrBlobPtr.h"
using namespace std;

class StrBlob {
public:
	friend class StrBlobPtr;
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	// return StrBlobPtr to the first element
	StrBlobPtr begin();
	// return StrBlobPtr to the one past the last element 
	StrBlobPtr end();
	
	// add and remove elements
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();

	// element access
	std::string& front();
	std::string& back();
private:
	std::shared_ptr<std::vector<std::string>> data;

	// throws msg if data[i] isn't valid
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()
{
	// if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {return StrBlobPtr(*this, data->size());}

#endif
