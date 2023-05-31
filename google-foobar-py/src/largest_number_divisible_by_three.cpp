#include "pretty_print.h"
#include "test_runner.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <sstream>
#include <set>
#include <list>
#include <string>
#include <map>
#include <exception>
#include <stdexcept>
#include <set>
using namespace std;


int make_num(const list<int>& lst) {
    int power = 1;
    int res = 0;
    
    for(auto it = lst.crbegin(); it != lst.crend(); ++it) {
        res += *it * power;
        power *= 10;
    }
    
    return res;
}

int solve(list<int> lst) {
    lst.sort();
    lst.reverse();
    
    int state = accumulate(cbegin(lst),cend(lst),0) % 3;
    
    auto tmp = find(lst.rbegin(),lst.rend(),0);
    tmp = tmp == lst.rend() ? lst.rbegin() : next(tmp);
    
    auto it2 = lst.rend();
    for(auto it = tmp; it != lst.rend() || 
    it2 != lst.rend() && (lst.erase(next(it2).base()), it = tmp,  state = 1); ++it) {
        if(state == 0) {
            return make_num(lst);
        }
        
        int rem = *it % 3;
        if(state == 1 && rem == 1) {
            lst.erase(next(it).base());
            return make_num(lst);
        } 
        if(state == 2 && rem == 1 && it2 == lst.rend()) {
            it2 = it;
        } 
        if(state == 2 && rem == 2) {
            lst.erase(next(it).base());
            return make_num(lst);
        }
    }
    
    return 0;
}

void TestBase() {
    ASSERT_EQUAL(solve({3,1,4,1}),4311);
    ASSERT_EQUAL(solve({3,1,4,1,5,9}),94311);
    ASSERT_EQUAL(solve({0,0,0}),0);
    ASSERT_EQUAL(solve({0,0,0}),0);
    ASSERT_EQUAL(solve({0,5,0}),0);
    ASSERT_EQUAL(solve({4,3,4}),3);
    ASSERT_EQUAL(solve({4,3,0,0}),300);
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestBase);

    return 0;
}
