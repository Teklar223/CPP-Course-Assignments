#include "doctest.h"
#include "OrgChart.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;
using namespace ariel;

TEST_CASE("OrgChart")
{
    SUBCASE("initialization")
    {
        CHECK_NOTHROW(OrgChart org;);
    }

    SUBCASE("add_root")
    {
        OrgChart org;
        CHECK_NOTHROW(org.add_root("CEO"));
        CHECK_NOTHROW(org.add_root("COO"));
        CHECK_NOTHROW(org.add_root("CTO"));
    }

    SUBCASE("add_sub")
    {
        OrgChart org;
        CHECK_NOTHROW(org.add_root("CEO").add_sub("CEO", "COO").add_sub("CEO", "CTO").add_sub("CEO", "CFO"););
        //"AAA" does not exist in the organisation:
        CHECK_THROWS(org.add_sub("AAA", "new employee"););
        CHECK_THROWS(org.add_sub("AAA", "12345"););
        CHECK_THROWS(org.add_sub("AAA", "asdfg"););
        CHECK_THROWS(org.add_sub("AAA", "BOSS"););
        CHECK_NOTHROW(org.add_sub("CEO", "AAA"));
        // now "AAA" does exist so:
        CHECK_NOTHROW(org.add_sub("AAA", "new employee"));
        CHECK_NOTHROW(org.add_sub("AAA", "12345"););
        CHECK_NOTHROW(org.add_sub("AAA", "asdfg"););
        CHECK_NOTHROW(org.add_sub("AAA", "BOSS"););

        OrgChart org1;
        org1.add_root("CEO");
        CHECK_NOTHROW(org1.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "COO"));
        CHECK_NOTHROW(org1.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(org1.add_sub("COO", "VP_BI"));

        // and the add_root().add_sub() syntax :

        OrgChart org2;
        CHECK_NOTHROW(org2.add_root("CEO").add_sub("CEO", "CFO").add_sub("CEO", "COO").add_sub("CTO", "VP_SW").add_sub("COO", "VP_BI"););

        OrgChart org3;
        CHECK_THROWS(org1.add_sub("CEO", "CTO"));
        CHECK_THROWS(org1.add_sub("CEO", "CFO"));
        CHECK_THROWS(org1.add_sub("CEO", "COO"));
        CHECK_THROWS(org1.add_sub("CTO", "VP_SW"));
        CHECK_THROWS(org1.add_sub("COO", "VP_BI"));
    }

    // TODO: iterator tests.
    SUBCASE("level order")
    {
        OrgChart org;
        vector<string> vec;
        for (auto it = org.begin_level_order(); it != org.end_level_order(); ++it)
        {
            vec.push_back(*it);
        }

        CHECK_EQ(vec.at(0), "1");
        CHECK_EQ(vec.at(1), "2");
        CHECK_EQ(vec.at(2), "12");
        CHECK_EQ(vec.at(3), "22");
        CHECK_EQ(vec.at(4), "3");
        CHECK_EQ(vec.at(5), "6");
        CHECK_EQ(vec.at(6), "9");
        CHECK_EQ(vec.at(7), "13");
        CHECK_EQ(vec.at(8), "16");
        CHECK_EQ(vec.at(9), "19");
        CHECK_EQ(vec.at(10), "23");
        CHECK_EQ(vec.at(11), "26");
        CHECK_EQ(vec.at(12), "29");
        CHECK_EQ(vec.at(13), "4");
        CHECK_EQ(vec.at(14), "5");
        CHECK_EQ(vec.at(15), "7");
        CHECK_EQ(vec.at(16), "8");
        CHECK_EQ(vec.at(17), "10");
        CHECK_EQ(vec.at(18), "11");
        CHECK_EQ(vec.at(19), "14");
        CHECK_EQ(vec.at(20), "15");
        CHECK_EQ(vec.at(21), "17");
        CHECK_EQ(vec.at(22), "18");
        CHECK_EQ(vec.at(23), "20");
        CHECK_EQ(vec.at(24), "21");
        CHECK_EQ(vec.at(25), "24");
        CHECK_EQ(vec.at(26), "25");
        CHECK_EQ(vec.at(27), "27");
        CHECK_EQ(vec.at(28), "28");
        CHECK_EQ(vec.at(29), "30");
        CHECK_EQ(vec.at(30), "31");
    }

    SUBCASE("reverse level order")
    {
        OrgChart org;
        vector<string> vec;
        for (auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it)
        {
            vec.push_back(*it);
        }

        CHECK_EQ(vec.at(0), "4");
        CHECK_EQ(vec.at(1), "5");
        CHECK_EQ(vec.at(2), "7");
        CHECK_EQ(vec.at(3), "8");
        CHECK_EQ(vec.at(4), "10");
        CHECK_EQ(vec.at(5), "11");
        CHECK_EQ(vec.at(6), "14");
        CHECK_EQ(vec.at(7), "15");
        CHECK_EQ(vec.at(8), "17");
        CHECK_EQ(vec.at(9), "18");
        CHECK_EQ(vec.at(10), "20");
        CHECK_EQ(vec.at(11), "21");
        CHECK_EQ(vec.at(12), "24");
        CHECK_EQ(vec.at(13), "25");
        CHECK_EQ(vec.at(14), "27");
        CHECK_EQ(vec.at(15), "28");
        CHECK_EQ(vec.at(16), "30");
        CHECK_EQ(vec.at(17), "31");
        CHECK_EQ(vec.at(18), "3");
        CHECK_EQ(vec.at(19), "6");
        CHECK_EQ(vec.at(20), "9");
        CHECK_EQ(vec.at(21), "13");
        CHECK_EQ(vec.at(22), "16");
        CHECK_EQ(vec.at(23), "19");
        CHECK_EQ(vec.at(24), "23");
        CHECK_EQ(vec.at(25), "26");
        CHECK_EQ(vec.at(26), "29");
        CHECK_EQ(vec.at(27), "2");
        CHECK_EQ(vec.at(28), "12");
        CHECK_EQ(vec.at(29), "22");
        CHECK_EQ(vec.at(30), "1");
    }

    SUBCASE("preorder")
    {
        OrgChart org;
        vector<string> vec;
        for (auto it = org.begin_preorder(); it != org.end_preorder(); ++it)
        {
            vec.push_back(*it);
        }

        CHECK_EQ(vec.at(0), "1");
        CHECK_EQ(vec.at(1), "2");
        CHECK_EQ(vec.at(2), "3");
        CHECK_EQ(vec.at(3), "4");
        CHECK_EQ(vec.at(4), "5");
        CHECK_EQ(vec.at(5), "6");
        CHECK_EQ(vec.at(6), "7");
        CHECK_EQ(vec.at(7), "8");
        CHECK_EQ(vec.at(8), "9");
        CHECK_EQ(vec.at(9), "10");
        CHECK_EQ(vec.at(10), "11");
        CHECK_EQ(vec.at(11), "12");
        CHECK_EQ(vec.at(12), "13");
        CHECK_EQ(vec.at(13), "14");
        CHECK_EQ(vec.at(14), "15");
        CHECK_EQ(vec.at(15), "16");
        CHECK_EQ(vec.at(16), "17");
        CHECK_EQ(vec.at(17), "18");
        CHECK_EQ(vec.at(18), "19");
        CHECK_EQ(vec.at(19), "20");
        CHECK_EQ(vec.at(20), "21");
        CHECK_EQ(vec.at(21), "22");
        CHECK_EQ(vec.at(22), "23");
        CHECK_EQ(vec.at(23), "24");
        CHECK_EQ(vec.at(24), "25");
        CHECK_EQ(vec.at(25), "26");
        CHECK_EQ(vec.at(26), "27");
        CHECK_EQ(vec.at(27), "28");
        CHECK_EQ(vec.at(28), "29");
        CHECK_EQ(vec.at(29), "30");
        CHECK_EQ(vec.at(30), "31");
    }

    SUBCASE("default")
    {
        OrgChart org;
        vector<string> vec;
        for (auto const &element : org)
        {
            vec.push_back(element);
        }

        CHECK_EQ(vec.at(0), "1");
        CHECK_EQ(vec.at(1), "2");
        CHECK_EQ(vec.at(2), "12");
        CHECK_EQ(vec.at(3), "22");
        CHECK_EQ(vec.at(4), "3");
        CHECK_EQ(vec.at(5), "6");
        CHECK_EQ(vec.at(6), "9");
        CHECK_EQ(vec.at(7), "13");
        CHECK_EQ(vec.at(8), "16");
        CHECK_EQ(vec.at(9), "19");
        CHECK_EQ(vec.at(10), "23");
        CHECK_EQ(vec.at(11), "26");
        CHECK_EQ(vec.at(12), "29");
        CHECK_EQ(vec.at(13), "4");
        CHECK_EQ(vec.at(14), "5");
        CHECK_EQ(vec.at(15), "7");
        CHECK_EQ(vec.at(16), "8");
        CHECK_EQ(vec.at(17), "10");
        CHECK_EQ(vec.at(18), "11");
        CHECK_EQ(vec.at(19), "14");
        CHECK_EQ(vec.at(20), "15");
        CHECK_EQ(vec.at(21), "17");
        CHECK_EQ(vec.at(22), "18");
        CHECK_EQ(vec.at(23), "20");
        CHECK_EQ(vec.at(24), "21");
        CHECK_EQ(vec.at(25), "24");
        CHECK_EQ(vec.at(26), "25");
        CHECK_EQ(vec.at(27), "27");
        CHECK_EQ(vec.at(28), "28");
        CHECK_EQ(vec.at(29), "30");
        CHECK_EQ(vec.at(30), "31");
    }
}
