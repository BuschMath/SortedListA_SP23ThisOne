#ifndef SORTED_H
#define SORTED_H

#include "ItemType.h"

class SortedType
{
public:
	SortedType();		//Done
	~SortedType();	//Done

	void MakeEmpty();	//Done
	bool IsFull();		//Done
	int GetLength();	//Done
	ItemType GetItem(ItemType item, bool& found);	
	bool PutItem(ItemType item);	
	bool DeleteItem(ItemType item);	
	void ResetList();	//Done
	ItemType GetNextItem();	//Done

private:
	ItemType list[Max_Items];
	int listSize;
	int loc;

	// Returns index of listItem just larger than item.
	int ItemSearch(ItemType item);
};

#endif // !SORTED_H

