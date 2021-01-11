#include <iostream>
#include <vector>
#include <fstream>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec)
{
	out << vec.size() << '\t' << '|' << '\t';

	for (int i = 0; i < vec.size(); i++)
	{
		out << &vec[i] << ' ';
	}
	out << '\n';
	return out;
}

//std::ostream& operator<<(std::ostream& out, const std::vector<int> vec)
//{
//	out << vec.size() << '\t' << '|' << '\t';
//
//	for (int i = 0; i < vec.size(); i++)
//	{
//		out << &vec[i] << ' ';
//	}
//	out << '\n';
//	return out;
//}

int main() 
{
	const int N = 64;

	std::vector<int> vec;

	std::ofstream data("data.txt", std::ofstream::out | std::ofstream::trunc);
	
	for (int i = 0; i < N; i++)
	{
		vec.push_back(i);
		data << vec;
		std::cout << vec;
	}

	std::cout << "\n\n";
	
	for (int i = N - 1; i > 0; i--)
	{
		vec.pop_back();
		data << vec;
		std::cout << vec;
	}

	data.close();
	return 0;
}