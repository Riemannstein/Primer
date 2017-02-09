#include "ex14_27.h"

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

StrBlobPtr& StrBlobPtr::operator++()
{
	// if curr aleardy points past end of StrBlobPtr, can't increment it
	check(curr, "increment past end of StrBlobPtr");
	// Advance the current state
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	// if curr is zero, decrementing it will yield an invalid subscript
	--curr; // move the current state back one element
	check(curr, "decrement past begin of StrBlobPtr");
	return *this
}
