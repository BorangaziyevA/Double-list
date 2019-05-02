#pragma once
#include<iostream>
#include<vector>

using namespace std;

template<class T>
struct elem
{
	T obj;
	elem<T> *next;
	elem<T> *prev;
	elem(T obj, elem<T> *next = nullptr, elem<T> *prev = nullptr);
};

template <class T>
class list_
{
	elem<T> *head;
	elem<T> *tail;
	size_t size_;
public:
	void push_back(const T& obj);
	void push_front(const T& obj);
	void pop_back();
	void pop_front();
	void insert(size_t pos, const T& obj);
	void erase(size_t pos, const T& obj);
	size_t size() const;
	const T& getElement(size_t pos) const;

	list_();

	list_(const list_<T>& right);
	list_(list_<T>&& right);
	list_<T>& operator=(const list_<T>& right);
	list_<T>& operator=(list_<T>&& right);
};

template<class T>
inline void list_<T>::push_back(const T & obj)
{
	elem<T> *n = new elem<T>;
	n->obj = obj;
	n->next = nullptr;
	n->prev = this->tail;
	if (this->tail == nullptr)
		this->tail = this->head = n;
	else
	{
		this->tail.next = n;
		this->tail = n;
	}
	size_++:
}

template<class T>
inline void list_<T>::push_front(const T & obj)
{
	elem<T> *n = new elem<T>;
	n->obj = obj;
	n->next = this->head;
	n->prev = nullptr;
	if (this->head == nullptr)
	{
		this->head = this->tail = nullptr;
	}
	else
	{
		this->head.prev = n;
		this->head = n;
	}
	size_++;
}

template<class T>
inline void list_<T>::pop_back()
{
	if (size_ == 0)
		return;
	if (head == tail)
	{
		delete this->head;
		this->head = this->tail = nullptr;
		this->size_ = 0;
		return;
	}
	this->tail->prev = this->tail;
	delete this->tail->next;
	this->tail->next = nullptr;
	size_--;

}

template<class T>
inline void list_<T>::pop_front()
{
	if (size_ == 0)
		return;
	if (head == tail)
	{
		delete this->head;
		this->head = this->tail = nullptr;
		this->size_ = 0;
		return;
	}
	head.next = head;
	delete head->prev;
	head->prev = nullptr;
	size_--;
}

template<class T>
inline void list_<T>::insert(size_t pos, const T & obj)
{
	if (pos > size_)
		return;
	if (pos == 0)
	{
		push_front(obj);
		return;
	}
	if (pos == size_)
	{
		push_back(obj);
		return;
	}
	int x = size_ / 2;
	elem<T>* flag;
	if (pos<x)
	{
		flag = head;
		for (size_t i = 0; i < pos - 1; i++)
		{
			flag = flag->next;
		}
	}
	else
	{
		flag = tail;
		for (size_t i = size_; i > pos; i--)
		{
			flag = flag->prev;
		}
	}

	elem<T> n;
	n.obj = obj;
	n.prev = flag->prev;
	flag->prev = n;
	n.next = flag;
	n.prev.next = n;
	
	size_++;
}

template<class T>
inline void list_<T>::erase(size_t pos, const T & obj)
{

}

template<class T>
inline size_t list_<T>::size() const
{
	return size_();
}

template<class T>
inline const T & list_<T>::getElement(size_t pos) const
{
	// TODO: вставьте здесь оператор return
}

template<class T>
inline list_<T>::list_()
{
	head = tail = nullptr;
	size_ = 0;
}

template<class T>
inline list_<T>::list_(const list_<T>& right)
{

}

template<class T>
inline list_<T>::list_(list_<T>&& right)
{

}

template<class T>
inline list_<T>& list_<T>::operator=(const list_<T>& right)
{
	// TODO: вставьте здесь оператор return
}

template<class T>
inline list_<T>& list_<T>::operator=(list_<T>&& right)
{
	// TODO: вставьте здесь оператор return
}
