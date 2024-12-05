#pragma once

template <typename Vector>
class vector_iterator
{
public:
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

private:
	PointerType vector_ptr = nullptr;

public:
	vector_iterator(PointerType ptr) : vector_ptr(ptr) {}
	vector_iterator(PointerType ptr, uint32_t outset) : vector_ptr(ptr + outset) {}

	vector_iterator& operator++()
	{
		this->vector_ptr++;
		return *this;
	}

	vector_iterator& operator++(int)
	{
		vector_iterator iter = *this;
		++(*this);
		return iter;
	}

	vector_iterator& operator--()
	{
		this->vector_ptr--;
		return *this;
	}

	vector_iterator& operator--(int)
	{
		vector_iterator iter = *this;
		--(*this);
		return iter;
	}

	vector_iterator& operator+(int outset) const
	{
		return this->vector_ptr + outset;
	}

	vector_iterator& operator-(int outset) const
	{
		return this->vector_ptr - outset;
	}

	ReferenceType operator[](uint32_t index)
	{
		return *(this->vector_ptr + index);
	}

	PointerType operator->()
	{
		return this->vector_ptr;
	}

	ReferenceType operator*()
	{
		return *this->vector_ptr;
	}

	bool operator==(const vector_iterator& other) const
	{
		return this->vector_ptr == other.vector_ptr;
	}

	bool operator!=(const vector_iterator& other) const
	{
		return !(*this == other);
	}
};

template <typename Vector>
class const_vector_iterator
{
public:
	using ValueType = typename Vector::ValueType;
	using PointerType = const ValueType*;
	using ReferenceType = const ValueType&;

private:
	PointerType vector_ptr = nullptr;

public:
	const_vector_iterator(PointerType ptr) : vector_ptr(ptr) {}
	const_vector_iterator(PointerType ptr, uint32_t outset) : vector_ptr(ptr + outset) {}

	const_vector_iterator& operator++()
	{
		this->vector_ptr++;
		return *this;
	}

	const_vector_iterator& operator++(int)
	{
		const_vector_iterator iter = *this;
		++(*this);
		return iter;
	}

	const_vector_iterator& operator--()
	{
		this->vector_ptr--;
		return *this;
	}

	const_vector_iterator& operator--(int)
	{
		const_vector_iterator iter = *this;
		--(*this);
		return iter;
	}

	const_vector_iterator& operator+(int outset) const
	{
		return this->vector_ptr + outset;
	}

	const_vector_iterator& operator-(int outset) const
	{
		return this->vector_ptr - outset;
	}

	ReferenceType operator[](uint32_t index)
	{
		return *(this->vector_ptr + index);
	}

	PointerType operator->()
	{
		return this->vector_ptr;
	}

	ReferenceType operator*()
	{
		return *this->vector_ptr;
	}

	bool operator==(const const_vector_iterator& other) const
	{
		return this->vector_ptr == other.vector_ptr;
	}

	bool operator!=(const const_vector_iterator& other) const
	{
		return !(*this == other);
	}
};

template <typename Vector>
class reverse_vector_iterator
{
public:
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

private:
	PointerType vector_ptr = nullptr;

public:
	reverse_vector_iterator(PointerType ptr) : vector_ptr(ptr) {}
	reverse_vector_iterator(PointerType ptr, uint32_t outset) : vector_ptr(ptr + outset) {}

	reverse_vector_iterator& operator++()
	{
		this->vector_ptr--;
		return *this;
	}

	reverse_vector_iterator& operator++(int)
	{
		reverse_vector_iterator iter = *this;
		++(*this);
		return iter;
	}

	reverse_vector_iterator& operator--()
	{
		this->vector_ptr++;
		return *this;
	}

	reverse_vector_iterator& operator--(int)
	{
		reverse_vector_iterator iter = *this;
		--(*this);
		return iter;
	}

	reverse_vector_iterator& operator+(int outset) const
	{
		return this->vector_ptr - outset;
	}

	reverse_vector_iterator& operator-(int outset) const
	{
		return this->vector_ptr + outset;
	}

	ReferenceType operator[](uint32_t index)
	{
		return *(this->vector_ptr - index);
	}

	PointerType operator->()
	{
		return this->vector_ptr;
	}

	ReferenceType operator*()
	{
		return *this->vector_ptr;
	}

	bool operator==(const reverse_vector_iterator& other) const
	{
		return this->vector_ptr == other.vector_ptr;
	}

	bool operator!=(const reverse_vector_iterator& other) const
	{
		return !(*this == other);
	}
};