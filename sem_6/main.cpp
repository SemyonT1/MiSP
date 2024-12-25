#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Wrong input!" << std::endl;
		return 1;
	}


	std::ifstream input(argv[1]);
	if (!input.is_open()) {
		std::cerr << "Error opening file: " << argv[1] << std::endl;
		return 1;
	}

	int N, a, b;
	input >> N >> a >> b;


	std::vector<int> arr(N);
	for (int i = 0; i < N; ++i) {
		input >> arr[i];
	}
	
	std::cout << "Original array: ";
	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	std::vector<int> new_array;
	std::copy_if(arr.begin(), arr.end(), std::back_inserter(new_array), [a, b](int x) { return x >= a && x <= b; });
	
	std::cout << "New array in range [" << a << ", " << b << "]: ";
	std::copy(new_array.begin(), new_array.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	
	auto max_it = std::max_element(new_array.begin(), new_array.end());

	int removed_pos = 0;
	int removed_value = 0;
	if (max_it != new_array.end()) {
		auto even_after_max = std::find_if(max_it + 1, new_array.end(), [](int x) { return x % 2 == 0; });
		
		removed_pos = std::distance(new_array.begin(), even_after_max);
		removed_value = *even_after_max;
		new_array.erase(even_after_max);
		
	}

	std::cout << "Array after removing: ";
	std::copy(new_array.begin(), new_array.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	if (removed_pos != 0) {
		std::cout << "Removed element: pos = " << removed_pos << ", value = " << removed_value << std::endl;
	}
	else {
		std::cout << "No element removed" << std::endl;
	}

	int positive_count = std::count_if(new_array.begin(), new_array.end(), [](int x) { return x > 0; });
	int negative_count = std::count_if(new_array.begin(), new_array.end(), [](int x) { return x < 0; });

	std::cout << "Positive numbers: " << positive_count << std::endl;
	std::cout << "Negative numbers: " << negative_count << std::endl;

	input.close();
	return 0;
}
