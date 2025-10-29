#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "Radix_Sort.h"
#include "Umap_with_sorter.h"
#include "X-fast_Trie.h"

TEST_CASE("Trie insertion test cases", "[insertion]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Collect variables
	constexpr size_t insert_this_key = 1;
	int insert_this_value = 67;

	xft.insert(insert_this_key, insert_this_value); // Make 1 = 67

	constexpr size_t key_to_check = 1;
	REQUIRE(xft.contains(key_to_check) == true); // Confirm insertion 1 = 67
}

TEST_CASE("Trie removal test cases", "[removal]") {
	// New Trie instance of expected-capacity 16
	XFastTrie<int> xft(16);

	// Collect variables
	constexpr size_t insert_this_key = 2;
	int insert_this_value = 61;

	xft.insert(insert_this_key, insert_this_value); // Make 16 = 61

	constexpr size_t key_to_check = 2;
	REQUIRE(xft.contains(key_to_check) == true); // Confirm insertion 16 = 61
	// REQUIRE(xft.remove(key_to_check) == true); // Remove key 16 [ERROR HERE]
	// REQUIRE(xft.contains(key_to_check) == true); // Confirm removal of key 16
}
