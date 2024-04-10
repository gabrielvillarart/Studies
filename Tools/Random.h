#pragma once

#include <chrono>

class Random {

	static constexpr unsigned int Noise32( int positionX, unsigned int seed )
	{
		constexpr unsigned int SQ5_BIT_NOISE1 = 0xd2a80a3f;	// 11010010101010000000101000111111
		constexpr unsigned int SQ5_BIT_NOISE2 = 0xa884f197;	// 10101000100001001111000110010111
		constexpr unsigned int SQ5_BIT_NOISE3 = 0x6C736F4B; // 01101100011100110110111101001011
		constexpr unsigned int SQ5_BIT_NOISE4 = 0xB79F3ABB;	// 10110111100111110011101010111011
		constexpr unsigned int SQ5_BIT_NOISE5 = 0x1b56c4f5;	// 00011011010101101100010011110101

		unsigned int mangledBits = (unsigned int) positionX;
		mangledBits *= SQ5_BIT_NOISE1;
		mangledBits += seed;
		mangledBits ^= (mangledBits >> 9);
		mangledBits += SQ5_BIT_NOISE2;
		mangledBits ^= (mangledBits >> 11);
		mangledBits *= SQ5_BIT_NOISE3;
		mangledBits ^= (mangledBits >> 13);
		mangledBits += SQ5_BIT_NOISE4;
		mangledBits ^= (mangledBits >> 15);
		mangledBits *= SQ5_BIT_NOISE5;
		mangledBits ^= (mangledBits >> 17);
		return mangledBits;
	}

	static unsigned int initStaticSeed()
	{
		constexpr unsigned int iterations_amount = 4;
		constexpr unsigned int bits_shift_delta = 32 / iterations_amount;
		unsigned int mangledBits = 0b10101010101010101010101010101010;
		for (size_t i = 0; i < iterations_amount; i++) {
			auto start = std::chrono::high_resolution_clock::now();
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float, std::milli> elapsed = finish - start;
			float msElapsed = elapsed.count();
			mangledBits ^= *(unsigned int*)&msElapsed;
			mangledBits << bits_shift_delta * i;
		}
		return mangledBits;
	}

	inline static unsigned int staticSeed = initStaticSeed();
	inline static int staticPos = (int)initStaticSeed();

public:
	static constexpr double zeroToOne( int index, unsigned int seed )
	{
		constexpr double one_over_max_uint = (1.0 / (double) 0xFFFFFFFF);
		return one_over_max_uint * (double) Noise32( index, seed );
	}

	static constexpr double negOneToOne( int index, unsigned int seed )
	{
		constexpr double one_over_max_int = (1.0 / (double) 0x7FFFFFFF);
		return one_over_max_int * (double) (int) Noise32( index, seed );
	}

	static double zeroToOne()
	{
		return zeroToOne(++staticPos, staticSeed);
	}

	static constexpr double negOneToOne()
	{
		return negOneToOne(++staticPos, staticSeed);
	}

	static unsigned int getBetween(unsigned int Min, unsigned int Max)
	{
		unsigned int result = Noise32(++staticPos, staticSeed);
		unsigned int diff = Max - Min;
		result %= diff;
		result += Min;
		return result;
	}

	static double getBetween(double Min, double Max)
	{
		double distance = Max - Min;
		double result = zeroToOne(++staticPos, staticSeed);
		result *= distance;
		result += Min;
		return result;
	}

	static float getBetween(float Min, float Max)
	{
		return (float)getBetween((double)Min, (double)Max);
	}
};

inline unsigned int RandomUInt32(unsigned int Min, unsigned int Max)
{
	return Random::getBetween(Min, Max);
}

inline unsigned int RandomInt32(unsigned int Min, unsigned int Max)
{
	return Random::getBetween(Min, Max);
}