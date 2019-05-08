#pragma once

class GrA {
public:
	GrA() {}; //: isDir(0), n(0), m(0) {}
	virtual bool create(size_t n) = 0;
	virtual bool addArc(size_t i, size_t j) = 0;
	virtual VList neighbors(size_t v) = 0;
	size_t getN() { return n; }
	size_t getM() { return m; }
	bool getIsDir() { return isDir; }
	void setisDir(bool d);
protected:
	bool isDir{ false };
	size_t n{ 0 }, m{ 0 };
};

class GrMA : public GrA {
public:
	~GrMA();
	bool create(size_t n);
	bool addArc(size_t i, size_t j);
	VList neighbors(size_t v);
protected:
	bool** E{ nullptr };
};

class GrL : public GrA {
public:
	~GrL();
	bool create(size_t n);
	bool addArc(size_t, size_t);
	VList neighbors(size_t v);
protected:
	typedef struct Node { size_t v; Node* next; } *PNode, ** PPNode;
	PPNode E{ nullptr };
};