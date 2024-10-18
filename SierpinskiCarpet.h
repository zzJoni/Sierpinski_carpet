#pragma once
#include "exponent.h"
#include <vector>
#include <iostream>
#include <vector>

class SierpinskiCarpet
{
public:
	explicit constexpr SierpinskiCarpet(const int recursionNum);

	// Prints the carpet
	void print() const;

private:
	// Constants used in the carpet
	static constexpr std::size_t m_minUnitSize{ 3 };
	static constexpr char m_filledSymbol{ '#' };

	// Values used to store carpet and related info
	const std::size_t m_size{};
	std::vector<std::vector<char>> m_sierpinskiCarpet{};

	// Populates the sierpinski carpet
	constexpr void populateCarpet();
}; 

// Constructor
constexpr SierpinskiCarpet::SierpinskiCarpet(const int recursionNum)
	: m_size{ static_cast<std::size_t>(exponent(static_cast<int>(m_minUnitSize), recursionNum)), }
{
	if (m_size < 1)
		return;

	// Sets the carpet to the apropriate size
	m_sierpinskiCarpet.resize(m_size);
	for (auto& row : m_sierpinskiCarpet)
	{
		row.resize(m_size, ' ');
	}

	// Populates the carpet
	populateCarpet();
}

// Prints the carpet
inline void SierpinskiCarpet::print() const
{
	for (auto line : m_sierpinskiCarpet)
	{
		for (auto value : line)
		{
			std::cout << value << ' ';
		}

		std::cout << "\n";
	}
}

// Populates the sierpinski carpet
constexpr void SierpinskiCarpet::populateCarpet()
{
	m_sierpinskiCarpet[0][0] = m_filledSymbol;

	// Determines how much of the carpet is filled
	std::size_t filledAreaSize{};
	for (std::size_t i{ 0 }; i < m_size; ++i)
	{
		if (m_sierpinskiCarpet[0][i] != m_filledSymbol)
		{
			filledAreaSize = i;
			break;
		}
	}
	// Copies the filled section into unfilled areas
	for (std::size_t i{ 0 }; i < filledAreaSize; ++i)
	{
		for (std::size_t z{ 0 }; z < filledAreaSize; ++z)
		{
			// Row 1
			m_sierpinskiCarpet[i][z + filledAreaSize] = m_sierpinskiCarpet[i][z];
			m_sierpinskiCarpet[i][z + (filledAreaSize * 2)] = m_sierpinskiCarpet[i][z];
			// Row 2
			m_sierpinskiCarpet[i + filledAreaSize][z] = m_sierpinskiCarpet[i][z];
			m_sierpinskiCarpet[i + filledAreaSize][z + (filledAreaSize * 2)] = m_sierpinskiCarpet[i][z];
			// Row 3
			m_sierpinskiCarpet[i + (filledAreaSize * 2)][z] = m_sierpinskiCarpet[i][z];
			m_sierpinskiCarpet[i + (filledAreaSize * 2)][z + filledAreaSize] = m_sierpinskiCarpet[i][z];
			m_sierpinskiCarpet[i + (filledAreaSize * 2)][z + (filledAreaSize * 2)] = m_sierpinskiCarpet[i][z];
		}
	}
	// Runs the function again if the carpet is not full
	if (m_sierpinskiCarpet[0][m_size - 1] != m_filledSymbol)
		populateCarpet();
}
