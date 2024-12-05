#pragma once

#include <iostream>
#include <utility>
#include <memory>
#include <cstdint>

#include "Iterator.hpp"

namespace
{
	const constexpr uint32_t GROWTH_FACTOR = 2;
}

template <typename T, typename Allocator = std::allocator<T>>
class Vector
{
public:
	using ValueType = T;
	using vector_iterator = vector_iterator<Vector<T>>;
	using const_vector_iterator = const_vector_iterator<Vector<T>>;
	using reverse_vector_iterator = reverse_vector_iterator<Vector<T>>;

	vector_iterator begin()
	{
		return vector_iterator{ this->data };
	}

	vector_iterator end()
	{
		return vector_iterator{ this->data + this->size };
	}

	const_vector_iterator cbegin()
	{
		return const_vector_iterator{ this->data };
	}

	const_vector_iterator cend()
	{
		return const_vector_iterator{ this->data + this->size };
	}

	reverse_vector_iterator rbegin()
	{
		return getSize() > 0 ?
			reverse_vector_iterator(&this->data[getSize() - 1]) :
			reverse_vector_iterator(nullptr);
	}

	reverse_vector_iterator rend()
	{
		return getSize() > 0 ?
			reverse_vector_iterator(this->data - 1) :
			reverse_vector_iterator(nullptr);
	}

private:
	T* data;
	uint32_t size;
	uint32_t capacity;

	Allocator allocator;

	uint32_t allocateCapacity() const;

	void copyFrom(const Vector<T, Allocator>& other);
	void free();

public:
	Vector();
	explicit Vector(uint32_t size);
	Vector(uint32_t size, const T& element);

	Vector(const Vector<T, Allocator>& other);
	Vector& operator=(const Vector<T, Allocator>& other);

	Vector(Vector<T, Allocator>&& other) noexcept;
	Vector& operator=(Vector<T, Allocator>&& other) noexcept;

	const T* getData() const;
	T* getData();

	uint32_t getSize() const;
	uint32_t getCapacity() const;

	void resize(uint32_t newCapacity);
	void reserve(uint32_t newCapacity);

	const T& operator[](uint32_t index) const;
	T& operator[](uint32_t index);

	const T& front() const;
	T& front();

	const T& back() const;
	T& back();

	void push_back(const T& element);
	void push_back(T&& element);

	void pop_back();

	void erase(const_vector_iterator pos);
	void erase(const_vector_iterator start, const_vector_iterator end);

	bool empty() const;
	void clear();

	~Vector() noexcept;
};

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector() : data(nullptr), size(0), capacity(0) {}

template<typename T, typename Allocator>
inline Vector<T, Allocator>::Vector(uint32_t size) :
	data{ this->allocator.allocate(size) },
	size{ size },
	capacity{ size }
{
	for (uint32_t i = 0; i < getSize(); i++)
	{
		this->allocator.construct(&this->data[i]);
	}
}

template<typename T, typename Allocator>
inline Vector<T, Allocator>::Vector(uint32_t size, const T& element) :
	data{ this->allocator.allocate(size) },
	size{ size },
	capacity{ size }
{
	for (uint32_t i = 0; i < getSize(); i++)
	{
		this->allocator.construct(&this->data[i], element);
	}
}

template<typename T, typename Allocator>
inline Vector<T, Allocator>::Vector(const Vector<T, Allocator>& other)
{
	copyFrom(other);
}

