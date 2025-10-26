#include "../include/as1.hpp"
#include <iostream>

namespace homework {

void swap_ptr(int* a, int* b, int *c) { 
    int savea = *a;
    *a=*b;
    *b=*c;
    *c=savea;
    return;
}
UniqueData::UniqueData(int value) : data_(std::make_unique<int>(value)){}
int UniqueData::get() const{
    return *data_;
}
void UniqueData::set(int value) {
    *data_=value;
    return;
}
};



