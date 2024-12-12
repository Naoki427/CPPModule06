// #include <iostream>
// #include <limits.h>

// int main() {
// 	float num = 34020;
// 	// size_t j = 1;
// 	for (size_t i = 1; i < 20; i++)
// 	{
// 		num *= 100;
// 		// j  *= 10;
// 		std::cout << num << ", ";
// 	}
// 	return 0;
// }

// #include <iostream>
// #include <float.h>

// int main() {
//     std::cout << "floatの最大値: " << FLT_MAX << std::endl;
//     std::cout << "floatの最小値: " << FLT_MIN << std::endl;
//     std::cout << "doubleの最大値: " << DBL_MAX << std::endl;
//     std::cout << "doubleの最小値: " << DBL_MIN << std::endl;
//     return 0;
// }

#include <iostream>
#include <string>

int main() {
    std::string str = "0000000000000000000000000000000000000";  // 変換対象の文字列
    float num = std::stof(str); // 文字列をfloatに変換

    std::cout << "変換後の値: " << num << std::endl;  // 結果の表示
    return 0;
}