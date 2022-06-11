/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main()
{
    OrgChart organization;
    /*

    organization.add_root("CEO")
        .add_sub("CEO", "CTO")    // Now the CTO is subordinate to the CEO
        .add_sub("CEO", "CFO")    // Now the CFO is subordinate to the CEO
        .add_sub("CEO", "COO")    // Now the COO is subordinate to the CEO
        .add_sub("CTO", "VP_SW")  // Now the VP Software is subordinate to the CTO
        .add_sub("COO", "VP_BI"); // Now the VP_BI is subordinate to the COO
        */
    organization.add_root("1").add_sub("1", "2").add_sub("1", "12").add_sub("1", "22").add_sub("2", "3").add_sub("2", "6").add_sub("2", "9").add_sub("12", "13").add_sub("12", "16").add_sub("12", "19").add_sub("22", "23").add_sub("22", "26").add_sub("22", "29").add_sub("3", "4").add_sub("3", "5").add_sub("6", "7").add_sub("6", "8").add_sub("9", "10").add_sub("9", "11").add_sub("13", "14").add_sub("13", "15").add_sub("16", "17").add_sub("16", "18").add_sub("19", "20").add_sub("19", "21").add_sub("23", "24").add_sub("23", "25").add_sub("26", "27").add_sub("26", "28").add_sub("29", "30").add_sub("29", "31");

    cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
         CEO
         |--------|--------|
         CTO      CFO      COO
         |                 |
         VP_SW             VP_BI
   */
    cout << "LEVEL : ";
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        cout << (*it) << " ";
    } // prints: CEO CTO CFO COO VP_SW VP_BI
    cout << endl;
    cout << "REVERSE : ";
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        cout << (*it) << " ";
    } // prints: VP_SW VP_BI CTO CFO COO CEO
    cout << endl;
    cout << "\'PREORDER\' : ";
    for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
    {
        cout << (*it) << " ";
    } // prints: CEO CTO VP_SW CFO COO VP_BI
    cout << endl;
    cout << "AUTO :  ";
    for (auto const &element : organization) // changed from 'int element' to 'auto element'
    {                                        // this should work like level order
        cout << element << " ";
    } // prints: CEO CTO CFO COO VP_SW VP_BI
    // demonstrate the arrow operator:
    cout << endl;
    cout << "Arrow op : ";
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        cout << it->size() << " ";
    } // prints: 3 3 3 3 5 5
    cout << endl << endl;

    cout << "move and copy constructors:" << endl << endl;

    cout << "copy constuctor and then calling print:" << endl;
    OrgChart newchart{organization};
    cout << newchart << endl << endl; //expected to be the same as the first print!

    cout << "copy assignment and then calling print:" << endl;
    OrgChart newchart2 = newchart;
    cout << newchart2 << endl << endl;

    cout << "move assignment and then calling print:" << endl;
    OrgChart moved_chart{move(newchart2)};
    cout << moved_chart << endl << endl;

    cout << "move assignment and then calling print:" << endl;
    OrgChart moved_chart2 = move(moved_chart);
    cout << moved_chart2 << endl << endl;

    cout << "Now the compiler will call the destructors and we will see that they are indeed different objects:" << endl << endl;
}