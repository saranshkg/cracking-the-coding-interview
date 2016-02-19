#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <cstddef>
#include <cassert>

/**
 * @brief implementation of three stacks stored as a single array of length 3n,
 *        with each stack being allowed to store at most n elements
 */
template< typename T >
class three_stacks
{
public:
	/** @brief constructor for three stacks of maximum size n */
	three_stacks(const size_t n): max_stack_size_(n)
	{
		values_ = new T[3*n];
	}

	/** @brief destructor */
	~three_stacks()
	{
		delete[] values_;
	}

	/**
	 * @brief pushes a value into the k-th stack
	 * @return true if the value was inserted, false otherwise
	 * @note complexity: O(1) in both time and space
	 */
	bool push(const size_t k, const T& value)
	{
		if (stack_size_[k] == max_stack_size_)
		{
			return false;
		}
		else
		{
			values_[k*max_stack_size_ + stack_size_[k]] = value;
			++stack_size_[k];
			return true;
		}
	}

	/**
	 * @brief pops a value from the k-th stack
	 * @note complexity: O(1) in both time and space
	 */
	void pop(const size_t k)
	{
		if (stack_size_[k] == 0)
		{
			return;
		}
		--stack_size_[k];
	}

	/**
	 * @brief returns the value on top of the k-th stack
	 * @note complexity: O(1) in both time and space
	 */
	T top(const size_t k) const
	{
		assert(empty(k) == false);
		return values_[k*max_stack_size_ + stack_size_[k] - 1];
	}

	/**
	 * @brief returns the number of elements on the k-th stack
	 * @note complexity: O(1) in both time and space
	 */
	size_t size(const size_t k) const
	{
		return stack_size_[k];
	}

	/**
	 * @brief returns true if the k-th stack is empty, false otherwise
	 * @note complexity: O(1) in both time and space
	 */
	bool empty(const size_t k) const
	{
		return stack_size_[k] == 0;
	}

private:
	T* values_;
	size_t max_stack_size_;
	size_t stack_size_[3] = { 0, 0, 0 };
};

#endif /* __STACK_HPP__ */