#include "ItemType.h"

ItemType::ItemType()
{
	item = 0;
}

ItemType::~ItemType()
{
}

void ItemType::Print(ostream& Stream)
{
	Stream << item;
}

RelationType ItemType::ComparedTo(ItemType item_)
{
	if (item > item_.GetItem())
		return RelationType::GREATER;
	else if (item < item_.GetItem())
		return RelationType::LESS;

	return RelationType::EQUAL;
}
