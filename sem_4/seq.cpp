#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

void print(std::vector<int> vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}
int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Wrong Input!" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(inputFile, line);
    

    std::istringstream iss(line);
    std::vector<int> vec;
    int num;

    while (iss >> num) {
        vec.push_back(num);
    }
    print(vec);


    auto it = std::unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
    print(vec);

    int count0 = std::count(vec.begin(), vec.end(), 0);
    int count1 = std::count(vec.begin(), vec.end(), 1);

    std::ofstream outputFile(argv[2]);
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    outputFile << count1 << " " << count0 << std::endl;
    
    inputFile.close();
    outputFile.close();

    return 0;
}
