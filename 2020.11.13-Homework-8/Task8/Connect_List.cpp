#include "Connect_List.h"

Connect_List::Connect_List(const Connect_List& list)
{
	tail = head = nullptr;
	count = 0;
	Node* temp = list.head;
	while (temp != nullptr)
	{
		addToTail(temp->data);
		temp = temp->next;
	}
}

Connect_List::~Connect_List()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* node = temp;
		temp = temp->next;
		delete node;
	}
}

bool Connect_List::indexValid(int index)
{
	return (index >= 0 && index < count);
}

int Connect_List::length()
{
	return count;
}

bool Connect_List::addToTail(int element)
{
	if (tail == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		tail->next = new Node(element);
		tail = tail->next;
	}
	++count;
	return true;
}

bool Connect_List::addToHead(int element)
{
	if (head == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		head = new Node(element, head);
	}
	++count;
	return true;
}

bool Connect_List::add(int element, int index)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		addToHead(element);
	}
	if (index == count)
	{
		addToTail(element);
	}

	Node* temp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		temp = temp->next;
	}
	temp->next = new Node(element, temp->next);
	++count;
	return true;
}

int Connect_List::get(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		return head->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}

	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

bool Connect_List::set(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		head->data = element;
	}
	else if (index == count - 1)
	{
		tail->data = element;
	}
	else
	{
		Node* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		temp->data = element;
	}
	return true;
}

int& Connect_List::operator[](int index)
{
	if (head == nullptr)
	{
		addToHead(0);
		return head->data;
	}
	if (index <= 0)
	{
		return head->data;
	}
	if (index >= count)
	{
		addToTail(0);
		return tail->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}
	Node* temp = head;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->next;
	}
	return temp->data;
}

std::ostream& operator<<(std::ostream& stream, const Connect_List list)
{
	stream << "[" << list.count << "]{";
	if (list.head == nullptr)
	{
		stream << "EMPTY";
	}
	else
	{
		Node* temp = list.head;
		while (temp != nullptr)
		{
			stream << temp->data;
			if (temp->next != nullptr)
			{
				stream << ", ";
			}
			temp = temp->next; //ïåðåõîäèì íà ñëåäóþùèé ýëåìåíò
		}
	}
	stream << "}";
	return stream;
}

void Connect_List::operator+=(int element)
{
	addToTail(element);
}

int Connect_List::extractHead()
{
	if (head == nullptr)
	{
		return -1;
	}
	int element = head->data;
	Node* temp = head->next;
	delete head;
	head = temp;
	--count;
	return element;
}

int Connect_List::extractTail()
{
	if (tail == nullptr)
	{
		return -1;
	}
	int element = tail->data;
	Node* temp = head;
	for (int i = 0; i < count - 2; ++i)
	{
		temp = temp->next;
	}
	delete tail;
	tail = temp;
	tail->next = nullptr;
	--count;
	return element;
}

int Connect_List::extract(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		extractHead();
	}
	if (index == count - 1)
	{
		extractTail();
	}
	Node* temp1 = head;
	for (int i = 0; i < index - 1; ++i)
	{
		temp1 = temp1->next;
	}
	Node* temp2 = temp1->next;
	int element = temp2->data;
	temp1->next = temp2->next;
	delete temp2;
	--count;
	return element;
}

void Connect_List::operator-=(int index)
{
	if (indexValid(index))
	{
		extract(index);
	}
}

Connect_List& Connect_List::operator=(Connect_List list)
{
	for (int i = 0; i < count; ++i)
	{
		extractHead();
	}
	Node* temp = list.head;
	for (Node* temp = list.head; temp != nullptr; temp = temp->next)
	{
		addToTail(temp->data);
	}
	return *this;
}

int Connect_List::indexOf(int element)
{
	Node* temp = head;
	for (int i = 0; i < count; ++i)
	{
		if (temp->data == element)
		{
			return i;
		}
		temp = temp->next;
	}
	return -1;
}

bool Connect_List::contains(int element)
{
	return indexOf(element);
}
