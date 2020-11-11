#include"ArrayList.h"

ArrayList::ArrayList()
{
	count = 0;
	capacity = 10;
	data = new int[capacity];
}

ArrayList::ArrayList(int cap)
{
	count = 0;
	capacity = cap;
	data = new int[capacity];
}

ArrayList::~ArrayList()
{
	delete[] data;
}



void expand(int*& data, int& capacity)
{
	int* temp = new int[capacity*2];
	for (int i = 0; i < capacity; ++i)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	capacity *= 2;
}

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand(data, capacity);
	}
	data[count] = element;
	++count;
	return true;
}

bool indexIncorrect(int index, int count)
{
	return ((index < 0) || (index >= count));
}


bool ArrayList::add(int index, int element)
{
	if (indexIncorrect(index, count))
	{
		return false;
	}
	if (count == capacity)
	{
		expand(data,capacity);
	}
	for (int i = count - 1; i > index; --i)
	{
		data[i] = data[i - 1];
	}
	data[index] = element;
	++count;
	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	for(int i = 0; i < list.count; ++i)
	{
		add(list.data[i]);
	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	if (indexIncorrect(index, count))
	{
		return false;
	}

	for (int i = 0; i < list.count; ++i)
	{
		add(index + i,list.data[i]);
	}
	return true;
}



void ArrayList::clear()
{
	count = 0;
}

bool ArrayList::contains(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index)
{
	if (indexIncorrect(index, count))
	{
		return -1;
	}
	return data[index];
}

int ArrayList::indexOf(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return -1;
}

bool ArrayList::isEmpty()
{
	return (count > 0);
}

void ArrayList::print()
{
	for (int i = 0; i < count; ++i)
	{
		cout << data[i] << ";";
	}
}

bool ArrayList::remove(int index)
{
	if (indexIncorrect(index, count))
	{
		return false;
	}
	for (int i = index; i < count - 1; ++i)
	{
		data[i] = data[i + 1];
	}
	count--;
	return true;
}

int ArrayList::swap(int index1, int index2)
{
	if (indexIncorrect(index1, count))
	{
		return false;
	}
	data[index1] = data[index1] ^ data[index2];
	data[index2]= data[index1]^data[index2];
	data[index1]= data[index1]^data[index2];
	return true;
}
