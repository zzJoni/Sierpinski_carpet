#include "SignedArrayView.h"
#include <vector>
#include <cassert>

template <typename T>
class NumericArrayView
{
public:
	constexpr explicit NumericArrayView(T& array) : m_array{ array } {}

	// Gets the largest value in the array
	constexpr const auto& getLargest() const 
	{
		assert(m_array.size() > 0 && "getLargest called on an empty array");

		const auto* largest{ &m_array[0] };

		for (auto element : m_array)
		{
			if (element > *largest)
			{ 
				largest = &element;
			}
		}

		return *largest;
	}

private:
	T& m_array{};
};