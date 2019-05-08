#pragma once

class VList {
public:
	VList() = default;
	VList(size_t);
	VList(const VList&) = delete;
	VList(VList&&) noexcept;
	~VList();
	void add(size_t v);
	bool notEmpty();
	void output(std::ofstream& f);
protected:
	size_t nmax{ 0 }, n{ 0 };
	size_t* vList{ nullptr };
};