#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H


#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include "StrBlob.h"

class StrBlobPtr{
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    StrBlobPtr(StrBlob &a): wptr(a.data) {}
    std::string& deref() const;
    StrBlobPtr& incr();       // prefix version
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
        
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;      // current position within the array
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg)
const
{
    auto ret = wptr.lock();   // is the vector still around?
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // otherwise, return a shared_ptr to the vector
}


std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  // (*p) is the vector to which this object points
}	

#endif
