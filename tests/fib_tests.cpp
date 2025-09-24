#include <gtest/gtest.h>
#include <limits>
#include "fib.h"

TEST(FibBasic, SmallValues){
    EXPECT_EQ(fib(0),0u);
    EXPECT_EQ(fib(1),1u);
    EXPECT_EQ(fib(2),1u);
    EXPECT_EQ(fib(3),2u);
    EXPECT_EQ(fib(4),3u);
    EXPECT_EQ(fib(5),5u);
    EXPECT_EQ(fib(10),55u);
}

TEST(FibEdge, UpperSafe){
    // 93 is the largest n where Fibonacci fits in 64 bits
    EXPECT_EQ(fib(93),12200160415121876738ull);
}

TEST(FibProperties, RecurrenceWindow){
    for(unsigned i=2;i<30;++i){
        EXPECT_EQ(fib(i), fib(i-1)+fib(i-2));
    }
}

TEST(FibMonotonic, Increasing){
    // Sequence is non-decreasing; only equality occurs at F(1)=F(2)=1
    EXPECT_EQ(fib(1), fib(2));
    for(unsigned i=2;i<30;++i){
        if(i>2) EXPECT_LT(fib(i-1), fib(i));
        else EXPECT_LE(fib(i-1), fib(i));
    }
}

int main(int argc,char**argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
