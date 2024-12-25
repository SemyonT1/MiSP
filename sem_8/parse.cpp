#include <iostream>
#include <optional>
#include <string>

std::optional<double> Parse(const std::string& str) {
    try {
        size_t count_value;
        double value = std::stod(str, &count_value);
        if (count_value == str.length()) {
            return value;
        }
    }
    catch (const std::exception& e) {
        e.what();
    }
    return std::nullopt;
}
double SumArgs(int argc, char* argv[]) {
    double sum = 0.0;
    for (int i = 1; i < argc; ++i) {
        auto num = Parse(argv[i]);
        if (num.has_value()) {
            sum += num.value();
        }
    }
    return sum;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Wrong input!" << std::endl;
        return -1;
    }
    double total = SumArgs(argc, argv);
    std::cout << "Sum of args: " << total << std::endl;
    return 0;
}