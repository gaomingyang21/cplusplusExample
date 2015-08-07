#include <iostream>
using namespace std;
#include <string>
#include <io.h>     // For access().
#include <sys/types.h>  // For stat().
#include <sys/stat.h>   // For stat().


bool FileExists(const char* absolutePath)
{
	if (_access(absolutePath, 0) == 0){

		struct stat status;
		stat(absolutePath, &status);

		return (status.st_mode) != 0;
	}
	return false;
}

// 确保输入文件名存在，格式类似..\\xxx\abc.txt
// 返回不重名的文件名，类似 abc(1).txt
string GenerateTheName(string fullname)
{
	int pos_point = fullname.find_last_of('.');
	string file_type = fullname.substr(pos_point + 1);
	string filename_prefix = fullname.substr(0, pos_point);

	bool isExited = true;
	char i = '0';
	while (isExited)
	{
		i = i + 1;
		if (FileExists(fullname.c_str()))
		{
			fullname = filename_prefix + "(" + i + ")." + file_type;
		}
		else
		{
			isExited = false;
		}
	}
	return fullname;
}

int _tmain(int argc, _TCHAR* argv[])
{	
	string fullname = "D:\\text\\1.txt";
	
	cout << "orinal name is :" << fullname << endl;
	cout << "the final name is :" << GenerateTheName(fullname);
	system("pause");
	return 0;
}
