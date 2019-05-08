#include <iostream>
#include <fstream>
#include "D:\Studying\Programming\LABS\Labka 2.5\Headers\vList.h"
#include "D:\Studying\Programming\LABS\Labka 2.5\Headers\grRepres.h"
using namespace std;

void GrA::setisDir(bool d) { isDir = d; }

GrL::~GrL() {
	for (size_t i = 0; i < n; ++i)
		while (true) {
			if (E[i] == nullptr)
				break;
			else {
				PNode delNode = E[i];
				E[i] = E[i]->next;
				delete delNode;
			}
		}
}

bool GrL::create(size_t _n) {
	n = _n;
	E = new(nothrow) PNode[_n]{};
	if (E == nullptr) {
		std::cout << "FreeMem Problems" << std::endl;
		return false;
	}
	return true;
}

bool GrL::addArc(size_t i, size_t j) {
	PNode p = new(nothrow) Node;
	if (p == nullptr)
		return false;
	p->v = j;
	p->next = E[i];
	E[i] = p;
	if (!isDir) {
		PNode p = new(nothrow) Node;
		if (p == nullptr)
			return false;
		p->v = i;
		p->next = E[j];
		E[j] = p;
	}
	++m;
	return true;
}

VList GrL::neighbors(size_t i) {
	VList L(n);
	PNode seek = E[i];
	while (seek != nullptr) {
		L.add(seek->v);
		seek = seek->next;
	}
	return L;
}
