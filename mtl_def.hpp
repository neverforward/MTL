#pragma once

// ����std�еĿ�
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
// �Ǳ�׼��
#ifdef _WIN32
#include <conio.h>
#endif

////////////////////////////////////
//       ����                     //
///////////////////////////////////

#define use_macro 0

/////////////////////////////
//     �궨��               //
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
//       һ�Ѻ�������        //
/////////////////////////////

namespace mtl
{
    // print��������
    void print(const char* format, ...);
    // println��������
    void println(const char* format, ...);
    // pass��������
    char pass [[deprecated("error")]] ();
    // adds��������
    template <typename T>
    double adds(const T& init, const T& value, ...);
    // max��������
    template <typename T1, typename T2>
    double max(T1, T2);
    // min��������
    template <typename T1, typename T2>
    double min(T1, T2);
    // maxs��������
    template <typename T, typename... Args>
    double maxs(T, Args...);
    // mins��������
    template <typename T, typename... Args>
    double mins(T, Args...);
    // gaussian_sum��������
    long gaussian_sum(int);
    // isPalindromic��������
    bool isPalindromic(int);
    bool isPalindromic(const char*);
    inline namespace types
    {
        // ������
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
        // type��������
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
        // squareArea��������
        int squareArea(int a);
        // squarePerimeter��������
        int squarePerimeter(int a);
        // rectangleArea��������
        int rectangleArea(int a, int b);
        // rectanglePerimeter��������
        int rectanglePerimeter(int a, int b);
        // BIM��������
        int BMI(int high, int kg);
        // circularArea��������
        double circularArea(int r);
        // circularPerimeter��������
        double circlePerimeter(int r);
        // triangleArea��������
        int triangleArea(int a, int b);
        // trianglePerimeter��������
        int trianglePerimeter(int a, int b, int c);
        // trapezoidalArea��������
        int trapezoidalArea(int a, int b, int c);
        // trapezoidalPerimeter��������
        int trapezoidalPerimeter(int a, int b, int c, int d);
        // add��������
        int add(int a, int b);
        // sub��������
        int sub(int a, int b);
        // mul��������
        int mul(int a, int b);
        // div��������
        int div(int a, int b);
        // mod��������
        int mod(int a, int b);
        // pow��������
        long long pow(long long a, long long b);
        // fib��������
        int fib(int n);
        // gcd��������
        int gcd(int a, int b);
        // lcm��������
        int lcm(int a, int b);
    }
    inline namespace charecter
    {
        // isAlpha��������
        bool isAlpha(char c);
        // isDigit��������
        bool isDigit(char c);
        // isAlnum��������
        bool isAlnum(char c);
        // isSpace��������
        bool isSpace(char c);
        // isLower��������
        bool isLower(char c);
        // isUpper��������
        bool isUpper(char c);
        // isLetter��������
        bool isLetter(char c);
        // toAscii��������
        int toAscii(char c);
        // toLower��������
        char toLower(char c);
        // toUpper��������
        char toUpper(char c);
        // toChar��������
        char toChar(int c);
    }
    inline namespace algorithm
    {
        // bubbleSort��������
        void bubbleSort(int* arr, int n);
        // selectionSort��������
        void selectionSort(int* arr, int n);
        // insertionSort��������
        void insertionSort(int* arr, int n);
        // quickSort��������
        void quickSort(int* arr, int low, int high);
        // heapSort��������
        void heapSort(int* arr, int n);
        // binary_search��������
        int binary_search(int arr[], int l, int r, int x);
        // linear_search��������
        int linear_search(int arr[], int n, int x);
        // reverse��������
        void reverse(int arr[], int n);
        // all��������
        bool all(int first, ...);
        // none��������
        bool none(int first, ...);
        // odd��������
        bool odd(int n);
        // even��������
        bool even(int n);
        // toGray��������
        int toGray(int n);
        // GreycodetoBinary��������
        int GreycodetoBinary(int n);
        // toBin��������
        int toBin(int n);
        // toOct��������
        int toOct(int n);
        // toHex��������
        int toHex(int n);
        // maxmin��
        template <typename Tp_>
        struct maxmin
        {
            static Tp_ max() {};
            static Tp_ min() {};
        };
    }
    inline namespace big_words
    {
        // A��������
        void A();
        // B��������
        void B();
        // C��������
        void C();
        // D��������
        void D();
        // E��������
        void E();
        // F��������
        void F();
        // G��������
        void G();
        // H��������
        void H();
        // I��������
        void I();
        // J��������
        void J();
        // K��������
        void K();
        // L��������
        void L();
        // M��������
        void M();
        // N��������
        void N();
        // O��������
        void O();
        // P��������
        void P();
        // Q��������
        void Q();
        // R��������
        void R();
        // S��������
        void S();
        // T��������
        void T();
        // U��������
        void U();
        // V��������
        void V();
        // W��������
        void W();
        // X��������
        void X();
        // Y��������
        void Y();
        // Z��������
        void Z();
        // one��������
        void one();
        // two��������
        void two();
        // three��������
        void three();
        // four��������
        void four();
        // five��������
        void five();
        // six��������
        void six();
        // seven��������
        void seven();
        // eight��������
        void eight();
        // nine��������
        void nine();
        // zero��������
        void zero();
    }
    inline namespace informations
    {
        // version��������
        void version();
        // help��������
        void help();
    }
}