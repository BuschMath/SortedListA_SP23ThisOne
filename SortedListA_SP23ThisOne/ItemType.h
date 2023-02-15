#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <ostream>

using namespace std;

const int Max_Items = 100;

enum RelationType
{
	LESS,
	GREATER,
	EQUAL
};

class ItemType
{
public:

	ItemType();
	~ItemType();

	void Initialize(int item_) { SetItem(item_); };
	void SetItem(int item_) { item = item_; };
	int GetItem() { return item; };

	void Print(ostream& Stream);

	RelationType ComparedTo(ItemType item_);

private:
	int item;
};

#endif // !ITEMTYPE_H
