#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 1) {
		for (int i = 1; i < argc; i++) {
			std::string str(argv[i]);
			for (size_t j = 0; j < str.length(); j++){
				std::cout << static_cast<char>(std::toupper(str[j]));
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "📢  📢  📢  📢  📢  📢  📢  📢  📢\n";
	return (0);
}
