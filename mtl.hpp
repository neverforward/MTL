/*

			MMM              MMM     TTTTTTTTTTTTTTTTTTTTTT   LLL
		   MMMMM          MMMMM     TTTTTTTTTTTTTTTTTTTTTT   LLL
		  MMMMMM        MMMMMM              TTT             LLL
		 MMM MMM     MMM  MMM              TTT             LLL
		MMM  MMM   MMM   MMM              TTT             LLL
	   MMM   MMM MMM    MMM              TTT             LLL
	  MMM     MMM      MMM              TTT             LLL
	 MMM     MMM      MMM              TTT             LLL
	MMM     MMM      MMM              TTT             LLLLLLLLLLLLLLLLLL
   MMM     MMM      MMM	             TTT             LLLLLLLLLLLLLLLLLL

					my template library
╭───┬────────────────────────────────────────────────────────────────────╮
| # |                             MTL                                    |
├───┼───┬────────────────────────────────────────────────────────────────┤
│ 1 |VER│v1.0.6                                                          │
├───┼───┼────────────────────────────────────────────────────────────────┤
| 2 |da │2024/5/30                                                       │
|   |ta │                                                                │
├───┼───┼────────────────────────────────────────────────────────────────┤
│   |   │Q:what is MTL?                                                  │
│   | i │A:MTL (my template library) is a C++ template library, which can|
|   | n | quickly develop C++ programs.                                  │
│ 3 | f │Q:How to use MTL?                                               │
│   | o │A:In C++ programs that require MTL, add #include "mtl.h" to the |
|   |   |    beginning of the file. And all functions are in the namespac|
|   |   |    e mtl, just use the mtl::[function name]                    |
├───┼───┼────────────────────────────────────────────────────────────────┤
|   |   |mtl::print and mtl::println usage instructions:                 |
|   |   |     The syntax is the same as std::printf, and you can use form|
|   |   |     atters such as "%d", "%f", and "%s".                       |
|   | T ├──────────────────────────────────────────────────────────────-─┤
|   | i |mtl::maxs and mtl::mins usage instructions:                     |
| 4 | p |    Because variable-length parameters are used, please do not u|
|   | s |    se arrays                                                   |
|   |   ├──────────────────────────────────────────────────────────────-─┤
|   |   |mtl::algorithm::BinaryTree and mtl::algorithm::Tree usage instru|
|   |   |ctions:                                                         |
|   |   |    Please write your own traversal function!!                  |
├───┼───┼──────────────────────────────────────────────────────────────-─┤
|   | w |Be sure to use Windows!! Otherwise, the help function           |
| 5 | a |cannot be used!!                                                |
|   | r |Be sure to use Windows!! Otherwise, the help function           |
|   | n |cannot be used!!                                                |
├───┼───┼──────────────────────────────────────────────────────────────-─┤
| # |   |                         MTL                                    |
╰───┴───┴────────────────────────────────────────────────────────────────╯

*/
#pragma once



#include "mtl_def.hpp"
// mtl(my template library)
namespace mtl
{
	// 边长型参会吧？
	void print(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
	}
	void println(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		print("\n");
		va_end(args);
	}
#ifdef _WIN32

	// 暂停程序
	char pass[[deprecated("error")]] ()
	{
		mtl::println("Please press any key to continue...");
		return _getch();
	}
#endif
	// 求n个数的和
	template <typename T>
	double adds(const T& init, const T& value, ...)
	{
		return (init + value);
	}
	// 最大值
	template <typename T1, typename T2>
	double max(T1 a, T2 b)
	{
		return a > b ? a : b;
	}
	// 最小值
	template <typename T1, typename T2>
	double min(T1 a, T2 b)
	{
		return a < b ? a : b;
	}
	// 多个数求最大值
	template <typename T, typename... Args>
	double maxs(T a, Args... args)
	{
		double max = a;
		for (auto& arg : { args... })
			max = (arg > max ? arg : max);
		return max;
	}
	// 多个数求最小值
	template <typename T, typename... Args>
	double mins(T a, Args... args)
	{
		double min = a;
		for (auto& arg : { args... })
			min = (arg < min ? arg : max);
		return min;
	}
	// 高斯求和
	long gaussian_sum(int n)
	{
		int sum = 0;
		for (int i = 0; i <= n; i++)
		{
			sum += i;
		}
		return sum;
	}
	// 判断是否是回文
	bool isPalindromic(const char* str)
	{
		size_t len = strlen(str);
		for (size_t i = 0; i < len / 2; i++)
		{
			if (str[i] != str[len - i - 1])
				return false;
		}
		return true;
	}
	// 判断是否是回文
	bool isPalindromic(int num)
	{
		char str[20];
		// sprintf(str, "%d", num);	
		sprintf_s(str,"%d" ,num);
		return isPalindromic(str);
	}
	//
	inline namespace types
	{

		// 类型判断
		type_t type(unsigned int a)
		{
			return mtl::types::type_t::unsigned_int_t;
		}

		type_t type(signed int a)
		{
			return mtl::types::type_t::signed_int_t;
		}

		type_t type(unsigned short a)
		{
			return mtl::types::type_t::unsigned_short_t;
		}

		type_t type(signed short a)
		{
			return mtl::types::type_t::signed_short_t;
		}

		type_t type(unsigned long a)
		{
			return mtl::types::type_t::unsigned_long_t;
			;
		}

		type_t type(signed long a)
		{
			return mtl::types::type_t::signed_long_t;
		}

		type_t type(unsigned long long a)
		{
			return mtl::types::type_t::unsigned_long_long_t;
		}

		type_t type(signed long long a)
		{
			return mtl::types::type_t::signed_long_long_t;
		}

		type_t type(float a)
		{
			return mtl::types::type_t::float_t;
		}

		type_t type(double a)
		{
			return mtl::types::type_t::double_t;
		}

		type_t type(long double a)
		{
			return mtl::types::type_t::long_double_t;
		}

		type_t type(char a)
		{
			return mtl::types::type_t::char_t;
		}
		// 类型
		typedef unsigned int uint_t;
		typedef signed int sint_t;
		typedef unsigned int* puint_t;
		typedef signed int* psint_t;
		typedef int default_t;
		typedef int* pdefault_t;

		typedef unsigned short ushort_t;
		typedef signed short sshort_t;
		typedef unsigned short* pushort_t;
		typedef signed short* psshort_t;
		typedef short small_t;
		typedef short* psmall_t;

		typedef unsigned long ulong_t;
		typedef signed long slong_t;
		typedef unsigned long* pulong_t;
		typedef signed long* pslong_t;
		typedef long big_t;
		typedef long* pbig_t;

		typedef unsigned long long ulong_long_t;
		typedef signed long long slong_long_t;
		typedef unsigned long long* pulong_long_t;
		typedef signed long long* pslong_long_long_t;
		typedef long long biggest_t;
		typedef long long* pbiggest_t;

		typedef float decimal_t;
		typedef float* pdecimal_t;

		typedef double big_decimal_t;
		typedef double* pbig_decimal_t;

		typedef long double biggest_decimal_t;
		typedef long double* pbiggest_decimal_t;

		typedef unsigned char uchar_t;
		typedef signed char schar_t;
		typedef char charecter_t;
		typedef char* str_t;
		typedef char* pchar_t;
		typedef char16_t unicode16_t;
		typedef char32_t unicode32_t;
		// c++20后定义了char8_t,使用UTF-8
#if defined(__cplusplus) && __cplusplus >= 202002L
		typedef char8_t unicode8_t;
#endif
	}
	inline namespace number
	{
		template <typename Tp_>
		static constexpr Tp_ pi = 3.141592653589793;

		template <typename Tp_>
		static constexpr Tp_ tua = 6.283185307179586;

		template <typename Tp_>
		static constexpr Tp_ e = 2.718281828459045;

		template <typename Tp_>
		static constexpr Tp_ phi = 1.618033988749894;
	}

