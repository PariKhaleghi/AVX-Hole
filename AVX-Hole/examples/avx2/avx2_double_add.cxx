// Copyright (c) 2022 Parisa Khaleghi
// All rights reserved

#include <avxhole/simd.hxx>
#include <avxhole/util.hxx>
#include <iostream>
#include <vector>

int main() {
	std::cout << "\nSIMD AVX2 Double Addition Example." << std::endl;

	// Input data
	std::vector<double> a {5.5, 5.5, 5.5, 5.5};
	std::vector<double> b {2.2, 2.2, 2.2, 2.2};

	// Container to store solution
	std::vector<double> c(4);

	// Define SIMD objects using input data
	auto va = avxhole::simd::avx2_load(a.data());
	auto vb = avxhole::simd::avx2_load(b.data());

	// Compute SIMD operation c = a + b
	auto cv = avxhole::simd::avx2_add(va, vb);

	// Transfer data from SIMD object to container
	avxhole::simd::avx2_store(c.data(), cv);

	// Display result
	avxhole::util::print_vector("\nc", c.size(), c.data(), 2, 3);

	// c = [
	//  7.7 7.7 7.7 7.7
	// ]
}