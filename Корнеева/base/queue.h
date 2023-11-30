#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "linkedlist.h"
#include <stdexcept>

template<typename T>
class TQueue : public TLinkedList<T>
{
public:
	T& peek();                      // ���������� ������ �� ������ ������� � �������
	void enqueue(const T& element); // ��������� ������� � ����� �������
	T dequeue();                    // ������� � ���������� ������ ������� � �������.
};

template<typename T>
T& TQueue<T>::peek()
{
	if (this->empty())
	{
		throw std::out_of_range("Queue is empty");
	}

	return (*this)[0];
}

template<typename T>
void TQueue<T>::enqueue(const T& element)
{
	this->push_back(element);
}

template<typename T>
T TQueue<T>::dequeue()
{
	if (this->empty())
	{
		throw std::out_of_range("Queue is empty");
	}

	T element = (*this)[0];
	this->remove(0);
	return element;
}

#endif // __QUEUE_H__