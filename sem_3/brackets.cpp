#include <fstream>
#include <iostream>
#include <stack>
#include <string>


void brackets(std::string str) {
	std::stack<char> st_brack;
	int k = 0;
	for (int i = 0; i < str.size(); ++i) {
		switch(str[i]) {
			case '(':
				st_brack.push(')');
				k = i + 1;
				break;
			case '[':
				st_brack.push(']');
				k = i + 1;
				break;
			case '{':
				st_brack.push('}');
				k = i + 1;
				break;
			case '}':
			case ']':
			case ')':
				if (st_brack.empty() || st_brack.top() != str[i]) {
					std::cout << i + 1 << std::endl;
				}
				st_brack.pop();
				break;
		}		
	}
	if (st_brack.empty()) {
		std::cout << "success" << std::endl;
	}
    else
    {
        std::cout << k << ' ';
    }
}

int main() {
	std::ifstream inf("test.txt");
	if (!inf.is_open()) {
		std::cerr << "File doesn't exist!" << std::endl;
        return -1;
	}
	else {
		std::string str;
		while (getline(inf, str)) {
			brackets(str);
		}
	}
	return 0;
}