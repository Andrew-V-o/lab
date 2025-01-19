#include "gtest/gtest.h"
#include "stack.h"
#include "calculator.h"

TEST(StackTest, PushPopInt) {
    Stack<int> s;
    s << 5;
    int value;
    s >> value;
    ASSERT_EQ(value, 5);
    ASSERT_TRUE(s.empty());
}

TEST(StackTest, PushPopDouble) {
    Stack<double> s;
    s << 3.14;
    double value;
    s >> value;
    ASSERT_DOUBLE_EQ(value, 3.14);
    ASSERT_TRUE(s.empty());
}

TEST(StackTest, AssignmentInt) {
    Stack<int> s1;
    s1 << 10;
    Stack<int> s2 = s1;
    int value;
    s2 >> value;
    ASSERT_EQ(value, 10);
}

TEST(StackTest, AssignmentDouble) {
    Stack<double> s1;
    s1 << 2.71;
    Stack<double> s2 = s1;
    double value;
    s2 >> value;
    ASSERT_DOUBLE_EQ(value, 2.71);
}

TEST(StackTest, Empty) {
    Stack<int> s;
    ASSERT_TRUE(s.empty());
    s << 5;
    ASSERT_FALSE(s.empty());
    int value;
    s >> value;
    ASSERT_TRUE(s.empty());
}

TEST(StackTest, IndexOutOfRange) {
    Stack<int> s;
    ASSERT_THROW(s[0], std::out_of_range);
    s << 5;
    ASSERT_NO_THROW(s[0]);
    ASSERT_THROW(s[1], std::out_of_range);
}

TEST(CalculatorTest, ValidExpression1) {
    Calculator calc;
    ASSERT_DOUBLE_EQ(calc.evaluate("(2+6)/(7-5)"), 4.0);
}

TEST(CalculatorTest, ValidExpression2) {
    Calculator calc;
    ASSERT_DOUBLE_EQ(calc.evaluate("2+3*4"), 14.0);
}

TEST(CalculatorTest, ValidExpression3) {
    Calculator calc;
    ASSERT_DOUBLE_EQ(calc.evaluate("10.5+2.5*2"), 15.5);
}

TEST(CalculatorTest, InvalidExpression1) {
    Calculator calc;
    ASSERT_THROW(calc.evaluate("(5+7/2"), std::invalid_argument);
}

TEST(CalculatorTest, DivisionByZero) {
    Calculator calc;
    ASSERT_THROW(calc.evaluate("10/0"), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}