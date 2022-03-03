#include <iostream>
#include <string>
#include <fstream>

// 개행은 안바뀌는 점 : getline 함수가 아니라 read 이용하기, tellg?
// 파일 권한에 따라 에러 처리 확실하게 하기
// 없는 파일일때 처리
// ./replace ' (enter) ' 'a' (enter)
//0000 -> 00

int main(int argc, char **argv)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string rpFileName;
	if (argc != 4 || !argv[2][0] || !argv[3][0]) {
		std::cout << "Input Error" << std::endl;
		return (1);
	}
	std::string origin = argv[2];
	std::string change = argv[3];
	ifs.open(argv[1]);
	rpFileName = argv[1];
	rpFileName += ".replace";
	ofs.open(rpFileName);
	while (ifs.peek() != EOF)
	{
		std::string line;
		std::getline(ifs, line);
		size_t resFind;
		resFind = line.std::string::find(origin, 0);
		while ((int)resFind != -1)
		{
			std::string front = line.substr(0, resFind);
			std::string back = line.substr(resFind + origin.length(), line.length());
			line = front + change + back;
			resFind = line.std::string::find(origin, 0);
		}
		ofs << line << "\n";
	}
	return (0);
}