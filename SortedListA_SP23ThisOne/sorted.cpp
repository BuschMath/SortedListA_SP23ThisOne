#include "sorted.h"

SortedType::SortedType()
{
	listSize = 0;
	loc = 0;
}

SortedType::~SortedType()
{
}

void SortedType::MakeEmpty()
{
	listSize = 0;
}

bool SortedType::IsFull()
{
	if (listSize == Max_Items)
		return true;

	return false;
}

int SortedType::GetLength()
{
	return listSize;
}

ItemType SortedType::GetItem(ItemType item, bool& found)
{
	for (int i = 0; i < listSize; i++)
	{
		if (item.ComparedTo(list[i]) == RelationType::EQUAL)
		{
			found = true;
			return list[i];
		}
	}

	found = false;
	return item;
}

bool SortedType::PutItem(ItemType item)
{
	if (!IsFull())
	{
		int tempLoc = ItemSearch(item);
		ItemType temp = list[tempLoc];
		ItemType nextTemp;
		list[tempLoc] = item;

		for (int i = tempLoc + 1; i < listSize; i++)
		{
			nextTemp = list[i];
			list[i] = temp;
			temp = nextTemp;
		}

		return true;
	}
	else
		return false;
}

bool SortedType::DeleteItem(ItemType item)
{
	for (int i = 0; i < listSize; i++)
	{
		if (item.ComparedTo(list[i]) == RelationType::EQUAL)
		{
			for (int j = i; j < listSize - 1; j++)
			{
				list[i] = list[i + 1];
			}
			listSize--;

			return true;
		}
	}
	return false;
}

void SortedType::ResetList()
{
	loc = 0;
}

ItemType SortedType::GetNextItem()
{
	return list[loc++];
}

int SortedType::ItemSearch(ItemType item)
{
	int lIndex = 0;
	int uIndex = listSize - 1;
	int tempLoc = (uIndex + lIndex) / 2;

	bool moreToSearch = (uIndex - lIndex) > 1;

	while (moreToSearch)
	{
		switch (list[tempLoc].ComparedTo(item))
		{
		case GREATER: uIndex = tempLoc;
			break;
		case LESS: lIndex = tempLoc;
			break;
		case EQUAL: uIndex = lIndex = tempLoc;
			break;
		default:
			break;
		}
		moreToSearch = (uIndex - lIndex) > 1;
		tempLoc = (uIndex + lIndex) / 2;
	}
	return uIndex;
}