	inline namespace math
	{
		// 正方形面积
		int squareArea(int a)
		{
			return a * a;
		}
		// 正方形周长
		int squarePerimeter(int a)
		{
			return a * 4;
		}
		// 矩形面积
		int rectangleArea(int a, int b)
		{
			return a * b;
		}
		// 矩形周长
		int rectanglePerimeter(int a, int b)
		{
			return (a + b) * 2;
		}
		// BMI
		int BMI(int high, int kg)
		{
			return (kg / high) * (kg / high);
		}
		// 圆的面积
		double circularArea(int r)
		{
			return pi<double> * r * r;
		}
		// 圆的周长
		double circlePerimeter(int r)
		{
			return 2 * pi<double> * r;
		}
		// 三角形面积
		int triangleArea(int a, int b)
		{
			return a * b / 2;
		}
		// 三角形周长
		int trianglePerimeter(int a, int b, int c)
		{
			return a + b + c;
		}
		// 梯形面积
		int trapezoidalArea(int a, int b, int c)
		{
			return (a + b) * c / 2;
		}
		// 梯形周长
		int trapezoidalPerimeter(int a, int b, int c, int d)
		{
			return a + b + c + d;
		}
		// 加法
		int add(int a, int b)
		{
			return a + b;
		}
		// 减法
		int sub(int a, int b)
		{
			return a - b;
		}
		// 乘法
		int mul(int a, int b)
		{
			return a * b;
		}
		// 除法
		int div(int a, int b)
		{
			return a / b;
		}
		// 取余
		int mod(int a, int b)
		{
			return a % b;
		}
		long long pow(long long a, long long b)
		{
			if (b < 0)
			{
				// 处理负指数的情况，根据定义，a 的 -b 次幂等于 1 / a 的 b 次幂
				a = 1 / a;
				b = -b;
			}

			long long result = 1;
			while (b > 0)
			{
				// 如果 b 是奇数，那么 a 的 b 次幂等于 a 的 (b / 2) 次幂的平方
				// 如果 b 是偶数，那么 a 的 b 次幂等于 a 的 (b / 2) 次幂的平方再乘以 a
				if (b % 2 == 1)
				{
					result *= a;
				}
				a *= a; // a 的平方
				b /= 2; // b 除以 2
			}
			return result;
		}

		// 斐波那契数列
		int fib(int n)
		{
			if (n == 1 || n == 2)
			{
				return 1;
			}
			return fib(n - 1) + fib(n - 2);
		}
		// 最大公约数
		int gcd(int a, int b)
		{
			while (b != 0)
			{
				int t = b;
				b = a % b;
				a = t;
			}
			return a;
		}
		// 最小公倍数
		int lcm(int a, int b)
		{
			return a * b / gcd(a, b);
		}
		// 绝对值
		int abs(int n)
		{
			return n < 0 ? -n : n;
		}
		// 阶乘
		int factorial(int n)
		{
			int result = 1;
			for (int i = 1; i <= n; i++)
			{
				result *= i;
			}
			return result;
		}

	}
	inline namespace charecter
	{
		// 判断是否为字母
		bool isAlpha(char c)
		{
			return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
		}
		// 判断是否为数字
		bool isDigit(char c)
		{
			return c >= '0' && c <= '9';
		}
		// 判断是否为字母或数字
		bool isAlnum(char c)
		{
			return isAlpha(c) || isDigit(c);
		}
		// 判断是否为空格
		bool isSpace(char c)
		{
			return c == ' ' || c == '\t' || c == '\n' || c == '\r';
		}
		// 判断是否为小写字母
		bool isLower(char c)
		{
			return c >= 'a' && c <= 'z';
		}
		// 判断是否为大写字母
		bool isUpper(char c)
		{
			return c >= 'A' && c <= 'Z';
		}
		// 判断是否为字母
		bool isLetter(char c)
		{
			return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
		}
		// 将字符转换为ASCII码
		int toAscii(char c)
		{
			return int(c);
		}
		// 将字符转换为小写字母
		char toLower(char c)
		{
			return isUpper(c) ? (c - 'A' + 'a') : c;
		}
		// 将字符转换为大写字母
		char toUpper(char c)
		{
			return isLower(c) ? (c - 'a' + 'A') : c;
		}
		// 将ASCII码转换为字符
		char toChar(int c)
		{
			return char(c);
		}
	}
	inline namespace algorithm
	{
		// 冒泡排序
		void bubbleSort(int* arr, int n)
		{
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = 0; j < n - i - 1; j++)
				{
					if (arr[j] > arr[j + 1])
					{
						int temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		}
		// 选择排序
		void selectionSort(int* arr, int n)
		{
			for (int i = 0; i < n - 1; i++)
			{
				int minIndex = i;
				for (int j = i + 1; j < n; j++)
				{
					if (arr[j] < arr[minIndex])
					{
						minIndex = j;
					}
				}
				if (minIndex != i)
				{
					int temp = arr[i];
					arr[i] = arr[minIndex];
					arr[minIndex] = temp;
				}
			}
		}
		// 插入排序
		void insertionSort(int* arr, int n)
		{
			for (int i = 1; i < n; i++)
			{
				int key = arr[i];
				int j = i - 1;
				while (j >= 0 && arr[j] > key)
				{
					arr[j + 1] = arr[j];
					j--;
				}
				arr[j + 1] = key;
			}
		}
		// 快速排序
		void quickSort(int* arr, int low, int high)
		{
			if (low < high)
			{
				int pivot = arr[low];
				int i = low, j = high;
				while (i < j)
				{
					while (i < j && arr[j] >= pivot)
						j--;
					if (i < j)
						arr[i++] = arr[j];
					while (i < j && arr[i] < pivot)
						i++;
					if (i < j)
						arr[j--] = arr[i];
				}
				arr[i] = pivot;
				quickSort(arr, low, i - 1);
				quickSort(arr, i + 1, high);
			}
			return;
		}
		void heapify(int* arr, int n, int i);
		// 堆排序
		void heapSort(int* arr, int n)
		{
			for (int i = n / 2 - 1; i >= 0; i--)
			{
				heapify(arr, n, i);
			}
			for (int i = n - 1; i > 0; i--)
			{
				int temp = arr[0];
				arr[0] = arr[i];
				arr[i] = temp;
				heapify(arr, i, 0);
				return;
			}
		}
		void heapify(int* arr, int n, int i)
		{
			int largest = i;
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			if (left < n && arr[left] > arr[largest])
				largest = left;
			if (right < n && arr[right] > arr[largest])
				largest = right;
			if (largest != i)
			{
				int temp = arr[i];
				arr[i] = arr[largest];
				arr[largest] = temp;
				heapify(arr, n, largest);
			}
		}
		// 二分法
		int binary_search(int arr[], int l, int r, int x)
		{
			while (l <= r)
			{
				int mid = l + (r - l) / 2; // 预防整数溢出
				if (x > arr[mid])
				{
					l = mid + 1;
				}
				else if (x < arr[mid])
				{
					r = mid - 1;
				}
				else
				{
					return mid + 1; // 找到元素，返回位置加一
				}
			}
			return -1; // 未找到元素，返回-1
		}
		// 线性查找
		int linear_search(int arr[], int n, int x)
		{
			for (int i = 0; i < n; i++)
			{
				if (arr[i] == x)
				{
					return i;
				}
			}
			return -1;
		}
		// 倒序
		void reverse(int arr[], int n)
		{
			for (int i = 0; i < n / 2; i++)
			{
				int temp = arr[i];
				arr[i] = arr[n - i - 1];
				arr[n - i - 1] = temp;
			}
		}

		// 判断所有参数是否都为真
		bool all(int first, ...)
		{
			va_list args;
			va_start(args, first);
			int arg = first;
			while (true)
			{
				arg = va_arg(args, int);
				if (!arg)
				{
					va_end(args);
					return false;
				}
				if (arg == int(false))
				{
					va_end(args);
					return true;
				}
			}
		}

		// 判断所有参数是否都为假
		bool none(int first, ...)
		{
			va_list args;
			va_start(args, first);
			int arg = first;
			while (true)
			{
				arg = va_arg(args, int);
				if (arg)
				{
					va_end(args);
					return false;
				}
				if (arg == int(true))
				{
					va_end(args);
					return true;
				}
			}
		}
		// 奇数
		bool odd(int n)
		{
			return n & 1;
		}
		// 偶数
		bool even(int n)
		{
			return !(n & 1);
		}
		// 转换为格雷码
		int toGray(int n)
		{
			return n ^ (n >> 1);
		}
		// 格雷码转换回二进制码
		int GreycodetoBinary(int n)
		{
			int binary = 0;
			int i = 0;
			while (n > 0)
			{
				binary += (n & 1) << i;
				n >>= 1;
				i++;
			}
			return binary;
		}
		// 转二进制
		int toBin(int n)
		{
			int binary = 0;
			while (n > 0)
			{
				binary = (n & 1) + binary * 10;
				n >>= 1;
			}
			return binary;
		}
		// 转八进制
		int toOct(int n)
		{
			int octal = 0;
			int i = 0;
			while (n > 0)
			{
				octal = (n & 7) + octal * 10;
				n >>= 3;
				i++;
			}
			return octal;
		}
		// 转十六进制
		int toHex(int n)
		{
			int hex = 0;
			int i = 0;
			while (n > 0)
			{
				hex = (n & 15) + hex * 10;
				n >>= 4;
				i++;
			}
			return hex;
		}
		int* prefix_sum(int arr[], int n)
		{
			int* sun = (int*)malloc(sizeof(int) * (n + 1));
			for (int i = 0; i < n; i++)
			{
				sun[i + 1] = sun[i] + arr[i];
			}
			sun[0] = 0; // 初始化第一个元素为0
			return sun;
		}
		// 区间和
		int* range_sum(int arr[], int l, int r)
		{
			int* sun = new int[r + 1];
			for (int i = l; i < r; i++)
			{
				sun[i + 1] = sun[i] + arr[i];
			}
			return sun;
		}
		// 前缀和(二维数组)
		// 计算二维数组的前缀和
		int** prefix_sum(int** arr, int n)
		{
			int** sun = (int**)0;
			for (int i = 0; i < n; i++)
			{
				sun[i + 1] = (int*)malloc(sizeof(int) * (n + 1));
				for (int j = 0; j < n; j++)
				{
					sun[i + 1][j + 1] = sun[i][j + 1] + sun[i + 1][j] + arr[i][j] - sun[i][j];
					if (i == 0 && j == 0)
					{
						sun[i + 1][j + 1] = arr[i][j];
					}
				}
			}
			sun[0][0] = 0; // 初始化左上角为0
			return sun;
		}
		// 区间和(二维数组)
		int** range_sum(int** arr, int l1, int r1, int l2, int r2)
		{
			int** sun = new int* [r2 + 1];
			for (int i = l1; i < r1; i++)
			{
				sun[i + 1] = new int[r1 + 1];
				for (int j = l2; j < r2; j++)
				{
					sun[i + 1][j + 1] = sun[i][j + 1] + sun[i + 1][j] + arr[i][j] - sun[i][j];
					if (i == 0 && j == 0)
					{
						sun[i + 1][j + 1] = arr[i][j];
					}
					if (i == 0 && j == 0)
					{
						sun[i + 1][j + 1] = arr[i][j];
					}
				}
			}
			return sun;
		}

		// 二叉树
		template <typename T>
		struct BinaryTree
		{
			T data;
			BinaryTree* left;
			BinaryTree* right;
			BinaryTree(T data) : data(data), left(nullptr), right(nullptr) {}
		};
		// 树
		template <typename T>
		struct Tree
		{
			T data;
			Tree* clilds[100];
			Tree(T data) : data(data) {}
		};
		// 图
		template <typename T>
		struct Graph
		{
			T data;
			Graph* edges[100];
			Graph(T data) : data(data) {}
		};
		// maxmin<int>
		template <>
		struct maxmin<int> {
			static constexpr int max() noerror {
				return 0b1111111111111111111111111111111;
			}
			static constexpr int min() noerror {
				return -0b1111111111111111111111111111111;
			}
			static constexpr int bit() noerror {
				return sizeof(int);
			}
		};
		// maxmin<signed int>
		template <>
		struct maxmin<unsigned int> {
			static constexpr unsigned int max() noerror {
				return 0b11111111111111111111111111111111;
			}
			static constexpr unsigned int min() noerror {
				return 0;
			}
			static constexpr int bit() noerror {
				return sizeof(unsigned int);
			}
		};
		// maxmin<short>
		template <>
		struct maxmin<short> {
			static constexpr short max() noerror {
				return 0b111111111111111;
			}
			static constexpr short min() noerror {
				return -0b111111111111111;
			}
			static constexpr int bit() noerror {
				return sizeof(short);
			}
		};
		// maxmin<unsigned short>
		template <>
		struct maxmin<unsigned short> {
			static constexpr unsigned short max() noerror {
				return 0b1111111111111111;
			}
			static constexpr unsigned short min() noerror {
				return 0;
			}
			static constexpr int bit() noerror {
				return sizeof(unsigned short);
			}
		};
		// maxmin<long>
		template <>
		struct maxmin<long> {
			static constexpr long max() noerror {
				return 0b1111111111111111111111111111111;
			}
			static constexpr long min() noerror {
				return -0b1111111111111111111111111111111;
			}
			static constexpr int bit() noerror {
				return sizeof(long);
			}
		};
		// maxmin<unsigned long>
		template <>
		struct maxmin<unsigned long> {
			static constexpr unsigned long max() noerror {
				return 0b11111111111111111111111111111111;
			}
			static constexpr unsigned long min() noerror {
				return 0;
			}
			static constexpr int bit() noerror {
				return sizeof(unsigned long);
			}
		};
		// maxmin<long long>
		template <>
		struct maxmin<long long> {
			static constexpr long long max() noerror {
				return 0b111111111111111111111111111111111111111111111111111111111111111;
			}
			static constexpr long long min() noerror {
				return -0b111111111111111111111111111111111111111111111111111111111111111;
			}
			static constexpr int bit() noerror {
				return sizeof(long long);
			}
		};
		// maxmin<unsigned long long>
		template <>
		struct maxmin<unsigned long long> {
			static constexpr unsigned long long max() noerror {
				return 0b1111111111111111111111111111111111111111111111111111111111111111;
			}
			static constexpr unsigned long long min() noerror {
				return 0;
			}
			static constexpr int bit() noerror {
				return sizeof(unsigned long long);
			}
		};
		// maxmin<float>
		template <>
		struct maxmin<float> {
			static constexpr float max() noerror {
				return (float)(3.402823466e+38);
			}
			static constexpr float min() noerror {
				return (float)(-3.402823466e+38);
			}
			static constexpr int bit() noerror {
				return sizeof(float);
			}
		};
		// maxmin<double>
		template <>
		struct maxmin<double> {
			static constexpr double max() noerror {
				return 1.7976931348623158e+308;
			}
			static constexpr double min() noerror {
				return -1.7976931348623158e+308;
			}
			static constexpr int bit() noerror {
				return sizeof(double);
			}
		};
		// maxmin<char>
		template <>
		struct maxmin<char> {
			static constexpr char max() noerror {
				return (char)(128);
			}
			static constexpr char min() noerror {
				return (char)(-128);
			}
			static constexpr int bit() noerror {
				return sizeof(char);
			}
		};
		// maxmin<char32_t>
		template <>
		struct maxmin<char32_t> {
			static constexpr char32_t max() noerror {
				return (char32_t)(0b1111111111111111111111111111111);
			}
			static constexpr char32_t min() noerror {
				return (char32_t)(-0b1111111111111111111111111111111);
			}
			static constexpr int bit() noerror {
				return sizeof(char32_t);
			}
		};
		// maxmin<char16_t>
		template <>
		struct maxmin<char16_t> {
			static constexpr char16_t max() noerror {
				return (char16_t)(0b111111111111111);
			}
			static constexpr char16_t min() noerror {
				return (char16_t)(-0b111111111111111);
			}
			static constexpr int bit() noerror {
				return sizeof(char16_t);
			}
		};
#if defined(__cplusplus) && __cplusplus >= 202002L
		// maxmin<char8_t>
		template <>
		struct maxmin<char8_t> {
			static constexpr char8_t max() noerror {
				return (char8_t)(0b1111111);
			}
			static constexpr char8_t min() noerror {
				return (char8_t)(-0b1111111);
			}
			static constexpr int bit() noerror {
				return sizeof(char8_t);
			}
		};
#endif
		// true_t
		struct true_t {
			static constexpr bool value = true;
			static constexpr bool no = false;
		};
		// false_t
		struct false_t {
			static constexpr bool value = false;
			static constexpr bool no = true;
		};
		// two
		struct twoval {
			int a;
			int b;
			twoval(int _a, int _b) { a = _a; b = _b; }
		};
		constexpr bool eq(int a, int b) noerror { return a == b; }
		constexpr bool neq(int a, int b) noerror { return a != b; }
		constexpr bool lt(int a, int b) noerror { return a < b; }
		constexpr bool lteq(int a, int b) noerror { return a <= b; }
		constexpr bool gt(int a, int b) noerror { return a > b; }
		constexpr bool gteq(int a, int b) noerror { return a >= b; }
		template<typename Tp_>
		class operators {
			public:
				operators(Tp_ VAL) { value = VAL; }
				void operator = (int _value) {
					value = _value;
				}
				void operator += (Tp_ _value) {
					value = value + _value;
				}
				void operator -= (Tp_ _value) {
					value = value - _value;
				}
				void operator *= (Tp_ _value) {
					value = value * _value;
				}
				void operator /= (Tp_ _value) {
					value = value / _value;
				}
				void operator %= (Tp_ _value) {
					value = value % _value;
				}
				void operator &= (Tp_ _value) {
					value = value & _value;
				}
				void operator |= (Tp_ _value) {
					value = value | _value;
				}
				void operator ^= (Tp_ _value) {
					value = value ^ _value;
				}
				void operator >>= (Tp_ _value) {
					value = value >> _value;
				}
				void operator <<= (Tp_ _value) {
					value = value << _value;
				}
				void operator ++ () {
					value = value + 1;
				}
				void operator ++ (int) {
					value = value + 1;
				}
				void operator -- () {
					value = value - 1;
				}
				void operator -- (int) {
					value = value - 1;
				}
				bool operator ! () {
					return !value;
				}
				bool operator && (operators _value) {
					return value && _value.value;
				}
				bool operator && (const Tp_ _value) {
					return value && _value;
				}
				bool operator || (operators _value) {
					return value || _value.value;
				}
				bool operator || (const Tp_ _value) {
					return value || _value;
				}
				friend bool operator==(const operators& x, const operators& y) {
					return x.value == y.value;
				}
				friend bool operator==(const Tp_ x, const operators& y) {
					return x == y.value;
				}
				friend bool operator==(const operators& x, const Tp_ y) {
					return x.value == y;
				}

				friend bool operator!=(const operators& x, const operators& y) {
					return x.value != y.value;
				}
				friend bool operator!=(const Tp_ x, const operators& y) {
					return x != y.value;
				}
				friend bool operator==(const operators& x, const Tp_ y) {
					return x.value != y;
				}

				friend bool operator<(const operators& x, const operators& y) {
					return x.value < y.value;
				}
				friend bool operator<(const Tp_ x, const operators& y) {
					return x < y.value;
				}
				friend bool operator<(const operators& x, const Tp_ y) {
					return x.value < y;
				}

				friend bool operator>(const operators& x, const operators& y) {
					return x.value > y.value;
				}
				friend bool operator>(const Tp_ x, const operators& y) {
					return x > y.value;
				}
				friend bool operator>(const operators& x, const Tp_ y) {
					return x.value > y;
				}

				friend bool operator<=(const operators& x, const operators& y) {
					return x.value <= y.value;
				}
				friend bool operator<=(const Tp_ x, const operators& y) {
					return x <= y.value;
				}
				friend bool operator<=(const operators& x, const Tp_ y) {
					return x.value <= y;
				}

				friend bool operator>=(const operators& x, const operators& y) {
					return x.value >= y.value;
				}
				friend bool operator>=(const Tp_ x, const operators& y) {
					return x >= y.value;
				}
				friend bool operator>=(const operators& x, const Tp_ y) {
					return x.value == y;
				}
				Tp_ value;
		};
	}
	// 大字
	namespace big_words
	{
		void A()
		{
			mtl::print(R"(
          AAAAA
         AAA AAA
        AAA   AAA
       AAA     AAA
      AAA       AAA
     AAAAAAAAAAAAAAA
    AAA           AAA
   AAA             AAA
  AAA               AAA
 AAA                 AAA
)");
		}
		void B()
		{
			mtl::print(R"(
BBBBBBBBBBBBBBB
BBB           BBB
BBB            BBB
BBB           BBB
BBBBBBBBBBBBBBBB
BBB           BBB
BBB            BBB
BBB             BBB
BBB            BBB
BBBBBBBBBBBBBBBB
)");
		}
		void C()
		{
			mtl::print(R"(
    CCCCCCCCCCCCCCC
   CCCCCCCCCCCCCCCCC
  CCCC
 CCCC
CCCC
CCCC
 CCCC
  CCCC
   CCCCCCCCCCCCCCCCCC
    CCCCCCCCCCCCCCCC
)");
		}
		void D()
		{
			mtl::print(R"(
DDDDDDDDDDDDDDDDDDD
DDD              DDD
DDD                DDD
DDD                 DDD
DDD                 DDD
DDD                 DDD
DDD                 DDD
DDD                 DDD
DDD               DDD
DDDDDDDDDDDDDDDDDDDD
)");
		}
		void E()
		{
			mtl::print(R"(
EEEEEEEEEEEEEEEEEEEE
EEE
EEE
EEE
EEE
EEEEEEEEEEEEEEEEEEEE
EEE
EEE
EEE
EEEEEEEEEEEEEEEEEEEE
)");
		}
		void F()
		{
			mtl::print(R"(
FFFFFFFFFFFFFFFFFFFF
FFF
FFF
FFF
FFF
FFFFFFFFFFFFFFFFFFFF
FFF
FFF
FFF
FFF
)");
		}
		void G()
		{
			mtl::print(R"(
    GGGGGGGGGGGGGG
   GGG
  GGG
 GGG
GGG
GGG
 GGG         GGGGGGGGG
  GGG              GGG
   GGG            GGG
    GGGGGGGGGGGGGGGG
)");
		}
		void H()
		{
			mtl::print(R"(
HHH            HHH
HHH            HHH
HHH            HHH
HHH            HHH
HHHHHHHHHHHHHHHHHH
HHHHHHHHHHHHHHHHHH
HHH            HHH
HHH            HHH
HHH            HHH
HHH            HHH
)");
		}
		void I()
		{
			mtl::print(R"(
IIIIIIIIIIIIIIIIIII
        III
        III
        III
        III
        III
        III
        III
        III
IIIIIIIIIIIIIIIIIII
)");
		}
		void J()
		{
			mtl::print(R"(
 JJJJJJJJJJJJJJJJJJJ
         JJJ
         JJJ
         JJJ
         JJJ
         JJJ
         JJJ
JJJ      JJJ
 JJJ    JJJ
   JJJJJ
)");
		}
		void K()
		{
			mtl::print(R"(
KKK          KKK
KKK        KKK
KKK      KKK
KKK    KKK
KKKKKKKK
KKK    KKK
KKK      KKK
KKK        KKK
KKK         KKK
KKK          KKK
)");
		}

		void L()
		{
			mtl::print(R"(
LLL
LLL
LLL
LLL
LLL
LLL
LLL
LLL
LLLLLLLLLLLLLLL
LLLLLLLLLLLLLLL
)");
		}
		void N()
		{
			mtl::print(R"(
NNN        NNN
NNNNN      NNN
NNN NNN    NNN
NNN  NNN   NNN
NNN   NNN  NNN
NNN    NNN NNN 
NNN     NNNNNN
NNN      NNNNN
NNN        NNN
NNN        NNN
)");
		}
		void M()
		{
			mtl::print(R"(
MMM               MMM
MMMMM            MMMM
MMM MMM         MMMMM
MMM  MMM       MMMMMM
MMM   MMM     MMM MMM
MMM    MMM   MMM  MMM
MMM     MMM MMM   MMM
MMM      MMMMM    MMM
MMM       MMM     MMM
MMM       MMM     MMM
)");
		}

		void O()
		{
			mtl::print(R"(
      OOOOOOO
    OOO     OOO
  OOO         OOO
 OO             OO
 OO             OO
  OOO         OOO
    OOO     OOO
      OOOOOOO     
)");
		}
		void P()
		{
			mtl::print(R"(
PPPPPPPPPPPPPPPP
PPP            PPP
PPP             PPP   
PPP            PPP
PPP           PPP
PPPPPPPPPPPPPPP
PPP
PPP
PPP
PPP
)");
		}
		void Q()
		{
			mtl::print(R"(
      QQQQQQQ
    QQQ     QQQ
  QQQ        QQQ
QQQ            QQQ
QQQ            QQQ
  QQQ   QQQ   QQQ
    QQQ   QQQQQ
      QQQQQQQQ   
            QQQ
)");
		}
		void R()
		{
			mtl::print(R"(
RRRRRRRRRRR
RRR       RRR
RRR        RRR
RRR       RRR
RRRRRRRRRRRR
RRRRRR
RRR RRR
RRR   RRR
RRR     RRR
RRR       RRR
)");
		}
		void S()
		{
			mtl::print(R"(
    SSSSSSSSSSSSSSS
 SSS
SSS
  SSS
   SSS
    SSSSSSSSSSSSSSSS
                  SSS
                   SSS
                  SSS
    SSSSSSSSSSSSSSSSS
)");
		}
		void T()
		{
			mtl::print(R"(
TTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTT
        TTT
        TTT
        TTT
        TTT
        TTT
        TTT
        TTT
        TTT
)");
		}
		void U()
		{
			mtl::print(R"(
UUU                UUU
UUU                UUU
UUU                UUU
UUU                UUU
UUU                UUU
UUU                UUU
 UUU              UUU
  UUU            UUU
   UUUUUUUUUUUUUUUU
    UUUUUUUUUUUUUU
)");
		}
		void V()
		{
			mtl::print(R"(
VVV                 VVV
 VVV               VVV
  VVV             VVV
   VVV           VVV
    VVV         VVV 
     VVV       VVV
      VVV     VVV
       VVV   VVV
        VVV VVV
         VVVVV
)");
		}
		void W()
		{
			mtl::print(R"(
WWW       WWWWW       WWW
WWW       WWWWW       WWW
 WWW     WWW WWW     WWW
 WWW     WWW WWW     WWW
  WWW   WWW   WWW   WWW
  WWW   WWW   WWW   WWW
   WWW WWW     WWW WWW
   WWW WWW     WWW WWW
    WWWWW       WWWWW
    WWWWW       WWWWW
)");
		}
		void X()
		{
			mtl::print(R"(
XXX               XXX
  XXX           XXX
    XXX       XXX
      XXX   XXX
        XXXXX
        XXXXXX
      XXX    XXX
    XXX       XXX
  XXX           XXX
XXX               XXX
)");
		}
		void Y()
		{
			mtl::print(R"(
YYY             YYY
  YYY         YYY
    YYY     YYY
      YYY YYY
       YYYYY
        YYY
        YYY
        YYY
        YYY
        YYY
)");
		}
		void Z()
		{
			mtl::print(R"(
ZZZZZZZZZZZZZZZZZZZZ
                 ZZZ
               ZZZ
             ZZZ
           ZZZ
         ZZZ
       ZZZ
     ZZZ
   ZZZ
ZZZZZZZZZZZZZZZZZZZZ
)");
		}
		void one()
		{
			mtl::print(R"(
        1111111
            111
            111
            111
            111
            111
            111
            111
            111
            111
        11111111111
)");
		}
		void two()
		{
			mtl::print(R"(
22222222222222222222
                 222
                 222
                 222
22222222222222222222
222
222
222
222
22222222222222222222
)");
		}
		void three()
		{
			mtl::print(R"(
33333333333333333333
                 333
                 333
                 333
33333333333333333333
                 333
                 333
                 333
                 333
33333333333333333333
)");
		}
		void four()
		{
			mtl::print(R"(
444           444
444           444
444           444
444           444
4444444444444444444
              444
              444
              444
              444
              444
)");
		}
		void five()
		{
			mtl::print(R"(
5555555555555555555
555
555
555
5555555555555555555
                555
                555
                555
                555
5555555555555555555
)");
		}
		void six()
		{
			mtl::print(R"(
6666666666666666666
666                
666
666
6666666666666666666
666             666
666             666
666             666
666             666
6666666666666666666
)");
		}
		void seven()
		{
			mtl::print(R"(
77777777777777777777
                 777
                 777
                 777
                 777
                 777
                 777
                 777
                 777
                 777
)");
		}
		void eight()
		{
			mtl::print(R"(
88888888888888888888
888              888
888              888
888              888
88888888888888888888
888              888
888              888
888              888
888              888
88888888888888888888
)");
		}
		void nine()
		{
			mtl::print(R"(
99999999999999999999
999              999
999              999
999              999
99999999999999999999
                 999
                 999
                 999
                 999
99999999999999999999
)");
		}
		void zero()
		{
			mtl::print(R"(
00000000000000000000
000              000
000              000
000              000
000              000
000              000
000              000
000              000
000              000
00000000000000000000
)");
		}
	}
	// 信息
	inline namespace informations
	{
		// 版本
		void version()
		{
			mtl::println(R"(
            MMM              MMM     TTTTTTTTTTTTTTTTTTTTTT   LLL
           MMMMM          MMMMM     TTTTTTTTTTTTTTTTTTTTTT   LLL
          MMMMMM        MMMMMM              TTT             LLL
         MMM MMM     MMM  MMM              TTT             LLL
        MMM  MMM   MMM   MMM              TTT             LLL
       MMM   MMM MMM    MMM              TTT             LLL
      MMM     MMM      MMM              TTT             LLL
     MMM     MMM      MMM              TTT             LLL
    MMM     MMM      MMM              TTT             LLLLLLLLLLLLLLLLLL
   MMM     MMM      MMM	             TTT             LLLLLLLLLLLLLLLLLL
)");
			mtl::println(R"(
╭───┬────────────────────╮
│ # │      MTL           │
├───┼────────────────────┤
│ 1 │MTL Version: 1.0.6  │
├───┼────────────────────┤
│ 2 │data: 2024/5/30     │
╰───┴────────────────────╯
)");
		}
		// 帮助

		void help()
		{
#ifdef _WIN32
			mtl::println("Please turn on README.txt\nhelp now?\n\nplease press h, else press other key.");
			if (_getch() == 'h')
			{
#endif
				mtl::println(R"(
╭────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
│                                             MTL Library - Functions                                                    │
├──────┬─────────────────────────────┬───────────────────────────────────────┬─────────────┬─────────────────────────────┤
│     #│                Function name│                            Description│Return type  │                     Examples│
├──────┼─────────────────────────────┼───────────────────────────────────────┼─────────────┼─────────────────────────────┤
│     1│                        print│Print something to the stdout          │         void│             print("%d",123);│
│     2│                      println│Print something to the stdout&end line │         void│           println("%d",123);│
│     3│                         pass│Stop program                           │         void│                      pass();│
│     4│                         adds│Find the sum of n numbers              │       double│                 adds(1,2,3);│
│     5│                          max│Find the max of 2 numbers              │       double│                    max(1,2);│
│     6│                          min│Find the min of 2 numbers              │       double│                    min(1,2);│
│     7│                         mins│Find the min of n numbers              │       double│                   mins(1,2);│
│     8│                         maxs│Find the max of n numbers              │       double│                   maxs(1,2);│ 
│     9│                 gaussian_sum│Gaussian sum                           │         long│             gaussian_sum(5);│
│    10│                isPalindromic│Is palindromic                         │         bool│       isPalindromic("abba");│
│    11│                         type│Get type of a variable                 │       type_t│                     type(1);│
│    12│                   squareArea│square area                            │          int│               squareArea(2);│
│    13│              squarePerimeter│square perimeter                       │          int│          squarePerimeter(2);│
│    14│                rectangleArea│rectangle area                         │          int│          rectangleArea(2,3);│
│    15│           rectanglePerimeter│rectangle perimeter                    │          int│     rectanglePerimeter(2,3);│
│    16│                   circleArea│circle area                            │       double│                circleArea(2)│
│    17│              circlePerimeter│circle perimeter                       │       double│           circlePerimeter(2)│
│    18│                 triangleArea│triangle area                          │          int│            triangleArea(2,3)│
│    19│            trianglePerimeter│triangle perimeter                     │          int│       trianglePerimeter(2,3)│
│    20│                          BIM│BIM                                    │          int│                 BIM(50,130);│
│    21│              trapezoidalArea│trapezoidal area                       │          int│      trapezoidalArea(1,2,3);│
│    22│         trapezoidalPerimeter│                                       │          int│ trapezoidalPerimeter(1,2,3);│
│    23│                          add│add 2 numbers                          │          int│                    add(1,2);│
│    24│                          sub│sub 2 numbers                          │          int│                    sub(1,2);│
│    25│                          mul│mul 2 numbers                          │          int│                    mul(1,2);│
│    26│                          div│div 2 numbers                          │          int│                    div(1,2);│
│    27│                          mod│mod 2 numbers                          │          int│                    mod(1,2);│
│    28│                          pow│pow 2 numbers                          │    long long│                    pow(1,2);│
│    29│                          fib│fib                                    │          int│                    fib(1,2);│
│    30│                          gcd│gcd                                    │          int│                    gcd(1,2);│
│    31│                          lcm│lcm                                    │          int│                    lcm(1,2);│
│    32│                          abs│abs                                    │          int│                      abs(1);│
│    33│                    factorial│factorial                              │          int│                factorial(1);│
│    34│                      isAlpha│is alpha                               │         bool│                isAlpha('a');│
│    35│                      isAlNum│is alNum                               │         bool│                isAlNum('a');│
│    36│                      isLower│is lower                               │         bool│                isLower('a');│
│    37│                      isUpper│is upper                               │         bool│                isUpper('A');│
│    38│                      isSpace│is space                               │         bool│                isSpace(' ');│
│    39│                      isDight│is dight                               │         bool│                isDight('1');│
│    40│                     isLetter│is Letter                              │         bool│                isLetter('1);│
│    41│                      toAscii│to ascii code                          │          int│                toAscii('a');│
│    42│                       toChar│to char                                │          int│                  toChar(97);│
│    43│                      toLower│to lower                               │          int│                toLower('A');│
│    44│                      toUpper│to upper                               │          int│                toUpper('a');│
│    45│                   bubbleSort│bubble sort                            │         void│   bubbleSort({1,2,3,4,5},5);│
│    46│                selectionSort│selection sort                         │         void│selectionSort({1,2,3,4,5},5);│
│    47│                insertionSort│insertion sort                         │         void│insertionSort({1,2,3,4,5},5);│
│    48│                    quickSort│merge sort                             │         void│  quickSort({1,2,3,4,5},1,1);│
│    49│                     heapSort│heap sort                              │         void│     heapSort({1,2,3,4,5},5);│
│    50│                binary_search│binary search                          │          int│binary_search({1,2,5},0,3,5);│
│    51│                linear_search│linear search                          │          int│linear_search({1,2,5},0,3,5);│
│    52│                      reverse│reverse list                           │         void│      reverse({1,2,3,4,5},5);│
│    53│                          all│all true                               │         bool│                  all(1,1,0);│
│    54│                         none│none true                              │         bool│                 none(1,1,0);│
│    55│                          odd│is odd                                 │         bool│                      odd(1);│
│    56│                         even│is even                                │         bool│                     even(1);│
│    57│                       toGrey│to grey                                │          int│                 toGrey(255);│
│    58│             GreycodetoBinary│grey code to binary                    │          int│         GreycodetoBinary(1);│
│    59│                        toBin│to bin                                 │          int│                    toBin(1);│
│    60│                        toOct│to oct                                 │          int│                    toOct(1);│
│    61│                        toHex│to hex                                 │          int│                    toHex(1);│
│    62│                   prefix_sum│prefix sum                             │int* or int**│   prefix_sum({1,2,3,4,5},5);│
│    63│                    range_sum│range sum                              │int* or int**│  range_sum({1,2,3,4,5},3,4);│
│    64│                            A│print A                                │         void│                         A();│
│    65│                            B│print B                                │         void│                         B();│
│    66│                            C│print C                                │         void│                         C();│
│    67│                            D│print D                                │         void│                         D();│
│    68│                            E│print E                                │         void│                         E();│
│    69│                            F│print F                                │         void│                         F();│
│    70│                            G│print G                                │         void│                         G();│
│    71│                            H│print H                                │         void│                         H();│
│    72│                            I│print I                                │         void│                         I();│
│    73│                            J│print J                                │         void│                         J();│
│    74│                            K│print K                                │         void│                         K();│
│    75│                            L│print L                                │         void│                         L();│
│    76│                            M│print M                                │         void│                         M();│
│    77│                            N│print N                                │         void│                         N();│
│    78│                            O│print O                                │         void│                         O();│
│    79│                            P│print P                                │         void│                         P();│
│    80│                            Q│print Q                                │         void│                         Q();│
│    81│                            R│print R                                │         void│                         R();│
│    82│                            S│print S                                │         void│                         S();│
│    83│                            T│print T                                │         void│                         T();│
│    84│                            U│print U                                │         void│                         U();│
│    85│                            V│print V                                │         void│                         V();│
│    86│                            W│print W                                │         void│                         W();│
│    87│                            X│print X                                │         void│                         X();│
│    88│                            Y│print Y                                │         void│                         Y();│
│    89│                            Z│print Z                                │         void│                         Z();│
│    90│                          one│print 1                                │         void│                       one();│
│    91│                          two│print 2                                │         void│                       two();│
│    92│                        three│print 3                                │         void│                     three();│
│    93│                         four│print 4                                │         void│                      four();│
│    94│                         five│print 5                                │         void│                      five();│
│    95│                          six│print 6                                │         void│                       six();│
│    96│                        seven│print 7                                │         void│                     seven();│
│    97│                        eight│print 8                                │         void│                     eight();│
│    98│                         nine│print 9                                │         void│                      nine();│
│    99│                         zero│print 0                                │         void│                      zero();│
│   100│                      version│print version                          │         void│                   version();│
├──────┼─────────────────────────────┼───────────────────────────────────────┼─────────────┼─────────────────────────────┤
│     #│                Function name│                            Description│Return type  │                     Examples│
╰──────┴─────────────────────────────┴───────────────────────────────────────┴─────────────┴─────────────────────────────╯)");
				mtl::print(R"(



╭────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
│                                             MTL Library - Types                                                        │
├──────┬─────────────────────────────┬─────────────────────────────────────────────────┬─────────────────────────────────┤
│     #│                    type name│                   info                          │                    Original type│
├──────┼─────────────────────────────┼─────────────────────────────────────────────────┼─────────────────────────────────┤
│     1│                       uint_t│                    --                           │                     unsigned int│
│     2│                       sint_t│                    --                           │                       signed int│
│     3│                      puint_t│                    --                           │                    unsigned int*│
│     4│                      psint_t│                    --                           │                      signed int*│
│     5│                    default_t│                    --                           │                              int│
│     6│                   pdefault_t│                    --                           │                             int*│
│     7│                     ushort_t│                    --                           │                   unsigned short│
│     8│                     sshort_t│                    --                           │                     signed short│
│     9│                    pushort_t│                    --                           │                  unsigned short*│
│    10│                    psshort_t│                    --                           │                    signed short*│
│    11│                      small_t│                    --                           │                            short│
│    12│                     psmall_t│                    --                           │                           short*│
│    13│                      ulong_t│                    --                           │                     unsignd long│
│    14│                      slong_t│                    --                           │                      signed long│
│    15│                     pulong_t│                    --                           │                   unsigned long*│
│    16│                     pslong_t│                    --                           │                     signed long*│
│    17│                        big_t│                    --                           │                             long│
│    18│                       pbig_t│                    --                           │                            long*│
│    19│                 ulong_long_t│                    --                           │               unsigned long long│
│    20│                 slong_long_t│                    --                           │                 signed long long│
│    21│                pulong_long_t│                    --                           │              unsigned long long*│
│    22│                pslong_long_t│                    --                           │                signed long long*│
│    23│                    biggest_t│                    --                           │                        long long│
│    24│                    pbigest_t│                    --                           │                       long long*│
│    25│                    decimal_t│                    --                           │                            float│
│    26│                   pdecimal_t│                    --                           │                           float*│
│    27│                big_decimal_t│                    --                           │                           double│
│    28│               pbig_decimal_t│                    --                           │                          double*│
│    29│            biggest_decimal_t│                    --                           │                      long double│
│    30│           pbiggest_decimal_t│                    --                           │                     long double*│
│    31│                      uchat_t│                    --                           │                    unsigned char│
│    32│                      schar_t│                    --                           │                      signed char│
│    33│                  charecter_t│                    --                           │                             char│
│    34│                        str_t│                    --                           │                            char*│
│    35│                      pchat_t│                    --                           │                            char*│
│    36│                  unicode16_t│                    --                           │                         char16_t│
│    37│                  unicode32_t│                    --                           │                         char32_t│
│    38│                   unicode8_t│Can only be run on versions after C++20!!        │                          char8_t│
│    39│                   BinaryTree│Please write your own function to traverse the bi│                --               │
│      │                             │nary tree                                        │                                 │
│    40│                         Tree│Please write your own function to traverse the bi│                --               │
│      │                             │nary tree                                        │                                 │
│    41│                        Graph│                    --                           │                --               │
│    42│                       maxmin│Returns the maximum and minimum of the type      │                --               │
|    43|                       true_t|Return true                                      |                --               |
|    44|                      false_t|Return false                                     |                --               |
|    45|                    operators|                    --                           |                --
├──────┼─────────────────────────────┼─────────────────────────────────────────────────┼─────────────────────────────────┤
│     #│                    type name│                                             info│                    Original type│
╰──────┴─────────────────────────────┴─────────────────────────────────────────────────┴─────────────────────────────────╯)");
				mtl::print(R"(


╭────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
│                                          MTL - Macro definitions                                                       │
├──────┬────────────────────────────────────────────┬────────────────────────────────────────────────────────────────────┤
│     #│                                        name│                                                               value│
├──────┼────────────────────────────────────────────┼────────────────────────────────────────────────────────────────────┤
│     1│                                       noerr│                                                            noexcept│
│     2│                                     noerror│                                                            noexcept│
│     3│                                  lower_list│                                        "abcdefghijklmnopqrstuvwxyz"│
│     4│                                  upper_list│                                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"│
│     5│                                 number_list│                                                        "0123456789"│
│     6│                                 symbol_list│                                  "!@#$%^&*()_+-=[]\\{}│;':\",./<>?"│
│     7│                                  ascii_list│"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%│
│      │                                            │^&*()_+-=[]\\{}│;':\",./<>?"                                        │
│     8│                                   ascii_len│                                                                (94)│
│     9│                               all_ascii_len│                                                               (128)│
│    10│                                     int_max│                                                        (2147483647)│
│    11│                                     int_min│                                                       (-2147483648)│
│    12│                                   short_max│                                                             (32767)│
│    13│                                   short_min│                                                            (-32768)│
│    14│                                    long_max│                                                         (922337203)│
│    15│                                    long_min│                                                        (-922337203)│
│    15│                               long_long_max│                                                         (922337203)│
│    16│                               long_long_min│                                                        (-922337203)│
│    17│                                  double_max│                                           (1.7976931348623158e+308)│
│    18│                                  double_min│                                          (-1.7976931348623158e+308)│
│    19│                                   float_max│                                                     (3.4028235e+38)│
│    20│                                   float_min│                                                    (-3.4028235e+38)│
│    21│                                   bool_true│                                                                 (1)│
│    22│                                  bool_false│                                                                 (0)│
│    23│                                   bool_null│                                                                 (0)│
│    24│                                    null_str│                                                                ("")│
│    25│                             float_precision│                                                                 (6)│
│    26│                            double_precision│                                                                (15)│
│    27│                               int_precision│                                                                (10)│
│    28│                              long_precision│                                                                (20)│
│    29│                             short_precision│                                                                 (5)│
│    30│                         long_long_precision│                                                                (20)│
│    31│                              char_precision│                                                                 (1)│
├──────┼────────────────────────────────────────────┼────────────────────────────────────────────────────────────────────┤
│     #│                                        name│                                                               value│
╰──────┴────────────────────────────────────────────┴────────────────────────────────────────────────────────────────────╯)");
#ifdef _WIN32
			}
#endif
		}

	}
}
