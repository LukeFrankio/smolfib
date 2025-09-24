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

TEST(FibBig, Exact100){
    EXPECT_EQ(fib_str(100),
        "354224848179261915075");
}

TEST(FibBig, Lengths){
    EXPECT_EQ(fib_str(100).size(), 21u);
    EXPECT_EQ(fib_str(500).size(), 105u); // F(500) has 105 digits
    EXPECT_EQ(fib_str(1000).size(), 209u); // F(1000) has 209 digits
}

TEST(FibBig, PrefixSuffix){
    auto f500=fib_str(500); auto f1000=fib_str(1000);
    EXPECT_EQ(f500.substr(0,5), "13942");
    EXPECT_EQ(f500.substr(f500.size()-5), "94125");
    EXPECT_EQ(f1000.substr(0,5), "43466");
    EXPECT_EQ(f1000.substr(f1000.size()-5), "28875");
}

TEST(FibBig, RecurrenceConsistency){
    // Check F(1000) = F(999)+F(998) via string addition quick check on last 10 digits
    auto f998=fib_str(998); auto f999=fib_str(999); auto f1000=fib_str(1000);
    auto last10=[](const std::string& s){return s.size()>10?s.substr(s.size()-10):s;};
    auto add=[&](std::string a,std::string b){
        std::string s; int c=0; auto i=a.rbegin(),j=b.rbegin();
        while(i!=a.rend()||j!=b.rend()||c){int d=c; if(i!=a.rend()) d+=*i++-'0'; if(j!=b.rend()) d+=*j++-'0'; s.push_back('0'+d%10); c=d/10;}
        std::reverse(s.begin(),s.end()); return s; };
    auto sum=add(f998,f999);
    EXPECT_EQ(last10(sum), last10(f1000));
    EXPECT_EQ(sum, f1000); // full equality (slow but fine for these sizes)
}

int main(int argc,char**argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
