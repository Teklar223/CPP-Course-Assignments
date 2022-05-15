#include "doctest.h"
#include "OrgChart.hpp"
#include "string"
using namespace std;
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
        CHECK_NOTHROW(org.add_root("CEO").add_sub("CEO","COO").add_sub("CEO","CTO").add_sub("CEO","CFO"););
        //"AAA" does not exist in the organisation:
        CHECK_THROWS(org.add_sub("AAA", "new employee"););
        CHECK_THROWS(org.add_sub("AAA", "12345"););
        CHECK_THROWS(org.add_sub("AAA", "asdfg"););
        CHECK_THROWS(org.add_sub("AAA", "BOSS"););
        CHECK_NOTHROW(org.add_sub("CEO","AAA"));
        // now "AAA" does exist so:
        CHECK_NOTHROW(org.add_sub("AAA","new employee"));
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

    //TODO: iterator tests.
    SUBCASE("level order")
    {

    }

    SUBCASE("reverse level order")
    {

    }

    SUBCASE("preorder")
    {

    }
}