template<typename T, typename Allocator>
inline Vector<T, Allocator>& Vector<T, Allocator>::operator=(const Vector<T, Allocator>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T, typename Allocator>
inline Vector<T, Allocator>::Vector(Vector<T, Allocator>&& other) noexcept :
	data{ std::exchange(other.getData(), nullptr) },
	size{ std::exchange(other.getSize(), 0) },
	capacity{ std::exchange(other.getCapacity(), 0) } {}

template<typename T, typename Allocator>
inline Vector<T, Allocator>& Vector<T, Allocator>::operator=(Vector<T, Allocator>&& other) noexcept
{
	this->data = std::exchange(other.getData(), nullptr);
	this->size = std::exchange(other.getSize(), 0);
	this->capacity = std::exchange(other.getCapacity(), 0);

	return *this;
}

template<typename T, typename Allocator>
inline const T* Vector<T, Allocator>::getData() const
{
	return this->data;
}

template<typename T, typename Allocator>
inline T* Vector<T, Allocator>::getData()
{
	return this->data;
}

template<typename T, typename Allocator>
inline uint32_t Vector<T, Allocator>::getSize() const
{
	return this->size;
}

template<typename T, typename Allocator>
inline uint32_t Vector<T, Allocator>::getCapacity() const
{
	return this->capacity;
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::resize(uint32_t newCapacity)
{
	if (newCapacity < getSize())
	{
		for (uint32_t i = newCapacity; i < getSize(); i++)
		{
			this->allocator.destroy(&this->data[i]);
		}

		this->size = newCapacity;
	}
	else if (newCapacity > getSize())
	{
		if (newCapacity <= getCapacity())
		{
			for (uint32_t i = getSize(); i < newCapacity; i++)
			{
				this->allocator.construct(&this->data[i]);
			}

			this->size = newCapacity;
		}
		else
		{
			T* newData = this->allocator.allocate(newCapacity);

			for (uint32_t i = 0; i < getSize(); i++)
			{
				this->allocator.construct(&newData[i], std::move(this->data[i]));
			}

			for (uint32_t i = getSize(); i < newCapacity; i++)
			{
				this->allocator.construct(&newData[i]);
			}

			this->allocator.deallocate(this->data, getCapacity());

			this->data = newData;
			this->capacity = newCapacity;
		}
	}
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::reserve(uint32_t newCapacity)
{
	if (newCapacity <= getCapacity()) return;

	T* newData = this->allocator.allocate(newCapacity);

	for (uint32_t i = 0; i < getSize(); i++)
	{
		this->allocator.construct(&newData[i], std::move(this->data[i]));
	}

	this->allocator.deallocate(this->data, getCapacity());

	this->data = newData;
	this->capacity = newCapacity;
}

template<typename T, typename Allocator>
inline const T& Vector<T, Allocator>::operator[](uint32_t index) const
{
	return this->data[index];
}

template<typename T, typename Allocator>
inline T& Vector<T, Allocator>::operator[](uint32_t index)
{
	return this->data[index];
}

template<typename T, typename Allocator>
inline const T& Vector<T, Allocator>::front() const
{
	return this->data[0];
}

template<typename T, typename Allocator>
inline T& Vector<T, Allocator>::front()
{
	return this->data[0];
}

template<typename T, typename Allocator>
inline const T& Vector<T, Allocator>::back() const
{
	return this->data[getSize() - 1];
}

template<typename T, typename Allocator>
inline T& Vector<T, Allocator>::back()
{
	return this->data[getSize() - 1];
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::push_back(const T& element)
{
	if (getSize() >= getCapacity()) reserve(allocateCapacity());

	this->allocator.construct(this->data[this->size++], element);
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::push_back(T&& element)
{
	if (getSize() >= getCapacity()) reserve(allocateCapacity());

	this->allocator.construct(&this->data[this->size++], std::move(element));
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::pop_back()
{
	if (empty()) return;

	erase(--end());
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::erase(const_vector_iterator pos)
{
	erase(pos, pos + 1);
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::erase(const_vector_iterator start, const_vector_iterator end)
{
	int deletedCount = end - start;

	if (deletedCount <= 0)
	{
		return;
	}

	int first = start - begin();
	int last = end - begin();

	if (end != cend())
	{
		uint32_t idx = first;

		for (uint32_t i = last; i < getSize(); i++)
		{
			this->allocator.construct(&this->data[idx], std::move(this->data[i]));
			++idx;
		}
	}

	for (uint32_t i = last; i < getSize(); i++)
	{
		this->allocator.destroy(&this->data[i]);
	}

	this->size -= deletedCount;
}

template<typename T, typename Allocator>
inline bool Vector<T, Allocator>::empty() const
{
	return getSize() == 0;
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::clear()
{
	for (uint32_t i = 0; i < getSize(); i++)
	{
		this->allocator.destroy(&this->data[i]);
	}

	this->size = 0;
}

template<typename T, typename Allocator>
inline Vector<T, Allocator>::~Vector() noexcept
{
	free();
}

template<typename T, typename Allocator>
inline uint32_t Vector<T, Allocator>::allocateCapacity() const
{
	if (getCapacity() == 0) return 1;

	return getCapacity() * GROWTH_FACTOR;
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::copyFrom(const Vector<T, Allocator>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->data = this->allocator.allocate(other.getCapacity());

	for (uint32_t i = 0; i < getSize(); i++)
	{
		this->allocator.construct(&this->data[i], other.data[i]);
	}
}

template<typename T, typename Allocator>
inline void Vector<T, Allocator>::free()
{
	for (uint32_t i = 0; i < getSize(); i++)
	{
		this->allocator.destroy(&this->data[i]);
	}

	this->allocator.deallocate(this->data, getCapacity());
}
