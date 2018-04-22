#ifndef VECTOR_BAG_H
#define VECTOR_BAG_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "BagInterface.h"
using namespace std;

template<class ItemType>
class VectorBag : public BagInterface<ItemType> {
private:
	vector<ItemType> items;
	int getIndexOf(const ItemType& target) const;
public:
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
   	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const;
	VectorBag<ItemType> operator+(VectorBag<ItemType> anotherBag);
	VectorBag<ItemType> operator-(VectorBag<ItemType> anotherBag);
	VectorBag<ItemType> operator*(VectorBag<ItemType> anotherBag);
};

#endif
