#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
	char arr[] = "Hola queridos amigos";
	std::reverse(std::begin(arr), std::end(arr));

	for (auto i : arr)
		std::cout << i << ' ';
}
