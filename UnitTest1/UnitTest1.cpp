#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\aizen\Documents\lab c++\Lab_8.1_rek\Lab_8.1_rek\Lab_8.1_rek.cpp"   // змініть на реальну назву вашого рекурсивного проєкту

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCount)
        {
            char s1[] = "";
            char s2[] = "S";
            char s3[] = "xyz";
            char s4[] = "SQ";
            char s5[] = "SQQS";
            char s6[] = "SQxQSxSQ";
            char s7[] = "SQS";

            Assert::AreEqual(0, Count(s1));
            Assert::AreEqual(0, Count(s2));
            Assert::AreEqual(0, Count(s3));
            Assert::AreEqual(1, Count(s4));
            Assert::AreEqual(2, Count(s5));
            Assert::AreEqual(3, Count(s6));
            Assert::AreEqual(1, Count(s7));   // пари не перекриваються
        }

        TEST_METHOD(TestChange)
        {
            char s1[151] = "xSQyQS";
            char* res = Change(s1);

            Assert::AreEqual("x***y***", s1);   // змінений параметр
            Assert::AreEqual("x***y***", res);  // повернений рядок

            delete[] res;
        }

        TEST_METHOD(TestChangeNoGroups)
        {
            char s[151] = "xyz";
            char* res = Change(s);

            Assert::AreEqual("xyz", s);
            Assert::AreEqual("xyz", res);

            delete[] res;
        }

        TEST_METHOD(TestChangeOnlyGroups)
        {
            char s[151] = "SQQS";
            char* res = Change(s);

            Assert::AreEqual("******", s);
            Assert::AreEqual("******", res);

            delete[] res;
        }

        TEST_METHOD(TestChangeOverlap)
        {
            char s[151] = "SQS";
            char* res = Change(s);

            Assert::AreEqual("***S", s);
            Assert::AreEqual("***S", res);

            delete[] res;
        }
    };
}