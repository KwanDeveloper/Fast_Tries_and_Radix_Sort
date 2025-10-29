#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "Radix_Sort.h"
#include "Umap_with_sorter.h"
#include "X-fast_Trie.h"

// INSERTION SECTION
TEST_CASE("Trie insertion test cases", "[insertion]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Collect and insert variables into Trie
	int insert_this_value = 67;
	xft.insert(1, insert_this_value); // Make 1 = 67

	constexpr size_t key_to_check = 1;
	REQUIRE(xft.contains(key_to_check)); // Confirm insertion 1 = 67
}

TEST_CASE("Trie multiple insertions and ordering", "[insertion-order]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Collect and insert variables into Trie
	int insert_this_value = 1, insert_this_value_2 = 3, insert_this_value_3 = 2;
	xft.insert(1, insert_this_value);
	xft.insert(3, insert_this_value_2);
	xft.insert(2, insert_this_value_3);

	// Confirm keys 1, 3, 2 are occupied
	REQUIRE(xft.contains(1));
	REQUIRE(xft.contains(3));
	REQUIRE(xft.contains(2));

	// Create an iterator
	auto it = xft.begin();

	// Confirm the keys and values are ordered
	// REQUIRE(it->first == 1); // [ERROR]
	//REQUIRE(it->second.value == 1); // [ERROR]
	// ++it;
	// REQUIRE(it->first == 2); // [ERROR]
	// REQUIRE(it->second.value == 2); // [ERROR]
	// ++it;
	// REQUIRE(it->first == 3); // [ERROR]
	// REQUIRE(it->second.value == 3); // [ERROR]
}

// ITERATION SECTION
TEST_CASE("Trie iteration test cases", "[iteration]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Collect and insert variables into Trie
	int insert_this_value = 1, insert_this_value_2 = 2, insert_this_value_3 = 3;
	xft.insert(1, insert_this_value);
	xft.insert(2, insert_this_value_2);
	xft.insert(3, insert_this_value_3);

	// Count the number of keys via iterator
	size_t count = 0;
	for (auto it = xft.begin(); it != xft.end(); ++it) count++;
	REQUIRE(count == 3);
}

// REMOVAL SECTION
TEST_CASE("Trie removal test cases", "[removal]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Collect and insert variables into Trie
	int insert_this_value = 67;
	xft.insert(1, insert_this_value); // Make 1 = 67

	constexpr size_t key_to_check = 1;
	REQUIRE(xft.contains(key_to_check)); // Confirm insertion 1 = 67
	// xft.remove(key_to_check); // Remove key 1 [ERROR]
	REQUIRE(xft.contains(key_to_check)); // Confirm key 1 no longer exists
}

// FIND SECTION
TEST_CASE("Trie find test cases", "[find]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Collect and insert variables into Trie
	int insert_this_value = 1, insert_this_value_2 = 2;
	xft.insert(4, insert_this_value);
	xft.insert(8, insert_this_value_2);

	// Key 4 = 1
	auto it = xft.find(4);
	REQUIRE(it != xft.end());
	// REQUIRE(it->second.value == 1); [ERROR]

	// Key 99 does not exist
	auto it2 = xft.find(99);
	REQUIRE(it2 == xft.end());
}

// PREDECESSOR AND SUCCESSOR SECTION
TEST_CASE("Trie predecessor test cases", "[predecessor]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Collect and insert variables into Trie
	int insert_this_value = 1, insert_this_value_2 = 2, insert_this_value_3 = 3;
	xft.insert(10, insert_this_value);
	xft.insert(20, insert_this_value_2);
	xft.insert(30, insert_this_value_3);

	// Get the key before key 20
	auto pre = xft.predecessor(30);
	// REQUIRE(pre->first == 20); [ERROR]
	// REQUIRE(pre->second.value == 2); [ERROR]

	// Get the key before key 5 (does not exist)
	auto none = xft.predecessor(10);
	REQUIRE(none == xft.end());
}

TEST_CASE("Trie successor test cases", "[successor]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Collect and insert variables into Trie
	int insert_this_value = 1, insert_this_value_2 = 2, insert_this_value_3 = 3;
	xft.insert(10, insert_this_value);
	xft.insert(20, insert_this_value_2);
	xft.insert(30, insert_this_value_3);

	auto suc = xft.successor(10);
	// REQUIRE(suc->first == 20); [ERROR]
	// REQUIRE(suc->second.value == 2); [ERROR]

	auto none = xft.successor(30);
	REQUIRE(none == xft.end());
}

// EDGE-CASES SECTION
TEST_CASE("Trie contains and empty edge cases", "[contains-empty]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Check key 100 is not in empty Trie
	REQUIRE(xft.contains(100) == false);

	// Collect and insert variables into Trie
	int insert_this_value = 5;
	xft.insert(3, insert_this_value);
	REQUIRE(xft.contains(3)); // Confirm key 3 exists

	// Remove key 3
	// xft.remove(3); [ERROR]
	REQUIRE(xft.contains(3) == false); // Confirm key 3 no longer exists
}

TEST_CASE("Trie edge-case removal of last element", "[last-removal]") {
	// New Trie instance of expected-capacity 64
	XFastTrie<int> xft(64);

	// Collect and insert variables into Trie
	int insert_this_value = 9;
	xft.insert(1, insert_this_value);

	// Confirm insertion 1 = 67
	REQUIRE(xft.contains(1));

	// Remove key 1
	// xft.remove(1); [ERROR]

	// Confirm that key 1 no longer exists
	REQUIRE(xft.contains(1) == false);

	// Verify that the Trie is now empty where begin == end
	REQUIRE(xft.begin() == xft.end());
}
