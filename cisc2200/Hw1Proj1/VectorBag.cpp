#include "VectorBag.h"

template<class ItemType>
int VectorBag<ItemType>::getIndexOf(const ItemType& target) const {
	bool found = false;
	int result = -1;
	int searchIndex = 0;
	while (!found && (searchIndex < items.size())) {
		if (items[searchIndex] == target) {
			found = true;
			result = searchIndex;
		}
		else
			searchIndex++;
	}
	
	return result;
}

template<class ItemType>
int VectorBag<ItemType>::getCurrentSize() const {
	return items.size();
}

template<class ItemType>
bool VectorBag<ItemType>::isEmpty() const {
	return items.size() == 0;
}

template<class ItemType>
bool VectorBag<ItemType>::add(const ItemType& newEntry) {
	bool hasRoomToAdd = (items.size() < items.max_size());
	if (hasRoomToAdd)
		items.push_back(newEntry);
	
	return hasRoomToAdd;
}

template<class ItemType>
bool VectorBag<ItemType>::remove(const ItemType& anEntry) {
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
		items.erase(items.begin() + locatedIndex);
	
	return canRemoveItem;
}

template<class ItemType>
void VectorBag<ItemType>::clear() {
	items.clear();
}

template<class ItemType>
bool VectorBag<ItemType>::contains(const ItemType& anEntry) const {
	bool found = false;
	int curIndex = 0;
	while (!found && (curIndex < items.size())) {
		if (anEntry == items[curIndex])
			found = true;
		curIndex++;
	}
	  
	return found;
}

template<class ItemType>
int VectorBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
	int frequency = 0;
	int curIndex = 0;
	while (curIndex < items.size()) {
		if (items[curIndex] == anEntry)
			frequency++;
		curIndex++;
	}
   
   return frequency;
}

template<class ItemType>
vector<ItemType> VectorBag<ItemType>::toVector() const {
	vector<ItemType> bagContents;
	for (int i = 0; i < items.size(); i++)
		bagContents.push_back(items[i]);

	return bagContents;
}

template<class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator+(VectorBag<ItemType> anotherBag) {
	for (int i = 0; i < items.size(); i++)
		anotherBag.add(items[i]);
	
	return anotherBag;
}

template<class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator-(VectorBag<ItemType> anotherBag) {
	VectorBag<ItemType> diffBag;
	vector<ItemType> second = anotherBag.toVector();
	for (int i = 0; i < items.size(); i++)
		diffBag.add(items[i]);
	for (int i = 0; i < second.size(); i++)
		diffBag.remove(second[i]);
		
	return diffBag;
}

template<class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator*(VectorBag<ItemType> anotherBag) {
	VectorBag<ItemType> interBag;
	for (int i = 0; i < items.size(); i++)
		interBag.add(items[i]);
		
	return interBag - (interBag - anotherBag);
}
