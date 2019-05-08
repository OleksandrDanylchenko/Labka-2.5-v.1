#pragma once

#include <fstream>
#include "D:\Studying\Programming\LABS\Labka 2.5\Headers\vList.h"
#include "D:\Studying\Programming\LABS\Labka 2.5\Headers\grRepres.h"
using namespace std;

VList::VList(size_t _n) : vList{ new size_t[_n] }, nmax{ _n }, n{ 0 } {}
VList::VList(VList&& r) noexcept : nmax{ 0 }, n{ 0 }, vList{ nullptr } {
	nmax = r.nmax;
	n = r.n;
	vList = r.vList;

	r.nmax = r.n = 0;
	r.vList = nullptr;
}

VList::~VList() {
	delete[]vList;
}
void VList::add(size_t v) {
	if (n < nmax)
		vList[n++] = v;
}
bool VList::notEmpty() { return n > 0; }

void VList::output(ofstream& f) {
	for (size_t i = 0; i < n; ++i)
		f << vList[i] << ' ';
}