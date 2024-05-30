#pragma once

// 导入std中的库
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
// 非标准库
#ifdef _WIN32
#include <conio.h>
#endif

////////////////////////////////////
//       工具                     //
///////////////////////////////////

#define use_macro 0

/////////////////////////////
//     宏定义               //
/////////////////////////////


#define noerr noexcept
#define noerror noexcept
#define EXIT(_CODE) do { return _CODE;} while(0)


#ifdef use_macro

#define lower_list ("abcdefghijklmnopqrstuvwxyz")
#define upper_list ("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
#define number_list ("0123456789")
#define symbol_list ("!@#$%^&*()_+-=[]\\{}|;':\",./<>?")
#define ascii_list ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]\\{}|;':\",./<>?")

#define ascii_len (94)
#define all_ascii_len (128)

#define int_max (2147483647)
#define int_min (-2147483648)

#define short_max (32767)
#define short_min (-32768)

#define long_max (9223372036854775807)
#define long_min (-9223372036854775808)

#define long_long_max (9223372036854775807)
#define long_long_min (-9223372036854775808)

#define double_max (1.7976931348623158e+308)
#define double_min (-1.7976931348623158e+308)

#define float_max (3.402823466e+38)
#define float_min (-3.402823466e+38)

#define bool_true (1)
#define bool_false (0)
#define bool_null (0)
#define null_str ("")

#define float_precision (6)

#define double_precision (15)

#define int_precision (10)

#define short_precision (5)

#define long_precision (20)

#define long_long_precision (20)

#define char_precision (1)

#endif


//////////////////////////////
//       一堆函数声明        //
/////////////////////////////

namespace mtl
{
    // print函数声明
    void print(const char* format, ...);
    // println函数声明
    void println(const char* format, ...);
    // pass函数声明
    char pass [[deprecated("error")]] ();
    // adds函数声明
    template <typename T>
    double adds(const T& init, const T& value, ...);
    // max函数声明
    template <typename T1, typename T2>
    double max(T1, T2);
    // min函数声明
    template <typename T1, typename T2>
    double min(T1, T2);
    // maxs函数声明
    template <typename T, typename... Args>
    double maxs(T, Args...);
    // mins函数声明
    template <typename T, typename... Args>
    double mins(T, Args...);
    // gaussian_sum函数声明
    long gaussian_sum(int);
    // isPalindromic函数声明
    bool isPalindromic(int);
    bool isPalindromic(const char*);
    inline namespace types
    {
        // 类型类
        enum type_t
        {
            unsigned_int_t         = 0,
            signed_int_t           = 1,
            unsigned_short_t       = 2,
            signed_short_t         = 3,
            unsigned_long_t        = 4,
            signed_long_t          = 5,
            unsigned_long_long_t   = 6,
            signed_long_long_t     = 7,
            float_t                = 8,
            double_t               = 9,
            long_double_t          =10,
            char_t                 =11
        };
        // type函数声明
        type_t type(unsigned int);
        type_t type(signed int);
        type_t type(unsigned short);
        type_t type(signed short);
        type_t type(unsigned long);
        type_t type(signed long);
        type_t type(unsigned long long);
        type_t type(signed long long);
        type_t type(float);
        type_t type(double);
        type_t type(long double);
        type_t type(char);
    }

