#include <iostream>
#include <fstream>

#include "D:\Studying\Programming\LABS\Labka 2.5\Headers\vList.h"
#include "D:\Studying\Programming\LABS\Labka 2.5\Headers\grRepres.h"

using namespace std;

void GrA::setisDir(bool d) { isDir = d; }

GrMA::~GrMA() {
	if (E != nullptr) {
		for (size_t l = 0; l < n; ++l) {
			delete[] E[l];
			E[l] = nullptr;
		}
		delete[] E;
		E = nullptr;
	}
}

bool GrMA::create(size_t _n) {
	// deletes all the information in previous 2D array
	if (E != nullptr) {
		for (size_t l = 0; l < n; ++l) {
			delete[] E[l];
			E[l] = nullptr;
		}
		delete[] E;
		E = nullptr;
	}

	// creates new 2D matrix
	n = _n;
	E = new(nothrow) bool* [n] {};
	if (E != nullptr)
		for (size_t i = 0; i < n; ++i) {
			E[i] = new(nothrow) bool [n]{};
			if (E[i] == nullptr)
				break;
		}
	return (E != nullptr);
}

bool GrMA::addArc(size_t v, size_t w) {
	E[v][w] = true;
	if (!isDir) // if graph isn't directed it's adjacency matrix is symmetric
		E[w][v] = true;
	++m;
	return true;
}

VList GrMA::neighbors(size_t i) {
	VList L(n);
	for (int j = 0; j < n; ++j) // check entire matrix
		if (E[i][j] != false)
			L.add(j);
	return L;
}