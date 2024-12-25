#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

std::string del_spaces(const std::string& str) {
    size_t start = str.find_first_not_of(' ');
    size_t end = str.find_last_not_of(' ');
    return str.substr(start, end - start + 1);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Wrong Input!" << std::endl;
        return -1;
    }
    std::ifstream inf(argv[1]);
    if (!inf.is_open()) {
        std::cerr << "File is not found!" << std::endl;
        return -1;
    }

    std::map<std::string, std::vector<std::tuple<std::string, int, double>>> categories;

    std::string line;
    while (std::getline(inf, line)) {
        std::stringstream ss(line);
        std::string name, category, amountStr, priceStr;

        std::getline(ss, name, ',');
        std::getline(ss, category, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, priceStr, ',');

        name = del_spaces(name);
        category = del_spaces(category);
        amountStr = del_spaces(amountStr);
        priceStr = del_spaces(priceStr);

        int amount = std::stoi(amountStr);
        double price = std::stod(priceStr);
       
        categories[category].emplace_back(name, amount, price);
    }
    for (const auto& [category, products] : categories) {
        int totalAmount = 0;
        double maxIncome = 0.0;
        std::string maxPrice_product, minPrice_product;
        double maxPrice = 0.0;
        double minPrice = 1000000.0;
        for (const auto& product : products) {
            auto [name, amount, price] = product;
            totalAmount += amount;
            maxIncome += amount * price;
            if (price > maxPrice) {
                maxPrice = price;
                maxPrice_product = name;
            }
            if (price < minPrice) {
                minPrice = price;
                minPrice_product = name;
            }
        }
        std::cout << "Category: " << category << std::endl;
        std::cout << "total amount: " << totalAmount << std::endl;
        std::cout << "max income: " << maxIncome << std::endl;
        std::cout << "product with max price: " << maxPrice_product << std::endl;
        std::cout << "product with min price: " << minPrice_product << std::endl;
        std::cout << "----------------------" << std::endl;
    }

}