    inline namespace math
    {
        // squareArea函数声明
        int squareArea(int a);
        // squarePerimeter函数声明
        int squarePerimeter(int a);
        // rectangleArea函数声明
        int rectangleArea(int a, int b);
        // rectanglePerimeter函数声明
        int rectanglePerimeter(int a, int b);
        // BIM函数声明
        int BMI(int high, int kg);
        // circularArea函数声明
        double circularArea(int r);
        // circularPerimeter函数声明
        double circlePerimeter(int r);
        // triangleArea函数声明
        int triangleArea(int a, int b);
        // trianglePerimeter函数声明
        int trianglePerimeter(int a, int b, int c);
        // trapezoidalArea函数声明
        int trapezoidalArea(int a, int b, int c);
        // trapezoidalPerimeter函数声明
        int trapezoidalPerimeter(int a, int b, int c, int d);
        // add函数声明
        int add(int a, int b);
        // sub函数声明
        int sub(int a, int b);
        // mul函数声明
        int mul(int a, int b);
        // div函数声明
        int div(int a, int b);
        // mod函数声明
        int mod(int a, int b);
        // pow函数声明
        long long pow(long long a, long long b);
        // fib函数声明
        int fib(int n);
        // gcd函数声明
        int gcd(int a, int b);
        // lcm函数声明
        int lcm(int a, int b);
    }
    inline namespace charecter
    {
        // isAlpha函数声明
        bool isAlpha(char c);
        // isDigit函数声明
        bool isDigit(char c);
        // isAlnum函数声明
        bool isAlnum(char c);
        // isSpace函数声明
        bool isSpace(char c);
        // isLower函数声明
        bool isLower(char c);
        // isUpper函数声明
        bool isUpper(char c);
        // isLetter函数声明
        bool isLetter(char c);
        // toAscii函数声明
        int toAscii(char c);
        // toLower函数声明
        char toLower(char c);
        // toUpper函数声明
        char toUpper(char c);
        // toChar函数声明
        char toChar(int c);
    }
    inline namespace algorithm
    {
        // bubbleSort函数声明
        void bubbleSort(int* arr, int n);
        // selectionSort函数声明
        void selectionSort(int* arr, int n);
        // insertionSort函数声明
        void insertionSort(int* arr, int n);
        // quickSort函数声明
        void quickSort(int* arr, int low, int high);
        // heapSort函数声明
        void heapSort(int* arr, int n);
        // binary_search函数声明
        int binary_search(int arr[], int l, int r, int x);
        // linear_search函数声明
        int linear_search(int arr[], int n, int x);
        // reverse函数声明
        void reverse(int arr[], int n);
        // all函数声明
        bool all(int first, ...);
        // none函数声明
        bool none(int first, ...);
        // odd函数声明
        bool odd(int n);
        // even函数声明
        bool even(int n);
        // toGray函数声明
        int toGray(int n);
        // GreycodetoBinary函数声明
        int GreycodetoBinary(int n);
        // toBin函数声明
        int toBin(int n);
        // toOct函数声明
        int toOct(int n);
        // toHex函数声明
        int toHex(int n);
        // maxmin类
        template <typename Tp_>
        struct maxmin
        {
            static Tp_ max() {};
            static Tp_ min() {};
        };
    }
    inline namespace big_words
    {
        // A函数声明
        void A();
        // B函数声明
        void B();
        // C函数声明
        void C();
        // D函数声明
        void D();
        // E函数声明
        void E();
        // F函数声明
        void F();
        // G函数声明
        void G();
        // H函数声明
        void H();
        // I函数声明
        void I();
        // J函数声明
        void J();
        // K函数声明
        void K();
        // L函数声明
        void L();
        // M函数声明
        void M();
        // N函数声明
        void N();
        // O函数声明
        void O();
        // P函数声明
        void P();
        // Q函数声明
        void Q();
        // R函数声明
        void R();
        // S函数声明
        void S();
        // T函数声明
        void T();
        // U函数声明
        void U();
        // V函数声明
        void V();
        // W函数声明
        void W();
        // X函数声明
        void X();
        // Y函数声明
        void Y();
        // Z函数声明
        void Z();
        // one函数声明
        void one();
        // two函数声明
        void two();
        // three函数声明
        void three();
        // four函数声明
        void four();
        // five函数声明
        void five();
        // six函数声明
        void six();
        // seven函数声明
        void seven();
        // eight函数声明
        void eight();
        // nine函数声明
        void nine();
        // zero函数声明
        void zero();
    }
    inline namespace informations
    {
        // version函数声明
        void version();
        // help函数声明
        void help();
    }
}