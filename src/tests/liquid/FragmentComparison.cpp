#include <liquid/Fragment.hpp>

#include <iostream>
#include <cstdlib>

using namespace Liquid;

#define Assert(expression, description)         \
    if (!(expression))                          \
    {                                           \
        std::cout << "\033[31m[FAILED]\033[0m " \
                  << description << std::endl;  \
                                                \
        Cleanup();                              \
        return EXIT_FAILURE;                    \
    }

#define Passed(description)                     \
    std::cout << "\033[32m[PASSED]\033[0m "     \
    << description << std::endl;

// * Variable destruction
#define Cleanup()                               \
    delete var0;                                \
    delete var1;                                \
    delete var2;                                \
    delete var3;                                \
    delete var4;                                \
    delete var5;                                \
    delete var6;                                \
    delete var7;                                \
    delete var8;                                \
    delete var9;                                \
    delete var10;                               \
    delete var11;                               \
    delete var12;                               \
    delete var13;                               \
    delete var14;                               \
    delete var15;                               \
    delete var16;                               \
    delete var17;                               \
    delete var18;

int main()
{
// * Variable initialization
    Fragment* var0 = new NullFragment();
    Fragment* var1 = new EmptyFragment();
    Fragment* var2 = new IntegerFragment(0);
    Fragment* var3 = new IntegerFragment(1);
    Fragment* var4 = new IntegerFragment(-1);
    Fragment* var5 = new FloatFragment(0.0);
    Fragment* var6 = new FloatFragment(0.1);
    Fragment* var7 = new FloatFragment(1.0);
    Fragment* var8 = new FloatFragment(-0.1);
    Fragment* var9 = new FloatFragment(-1.0);
    Fragment* var10 = new HashFragment();
    Fragment* var11 = new ArrayFragment();
    Fragment* var12 = new ArrayFragment(); reinterpret_cast<ArrayFragment*>(var12)->Add(new StringFragment("Test"));;
    Fragment* var13 = new BooleanFragment(true);
    Fragment* var14 = new BooleanFragment(false);
    Fragment* var15 = new StringFragment("");
    Fragment* var16 = new StringFragment("..");
    Fragment* var17 = new StringFragment("t");
    Fragment* var18 = new StringFragment("f");

    bool resultA, 
        resultB; 

// * Evaluating null
    Assert(var0->Compare(NULL, ConditionalImplicit) == false,
           "Implicit test of null failed");
    Passed("Implicit test of null");

// Evaluating null against null
    resultA = var0->Compare(var0, ConditionalEquals);
    Assert(resultA == true,
           "null == null should have been true");
    resultB = var0->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == null is inconsistent");
    Passed("null == null");
    resultA = var0->Compare(var0, ConditionalNotEquals);
    Assert(resultA == false,
           "null != null should have been false");
    resultB = var0->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != null is inconsistent");
    Passed("null != null");
    resultA = var0->Compare(var0, ConditionalLessThan);
    Assert(resultA == false,
           "null < null should have been false");
    resultB = var0->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < null is inconsistent");
    Passed("null < null");
    resultA = var0->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= null should have been false");
    resultB = var0->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= null is inconsistent");
    Passed("null >= null");
    resultA = var0->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= null should have been false");
    resultB = var0->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= null is inconsistent");
    Passed("null <= null");

// Evaluating null against empty
    resultA = var0->Compare(var1, ConditionalEquals);
    Assert(resultA == true,
           "null == empty should have been true");
    resultB = var1->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == empty is inconsistent");
    Passed("null == empty");
    resultA = var0->Compare(var1, ConditionalNotEquals);
    Assert(resultA == false,
           "null != empty should have been false");
    resultB = var1->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != empty is inconsistent");
    Passed("null != empty");
    resultA = var0->Compare(var1, ConditionalLessThan);
    Assert(resultA == false,
           "null < empty should have been false");
    resultB = var1->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < empty is inconsistent");
    Passed("null < empty");
    resultA = var0->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= empty should have been false");
    resultB = var1->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= empty is inconsistent");
    Passed("null >= empty");
    resultA = var0->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= empty should have been false");
    resultB = var1->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= empty is inconsistent");
    Passed("null <= empty");

// Evaluating null against int(0)
    resultA = var0->Compare(var2, ConditionalEquals);
    Assert(resultA == false,
           "null == int(0) should have been false");
    resultB = var2->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == int(0) is inconsistent");
    Passed("null == int(0)");
    resultA = var0->Compare(var2, ConditionalNotEquals);
    Assert(resultA == true,
           "null != int(0) should have been true");
    resultB = var2->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != int(0) is inconsistent");
    Passed("null != int(0)");
    resultA = var0->Compare(var2, ConditionalLessThan);
    Assert(resultA == false,
           "null < int(0) should have been false");
    resultB = var2->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < int(0) is inconsistent");
    Passed("null < int(0)");
    resultA = var0->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= int(0) should have been false");
    resultB = var2->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= int(0) is inconsistent");
    Passed("null >= int(0)");
    resultA = var0->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= int(0) should have been false");
    resultB = var2->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= int(0) is inconsistent");
    Passed("null <= int(0)");

// Evaluating null against int(1)
    resultA = var0->Compare(var3, ConditionalEquals);
    Assert(resultA == false,
           "null == int(1) should have been false");
    resultB = var3->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == int(1) is inconsistent");
    Passed("null == int(1)");
    resultA = var0->Compare(var3, ConditionalNotEquals);
    Assert(resultA == true,
           "null != int(1) should have been true");
    resultB = var3->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != int(1) is inconsistent");
    Passed("null != int(1)");
    resultA = var0->Compare(var3, ConditionalLessThan);
    Assert(resultA == false,
           "null < int(1) should have been false");
    resultB = var3->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < int(1) is inconsistent");
    Passed("null < int(1)");
    resultA = var0->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= int(1) should have been false");
    resultB = var3->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= int(1) is inconsistent");
    Passed("null >= int(1)");
    resultA = var0->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= int(1) should have been false");
    resultB = var3->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= int(1) is inconsistent");
    Passed("null <= int(1)");

// Evaluating null against int(-1)
    resultA = var0->Compare(var4, ConditionalEquals);
    Assert(resultA == false,
           "null == int(-1) should have been false");
    resultB = var4->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == int(-1) is inconsistent");
    Passed("null == int(-1)");
    resultA = var0->Compare(var4, ConditionalNotEquals);
    Assert(resultA == true,
           "null != int(-1) should have been true");
    resultB = var4->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != int(-1) is inconsistent");
    Passed("null != int(-1)");
    resultA = var0->Compare(var4, ConditionalLessThan);
    Assert(resultA == false,
           "null < int(-1) should have been false");
    resultB = var4->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < int(-1) is inconsistent");
    Passed("null < int(-1)");
    resultA = var0->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= int(-1) should have been false");
    resultB = var4->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= int(-1) is inconsistent");
    Passed("null >= int(-1)");
    resultA = var0->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= int(-1) should have been false");
    resultB = var4->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= int(-1) is inconsistent");
    Passed("null <= int(-1)");

// Evaluating null against float(0.0)
    resultA = var0->Compare(var5, ConditionalEquals);
    Assert(resultA == false,
           "null == float(0.0) should have been false");
    resultB = var5->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == float(0.0) is inconsistent");
    Passed("null == float(0.0)");
    resultA = var0->Compare(var5, ConditionalNotEquals);
    Assert(resultA == true,
           "null != float(0.0) should have been true");
    resultB = var5->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != float(0.0) is inconsistent");
    Passed("null != float(0.0)");
    resultA = var0->Compare(var5, ConditionalLessThan);
    Assert(resultA == false,
           "null < float(0.0) should have been false");
    resultB = var5->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < float(0.0) is inconsistent");
    Passed("null < float(0.0)");
    resultA = var0->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= float(0.0) should have been false");
    resultB = var5->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= float(0.0) is inconsistent");
    Passed("null >= float(0.0)");
    resultA = var0->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= float(0.0) should have been false");
    resultB = var5->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= float(0.0) is inconsistent");
    Passed("null <= float(0.0)");

// Evaluating null against float(0.1)
    resultA = var0->Compare(var6, ConditionalEquals);
    Assert(resultA == false,
           "null == float(0.1) should have been false");
    resultB = var6->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == float(0.1) is inconsistent");
    Passed("null == float(0.1)");
    resultA = var0->Compare(var6, ConditionalNotEquals);
    Assert(resultA == true,
           "null != float(0.1) should have been true");
    resultB = var6->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != float(0.1) is inconsistent");
    Passed("null != float(0.1)");
    resultA = var0->Compare(var6, ConditionalLessThan);
    Assert(resultA == false,
           "null < float(0.1) should have been false");
    resultB = var6->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < float(0.1) is inconsistent");
    Passed("null < float(0.1)");
    resultA = var0->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= float(0.1) should have been false");
    resultB = var6->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= float(0.1) is inconsistent");
    Passed("null >= float(0.1)");
    resultA = var0->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= float(0.1) should have been false");
    resultB = var6->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= float(0.1) is inconsistent");
    Passed("null <= float(0.1)");

// Evaluating null against float(1.0)
    resultA = var0->Compare(var7, ConditionalEquals);
    Assert(resultA == false,
           "null == float(1.0) should have been false");
    resultB = var7->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == float(1.0) is inconsistent");
    Passed("null == float(1.0)");
    resultA = var0->Compare(var7, ConditionalNotEquals);
    Assert(resultA == true,
           "null != float(1.0) should have been true");
    resultB = var7->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != float(1.0) is inconsistent");
    Passed("null != float(1.0)");
    resultA = var0->Compare(var7, ConditionalLessThan);
    Assert(resultA == false,
           "null < float(1.0) should have been false");
    resultB = var7->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < float(1.0) is inconsistent");
    Passed("null < float(1.0)");
    resultA = var0->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= float(1.0) should have been false");
    resultB = var7->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= float(1.0) is inconsistent");
    Passed("null >= float(1.0)");
    resultA = var0->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= float(1.0) should have been false");
    resultB = var7->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= float(1.0) is inconsistent");
    Passed("null <= float(1.0)");

// Evaluating null against float(-0.1)
    resultA = var0->Compare(var8, ConditionalEquals);
    Assert(resultA == false,
           "null == float(-0.1) should have been false");
    resultB = var8->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == float(-0.1) is inconsistent");
    Passed("null == float(-0.1)");
    resultA = var0->Compare(var8, ConditionalNotEquals);
    Assert(resultA == true,
           "null != float(-0.1) should have been true");
    resultB = var8->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != float(-0.1) is inconsistent");
    Passed("null != float(-0.1)");
    resultA = var0->Compare(var8, ConditionalLessThan);
    Assert(resultA == false,
           "null < float(-0.1) should have been false");
    resultB = var8->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < float(-0.1) is inconsistent");
    Passed("null < float(-0.1)");
    resultA = var0->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= float(-0.1) should have been false");
    resultB = var8->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= float(-0.1) is inconsistent");
    Passed("null >= float(-0.1)");
    resultA = var0->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= float(-0.1) should have been false");
    resultB = var8->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= float(-0.1) is inconsistent");
    Passed("null <= float(-0.1)");

// Evaluating null against float(-1.0)
    resultA = var0->Compare(var9, ConditionalEquals);
    Assert(resultA == false,
           "null == float(-1.0) should have been false");
    resultB = var9->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == float(-1.0) is inconsistent");
    Passed("null == float(-1.0)");
    resultA = var0->Compare(var9, ConditionalNotEquals);
    Assert(resultA == true,
           "null != float(-1.0) should have been true");
    resultB = var9->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != float(-1.0) is inconsistent");
    Passed("null != float(-1.0)");
    resultA = var0->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "null < float(-1.0) should have been false");
    resultB = var9->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < float(-1.0) is inconsistent");
    Passed("null < float(-1.0)");
    resultA = var0->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= float(-1.0) should have been false");
    resultB = var9->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= float(-1.0) is inconsistent");
    Passed("null >= float(-1.0)");
    resultA = var0->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= float(-1.0) should have been false");
    resultB = var9->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= float(-1.0) is inconsistent");
    Passed("null <= float(-1.0)");

// Evaluating null against hash
    resultA = var0->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "null == hash should have been false");
    resultB = var10->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == hash is inconsistent");
    Passed("null == hash");
    resultA = var0->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "null != hash should have been true");
    resultB = var10->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != hash is inconsistent");
    Passed("null != hash");
    resultA = var0->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "null < hash should have been false");
    resultB = var10->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < hash is inconsistent");
    Passed("null < hash");
    resultA = var0->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= hash should have been false");
    resultB = var10->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= hash is inconsistent");
    Passed("null >= hash");
    resultA = var0->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= hash should have been false");
    resultB = var10->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= hash is inconsistent");
    Passed("null <= hash");

// Evaluating null against array()
    resultA = var0->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "null == array() should have been false");
    resultB = var11->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == array() is inconsistent");
    Passed("null == array()");
    resultA = var0->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "null != array() should have been true");
    resultB = var11->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != array() is inconsistent");
    Passed("null != array()");
    resultA = var0->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "null < array() should have been false");
    resultB = var11->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < array() is inconsistent");
    Passed("null < array()");
    resultA = var0->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= array() should have been false");
    resultB = var11->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= array() is inconsistent");
    Passed("null >= array()");
    resultA = var0->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= array() should have been false");
    resultB = var11->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= array() is inconsistent");
    Passed("null <= array()");

// Evaluating null against array(..)
    resultA = var0->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "null == array(..) should have been false");
    resultB = var12->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == array(..) is inconsistent");
    Passed("null == array(..)");
    resultA = var0->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "null != array(..) should have been true");
    resultB = var12->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != array(..) is inconsistent");
    Passed("null != array(..)");
    resultA = var0->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "null < array(..) should have been false");
    resultB = var12->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < array(..) is inconsistent");
    Passed("null < array(..)");
    resultA = var0->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= array(..) should have been false");
    resultB = var12->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= array(..) is inconsistent");
    Passed("null >= array(..)");
    resultA = var0->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= array(..) should have been false");
    resultB = var12->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= array(..) is inconsistent");
    Passed("null <= array(..)");

// Evaluating null against bool(true)
    resultA = var0->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "null == bool(true) should have been false");
    resultB = var13->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == bool(true) is inconsistent");
    Passed("null == bool(true)");
    resultA = var0->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "null != bool(true) should have been true");
    resultB = var13->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != bool(true) is inconsistent");
    Passed("null != bool(true)");
    resultA = var0->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "null < bool(true) should have been false");
    resultB = var13->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < bool(true) is inconsistent");
    Passed("null < bool(true)");
    resultA = var0->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= bool(true) should have been false");
    resultB = var13->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= bool(true) is inconsistent");
    Passed("null >= bool(true)");
    resultA = var0->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= bool(true) should have been false");
    resultB = var13->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= bool(true) is inconsistent");
    Passed("null <= bool(true)");

// Evaluating null against bool(false)
    resultA = var0->Compare(var14, ConditionalEquals);
    Assert(resultA == false,
           "null == bool(false) should have been false");
    resultB = var14->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == bool(false) is inconsistent");
    Passed("null == bool(false)");
    resultA = var0->Compare(var14, ConditionalNotEquals);
    Assert(resultA == true,
           "null != bool(false) should have been true");
    resultB = var14->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != bool(false) is inconsistent");
    Passed("null != bool(false)");
    resultA = var0->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "null < bool(false) should have been false");
    resultB = var14->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < bool(false) is inconsistent");
    Passed("null < bool(false)");
    resultA = var0->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= bool(false) should have been false");
    resultB = var14->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= bool(false) is inconsistent");
    Passed("null >= bool(false)");
    resultA = var0->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= bool(false) should have been false");
    resultB = var14->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= bool(false) is inconsistent");
    Passed("null <= bool(false)");

// Evaluating null against string("")
    resultA = var0->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "null == string(\"\") should have been false");
    resultB = var15->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == string(\"\") is inconsistent");
    Passed("null == string(\"\")");
    resultA = var0->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "null != string(\"\") should have been true");
    resultB = var15->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != string(\"\") is inconsistent");
    Passed("null != string(\"\")");
    resultA = var0->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "null < string(\"\") should have been false");
    resultB = var15->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < string(\"\") is inconsistent");
    Passed("null < string(\"\")");
    resultA = var0->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= string(\"\") should have been false");
    resultB = var15->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= string(\"\") is inconsistent");
    Passed("null >= string(\"\")");
    resultA = var0->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= string(\"\") should have been false");
    resultB = var15->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= string(\"\") is inconsistent");
    Passed("null <= string(\"\")");

// Evaluating null against string("..")
    resultA = var0->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "null == string(\"..\") should have been false");
    resultB = var16->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == string(\"..\") is inconsistent");
    Passed("null == string(\"..\")");
    resultA = var0->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "null != string(\"..\") should have been true");
    resultB = var16->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != string(\"..\") is inconsistent");
    Passed("null != string(\"..\")");
    resultA = var0->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "null < string(\"..\") should have been false");
    resultB = var16->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < string(\"..\") is inconsistent");
    Passed("null < string(\"..\")");
    resultA = var0->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= string(\"..\") should have been false");
    resultB = var16->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= string(\"..\") is inconsistent");
    Passed("null >= string(\"..\")");
    resultA = var0->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= string(\"..\") should have been false");
    resultB = var16->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= string(\"..\") is inconsistent");
    Passed("null <= string(\"..\")");

// Evaluating null against string("t")
    resultA = var0->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "null == string(\"t\") should have been false");
    resultB = var17->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == string(\"t\") is inconsistent");
    Passed("null == string(\"t\")");
    resultA = var0->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "null != string(\"t\") should have been true");
    resultB = var17->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != string(\"t\") is inconsistent");
    Passed("null != string(\"t\")");
    resultA = var0->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "null < string(\"t\") should have been false");
    resultB = var17->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < string(\"t\") is inconsistent");
    Passed("null < string(\"t\")");
    resultA = var0->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= string(\"t\") should have been false");
    resultB = var17->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= string(\"t\") is inconsistent");
    Passed("null >= string(\"t\")");
    resultA = var0->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= string(\"t\") should have been false");
    resultB = var17->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= string(\"t\") is inconsistent");
    Passed("null <= string(\"t\")");

// Evaluating null against string("f")
    resultA = var0->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "null == string(\"f\") should have been false");
    resultB = var18->Compare(var0, ConditionalEquals);
    Assert(resultA == resultB,
           "null == string(\"f\") is inconsistent");
    Passed("null == string(\"f\")");
    resultA = var0->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "null != string(\"f\") should have been true");
    resultB = var18->Compare(var0, ConditionalNotEquals);
    Assert(resultA == resultB,
           "null != string(\"f\") is inconsistent");
    Passed("null != string(\"f\")");
    resultA = var0->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "null < string(\"f\") should have been false");
    resultB = var18->Compare(var0, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "null < string(\"f\") is inconsistent");
    Passed("null < string(\"f\")");
    resultA = var0->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "null >= string(\"f\") should have been false");
    resultB = var18->Compare(var0, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "null >= string(\"f\") is inconsistent");
    Passed("null >= string(\"f\")");
    resultA = var0->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "null <= string(\"f\") should have been false");
    resultB = var18->Compare(var0, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "null <= string(\"f\") is inconsistent");
    Passed("null <= string(\"f\")");

// * Evaluating empty
    Assert(var1->Compare(NULL, ConditionalImplicit) == false,
           "Implicit test of empty failed");
    Passed("Implicit test of empty");

// Evaluating empty against empty
    resultA = var1->Compare(var1, ConditionalEquals);
    Assert(resultA == true,
           "empty == empty should have been true");
    resultB = var1->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == empty is inconsistent");
    Passed("empty == empty");
    resultA = var1->Compare(var1, ConditionalNotEquals);
    Assert(resultA == false,
           "empty != empty should have been false");
    resultB = var1->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != empty is inconsistent");
    Passed("empty != empty");
    resultA = var1->Compare(var1, ConditionalLessThan);
    Assert(resultA == false,
           "empty < empty should have been false");
    resultB = var1->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < empty is inconsistent");
    Passed("empty < empty");
    resultA = var1->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= empty should have been false");
    resultB = var1->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= empty is inconsistent");
    Passed("empty >= empty");
    resultA = var1->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= empty should have been false");
    resultB = var1->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= empty is inconsistent");
    Passed("empty <= empty");

// Evaluating empty against int(0)
    resultA = var1->Compare(var2, ConditionalEquals);
    Assert(resultA == false,
           "empty == int(0) should have been false");
    resultB = var2->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == int(0) is inconsistent");
    Passed("empty == int(0)");
    resultA = var1->Compare(var2, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != int(0) should have been true");
    resultB = var2->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != int(0) is inconsistent");
    Passed("empty != int(0)");
    resultA = var1->Compare(var2, ConditionalLessThan);
    Assert(resultA == false,
           "empty < int(0) should have been false");
    resultB = var2->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < int(0) is inconsistent");
    Passed("empty < int(0)");
    resultA = var1->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= int(0) should have been false");
    resultB = var2->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= int(0) is inconsistent");
    Passed("empty >= int(0)");
    resultA = var1->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= int(0) should have been false");
    resultB = var2->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= int(0) is inconsistent");
    Passed("empty <= int(0)");

// Evaluating empty against int(1)
    resultA = var1->Compare(var3, ConditionalEquals);
    Assert(resultA == false,
           "empty == int(1) should have been false");
    resultB = var3->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == int(1) is inconsistent");
    Passed("empty == int(1)");
    resultA = var1->Compare(var3, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != int(1) should have been true");
    resultB = var3->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != int(1) is inconsistent");
    Passed("empty != int(1)");
    resultA = var1->Compare(var3, ConditionalLessThan);
    Assert(resultA == false,
           "empty < int(1) should have been false");
    resultB = var3->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < int(1) is inconsistent");
    Passed("empty < int(1)");
    resultA = var1->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= int(1) should have been false");
    resultB = var3->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= int(1) is inconsistent");
    Passed("empty >= int(1)");
    resultA = var1->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= int(1) should have been false");
    resultB = var3->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= int(1) is inconsistent");
    Passed("empty <= int(1)");

// Evaluating empty against int(-1)
    resultA = var1->Compare(var4, ConditionalEquals);
    Assert(resultA == false,
           "empty == int(-1) should have been false");
    resultB = var4->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == int(-1) is inconsistent");
    Passed("empty == int(-1)");
    resultA = var1->Compare(var4, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != int(-1) should have been true");
    resultB = var4->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != int(-1) is inconsistent");
    Passed("empty != int(-1)");
    resultA = var1->Compare(var4, ConditionalLessThan);
    Assert(resultA == false,
           "empty < int(-1) should have been false");
    resultB = var4->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < int(-1) is inconsistent");
    Passed("empty < int(-1)");
    resultA = var1->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= int(-1) should have been false");
    resultB = var4->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= int(-1) is inconsistent");
    Passed("empty >= int(-1)");
    resultA = var1->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= int(-1) should have been false");
    resultB = var4->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= int(-1) is inconsistent");
    Passed("empty <= int(-1)");

// Evaluating empty against float(0.0)
    resultA = var1->Compare(var5, ConditionalEquals);
    Assert(resultA == false,
           "empty == float(0.0) should have been false");
    resultB = var5->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == float(0.0) is inconsistent");
    Passed("empty == float(0.0)");
    resultA = var1->Compare(var5, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != float(0.0) should have been true");
    resultB = var5->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != float(0.0) is inconsistent");
    Passed("empty != float(0.0)");
    resultA = var1->Compare(var5, ConditionalLessThan);
    Assert(resultA == false,
           "empty < float(0.0) should have been false");
    resultB = var5->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < float(0.0) is inconsistent");
    Passed("empty < float(0.0)");
    resultA = var1->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= float(0.0) should have been false");
    resultB = var5->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= float(0.0) is inconsistent");
    Passed("empty >= float(0.0)");
    resultA = var1->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= float(0.0) should have been false");
    resultB = var5->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= float(0.0) is inconsistent");
    Passed("empty <= float(0.0)");

// Evaluating empty against float(0.1)
    resultA = var1->Compare(var6, ConditionalEquals);
    Assert(resultA == false,
           "empty == float(0.1) should have been false");
    resultB = var6->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == float(0.1) is inconsistent");
    Passed("empty == float(0.1)");
    resultA = var1->Compare(var6, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != float(0.1) should have been true");
    resultB = var6->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != float(0.1) is inconsistent");
    Passed("empty != float(0.1)");
    resultA = var1->Compare(var6, ConditionalLessThan);
    Assert(resultA == false,
           "empty < float(0.1) should have been false");
    resultB = var6->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < float(0.1) is inconsistent");
    Passed("empty < float(0.1)");
    resultA = var1->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= float(0.1) should have been false");
    resultB = var6->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= float(0.1) is inconsistent");
    Passed("empty >= float(0.1)");
    resultA = var1->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= float(0.1) should have been false");
    resultB = var6->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= float(0.1) is inconsistent");
    Passed("empty <= float(0.1)");

// Evaluating empty against float(1.0)
    resultA = var1->Compare(var7, ConditionalEquals);
    Assert(resultA == false,
           "empty == float(1.0) should have been false");
    resultB = var7->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == float(1.0) is inconsistent");
    Passed("empty == float(1.0)");
    resultA = var1->Compare(var7, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != float(1.0) should have been true");
    resultB = var7->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != float(1.0) is inconsistent");
    Passed("empty != float(1.0)");
    resultA = var1->Compare(var7, ConditionalLessThan);
    Assert(resultA == false,
           "empty < float(1.0) should have been false");
    resultB = var7->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < float(1.0) is inconsistent");
    Passed("empty < float(1.0)");
    resultA = var1->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= float(1.0) should have been false");
    resultB = var7->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= float(1.0) is inconsistent");
    Passed("empty >= float(1.0)");
    resultA = var1->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= float(1.0) should have been false");
    resultB = var7->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= float(1.0) is inconsistent");
    Passed("empty <= float(1.0)");

// Evaluating empty against float(-0.1)
    resultA = var1->Compare(var8, ConditionalEquals);
    Assert(resultA == false,
           "empty == float(-0.1) should have been false");
    resultB = var8->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == float(-0.1) is inconsistent");
    Passed("empty == float(-0.1)");
    resultA = var1->Compare(var8, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != float(-0.1) should have been true");
    resultB = var8->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != float(-0.1) is inconsistent");
    Passed("empty != float(-0.1)");
    resultA = var1->Compare(var8, ConditionalLessThan);
    Assert(resultA == false,
           "empty < float(-0.1) should have been false");
    resultB = var8->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < float(-0.1) is inconsistent");
    Passed("empty < float(-0.1)");
    resultA = var1->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= float(-0.1) should have been false");
    resultB = var8->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= float(-0.1) is inconsistent");
    Passed("empty >= float(-0.1)");
    resultA = var1->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= float(-0.1) should have been false");
    resultB = var8->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= float(-0.1) is inconsistent");
    Passed("empty <= float(-0.1)");

// Evaluating empty against float(-1.0)
    resultA = var1->Compare(var9, ConditionalEquals);
    Assert(resultA == false,
           "empty == float(-1.0) should have been false");
    resultB = var9->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == float(-1.0) is inconsistent");
    Passed("empty == float(-1.0)");
    resultA = var1->Compare(var9, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != float(-1.0) should have been true");
    resultB = var9->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != float(-1.0) is inconsistent");
    Passed("empty != float(-1.0)");
    resultA = var1->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "empty < float(-1.0) should have been false");
    resultB = var9->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < float(-1.0) is inconsistent");
    Passed("empty < float(-1.0)");
    resultA = var1->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= float(-1.0) should have been false");
    resultB = var9->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= float(-1.0) is inconsistent");
    Passed("empty >= float(-1.0)");
    resultA = var1->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= float(-1.0) should have been false");
    resultB = var9->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= float(-1.0) is inconsistent");
    Passed("empty <= float(-1.0)");

// Evaluating empty against hash
    resultA = var1->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "empty == hash should have been false");
    resultB = var10->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == hash is inconsistent");
    Passed("empty == hash");
    resultA = var1->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != hash should have been true");
    resultB = var10->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != hash is inconsistent");
    Passed("empty != hash");
    resultA = var1->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "empty < hash should have been false");
    resultB = var10->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < hash is inconsistent");
    Passed("empty < hash");
    resultA = var1->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= hash should have been false");
    resultB = var10->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= hash is inconsistent");
    Passed("empty >= hash");
    resultA = var1->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= hash should have been false");
    resultB = var10->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= hash is inconsistent");
    Passed("empty <= hash");

// Evaluating empty against array()
    resultA = var1->Compare(var11, ConditionalEquals);
    Assert(resultA == true,
           "empty == array() should have been true");
    resultB = var11->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == array() is inconsistent");
    Passed("empty == array()");
    resultA = var1->Compare(var11, ConditionalNotEquals);
    Assert(resultA == false,
           "empty != array() should have been false");
    resultB = var11->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != array() is inconsistent");
    Passed("empty != array()");
    resultA = var1->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "empty < array() should have been false");
    resultB = var11->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < array() is inconsistent");
    Passed("empty < array()");
    resultA = var1->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= array() should have been false");
    resultB = var11->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= array() is inconsistent");
    Passed("empty >= array()");
    resultA = var1->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= array() should have been false");
    resultB = var11->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= array() is inconsistent");
    Passed("empty <= array()");

// Evaluating empty against array(..)
    resultA = var1->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "empty == array(..) should have been false");
    resultB = var12->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == array(..) is inconsistent");
    Passed("empty == array(..)");
    resultA = var1->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != array(..) should have been true");
    resultB = var12->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != array(..) is inconsistent");
    Passed("empty != array(..)");
    resultA = var1->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "empty < array(..) should have been false");
    resultB = var12->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < array(..) is inconsistent");
    Passed("empty < array(..)");
    resultA = var1->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= array(..) should have been false");
    resultB = var12->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= array(..) is inconsistent");
    Passed("empty >= array(..)");
    resultA = var1->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= array(..) should have been false");
    resultB = var12->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= array(..) is inconsistent");
    Passed("empty <= array(..)");

// Evaluating empty against bool(true)
    resultA = var1->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "empty == bool(true) should have been false");
    resultB = var13->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == bool(true) is inconsistent");
    Passed("empty == bool(true)");
    resultA = var1->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != bool(true) should have been true");
    resultB = var13->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != bool(true) is inconsistent");
    Passed("empty != bool(true)");
    resultA = var1->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "empty < bool(true) should have been false");
    resultB = var13->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < bool(true) is inconsistent");
    Passed("empty < bool(true)");
    resultA = var1->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= bool(true) should have been false");
    resultB = var13->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= bool(true) is inconsistent");
    Passed("empty >= bool(true)");
    resultA = var1->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= bool(true) should have been false");
    resultB = var13->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= bool(true) is inconsistent");
    Passed("empty <= bool(true)");

// Evaluating empty against bool(false)
    resultA = var1->Compare(var14, ConditionalEquals);
    Assert(resultA == false,
           "empty == bool(false) should have been false");
    resultB = var14->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == bool(false) is inconsistent");
    Passed("empty == bool(false)");
    resultA = var1->Compare(var14, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != bool(false) should have been true");
    resultB = var14->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != bool(false) is inconsistent");
    Passed("empty != bool(false)");
    resultA = var1->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "empty < bool(false) should have been false");
    resultB = var14->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < bool(false) is inconsistent");
    Passed("empty < bool(false)");
    resultA = var1->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= bool(false) should have been false");
    resultB = var14->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= bool(false) is inconsistent");
    Passed("empty >= bool(false)");
    resultA = var1->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= bool(false) should have been false");
    resultB = var14->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= bool(false) is inconsistent");
    Passed("empty <= bool(false)");

// Evaluating empty against string("")
    resultA = var1->Compare(var15, ConditionalEquals);
    Assert(resultA == true,
           "empty == string(\"\") should have been true");
    resultB = var15->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == string(\"\") is inconsistent");
    Passed("empty == string(\"\")");
    resultA = var1->Compare(var15, ConditionalNotEquals);
    Assert(resultA == false,
           "empty != string(\"\") should have been false");
    resultB = var15->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != string(\"\") is inconsistent");
    Passed("empty != string(\"\")");
    resultA = var1->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "empty < string(\"\") should have been false");
    resultB = var15->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < string(\"\") is inconsistent");
    Passed("empty < string(\"\")");
    resultA = var1->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= string(\"\") should have been false");
    resultB = var15->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= string(\"\") is inconsistent");
    Passed("empty >= string(\"\")");
    resultA = var1->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= string(\"\") should have been false");
    resultB = var15->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= string(\"\") is inconsistent");
    Passed("empty <= string(\"\")");

// Evaluating empty against string("..")
    resultA = var1->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "empty == string(\"..\") should have been false");
    resultB = var16->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == string(\"..\") is inconsistent");
    Passed("empty == string(\"..\")");
    resultA = var1->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != string(\"..\") should have been true");
    resultB = var16->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != string(\"..\") is inconsistent");
    Passed("empty != string(\"..\")");
    resultA = var1->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "empty < string(\"..\") should have been false");
    resultB = var16->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < string(\"..\") is inconsistent");
    Passed("empty < string(\"..\")");
    resultA = var1->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= string(\"..\") should have been false");
    resultB = var16->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= string(\"..\") is inconsistent");
    Passed("empty >= string(\"..\")");
    resultA = var1->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= string(\"..\") should have been false");
    resultB = var16->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= string(\"..\") is inconsistent");
    Passed("empty <= string(\"..\")");

// Evaluating empty against string("t")
    resultA = var1->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "empty == string(\"t\") should have been false");
    resultB = var17->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == string(\"t\") is inconsistent");
    Passed("empty == string(\"t\")");
    resultA = var1->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != string(\"t\") should have been true");
    resultB = var17->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != string(\"t\") is inconsistent");
    Passed("empty != string(\"t\")");
    resultA = var1->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "empty < string(\"t\") should have been false");
    resultB = var17->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < string(\"t\") is inconsistent");
    Passed("empty < string(\"t\")");
    resultA = var1->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= string(\"t\") should have been false");
    resultB = var17->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= string(\"t\") is inconsistent");
    Passed("empty >= string(\"t\")");
    resultA = var1->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= string(\"t\") should have been false");
    resultB = var17->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= string(\"t\") is inconsistent");
    Passed("empty <= string(\"t\")");

// Evaluating empty against string("f")
    resultA = var1->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "empty == string(\"f\") should have been false");
    resultB = var18->Compare(var1, ConditionalEquals);
    Assert(resultA == resultB,
           "empty == string(\"f\") is inconsistent");
    Passed("empty == string(\"f\")");
    resultA = var1->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "empty != string(\"f\") should have been true");
    resultB = var18->Compare(var1, ConditionalNotEquals);
    Assert(resultA == resultB,
           "empty != string(\"f\") is inconsistent");
    Passed("empty != string(\"f\")");
    resultA = var1->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "empty < string(\"f\") should have been false");
    resultB = var18->Compare(var1, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "empty < string(\"f\") is inconsistent");
    Passed("empty < string(\"f\")");
    resultA = var1->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "empty >= string(\"f\") should have been false");
    resultB = var18->Compare(var1, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "empty >= string(\"f\") is inconsistent");
    Passed("empty >= string(\"f\")");
    resultA = var1->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "empty <= string(\"f\") should have been false");
    resultB = var18->Compare(var1, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "empty <= string(\"f\") is inconsistent");
    Passed("empty <= string(\"f\")");

// * Evaluating int(0)
    Assert(var2->Compare(NULL, ConditionalImplicit) == false,
           "Implicit test of int(0) failed");
    Passed("Implicit test of int(0)");

// Evaluating int(0) against int(0)
    resultA = var2->Compare(var2, ConditionalEquals);
    Assert(resultA == true,
           "int(0) == int(0) should have been true");
    resultB = var2->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == int(0) is inconsistent");
    Passed("int(0) == int(0)");
    resultA = var2->Compare(var2, ConditionalNotEquals);
    Assert(resultA == false,
           "int(0) != int(0) should have been false");
    resultB = var2->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != int(0) is inconsistent");
    Passed("int(0) != int(0)");
    resultA = var2->Compare(var2, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < int(0) should have been false");
    resultB = var2->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < int(0) is inconsistent");
    Passed("int(0) < int(0)");
    resultA = var2->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(0) >= int(0) should have been true");
    resultB = var2->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= int(0) is inconsistent");
    Passed("int(0) >= int(0)");
    resultA = var2->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(0) <= int(0) should have been true");
    resultB = var2->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= int(0) is inconsistent");
    Passed("int(0) <= int(0)");

// Evaluating int(0) against int(1)
    resultA = var2->Compare(var3, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == int(1) should have been false");
    resultB = var3->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == int(1) is inconsistent");
    Passed("int(0) == int(1)");
    resultA = var2->Compare(var3, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != int(1) should have been true");
    resultB = var3->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != int(1) is inconsistent");
    Passed("int(0) != int(1)");
    resultA = var2->Compare(var3, ConditionalLessThan);
    Assert(resultA == true,
           "int(0) < int(1) should have been true");
    resultB = var3->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < int(1) is inconsistent");
    Passed("int(0) < int(1)");
    resultA = var2->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= int(1) should have been false");
    resultB = var3->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= int(1) is inconsistent");
    Passed("int(0) >= int(1)");
    resultA = var2->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(0) <= int(1) should have been true");
    resultB = var3->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= int(1) is inconsistent");
    Passed("int(0) <= int(1)");

// Evaluating int(0) against int(-1)
    resultA = var2->Compare(var4, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == int(-1) should have been false");
    resultB = var4->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == int(-1) is inconsistent");
    Passed("int(0) == int(-1)");
    resultA = var2->Compare(var4, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != int(-1) should have been true");
    resultB = var4->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != int(-1) is inconsistent");
    Passed("int(0) != int(-1)");
    resultA = var2->Compare(var4, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < int(-1) should have been false");
    resultB = var4->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < int(-1) is inconsistent");
    Passed("int(0) < int(-1)");
    resultA = var2->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(0) >= int(-1) should have been true");
    resultB = var4->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= int(-1) is inconsistent");
    Passed("int(0) >= int(-1)");
    resultA = var2->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= int(-1) should have been false");
    resultB = var4->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= int(-1) is inconsistent");
    Passed("int(0) <= int(-1)");

// Evaluating int(0) against float(0.0)
    resultA = var2->Compare(var5, ConditionalEquals);
    Assert(resultA == true,
           "int(0) == float(0.0) should have been true");
    resultB = var5->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == float(0.0) is inconsistent");
    Passed("int(0) == float(0.0)");
    resultA = var2->Compare(var5, ConditionalNotEquals);
    Assert(resultA == false,
           "int(0) != float(0.0) should have been false");
    resultB = var5->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != float(0.0) is inconsistent");
    Passed("int(0) != float(0.0)");
    resultA = var2->Compare(var5, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < float(0.0) should have been false");
    resultB = var5->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < float(0.0) is inconsistent");
    Passed("int(0) < float(0.0)");
    resultA = var2->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(0) >= float(0.0) should have been true");
    resultB = var5->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= float(0.0) is inconsistent");
    Passed("int(0) >= float(0.0)");
    resultA = var2->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(0) <= float(0.0) should have been true");
    resultB = var5->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= float(0.0) is inconsistent");
    Passed("int(0) <= float(0.0)");

// Evaluating int(0) against float(0.1)
    resultA = var2->Compare(var6, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == float(0.1) should have been false");
    resultB = var6->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == float(0.1) is inconsistent");
    Passed("int(0) == float(0.1)");
    resultA = var2->Compare(var6, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != float(0.1) should have been true");
    resultB = var6->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != float(0.1) is inconsistent");
    Passed("int(0) != float(0.1)");
    resultA = var2->Compare(var6, ConditionalLessThan);
    Assert(resultA == true,
           "int(0) < float(0.1) should have been true");
    resultB = var6->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < float(0.1) is inconsistent");
    Passed("int(0) < float(0.1)");
    resultA = var2->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= float(0.1) should have been false");
    resultB = var6->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= float(0.1) is inconsistent");
    Passed("int(0) >= float(0.1)");
    resultA = var2->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(0) <= float(0.1) should have been true");
    resultB = var6->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= float(0.1) is inconsistent");
    Passed("int(0) <= float(0.1)");

// Evaluating int(0) against float(1.0)
    resultA = var2->Compare(var7, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == float(1.0) should have been false");
    resultB = var7->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == float(1.0) is inconsistent");
    Passed("int(0) == float(1.0)");
    resultA = var2->Compare(var7, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != float(1.0) should have been true");
    resultB = var7->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != float(1.0) is inconsistent");
    Passed("int(0) != float(1.0)");
    resultA = var2->Compare(var7, ConditionalLessThan);
    Assert(resultA == true,
           "int(0) < float(1.0) should have been true");
    resultB = var7->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < float(1.0) is inconsistent");
    Passed("int(0) < float(1.0)");
    resultA = var2->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= float(1.0) should have been false");
    resultB = var7->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= float(1.0) is inconsistent");
    Passed("int(0) >= float(1.0)");
    resultA = var2->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(0) <= float(1.0) should have been true");
    resultB = var7->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= float(1.0) is inconsistent");
    Passed("int(0) <= float(1.0)");

// Evaluating int(0) against float(-0.1)
    resultA = var2->Compare(var8, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == float(-0.1) should have been false");
    resultB = var8->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == float(-0.1) is inconsistent");
    Passed("int(0) == float(-0.1)");
    resultA = var2->Compare(var8, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != float(-0.1) should have been true");
    resultB = var8->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != float(-0.1) is inconsistent");
    Passed("int(0) != float(-0.1)");
    resultA = var2->Compare(var8, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < float(-0.1) should have been false");
    resultB = var8->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < float(-0.1) is inconsistent");
    Passed("int(0) < float(-0.1)");
    resultA = var2->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(0) >= float(-0.1) should have been true");
    resultB = var8->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= float(-0.1) is inconsistent");
    Passed("int(0) >= float(-0.1)");
    resultA = var2->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= float(-0.1) should have been false");
    resultB = var8->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= float(-0.1) is inconsistent");
    Passed("int(0) <= float(-0.1)");

// Evaluating int(0) against float(-1.0)
    resultA = var2->Compare(var9, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == float(-1.0) should have been false");
    resultB = var9->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == float(-1.0) is inconsistent");
    Passed("int(0) == float(-1.0)");
    resultA = var2->Compare(var9, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != float(-1.0) should have been true");
    resultB = var9->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != float(-1.0) is inconsistent");
    Passed("int(0) != float(-1.0)");
    resultA = var2->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < float(-1.0) should have been false");
    resultB = var9->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < float(-1.0) is inconsistent");
    Passed("int(0) < float(-1.0)");
    resultA = var2->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(0) >= float(-1.0) should have been true");
    resultB = var9->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= float(-1.0) is inconsistent");
    Passed("int(0) >= float(-1.0)");
    resultA = var2->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= float(-1.0) should have been false");
    resultB = var9->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= float(-1.0) is inconsistent");
    Passed("int(0) <= float(-1.0)");

// Evaluating int(0) against hash
    resultA = var2->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == hash should have been false");
    resultB = var10->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == hash is inconsistent");
    Passed("int(0) == hash");
    resultA = var2->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != hash should have been true");
    resultB = var10->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != hash is inconsistent");
    Passed("int(0) != hash");
    resultA = var2->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < hash should have been false");
    resultB = var10->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < hash is inconsistent");
    Passed("int(0) < hash");
    resultA = var2->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= hash should have been false");
    resultB = var10->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= hash is inconsistent");
    Passed("int(0) >= hash");
    resultA = var2->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= hash should have been false");
    resultB = var10->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= hash is inconsistent");
    Passed("int(0) <= hash");

// Evaluating int(0) against array()
    resultA = var2->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == array() should have been false");
    resultB = var11->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == array() is inconsistent");
    Passed("int(0) == array()");
    resultA = var2->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != array() should have been true");
    resultB = var11->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != array() is inconsistent");
    Passed("int(0) != array()");
    resultA = var2->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < array() should have been false");
    resultB = var11->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < array() is inconsistent");
    Passed("int(0) < array()");
    resultA = var2->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= array() should have been false");
    resultB = var11->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= array() is inconsistent");
    Passed("int(0) >= array()");
    resultA = var2->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= array() should have been false");
    resultB = var11->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= array() is inconsistent");
    Passed("int(0) <= array()");

// Evaluating int(0) against array(..)
    resultA = var2->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == array(..) should have been false");
    resultB = var12->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == array(..) is inconsistent");
    Passed("int(0) == array(..)");
    resultA = var2->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != array(..) should have been true");
    resultB = var12->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != array(..) is inconsistent");
    Passed("int(0) != array(..)");
    resultA = var2->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < array(..) should have been false");
    resultB = var12->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < array(..) is inconsistent");
    Passed("int(0) < array(..)");
    resultA = var2->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= array(..) should have been false");
    resultB = var12->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= array(..) is inconsistent");
    Passed("int(0) >= array(..)");
    resultA = var2->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= array(..) should have been false");
    resultB = var12->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= array(..) is inconsistent");
    Passed("int(0) <= array(..)");

// Evaluating int(0) against bool(true)
    resultA = var2->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == bool(true) should have been false");
    resultB = var13->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == bool(true) is inconsistent");
    Passed("int(0) == bool(true)");
    resultA = var2->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != bool(true) should have been true");
    resultB = var13->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != bool(true) is inconsistent");
    Passed("int(0) != bool(true)");
    resultA = var2->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < bool(true) should have been false");
    resultB = var13->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < bool(true) is inconsistent");
    Passed("int(0) < bool(true)");
    resultA = var2->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= bool(true) should have been false");
    resultB = var13->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= bool(true) is inconsistent");
    Passed("int(0) >= bool(true)");
    resultA = var2->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= bool(true) should have been false");
    resultB = var13->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= bool(true) is inconsistent");
    Passed("int(0) <= bool(true)");

// Evaluating int(0) against bool(false)
    resultA = var2->Compare(var14, ConditionalEquals);
    Assert(resultA == true,
           "int(0) == bool(false) should have been true");
    resultB = var14->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == bool(false) is inconsistent");
    Passed("int(0) == bool(false)");
    resultA = var2->Compare(var14, ConditionalNotEquals);
    Assert(resultA == false,
           "int(0) != bool(false) should have been false");
    resultB = var14->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != bool(false) is inconsistent");
    Passed("int(0) != bool(false)");
    resultA = var2->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < bool(false) should have been false");
    resultB = var14->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < bool(false) is inconsistent");
    Passed("int(0) < bool(false)");
    resultA = var2->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= bool(false) should have been false");
    resultB = var14->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= bool(false) is inconsistent");
    Passed("int(0) >= bool(false)");
    resultA = var2->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= bool(false) should have been false");
    resultB = var14->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= bool(false) is inconsistent");
    Passed("int(0) <= bool(false)");

// Evaluating int(0) against string("")
    resultA = var2->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == string(\"\") should have been false");
    resultB = var15->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == string(\"\") is inconsistent");
    Passed("int(0) == string(\"\")");
    resultA = var2->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != string(\"\") should have been true");
    resultB = var15->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != string(\"\") is inconsistent");
    Passed("int(0) != string(\"\")");
    resultA = var2->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < string(\"\") should have been false");
    resultB = var15->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < string(\"\") is inconsistent");
    Passed("int(0) < string(\"\")");
    resultA = var2->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= string(\"\") should have been false");
    resultB = var15->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= string(\"\") is inconsistent");
    Passed("int(0) >= string(\"\")");
    resultA = var2->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= string(\"\") should have been false");
    resultB = var15->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= string(\"\") is inconsistent");
    Passed("int(0) <= string(\"\")");

// Evaluating int(0) against string("..")
    resultA = var2->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == string(\"..\") should have been false");
    resultB = var16->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == string(\"..\") is inconsistent");
    Passed("int(0) == string(\"..\")");
    resultA = var2->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != string(\"..\") should have been true");
    resultB = var16->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != string(\"..\") is inconsistent");
    Passed("int(0) != string(\"..\")");
    resultA = var2->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < string(\"..\") should have been false");
    resultB = var16->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < string(\"..\") is inconsistent");
    Passed("int(0) < string(\"..\")");
    resultA = var2->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= string(\"..\") should have been false");
    resultB = var16->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= string(\"..\") is inconsistent");
    Passed("int(0) >= string(\"..\")");
    resultA = var2->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= string(\"..\") should have been false");
    resultB = var16->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= string(\"..\") is inconsistent");
    Passed("int(0) <= string(\"..\")");

// Evaluating int(0) against string("t")
    resultA = var2->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == string(\"t\") should have been false");
    resultB = var17->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == string(\"t\") is inconsistent");
    Passed("int(0) == string(\"t\")");
    resultA = var2->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != string(\"t\") should have been true");
    resultB = var17->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != string(\"t\") is inconsistent");
    Passed("int(0) != string(\"t\")");
    resultA = var2->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < string(\"t\") should have been false");
    resultB = var17->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < string(\"t\") is inconsistent");
    Passed("int(0) < string(\"t\")");
    resultA = var2->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= string(\"t\") should have been false");
    resultB = var17->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= string(\"t\") is inconsistent");
    Passed("int(0) >= string(\"t\")");
    resultA = var2->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= string(\"t\") should have been false");
    resultB = var17->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= string(\"t\") is inconsistent");
    Passed("int(0) <= string(\"t\")");

// Evaluating int(0) against string("f")
    resultA = var2->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "int(0) == string(\"f\") should have been false");
    resultB = var18->Compare(var2, ConditionalEquals);
    Assert(resultA == resultB,
           "int(0) == string(\"f\") is inconsistent");
    Passed("int(0) == string(\"f\")");
    resultA = var2->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "int(0) != string(\"f\") should have been true");
    resultB = var18->Compare(var2, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(0) != string(\"f\") is inconsistent");
    Passed("int(0) != string(\"f\")");
    resultA = var2->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "int(0) < string(\"f\") should have been false");
    resultB = var18->Compare(var2, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(0) < string(\"f\") is inconsistent");
    Passed("int(0) < string(\"f\")");
    resultA = var2->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(0) >= string(\"f\") should have been false");
    resultB = var18->Compare(var2, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(0) >= string(\"f\") is inconsistent");
    Passed("int(0) >= string(\"f\")");
    resultA = var2->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(0) <= string(\"f\") should have been false");
    resultB = var18->Compare(var2, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(0) <= string(\"f\") is inconsistent");
    Passed("int(0) <= string(\"f\")");

// * Evaluating int(1)
    Assert(var3->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of int(1) failed");
    Passed("Implicit test of int(1)");

// Evaluating int(1) against int(1)
    resultA = var3->Compare(var3, ConditionalEquals);
    Assert(resultA == true,
           "int(1) == int(1) should have been true");
    resultB = var3->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == int(1) is inconsistent");
    Passed("int(1) == int(1)");
    resultA = var3->Compare(var3, ConditionalNotEquals);
    Assert(resultA == false,
           "int(1) != int(1) should have been false");
    resultB = var3->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != int(1) is inconsistent");
    Passed("int(1) != int(1)");
    resultA = var3->Compare(var3, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < int(1) should have been false");
    resultB = var3->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < int(1) is inconsistent");
    Passed("int(1) < int(1)");
    resultA = var3->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(1) >= int(1) should have been true");
    resultB = var3->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= int(1) is inconsistent");
    Passed("int(1) >= int(1)");
    resultA = var3->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(1) <= int(1) should have been true");
    resultB = var3->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= int(1) is inconsistent");
    Passed("int(1) <= int(1)");

// Evaluating int(1) against int(-1)
    resultA = var3->Compare(var4, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == int(-1) should have been false");
    resultB = var4->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == int(-1) is inconsistent");
    Passed("int(1) == int(-1)");
    resultA = var3->Compare(var4, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != int(-1) should have been true");
    resultB = var4->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != int(-1) is inconsistent");
    Passed("int(1) != int(-1)");
    resultA = var3->Compare(var4, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < int(-1) should have been false");
    resultB = var4->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < int(-1) is inconsistent");
    Passed("int(1) < int(-1)");
    resultA = var3->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(1) >= int(-1) should have been true");
    resultB = var4->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= int(-1) is inconsistent");
    Passed("int(1) >= int(-1)");
    resultA = var3->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= int(-1) should have been false");
    resultB = var4->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= int(-1) is inconsistent");
    Passed("int(1) <= int(-1)");

// Evaluating int(1) against float(0.0)
    resultA = var3->Compare(var5, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == float(0.0) should have been false");
    resultB = var5->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == float(0.0) is inconsistent");
    Passed("int(1) == float(0.0)");
    resultA = var3->Compare(var5, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != float(0.0) should have been true");
    resultB = var5->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != float(0.0) is inconsistent");
    Passed("int(1) != float(0.0)");
    resultA = var3->Compare(var5, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < float(0.0) should have been false");
    resultB = var5->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < float(0.0) is inconsistent");
    Passed("int(1) < float(0.0)");
    resultA = var3->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(1) >= float(0.0) should have been true");
    resultB = var5->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= float(0.0) is inconsistent");
    Passed("int(1) >= float(0.0)");
    resultA = var3->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= float(0.0) should have been false");
    resultB = var5->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= float(0.0) is inconsistent");
    Passed("int(1) <= float(0.0)");

// Evaluating int(1) against float(0.1)
    resultA = var3->Compare(var6, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == float(0.1) should have been false");
    resultB = var6->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == float(0.1) is inconsistent");
    Passed("int(1) == float(0.1)");
    resultA = var3->Compare(var6, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != float(0.1) should have been true");
    resultB = var6->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != float(0.1) is inconsistent");
    Passed("int(1) != float(0.1)");
    resultA = var3->Compare(var6, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < float(0.1) should have been false");
    resultB = var6->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < float(0.1) is inconsistent");
    Passed("int(1) < float(0.1)");
    resultA = var3->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(1) >= float(0.1) should have been true");
    resultB = var6->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= float(0.1) is inconsistent");
    Passed("int(1) >= float(0.1)");
    resultA = var3->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= float(0.1) should have been false");
    resultB = var6->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= float(0.1) is inconsistent");
    Passed("int(1) <= float(0.1)");

// Evaluating int(1) against float(1.0)
    resultA = var3->Compare(var7, ConditionalEquals);
    Assert(resultA == true,
           "int(1) == float(1.0) should have been true");
    resultB = var7->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == float(1.0) is inconsistent");
    Passed("int(1) == float(1.0)");
    resultA = var3->Compare(var7, ConditionalNotEquals);
    Assert(resultA == false,
           "int(1) != float(1.0) should have been false");
    resultB = var7->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != float(1.0) is inconsistent");
    Passed("int(1) != float(1.0)");
    resultA = var3->Compare(var7, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < float(1.0) should have been false");
    resultB = var7->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < float(1.0) is inconsistent");
    Passed("int(1) < float(1.0)");
    resultA = var3->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(1) >= float(1.0) should have been true");
    resultB = var7->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= float(1.0) is inconsistent");
    Passed("int(1) >= float(1.0)");
    resultA = var3->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(1) <= float(1.0) should have been true");
    resultB = var7->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= float(1.0) is inconsistent");
    Passed("int(1) <= float(1.0)");

// Evaluating int(1) against float(-0.1)
    resultA = var3->Compare(var8, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == float(-0.1) should have been false");
    resultB = var8->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == float(-0.1) is inconsistent");
    Passed("int(1) == float(-0.1)");
    resultA = var3->Compare(var8, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != float(-0.1) should have been true");
    resultB = var8->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != float(-0.1) is inconsistent");
    Passed("int(1) != float(-0.1)");
    resultA = var3->Compare(var8, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < float(-0.1) should have been false");
    resultB = var8->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < float(-0.1) is inconsistent");
    Passed("int(1) < float(-0.1)");
    resultA = var3->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(1) >= float(-0.1) should have been true");
    resultB = var8->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= float(-0.1) is inconsistent");
    Passed("int(1) >= float(-0.1)");
    resultA = var3->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= float(-0.1) should have been false");
    resultB = var8->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= float(-0.1) is inconsistent");
    Passed("int(1) <= float(-0.1)");

// Evaluating int(1) against float(-1.0)
    resultA = var3->Compare(var9, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == float(-1.0) should have been false");
    resultB = var9->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == float(-1.0) is inconsistent");
    Passed("int(1) == float(-1.0)");
    resultA = var3->Compare(var9, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != float(-1.0) should have been true");
    resultB = var9->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != float(-1.0) is inconsistent");
    Passed("int(1) != float(-1.0)");
    resultA = var3->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < float(-1.0) should have been false");
    resultB = var9->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < float(-1.0) is inconsistent");
    Passed("int(1) < float(-1.0)");
    resultA = var3->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(1) >= float(-1.0) should have been true");
    resultB = var9->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= float(-1.0) is inconsistent");
    Passed("int(1) >= float(-1.0)");
    resultA = var3->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= float(-1.0) should have been false");
    resultB = var9->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= float(-1.0) is inconsistent");
    Passed("int(1) <= float(-1.0)");

// Evaluating int(1) against hash
    resultA = var3->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == hash should have been false");
    resultB = var10->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == hash is inconsistent");
    Passed("int(1) == hash");
    resultA = var3->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != hash should have been true");
    resultB = var10->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != hash is inconsistent");
    Passed("int(1) != hash");
    resultA = var3->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < hash should have been false");
    resultB = var10->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < hash is inconsistent");
    Passed("int(1) < hash");
    resultA = var3->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(1) >= hash should have been false");
    resultB = var10->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= hash is inconsistent");
    Passed("int(1) >= hash");
    resultA = var3->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= hash should have been false");
    resultB = var10->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= hash is inconsistent");
    Passed("int(1) <= hash");

// Evaluating int(1) against array()
    resultA = var3->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == array() should have been false");
    resultB = var11->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == array() is inconsistent");
    Passed("int(1) == array()");
    resultA = var3->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != array() should have been true");
    resultB = var11->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != array() is inconsistent");
    Passed("int(1) != array()");
    resultA = var3->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < array() should have been false");
    resultB = var11->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < array() is inconsistent");
    Passed("int(1) < array()");
    resultA = var3->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(1) >= array() should have been false");
    resultB = var11->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= array() is inconsistent");
    Passed("int(1) >= array()");
    resultA = var3->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= array() should have been false");
    resultB = var11->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= array() is inconsistent");
    Passed("int(1) <= array()");

// Evaluating int(1) against array(..)
    resultA = var3->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == array(..) should have been false");
    resultB = var12->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == array(..) is inconsistent");
    Passed("int(1) == array(..)");
    resultA = var3->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != array(..) should have been true");
    resultB = var12->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != array(..) is inconsistent");
    Passed("int(1) != array(..)");
    resultA = var3->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < array(..) should have been false");
    resultB = var12->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < array(..) is inconsistent");
    Passed("int(1) < array(..)");
    resultA = var3->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(1) >= array(..) should have been false");
    resultB = var12->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= array(..) is inconsistent");
    Passed("int(1) >= array(..)");
    resultA = var3->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= array(..) should have been false");
    resultB = var12->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= array(..) is inconsistent");
    Passed("int(1) <= array(..)");

// Evaluating int(1) against bool(true)
    resultA = var3->Compare(var13, ConditionalEquals);
    Assert(resultA == true,
           "int(1) == bool(true) should have been true");
    resultB = var13->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == bool(true) is inconsistent");
    Passed("int(1) == bool(true)");
    resultA = var3->Compare(var13, ConditionalNotEquals);
    Assert(resultA == false,
           "int(1) != bool(true) should have been false");
    resultB = var13->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != bool(true) is inconsistent");
    Passed("int(1) != bool(true)");
    resultA = var3->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < bool(true) should have been false");
    resultB = var13->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < bool(true) is inconsistent");
    Passed("int(1) < bool(true)");
    resultA = var3->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(1) >= bool(true) should have been false");
    resultB = var13->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= bool(true) is inconsistent");
    Passed("int(1) >= bool(true)");
    resultA = var3->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= bool(true) should have been false");
    resultB = var13->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= bool(true) is inconsistent");
    Passed("int(1) <= bool(true)");

// Evaluating int(1) against bool(false)
    resultA = var3->Compare(var14, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == bool(false) should have been false");
    resultB = var14->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == bool(false) is inconsistent");
    Passed("int(1) == bool(false)");
    resultA = var3->Compare(var14, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != bool(false) should have been true");
    resultB = var14->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != bool(false) is inconsistent");
    Passed("int(1) != bool(false)");
    resultA = var3->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < bool(false) should have been false");
    resultB = var14->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < bool(false) is inconsistent");
    Passed("int(1) < bool(false)");
    resultA = var3->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(1) >= bool(false) should have been false");
    resultB = var14->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= bool(false) is inconsistent");
    Passed("int(1) >= bool(false)");
    resultA = var3->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= bool(false) should have been false");
    resultB = var14->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= bool(false) is inconsistent");
    Passed("int(1) <= bool(false)");

// Evaluating int(1) against string("")
    resultA = var3->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == string(\"\") should have been false");
    resultB = var15->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == string(\"\") is inconsistent");
    Passed("int(1) == string(\"\")");
    resultA = var3->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != string(\"\") should have been true");
    resultB = var15->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != string(\"\") is inconsistent");
    Passed("int(1) != string(\"\")");
    resultA = var3->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < string(\"\") should have been false");
    resultB = var15->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < string(\"\") is inconsistent");
    Passed("int(1) < string(\"\")");
    resultA = var3->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(1) >= string(\"\") should have been false");
    resultB = var15->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= string(\"\") is inconsistent");
    Passed("int(1) >= string(\"\")");
    resultA = var3->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= string(\"\") should have been false");
    resultB = var15->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= string(\"\") is inconsistent");
    Passed("int(1) <= string(\"\")");

// Evaluating int(1) against string("..")
    resultA = var3->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == string(\"..\") should have been false");
    resultB = var16->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == string(\"..\") is inconsistent");
    Passed("int(1) == string(\"..\")");
    resultA = var3->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != string(\"..\") should have been true");
    resultB = var16->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != string(\"..\") is inconsistent");
    Passed("int(1) != string(\"..\")");
    resultA = var3->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < string(\"..\") should have been false");
    resultB = var16->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < string(\"..\") is inconsistent");
    Passed("int(1) < string(\"..\")");
    resultA = var3->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(1) >= string(\"..\") should have been false");
    resultB = var16->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= string(\"..\") is inconsistent");
    Passed("int(1) >= string(\"..\")");
    resultA = var3->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= string(\"..\") should have been false");
    resultB = var16->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= string(\"..\") is inconsistent");
    Passed("int(1) <= string(\"..\")");

// Evaluating int(1) against string("t")
    resultA = var3->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == string(\"t\") should have been false");
    resultB = var17->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == string(\"t\") is inconsistent");
    Passed("int(1) == string(\"t\")");
    resultA = var3->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != string(\"t\") should have been true");
    resultB = var17->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != string(\"t\") is inconsistent");
    Passed("int(1) != string(\"t\")");
    resultA = var3->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < string(\"t\") should have been false");
    resultB = var17->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < string(\"t\") is inconsistent");
    Passed("int(1) < string(\"t\")");
    resultA = var3->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(1) >= string(\"t\") should have been false");
    resultB = var17->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= string(\"t\") is inconsistent");
    Passed("int(1) >= string(\"t\")");
    resultA = var3->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= string(\"t\") should have been false");
    resultB = var17->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= string(\"t\") is inconsistent");
    Passed("int(1) <= string(\"t\")");

// Evaluating int(1) against string("f")
    resultA = var3->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "int(1) == string(\"f\") should have been false");
    resultB = var18->Compare(var3, ConditionalEquals);
    Assert(resultA == resultB,
           "int(1) == string(\"f\") is inconsistent");
    Passed("int(1) == string(\"f\")");
    resultA = var3->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "int(1) != string(\"f\") should have been true");
    resultB = var18->Compare(var3, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(1) != string(\"f\") is inconsistent");
    Passed("int(1) != string(\"f\")");
    resultA = var3->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "int(1) < string(\"f\") should have been false");
    resultB = var18->Compare(var3, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(1) < string(\"f\") is inconsistent");
    Passed("int(1) < string(\"f\")");
    resultA = var3->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(1) >= string(\"f\") should have been false");
    resultB = var18->Compare(var3, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(1) >= string(\"f\") is inconsistent");
    Passed("int(1) >= string(\"f\")");
    resultA = var3->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(1) <= string(\"f\") should have been false");
    resultB = var18->Compare(var3, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(1) <= string(\"f\") is inconsistent");
    Passed("int(1) <= string(\"f\")");

// * Evaluating int(-1)
    Assert(var4->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of int(-1) failed");
    Passed("Implicit test of int(-1)");

// Evaluating int(-1) against int(-1)
    resultA = var4->Compare(var4, ConditionalEquals);
    Assert(resultA == true,
           "int(-1) == int(-1) should have been true");
    resultB = var4->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == int(-1) is inconsistent");
    Passed("int(-1) == int(-1)");
    resultA = var4->Compare(var4, ConditionalNotEquals);
    Assert(resultA == false,
           "int(-1) != int(-1) should have been false");
    resultB = var4->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != int(-1) is inconsistent");
    Passed("int(-1) != int(-1)");
    resultA = var4->Compare(var4, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < int(-1) should have been false");
    resultB = var4->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < int(-1) is inconsistent");
    Passed("int(-1) < int(-1)");
    resultA = var4->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(-1) >= int(-1) should have been true");
    resultB = var4->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= int(-1) is inconsistent");
    Passed("int(-1) >= int(-1)");
    resultA = var4->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(-1) <= int(-1) should have been true");
    resultB = var4->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= int(-1) is inconsistent");
    Passed("int(-1) <= int(-1)");

// Evaluating int(-1) against float(0.0)
    resultA = var4->Compare(var5, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == float(0.0) should have been false");
    resultB = var5->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == float(0.0) is inconsistent");
    Passed("int(-1) == float(0.0)");
    resultA = var4->Compare(var5, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != float(0.0) should have been true");
    resultB = var5->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != float(0.0) is inconsistent");
    Passed("int(-1) != float(0.0)");
    resultA = var4->Compare(var5, ConditionalLessThan);
    Assert(resultA == true,
           "int(-1) < float(0.0) should have been true");
    resultB = var5->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < float(0.0) is inconsistent");
    Passed("int(-1) < float(0.0)");
    resultA = var4->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= float(0.0) should have been false");
    resultB = var5->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= float(0.0) is inconsistent");
    Passed("int(-1) >= float(0.0)");
    resultA = var4->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(-1) <= float(0.0) should have been true");
    resultB = var5->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= float(0.0) is inconsistent");
    Passed("int(-1) <= float(0.0)");

// Evaluating int(-1) against float(0.1)
    resultA = var4->Compare(var6, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == float(0.1) should have been false");
    resultB = var6->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == float(0.1) is inconsistent");
    Passed("int(-1) == float(0.1)");
    resultA = var4->Compare(var6, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != float(0.1) should have been true");
    resultB = var6->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != float(0.1) is inconsistent");
    Passed("int(-1) != float(0.1)");
    resultA = var4->Compare(var6, ConditionalLessThan);
    Assert(resultA == true,
           "int(-1) < float(0.1) should have been true");
    resultB = var6->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < float(0.1) is inconsistent");
    Passed("int(-1) < float(0.1)");
    resultA = var4->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= float(0.1) should have been false");
    resultB = var6->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= float(0.1) is inconsistent");
    Passed("int(-1) >= float(0.1)");
    resultA = var4->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(-1) <= float(0.1) should have been true");
    resultB = var6->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= float(0.1) is inconsistent");
    Passed("int(-1) <= float(0.1)");

// Evaluating int(-1) against float(1.0)
    resultA = var4->Compare(var7, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == float(1.0) should have been false");
    resultB = var7->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == float(1.0) is inconsistent");
    Passed("int(-1) == float(1.0)");
    resultA = var4->Compare(var7, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != float(1.0) should have been true");
    resultB = var7->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != float(1.0) is inconsistent");
    Passed("int(-1) != float(1.0)");
    resultA = var4->Compare(var7, ConditionalLessThan);
    Assert(resultA == true,
           "int(-1) < float(1.0) should have been true");
    resultB = var7->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < float(1.0) is inconsistent");
    Passed("int(-1) < float(1.0)");
    resultA = var4->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= float(1.0) should have been false");
    resultB = var7->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= float(1.0) is inconsistent");
    Passed("int(-1) >= float(1.0)");
    resultA = var4->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(-1) <= float(1.0) should have been true");
    resultB = var7->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= float(1.0) is inconsistent");
    Passed("int(-1) <= float(1.0)");

// Evaluating int(-1) against float(-0.1)
    resultA = var4->Compare(var8, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == float(-0.1) should have been false");
    resultB = var8->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == float(-0.1) is inconsistent");
    Passed("int(-1) == float(-0.1)");
    resultA = var4->Compare(var8, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != float(-0.1) should have been true");
    resultB = var8->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != float(-0.1) is inconsistent");
    Passed("int(-1) != float(-0.1)");
    resultA = var4->Compare(var8, ConditionalLessThan);
    Assert(resultA == true,
           "int(-1) < float(-0.1) should have been true");
    resultB = var8->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < float(-0.1) is inconsistent");
    Passed("int(-1) < float(-0.1)");
    resultA = var4->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= float(-0.1) should have been false");
    resultB = var8->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= float(-0.1) is inconsistent");
    Passed("int(-1) >= float(-0.1)");
    resultA = var4->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(-1) <= float(-0.1) should have been true");
    resultB = var8->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= float(-0.1) is inconsistent");
    Passed("int(-1) <= float(-0.1)");

// Evaluating int(-1) against float(-1.0)
    resultA = var4->Compare(var9, ConditionalEquals);
    Assert(resultA == true,
           "int(-1) == float(-1.0) should have been true");
    resultB = var9->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == float(-1.0) is inconsistent");
    Passed("int(-1) == float(-1.0)");
    resultA = var4->Compare(var9, ConditionalNotEquals);
    Assert(resultA == false,
           "int(-1) != float(-1.0) should have been false");
    resultB = var9->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != float(-1.0) is inconsistent");
    Passed("int(-1) != float(-1.0)");
    resultA = var4->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < float(-1.0) should have been false");
    resultB = var9->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < float(-1.0) is inconsistent");
    Passed("int(-1) < float(-1.0)");
    resultA = var4->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "int(-1) >= float(-1.0) should have been true");
    resultB = var9->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= float(-1.0) is inconsistent");
    Passed("int(-1) >= float(-1.0)");
    resultA = var4->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "int(-1) <= float(-1.0) should have been true");
    resultB = var9->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= float(-1.0) is inconsistent");
    Passed("int(-1) <= float(-1.0)");

// Evaluating int(-1) against hash
    resultA = var4->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == hash should have been false");
    resultB = var10->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == hash is inconsistent");
    Passed("int(-1) == hash");
    resultA = var4->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != hash should have been true");
    resultB = var10->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != hash is inconsistent");
    Passed("int(-1) != hash");
    resultA = var4->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < hash should have been false");
    resultB = var10->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < hash is inconsistent");
    Passed("int(-1) < hash");
    resultA = var4->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= hash should have been false");
    resultB = var10->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= hash is inconsistent");
    Passed("int(-1) >= hash");
    resultA = var4->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(-1) <= hash should have been false");
    resultB = var10->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= hash is inconsistent");
    Passed("int(-1) <= hash");

// Evaluating int(-1) against array()
    resultA = var4->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == array() should have been false");
    resultB = var11->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == array() is inconsistent");
    Passed("int(-1) == array()");
    resultA = var4->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != array() should have been true");
    resultB = var11->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != array() is inconsistent");
    Passed("int(-1) != array()");
    resultA = var4->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < array() should have been false");
    resultB = var11->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < array() is inconsistent");
    Passed("int(-1) < array()");
    resultA = var4->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= array() should have been false");
    resultB = var11->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= array() is inconsistent");
    Passed("int(-1) >= array()");
    resultA = var4->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(-1) <= array() should have been false");
    resultB = var11->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= array() is inconsistent");
    Passed("int(-1) <= array()");

// Evaluating int(-1) against array(..)
    resultA = var4->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == array(..) should have been false");
    resultB = var12->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == array(..) is inconsistent");
    Passed("int(-1) == array(..)");
    resultA = var4->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != array(..) should have been true");
    resultB = var12->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != array(..) is inconsistent");
    Passed("int(-1) != array(..)");
    resultA = var4->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < array(..) should have been false");
    resultB = var12->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < array(..) is inconsistent");
    Passed("int(-1) < array(..)");
    resultA = var4->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= array(..) should have been false");
    resultB = var12->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= array(..) is inconsistent");
    Passed("int(-1) >= array(..)");
    resultA = var4->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(-1) <= array(..) should have been false");
    resultB = var12->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= array(..) is inconsistent");
    Passed("int(-1) <= array(..)");

// Evaluating int(-1) against bool(true)
    resultA = var4->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == bool(true) should have been false");
    resultB = var13->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == bool(true) is inconsistent");
    Passed("int(-1) == bool(true)");
    resultA = var4->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != bool(true) should have been true");
    resultB = var13->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != bool(true) is inconsistent");
    Passed("int(-1) != bool(true)");
    resultA = var4->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < bool(true) should have been false");
    resultB = var13->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < bool(true) is inconsistent");
    Passed("int(-1) < bool(true)");
    resultA = var4->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= bool(true) should have been false");
    resultB = var13->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= bool(true) is inconsistent");
    Passed("int(-1) >= bool(true)");
    resultA = var4->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(-1) <= bool(true) should have been false");
    resultB = var13->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= bool(true) is inconsistent");
    Passed("int(-1) <= bool(true)");

// Evaluating int(-1) against bool(false)
    resultA = var4->Compare(var14, ConditionalEquals);
    Assert(resultA == true,
           "int(-1) == bool(false) should have been true");
    resultB = var14->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == bool(false) is inconsistent");
    Passed("int(-1) == bool(false)");
    resultA = var4->Compare(var14, ConditionalNotEquals);
    Assert(resultA == false,
           "int(-1) != bool(false) should have been false");
    resultB = var14->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != bool(false) is inconsistent");
    Passed("int(-1) != bool(false)");
    resultA = var4->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < bool(false) should have been false");
    resultB = var14->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < bool(false) is inconsistent");
    Passed("int(-1) < bool(false)");
    resultA = var4->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= bool(false) should have been false");
    resultB = var14->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= bool(false) is inconsistent");
    Passed("int(-1) >= bool(false)");
    resultA = var4->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(-1) <= bool(false) should have been false");
    resultB = var14->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= bool(false) is inconsistent");
    Passed("int(-1) <= bool(false)");

// Evaluating int(-1) against string("")
    resultA = var4->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == string(\"\") should have been false");
    resultB = var15->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == string(\"\") is inconsistent");
    Passed("int(-1) == string(\"\")");
    resultA = var4->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != string(\"\") should have been true");
    resultB = var15->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != string(\"\") is inconsistent");
    Passed("int(-1) != string(\"\")");
    resultA = var4->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < string(\"\") should have been false");
    resultB = var15->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < string(\"\") is inconsistent");
    Passed("int(-1) < string(\"\")");
    resultA = var4->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= string(\"\") should have been false");
    resultB = var15->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= string(\"\") is inconsistent");
    Passed("int(-1) >= string(\"\")");
    resultA = var4->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(-1) <= string(\"\") should have been false");
    resultB = var15->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= string(\"\") is inconsistent");
    Passed("int(-1) <= string(\"\")");

// Evaluating int(-1) against string("..")
    resultA = var4->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == string(\"..\") should have been false");
    resultB = var16->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == string(\"..\") is inconsistent");
    Passed("int(-1) == string(\"..\")");
    resultA = var4->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != string(\"..\") should have been true");
    resultB = var16->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != string(\"..\") is inconsistent");
    Passed("int(-1) != string(\"..\")");
    resultA = var4->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < string(\"..\") should have been false");
    resultB = var16->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < string(\"..\") is inconsistent");
    Passed("int(-1) < string(\"..\")");
    resultA = var4->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= string(\"..\") should have been false");
    resultB = var16->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= string(\"..\") is inconsistent");
    Passed("int(-1) >= string(\"..\")");
    resultA = var4->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(-1) <= string(\"..\") should have been false");
    resultB = var16->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= string(\"..\") is inconsistent");
    Passed("int(-1) <= string(\"..\")");

// Evaluating int(-1) against string("t")
    resultA = var4->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == string(\"t\") should have been false");
    resultB = var17->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == string(\"t\") is inconsistent");
    Passed("int(-1) == string(\"t\")");
    resultA = var4->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != string(\"t\") should have been true");
    resultB = var17->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != string(\"t\") is inconsistent");
    Passed("int(-1) != string(\"t\")");
    resultA = var4->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < string(\"t\") should have been false");
    resultB = var17->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < string(\"t\") is inconsistent");
    Passed("int(-1) < string(\"t\")");
    resultA = var4->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= string(\"t\") should have been false");
    resultB = var17->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= string(\"t\") is inconsistent");
    Passed("int(-1) >= string(\"t\")");
    resultA = var4->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(-1) <= string(\"t\") should have been false");
    resultB = var17->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= string(\"t\") is inconsistent");
    Passed("int(-1) <= string(\"t\")");

// Evaluating int(-1) against string("f")
    resultA = var4->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "int(-1) == string(\"f\") should have been false");
    resultB = var18->Compare(var4, ConditionalEquals);
    Assert(resultA == resultB,
           "int(-1) == string(\"f\") is inconsistent");
    Passed("int(-1) == string(\"f\")");
    resultA = var4->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "int(-1) != string(\"f\") should have been true");
    resultB = var18->Compare(var4, ConditionalNotEquals);
    Assert(resultA == resultB,
           "int(-1) != string(\"f\") is inconsistent");
    Passed("int(-1) != string(\"f\")");
    resultA = var4->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "int(-1) < string(\"f\") should have been false");
    resultB = var18->Compare(var4, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "int(-1) < string(\"f\") is inconsistent");
    Passed("int(-1) < string(\"f\")");
    resultA = var4->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "int(-1) >= string(\"f\") should have been false");
    resultB = var18->Compare(var4, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) >= string(\"f\") is inconsistent");
    Passed("int(-1) >= string(\"f\")");
    resultA = var4->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "int(-1) <= string(\"f\") should have been false");
    resultB = var18->Compare(var4, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "int(-1) <= string(\"f\") is inconsistent");
    Passed("int(-1) <= string(\"f\")");

// * Evaluating float(0.0)
    Assert(var5->Compare(NULL, ConditionalImplicit) == false,
           "Implicit test of float(0.0) failed");
    Passed("Implicit test of float(0.0)");

// Evaluating float(0.0) against float(0.0)
    resultA = var5->Compare(var5, ConditionalEquals);
    Assert(resultA == true,
           "float(0.0) == float(0.0) should have been true");
    resultB = var5->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == float(0.0) is inconsistent");
    Passed("float(0.0) == float(0.0)");
    resultA = var5->Compare(var5, ConditionalNotEquals);
    Assert(resultA == false,
           "float(0.0) != float(0.0) should have been false");
    resultB = var5->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != float(0.0) is inconsistent");
    Passed("float(0.0) != float(0.0)");
    resultA = var5->Compare(var5, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < float(0.0) should have been false");
    resultB = var5->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < float(0.0) is inconsistent");
    Passed("float(0.0) < float(0.0)");
    resultA = var5->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(0.0) >= float(0.0) should have been true");
    resultB = var5->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= float(0.0) is inconsistent");
    Passed("float(0.0) >= float(0.0)");
    resultA = var5->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "float(0.0) <= float(0.0) should have been true");
    resultB = var5->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= float(0.0) is inconsistent");
    Passed("float(0.0) <= float(0.0)");

// Evaluating float(0.0) against float(0.1)
    resultA = var5->Compare(var6, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == float(0.1) should have been false");
    resultB = var6->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == float(0.1) is inconsistent");
    Passed("float(0.0) == float(0.1)");
    resultA = var5->Compare(var6, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != float(0.1) should have been true");
    resultB = var6->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != float(0.1) is inconsistent");
    Passed("float(0.0) != float(0.1)");
    resultA = var5->Compare(var6, ConditionalLessThan);
    Assert(resultA == true,
           "float(0.0) < float(0.1) should have been true");
    resultB = var6->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < float(0.1) is inconsistent");
    Passed("float(0.0) < float(0.1)");
    resultA = var5->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= float(0.1) should have been false");
    resultB = var6->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= float(0.1) is inconsistent");
    Passed("float(0.0) >= float(0.1)");
    resultA = var5->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "float(0.0) <= float(0.1) should have been true");
    resultB = var6->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= float(0.1) is inconsistent");
    Passed("float(0.0) <= float(0.1)");

// Evaluating float(0.0) against float(1.0)
    resultA = var5->Compare(var7, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == float(1.0) should have been false");
    resultB = var7->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == float(1.0) is inconsistent");
    Passed("float(0.0) == float(1.0)");
    resultA = var5->Compare(var7, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != float(1.0) should have been true");
    resultB = var7->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != float(1.0) is inconsistent");
    Passed("float(0.0) != float(1.0)");
    resultA = var5->Compare(var7, ConditionalLessThan);
    Assert(resultA == true,
           "float(0.0) < float(1.0) should have been true");
    resultB = var7->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < float(1.0) is inconsistent");
    Passed("float(0.0) < float(1.0)");
    resultA = var5->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= float(1.0) should have been false");
    resultB = var7->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= float(1.0) is inconsistent");
    Passed("float(0.0) >= float(1.0)");
    resultA = var5->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "float(0.0) <= float(1.0) should have been true");
    resultB = var7->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= float(1.0) is inconsistent");
    Passed("float(0.0) <= float(1.0)");

// Evaluating float(0.0) against float(-0.1)
    resultA = var5->Compare(var8, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == float(-0.1) should have been false");
    resultB = var8->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == float(-0.1) is inconsistent");
    Passed("float(0.0) == float(-0.1)");
    resultA = var5->Compare(var8, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != float(-0.1) should have been true");
    resultB = var8->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != float(-0.1) is inconsistent");
    Passed("float(0.0) != float(-0.1)");
    resultA = var5->Compare(var8, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < float(-0.1) should have been false");
    resultB = var8->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < float(-0.1) is inconsistent");
    Passed("float(0.0) < float(-0.1)");
    resultA = var5->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(0.0) >= float(-0.1) should have been true");
    resultB = var8->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= float(-0.1) is inconsistent");
    Passed("float(0.0) >= float(-0.1)");
    resultA = var5->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= float(-0.1) should have been false");
    resultB = var8->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= float(-0.1) is inconsistent");
    Passed("float(0.0) <= float(-0.1)");

// Evaluating float(0.0) against float(-1.0)
    resultA = var5->Compare(var9, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == float(-1.0) should have been false");
    resultB = var9->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == float(-1.0) is inconsistent");
    Passed("float(0.0) == float(-1.0)");
    resultA = var5->Compare(var9, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != float(-1.0) should have been true");
    resultB = var9->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != float(-1.0) is inconsistent");
    Passed("float(0.0) != float(-1.0)");
    resultA = var5->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < float(-1.0) should have been false");
    resultB = var9->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < float(-1.0) is inconsistent");
    Passed("float(0.0) < float(-1.0)");
    resultA = var5->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(0.0) >= float(-1.0) should have been true");
    resultB = var9->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= float(-1.0) is inconsistent");
    Passed("float(0.0) >= float(-1.0)");
    resultA = var5->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= float(-1.0) should have been false");
    resultB = var9->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= float(-1.0) is inconsistent");
    Passed("float(0.0) <= float(-1.0)");

// Evaluating float(0.0) against hash
    resultA = var5->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == hash should have been false");
    resultB = var10->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == hash is inconsistent");
    Passed("float(0.0) == hash");
    resultA = var5->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != hash should have been true");
    resultB = var10->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != hash is inconsistent");
    Passed("float(0.0) != hash");
    resultA = var5->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < hash should have been false");
    resultB = var10->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < hash is inconsistent");
    Passed("float(0.0) < hash");
    resultA = var5->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= hash should have been false");
    resultB = var10->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= hash is inconsistent");
    Passed("float(0.0) >= hash");
    resultA = var5->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= hash should have been false");
    resultB = var10->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= hash is inconsistent");
    Passed("float(0.0) <= hash");

// Evaluating float(0.0) against array()
    resultA = var5->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == array() should have been false");
    resultB = var11->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == array() is inconsistent");
    Passed("float(0.0) == array()");
    resultA = var5->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != array() should have been true");
    resultB = var11->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != array() is inconsistent");
    Passed("float(0.0) != array()");
    resultA = var5->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < array() should have been false");
    resultB = var11->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < array() is inconsistent");
    Passed("float(0.0) < array()");
    resultA = var5->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= array() should have been false");
    resultB = var11->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= array() is inconsistent");
    Passed("float(0.0) >= array()");
    resultA = var5->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= array() should have been false");
    resultB = var11->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= array() is inconsistent");
    Passed("float(0.0) <= array()");

// Evaluating float(0.0) against array(..)
    resultA = var5->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == array(..) should have been false");
    resultB = var12->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == array(..) is inconsistent");
    Passed("float(0.0) == array(..)");
    resultA = var5->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != array(..) should have been true");
    resultB = var12->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != array(..) is inconsistent");
    Passed("float(0.0) != array(..)");
    resultA = var5->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < array(..) should have been false");
    resultB = var12->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < array(..) is inconsistent");
    Passed("float(0.0) < array(..)");
    resultA = var5->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= array(..) should have been false");
    resultB = var12->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= array(..) is inconsistent");
    Passed("float(0.0) >= array(..)");
    resultA = var5->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= array(..) should have been false");
    resultB = var12->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= array(..) is inconsistent");
    Passed("float(0.0) <= array(..)");

// Evaluating float(0.0) against bool(true)
    resultA = var5->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == bool(true) should have been false");
    resultB = var13->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == bool(true) is inconsistent");
    Passed("float(0.0) == bool(true)");
    resultA = var5->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != bool(true) should have been true");
    resultB = var13->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != bool(true) is inconsistent");
    Passed("float(0.0) != bool(true)");
    resultA = var5->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < bool(true) should have been false");
    resultB = var13->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < bool(true) is inconsistent");
    Passed("float(0.0) < bool(true)");
    resultA = var5->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= bool(true) should have been false");
    resultB = var13->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= bool(true) is inconsistent");
    Passed("float(0.0) >= bool(true)");
    resultA = var5->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= bool(true) should have been false");
    resultB = var13->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= bool(true) is inconsistent");
    Passed("float(0.0) <= bool(true)");

// Evaluating float(0.0) against bool(false)
    resultA = var5->Compare(var14, ConditionalEquals);
    Assert(resultA == true,
           "float(0.0) == bool(false) should have been true");
    resultB = var14->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == bool(false) is inconsistent");
    Passed("float(0.0) == bool(false)");
    resultA = var5->Compare(var14, ConditionalNotEquals);
    Assert(resultA == false,
           "float(0.0) != bool(false) should have been false");
    resultB = var14->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != bool(false) is inconsistent");
    Passed("float(0.0) != bool(false)");
    resultA = var5->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < bool(false) should have been false");
    resultB = var14->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < bool(false) is inconsistent");
    Passed("float(0.0) < bool(false)");
    resultA = var5->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= bool(false) should have been false");
    resultB = var14->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= bool(false) is inconsistent");
    Passed("float(0.0) >= bool(false)");
    resultA = var5->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= bool(false) should have been false");
    resultB = var14->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= bool(false) is inconsistent");
    Passed("float(0.0) <= bool(false)");

// Evaluating float(0.0) against string("")
    resultA = var5->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == string(\"\") should have been false");
    resultB = var15->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == string(\"\") is inconsistent");
    Passed("float(0.0) == string(\"\")");
    resultA = var5->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != string(\"\") should have been true");
    resultB = var15->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != string(\"\") is inconsistent");
    Passed("float(0.0) != string(\"\")");
    resultA = var5->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < string(\"\") should have been false");
    resultB = var15->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < string(\"\") is inconsistent");
    Passed("float(0.0) < string(\"\")");
    resultA = var5->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= string(\"\") should have been false");
    resultB = var15->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= string(\"\") is inconsistent");
    Passed("float(0.0) >= string(\"\")");
    resultA = var5->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= string(\"\") should have been false");
    resultB = var15->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= string(\"\") is inconsistent");
    Passed("float(0.0) <= string(\"\")");

// Evaluating float(0.0) against string("..")
    resultA = var5->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == string(\"..\") should have been false");
    resultB = var16->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == string(\"..\") is inconsistent");
    Passed("float(0.0) == string(\"..\")");
    resultA = var5->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != string(\"..\") should have been true");
    resultB = var16->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != string(\"..\") is inconsistent");
    Passed("float(0.0) != string(\"..\")");
    resultA = var5->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < string(\"..\") should have been false");
    resultB = var16->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < string(\"..\") is inconsistent");
    Passed("float(0.0) < string(\"..\")");
    resultA = var5->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= string(\"..\") should have been false");
    resultB = var16->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= string(\"..\") is inconsistent");
    Passed("float(0.0) >= string(\"..\")");
    resultA = var5->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= string(\"..\") should have been false");
    resultB = var16->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= string(\"..\") is inconsistent");
    Passed("float(0.0) <= string(\"..\")");

// Evaluating float(0.0) against string("t")
    resultA = var5->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == string(\"t\") should have been false");
    resultB = var17->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == string(\"t\") is inconsistent");
    Passed("float(0.0) == string(\"t\")");
    resultA = var5->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != string(\"t\") should have been true");
    resultB = var17->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != string(\"t\") is inconsistent");
    Passed("float(0.0) != string(\"t\")");
    resultA = var5->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < string(\"t\") should have been false");
    resultB = var17->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < string(\"t\") is inconsistent");
    Passed("float(0.0) < string(\"t\")");
    resultA = var5->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= string(\"t\") should have been false");
    resultB = var17->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= string(\"t\") is inconsistent");
    Passed("float(0.0) >= string(\"t\")");
    resultA = var5->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= string(\"t\") should have been false");
    resultB = var17->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= string(\"t\") is inconsistent");
    Passed("float(0.0) <= string(\"t\")");

// Evaluating float(0.0) against string("f")
    resultA = var5->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "float(0.0) == string(\"f\") should have been false");
    resultB = var18->Compare(var5, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.0) == string(\"f\") is inconsistent");
    Passed("float(0.0) == string(\"f\")");
    resultA = var5->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.0) != string(\"f\") should have been true");
    resultB = var18->Compare(var5, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.0) != string(\"f\") is inconsistent");
    Passed("float(0.0) != string(\"f\")");
    resultA = var5->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.0) < string(\"f\") should have been false");
    resultB = var18->Compare(var5, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.0) < string(\"f\") is inconsistent");
    Passed("float(0.0) < string(\"f\")");
    resultA = var5->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.0) >= string(\"f\") should have been false");
    resultB = var18->Compare(var5, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) >= string(\"f\") is inconsistent");
    Passed("float(0.0) >= string(\"f\")");
    resultA = var5->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.0) <= string(\"f\") should have been false");
    resultB = var18->Compare(var5, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.0) <= string(\"f\") is inconsistent");
    Passed("float(0.0) <= string(\"f\")");

// * Evaluating float(0.1)
    Assert(var6->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of float(0.1) failed");
    Passed("Implicit test of float(0.1)");

// Evaluating float(0.1) against float(0.1)
    resultA = var6->Compare(var6, ConditionalEquals);
    Assert(resultA == true,
           "float(0.1) == float(0.1) should have been true");
    resultB = var6->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == float(0.1) is inconsistent");
    Passed("float(0.1) == float(0.1)");
    resultA = var6->Compare(var6, ConditionalNotEquals);
    Assert(resultA == false,
           "float(0.1) != float(0.1) should have been false");
    resultB = var6->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != float(0.1) is inconsistent");
    Passed("float(0.1) != float(0.1)");
    resultA = var6->Compare(var6, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < float(0.1) should have been false");
    resultB = var6->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < float(0.1) is inconsistent");
    Passed("float(0.1) < float(0.1)");
    resultA = var6->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(0.1) >= float(0.1) should have been true");
    resultB = var6->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= float(0.1) is inconsistent");
    Passed("float(0.1) >= float(0.1)");
    resultA = var6->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "float(0.1) <= float(0.1) should have been true");
    resultB = var6->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= float(0.1) is inconsistent");
    Passed("float(0.1) <= float(0.1)");

// Evaluating float(0.1) against float(1.0)
    resultA = var6->Compare(var7, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == float(1.0) should have been false");
    resultB = var7->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == float(1.0) is inconsistent");
    Passed("float(0.1) == float(1.0)");
    resultA = var6->Compare(var7, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != float(1.0) should have been true");
    resultB = var7->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != float(1.0) is inconsistent");
    Passed("float(0.1) != float(1.0)");
    resultA = var6->Compare(var7, ConditionalLessThan);
    Assert(resultA == true,
           "float(0.1) < float(1.0) should have been true");
    resultB = var7->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < float(1.0) is inconsistent");
    Passed("float(0.1) < float(1.0)");
    resultA = var6->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= float(1.0) should have been false");
    resultB = var7->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= float(1.0) is inconsistent");
    Passed("float(0.1) >= float(1.0)");
    resultA = var6->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "float(0.1) <= float(1.0) should have been true");
    resultB = var7->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= float(1.0) is inconsistent");
    Passed("float(0.1) <= float(1.0)");

// Evaluating float(0.1) against float(-0.1)
    resultA = var6->Compare(var8, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == float(-0.1) should have been false");
    resultB = var8->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == float(-0.1) is inconsistent");
    Passed("float(0.1) == float(-0.1)");
    resultA = var6->Compare(var8, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != float(-0.1) should have been true");
    resultB = var8->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != float(-0.1) is inconsistent");
    Passed("float(0.1) != float(-0.1)");
    resultA = var6->Compare(var8, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < float(-0.1) should have been false");
    resultB = var8->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < float(-0.1) is inconsistent");
    Passed("float(0.1) < float(-0.1)");
    resultA = var6->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(0.1) >= float(-0.1) should have been true");
    resultB = var8->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= float(-0.1) is inconsistent");
    Passed("float(0.1) >= float(-0.1)");
    resultA = var6->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= float(-0.1) should have been false");
    resultB = var8->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= float(-0.1) is inconsistent");
    Passed("float(0.1) <= float(-0.1)");

// Evaluating float(0.1) against float(-1.0)
    resultA = var6->Compare(var9, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == float(-1.0) should have been false");
    resultB = var9->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == float(-1.0) is inconsistent");
    Passed("float(0.1) == float(-1.0)");
    resultA = var6->Compare(var9, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != float(-1.0) should have been true");
    resultB = var9->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != float(-1.0) is inconsistent");
    Passed("float(0.1) != float(-1.0)");
    resultA = var6->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < float(-1.0) should have been false");
    resultB = var9->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < float(-1.0) is inconsistent");
    Passed("float(0.1) < float(-1.0)");
    resultA = var6->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(0.1) >= float(-1.0) should have been true");
    resultB = var9->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= float(-1.0) is inconsistent");
    Passed("float(0.1) >= float(-1.0)");
    resultA = var6->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= float(-1.0) should have been false");
    resultB = var9->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= float(-1.0) is inconsistent");
    Passed("float(0.1) <= float(-1.0)");

// Evaluating float(0.1) against hash
    resultA = var6->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == hash should have been false");
    resultB = var10->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == hash is inconsistent");
    Passed("float(0.1) == hash");
    resultA = var6->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != hash should have been true");
    resultB = var10->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != hash is inconsistent");
    Passed("float(0.1) != hash");
    resultA = var6->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < hash should have been false");
    resultB = var10->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < hash is inconsistent");
    Passed("float(0.1) < hash");
    resultA = var6->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= hash should have been false");
    resultB = var10->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= hash is inconsistent");
    Passed("float(0.1) >= hash");
    resultA = var6->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= hash should have been false");
    resultB = var10->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= hash is inconsistent");
    Passed("float(0.1) <= hash");

// Evaluating float(0.1) against array()
    resultA = var6->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == array() should have been false");
    resultB = var11->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == array() is inconsistent");
    Passed("float(0.1) == array()");
    resultA = var6->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != array() should have been true");
    resultB = var11->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != array() is inconsistent");
    Passed("float(0.1) != array()");
    resultA = var6->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < array() should have been false");
    resultB = var11->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < array() is inconsistent");
    Passed("float(0.1) < array()");
    resultA = var6->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= array() should have been false");
    resultB = var11->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= array() is inconsistent");
    Passed("float(0.1) >= array()");
    resultA = var6->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= array() should have been false");
    resultB = var11->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= array() is inconsistent");
    Passed("float(0.1) <= array()");

// Evaluating float(0.1) against array(..)
    resultA = var6->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == array(..) should have been false");
    resultB = var12->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == array(..) is inconsistent");
    Passed("float(0.1) == array(..)");
    resultA = var6->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != array(..) should have been true");
    resultB = var12->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != array(..) is inconsistent");
    Passed("float(0.1) != array(..)");
    resultA = var6->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < array(..) should have been false");
    resultB = var12->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < array(..) is inconsistent");
    Passed("float(0.1) < array(..)");
    resultA = var6->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= array(..) should have been false");
    resultB = var12->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= array(..) is inconsistent");
    Passed("float(0.1) >= array(..)");
    resultA = var6->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= array(..) should have been false");
    resultB = var12->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= array(..) is inconsistent");
    Passed("float(0.1) <= array(..)");

// Evaluating float(0.1) against bool(true)
    resultA = var6->Compare(var13, ConditionalEquals);
    Assert(resultA == true,
           "float(0.1) == bool(true) should have been true");
    resultB = var13->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == bool(true) is inconsistent");
    Passed("float(0.1) == bool(true)");
    resultA = var6->Compare(var13, ConditionalNotEquals);
    Assert(resultA == false,
           "float(0.1) != bool(true) should have been false");
    resultB = var13->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != bool(true) is inconsistent");
    Passed("float(0.1) != bool(true)");
    resultA = var6->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < bool(true) should have been false");
    resultB = var13->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < bool(true) is inconsistent");
    Passed("float(0.1) < bool(true)");
    resultA = var6->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= bool(true) should have been false");
    resultB = var13->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= bool(true) is inconsistent");
    Passed("float(0.1) >= bool(true)");
    resultA = var6->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= bool(true) should have been false");
    resultB = var13->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= bool(true) is inconsistent");
    Passed("float(0.1) <= bool(true)");

// Evaluating float(0.1) against bool(false)
    resultA = var6->Compare(var14, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == bool(false) should have been false");
    resultB = var14->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == bool(false) is inconsistent");
    Passed("float(0.1) == bool(false)");
    resultA = var6->Compare(var14, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != bool(false) should have been true");
    resultB = var14->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != bool(false) is inconsistent");
    Passed("float(0.1) != bool(false)");
    resultA = var6->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < bool(false) should have been false");
    resultB = var14->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < bool(false) is inconsistent");
    Passed("float(0.1) < bool(false)");
    resultA = var6->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= bool(false) should have been false");
    resultB = var14->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= bool(false) is inconsistent");
    Passed("float(0.1) >= bool(false)");
    resultA = var6->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= bool(false) should have been false");
    resultB = var14->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= bool(false) is inconsistent");
    Passed("float(0.1) <= bool(false)");

// Evaluating float(0.1) against string("")
    resultA = var6->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == string(\"\") should have been false");
    resultB = var15->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == string(\"\") is inconsistent");
    Passed("float(0.1) == string(\"\")");
    resultA = var6->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != string(\"\") should have been true");
    resultB = var15->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != string(\"\") is inconsistent");
    Passed("float(0.1) != string(\"\")");
    resultA = var6->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < string(\"\") should have been false");
    resultB = var15->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < string(\"\") is inconsistent");
    Passed("float(0.1) < string(\"\")");
    resultA = var6->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= string(\"\") should have been false");
    resultB = var15->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= string(\"\") is inconsistent");
    Passed("float(0.1) >= string(\"\")");
    resultA = var6->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= string(\"\") should have been false");
    resultB = var15->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= string(\"\") is inconsistent");
    Passed("float(0.1) <= string(\"\")");

// Evaluating float(0.1) against string("..")
    resultA = var6->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == string(\"..\") should have been false");
    resultB = var16->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == string(\"..\") is inconsistent");
    Passed("float(0.1) == string(\"..\")");
    resultA = var6->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != string(\"..\") should have been true");
    resultB = var16->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != string(\"..\") is inconsistent");
    Passed("float(0.1) != string(\"..\")");
    resultA = var6->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < string(\"..\") should have been false");
    resultB = var16->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < string(\"..\") is inconsistent");
    Passed("float(0.1) < string(\"..\")");
    resultA = var6->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= string(\"..\") should have been false");
    resultB = var16->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= string(\"..\") is inconsistent");
    Passed("float(0.1) >= string(\"..\")");
    resultA = var6->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= string(\"..\") should have been false");
    resultB = var16->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= string(\"..\") is inconsistent");
    Passed("float(0.1) <= string(\"..\")");

// Evaluating float(0.1) against string("t")
    resultA = var6->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == string(\"t\") should have been false");
    resultB = var17->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == string(\"t\") is inconsistent");
    Passed("float(0.1) == string(\"t\")");
    resultA = var6->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != string(\"t\") should have been true");
    resultB = var17->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != string(\"t\") is inconsistent");
    Passed("float(0.1) != string(\"t\")");
    resultA = var6->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < string(\"t\") should have been false");
    resultB = var17->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < string(\"t\") is inconsistent");
    Passed("float(0.1) < string(\"t\")");
    resultA = var6->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= string(\"t\") should have been false");
    resultB = var17->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= string(\"t\") is inconsistent");
    Passed("float(0.1) >= string(\"t\")");
    resultA = var6->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= string(\"t\") should have been false");
    resultB = var17->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= string(\"t\") is inconsistent");
    Passed("float(0.1) <= string(\"t\")");

// Evaluating float(0.1) against string("f")
    resultA = var6->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "float(0.1) == string(\"f\") should have been false");
    resultB = var18->Compare(var6, ConditionalEquals);
    Assert(resultA == resultB,
           "float(0.1) == string(\"f\") is inconsistent");
    Passed("float(0.1) == string(\"f\")");
    resultA = var6->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "float(0.1) != string(\"f\") should have been true");
    resultB = var18->Compare(var6, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(0.1) != string(\"f\") is inconsistent");
    Passed("float(0.1) != string(\"f\")");
    resultA = var6->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "float(0.1) < string(\"f\") should have been false");
    resultB = var18->Compare(var6, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(0.1) < string(\"f\") is inconsistent");
    Passed("float(0.1) < string(\"f\")");
    resultA = var6->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(0.1) >= string(\"f\") should have been false");
    resultB = var18->Compare(var6, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) >= string(\"f\") is inconsistent");
    Passed("float(0.1) >= string(\"f\")");
    resultA = var6->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(0.1) <= string(\"f\") should have been false");
    resultB = var18->Compare(var6, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(0.1) <= string(\"f\") is inconsistent");
    Passed("float(0.1) <= string(\"f\")");

// * Evaluating float(1.0)
    Assert(var7->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of float(1.0) failed");
    Passed("Implicit test of float(1.0)");

// Evaluating float(1.0) against float(1.0)
    resultA = var7->Compare(var7, ConditionalEquals);
    Assert(resultA == true,
           "float(1.0) == float(1.0) should have been true");
    resultB = var7->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == float(1.0) is inconsistent");
    Passed("float(1.0) == float(1.0)");
    resultA = var7->Compare(var7, ConditionalNotEquals);
    Assert(resultA == false,
           "float(1.0) != float(1.0) should have been false");
    resultB = var7->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != float(1.0) is inconsistent");
    Passed("float(1.0) != float(1.0)");
    resultA = var7->Compare(var7, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < float(1.0) should have been false");
    resultB = var7->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < float(1.0) is inconsistent");
    Passed("float(1.0) < float(1.0)");
    resultA = var7->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(1.0) >= float(1.0) should have been true");
    resultB = var7->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= float(1.0) is inconsistent");
    Passed("float(1.0) >= float(1.0)");
    resultA = var7->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "float(1.0) <= float(1.0) should have been true");
    resultB = var7->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= float(1.0) is inconsistent");
    Passed("float(1.0) <= float(1.0)");

// Evaluating float(1.0) against float(-0.1)
    resultA = var7->Compare(var8, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == float(-0.1) should have been false");
    resultB = var8->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == float(-0.1) is inconsistent");
    Passed("float(1.0) == float(-0.1)");
    resultA = var7->Compare(var8, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != float(-0.1) should have been true");
    resultB = var8->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != float(-0.1) is inconsistent");
    Passed("float(1.0) != float(-0.1)");
    resultA = var7->Compare(var8, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < float(-0.1) should have been false");
    resultB = var8->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < float(-0.1) is inconsistent");
    Passed("float(1.0) < float(-0.1)");
    resultA = var7->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(1.0) >= float(-0.1) should have been true");
    resultB = var8->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= float(-0.1) is inconsistent");
    Passed("float(1.0) >= float(-0.1)");
    resultA = var7->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= float(-0.1) should have been false");
    resultB = var8->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= float(-0.1) is inconsistent");
    Passed("float(1.0) <= float(-0.1)");

// Evaluating float(1.0) against float(-1.0)
    resultA = var7->Compare(var9, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == float(-1.0) should have been false");
    resultB = var9->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == float(-1.0) is inconsistent");
    Passed("float(1.0) == float(-1.0)");
    resultA = var7->Compare(var9, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != float(-1.0) should have been true");
    resultB = var9->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != float(-1.0) is inconsistent");
    Passed("float(1.0) != float(-1.0)");
    resultA = var7->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < float(-1.0) should have been false");
    resultB = var9->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < float(-1.0) is inconsistent");
    Passed("float(1.0) < float(-1.0)");
    resultA = var7->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(1.0) >= float(-1.0) should have been true");
    resultB = var9->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= float(-1.0) is inconsistent");
    Passed("float(1.0) >= float(-1.0)");
    resultA = var7->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= float(-1.0) should have been false");
    resultB = var9->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= float(-1.0) is inconsistent");
    Passed("float(1.0) <= float(-1.0)");

// Evaluating float(1.0) against hash
    resultA = var7->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == hash should have been false");
    resultB = var10->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == hash is inconsistent");
    Passed("float(1.0) == hash");
    resultA = var7->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != hash should have been true");
    resultB = var10->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != hash is inconsistent");
    Passed("float(1.0) != hash");
    resultA = var7->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < hash should have been false");
    resultB = var10->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < hash is inconsistent");
    Passed("float(1.0) < hash");
    resultA = var7->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(1.0) >= hash should have been false");
    resultB = var10->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= hash is inconsistent");
    Passed("float(1.0) >= hash");
    resultA = var7->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= hash should have been false");
    resultB = var10->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= hash is inconsistent");
    Passed("float(1.0) <= hash");

// Evaluating float(1.0) against array()
    resultA = var7->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == array() should have been false");
    resultB = var11->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == array() is inconsistent");
    Passed("float(1.0) == array()");
    resultA = var7->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != array() should have been true");
    resultB = var11->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != array() is inconsistent");
    Passed("float(1.0) != array()");
    resultA = var7->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < array() should have been false");
    resultB = var11->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < array() is inconsistent");
    Passed("float(1.0) < array()");
    resultA = var7->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(1.0) >= array() should have been false");
    resultB = var11->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= array() is inconsistent");
    Passed("float(1.0) >= array()");
    resultA = var7->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= array() should have been false");
    resultB = var11->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= array() is inconsistent");
    Passed("float(1.0) <= array()");

// Evaluating float(1.0) against array(..)
    resultA = var7->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == array(..) should have been false");
    resultB = var12->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == array(..) is inconsistent");
    Passed("float(1.0) == array(..)");
    resultA = var7->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != array(..) should have been true");
    resultB = var12->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != array(..) is inconsistent");
    Passed("float(1.0) != array(..)");
    resultA = var7->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < array(..) should have been false");
    resultB = var12->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < array(..) is inconsistent");
    Passed("float(1.0) < array(..)");
    resultA = var7->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(1.0) >= array(..) should have been false");
    resultB = var12->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= array(..) is inconsistent");
    Passed("float(1.0) >= array(..)");
    resultA = var7->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= array(..) should have been false");
    resultB = var12->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= array(..) is inconsistent");
    Passed("float(1.0) <= array(..)");

// Evaluating float(1.0) against bool(true)
    resultA = var7->Compare(var13, ConditionalEquals);
    Assert(resultA == true,
           "float(1.0) == bool(true) should have been true");
    resultB = var13->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == bool(true) is inconsistent");
    Passed("float(1.0) == bool(true)");
    resultA = var7->Compare(var13, ConditionalNotEquals);
    Assert(resultA == false,
           "float(1.0) != bool(true) should have been false");
    resultB = var13->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != bool(true) is inconsistent");
    Passed("float(1.0) != bool(true)");
    resultA = var7->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < bool(true) should have been false");
    resultB = var13->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < bool(true) is inconsistent");
    Passed("float(1.0) < bool(true)");
    resultA = var7->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(1.0) >= bool(true) should have been false");
    resultB = var13->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= bool(true) is inconsistent");
    Passed("float(1.0) >= bool(true)");
    resultA = var7->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= bool(true) should have been false");
    resultB = var13->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= bool(true) is inconsistent");
    Passed("float(1.0) <= bool(true)");

// Evaluating float(1.0) against bool(false)
    resultA = var7->Compare(var14, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == bool(false) should have been false");
    resultB = var14->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == bool(false) is inconsistent");
    Passed("float(1.0) == bool(false)");
    resultA = var7->Compare(var14, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != bool(false) should have been true");
    resultB = var14->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != bool(false) is inconsistent");
    Passed("float(1.0) != bool(false)");
    resultA = var7->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < bool(false) should have been false");
    resultB = var14->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < bool(false) is inconsistent");
    Passed("float(1.0) < bool(false)");
    resultA = var7->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(1.0) >= bool(false) should have been false");
    resultB = var14->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= bool(false) is inconsistent");
    Passed("float(1.0) >= bool(false)");
    resultA = var7->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= bool(false) should have been false");
    resultB = var14->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= bool(false) is inconsistent");
    Passed("float(1.0) <= bool(false)");

// Evaluating float(1.0) against string("")
    resultA = var7->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == string(\"\") should have been false");
    resultB = var15->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == string(\"\") is inconsistent");
    Passed("float(1.0) == string(\"\")");
    resultA = var7->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != string(\"\") should have been true");
    resultB = var15->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != string(\"\") is inconsistent");
    Passed("float(1.0) != string(\"\")");
    resultA = var7->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < string(\"\") should have been false");
    resultB = var15->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < string(\"\") is inconsistent");
    Passed("float(1.0) < string(\"\")");
    resultA = var7->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(1.0) >= string(\"\") should have been false");
    resultB = var15->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= string(\"\") is inconsistent");
    Passed("float(1.0) >= string(\"\")");
    resultA = var7->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= string(\"\") should have been false");
    resultB = var15->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= string(\"\") is inconsistent");
    Passed("float(1.0) <= string(\"\")");

// Evaluating float(1.0) against string("..")
    resultA = var7->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == string(\"..\") should have been false");
    resultB = var16->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == string(\"..\") is inconsistent");
    Passed("float(1.0) == string(\"..\")");
    resultA = var7->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != string(\"..\") should have been true");
    resultB = var16->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != string(\"..\") is inconsistent");
    Passed("float(1.0) != string(\"..\")");
    resultA = var7->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < string(\"..\") should have been false");
    resultB = var16->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < string(\"..\") is inconsistent");
    Passed("float(1.0) < string(\"..\")");
    resultA = var7->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(1.0) >= string(\"..\") should have been false");
    resultB = var16->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= string(\"..\") is inconsistent");
    Passed("float(1.0) >= string(\"..\")");
    resultA = var7->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= string(\"..\") should have been false");
    resultB = var16->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= string(\"..\") is inconsistent");
    Passed("float(1.0) <= string(\"..\")");

// Evaluating float(1.0) against string("t")
    resultA = var7->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == string(\"t\") should have been false");
    resultB = var17->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == string(\"t\") is inconsistent");
    Passed("float(1.0) == string(\"t\")");
    resultA = var7->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != string(\"t\") should have been true");
    resultB = var17->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != string(\"t\") is inconsistent");
    Passed("float(1.0) != string(\"t\")");
    resultA = var7->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < string(\"t\") should have been false");
    resultB = var17->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < string(\"t\") is inconsistent");
    Passed("float(1.0) < string(\"t\")");
    resultA = var7->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(1.0) >= string(\"t\") should have been false");
    resultB = var17->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= string(\"t\") is inconsistent");
    Passed("float(1.0) >= string(\"t\")");
    resultA = var7->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= string(\"t\") should have been false");
    resultB = var17->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= string(\"t\") is inconsistent");
    Passed("float(1.0) <= string(\"t\")");

// Evaluating float(1.0) against string("f")
    resultA = var7->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "float(1.0) == string(\"f\") should have been false");
    resultB = var18->Compare(var7, ConditionalEquals);
    Assert(resultA == resultB,
           "float(1.0) == string(\"f\") is inconsistent");
    Passed("float(1.0) == string(\"f\")");
    resultA = var7->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "float(1.0) != string(\"f\") should have been true");
    resultB = var18->Compare(var7, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(1.0) != string(\"f\") is inconsistent");
    Passed("float(1.0) != string(\"f\")");
    resultA = var7->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "float(1.0) < string(\"f\") should have been false");
    resultB = var18->Compare(var7, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(1.0) < string(\"f\") is inconsistent");
    Passed("float(1.0) < string(\"f\")");
    resultA = var7->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(1.0) >= string(\"f\") should have been false");
    resultB = var18->Compare(var7, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) >= string(\"f\") is inconsistent");
    Passed("float(1.0) >= string(\"f\")");
    resultA = var7->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(1.0) <= string(\"f\") should have been false");
    resultB = var18->Compare(var7, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(1.0) <= string(\"f\") is inconsistent");
    Passed("float(1.0) <= string(\"f\")");

// * Evaluating float(-0.1)
    Assert(var8->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of float(-0.1) failed");
    Passed("Implicit test of float(-0.1)");

// Evaluating float(-0.1) against float(-0.1)
    resultA = var8->Compare(var8, ConditionalEquals);
    Assert(resultA == true,
           "float(-0.1) == float(-0.1) should have been true");
    resultB = var8->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == float(-0.1) is inconsistent");
    Passed("float(-0.1) == float(-0.1)");
    resultA = var8->Compare(var8, ConditionalNotEquals);
    Assert(resultA == false,
           "float(-0.1) != float(-0.1) should have been false");
    resultB = var8->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != float(-0.1) is inconsistent");
    Passed("float(-0.1) != float(-0.1)");
    resultA = var8->Compare(var8, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < float(-0.1) should have been false");
    resultB = var8->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < float(-0.1) is inconsistent");
    Passed("float(-0.1) < float(-0.1)");
    resultA = var8->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(-0.1) >= float(-0.1) should have been true");
    resultB = var8->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= float(-0.1) is inconsistent");
    Passed("float(-0.1) >= float(-0.1)");
    resultA = var8->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "float(-0.1) <= float(-0.1) should have been true");
    resultB = var8->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= float(-0.1) is inconsistent");
    Passed("float(-0.1) <= float(-0.1)");

// Evaluating float(-0.1) against float(-1.0)
    resultA = var8->Compare(var9, ConditionalEquals);
    Assert(resultA == false,
           "float(-0.1) == float(-1.0) should have been false");
    resultB = var9->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == float(-1.0) is inconsistent");
    Passed("float(-0.1) == float(-1.0)");
    resultA = var8->Compare(var9, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-0.1) != float(-1.0) should have been true");
    resultB = var9->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != float(-1.0) is inconsistent");
    Passed("float(-0.1) != float(-1.0)");
    resultA = var8->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < float(-1.0) should have been false");
    resultB = var9->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < float(-1.0) is inconsistent");
    Passed("float(-0.1) < float(-1.0)");
    resultA = var8->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(-0.1) >= float(-1.0) should have been true");
    resultB = var9->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= float(-1.0) is inconsistent");
    Passed("float(-0.1) >= float(-1.0)");
    resultA = var8->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= float(-1.0) should have been false");
    resultB = var9->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= float(-1.0) is inconsistent");
    Passed("float(-0.1) <= float(-1.0)");

// Evaluating float(-0.1) against hash
    resultA = var8->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "float(-0.1) == hash should have been false");
    resultB = var10->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == hash is inconsistent");
    Passed("float(-0.1) == hash");
    resultA = var8->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-0.1) != hash should have been true");
    resultB = var10->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != hash is inconsistent");
    Passed("float(-0.1) != hash");
    resultA = var8->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < hash should have been false");
    resultB = var10->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < hash is inconsistent");
    Passed("float(-0.1) < hash");
    resultA = var8->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) >= hash should have been false");
    resultB = var10->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= hash is inconsistent");
    Passed("float(-0.1) >= hash");
    resultA = var8->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= hash should have been false");
    resultB = var10->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= hash is inconsistent");
    Passed("float(-0.1) <= hash");

// Evaluating float(-0.1) against array()
    resultA = var8->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "float(-0.1) == array() should have been false");
    resultB = var11->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == array() is inconsistent");
    Passed("float(-0.1) == array()");
    resultA = var8->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-0.1) != array() should have been true");
    resultB = var11->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != array() is inconsistent");
    Passed("float(-0.1) != array()");
    resultA = var8->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < array() should have been false");
    resultB = var11->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < array() is inconsistent");
    Passed("float(-0.1) < array()");
    resultA = var8->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) >= array() should have been false");
    resultB = var11->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= array() is inconsistent");
    Passed("float(-0.1) >= array()");
    resultA = var8->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= array() should have been false");
    resultB = var11->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= array() is inconsistent");
    Passed("float(-0.1) <= array()");

// Evaluating float(-0.1) against array(..)
    resultA = var8->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "float(-0.1) == array(..) should have been false");
    resultB = var12->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == array(..) is inconsistent");
    Passed("float(-0.1) == array(..)");
    resultA = var8->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-0.1) != array(..) should have been true");
    resultB = var12->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != array(..) is inconsistent");
    Passed("float(-0.1) != array(..)");
    resultA = var8->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < array(..) should have been false");
    resultB = var12->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < array(..) is inconsistent");
    Passed("float(-0.1) < array(..)");
    resultA = var8->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) >= array(..) should have been false");
    resultB = var12->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= array(..) is inconsistent");
    Passed("float(-0.1) >= array(..)");
    resultA = var8->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= array(..) should have been false");
    resultB = var12->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= array(..) is inconsistent");
    Passed("float(-0.1) <= array(..)");

// Evaluating float(-0.1) against bool(true)
    resultA = var8->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "float(-0.1) == bool(true) should have been false");
    resultB = var13->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == bool(true) is inconsistent");
    Passed("float(-0.1) == bool(true)");
    resultA = var8->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-0.1) != bool(true) should have been true");
    resultB = var13->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != bool(true) is inconsistent");
    Passed("float(-0.1) != bool(true)");
    resultA = var8->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < bool(true) should have been false");
    resultB = var13->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < bool(true) is inconsistent");
    Passed("float(-0.1) < bool(true)");
    resultA = var8->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) >= bool(true) should have been false");
    resultB = var13->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= bool(true) is inconsistent");
    Passed("float(-0.1) >= bool(true)");
    resultA = var8->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= bool(true) should have been false");
    resultB = var13->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= bool(true) is inconsistent");
    Passed("float(-0.1) <= bool(true)");

// Evaluating float(-0.1) against bool(false)
    resultA = var8->Compare(var14, ConditionalEquals);
    Assert(resultA == true,
           "float(-0.1) == bool(false) should have been true");
    resultB = var14->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == bool(false) is inconsistent");
    Passed("float(-0.1) == bool(false)");
    resultA = var8->Compare(var14, ConditionalNotEquals);
    Assert(resultA == false,
           "float(-0.1) != bool(false) should have been false");
    resultB = var14->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != bool(false) is inconsistent");
    Passed("float(-0.1) != bool(false)");
    resultA = var8->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < bool(false) should have been false");
    resultB = var14->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < bool(false) is inconsistent");
    Passed("float(-0.1) < bool(false)");
    resultA = var8->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) >= bool(false) should have been false");
    resultB = var14->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= bool(false) is inconsistent");
    Passed("float(-0.1) >= bool(false)");
    resultA = var8->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= bool(false) should have been false");
    resultB = var14->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= bool(false) is inconsistent");
    Passed("float(-0.1) <= bool(false)");

// Evaluating float(-0.1) against string("")
    resultA = var8->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "float(-0.1) == string(\"\") should have been false");
    resultB = var15->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == string(\"\") is inconsistent");
    Passed("float(-0.1) == string(\"\")");
    resultA = var8->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-0.1) != string(\"\") should have been true");
    resultB = var15->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != string(\"\") is inconsistent");
    Passed("float(-0.1) != string(\"\")");
    resultA = var8->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < string(\"\") should have been false");
    resultB = var15->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < string(\"\") is inconsistent");
    Passed("float(-0.1) < string(\"\")");
    resultA = var8->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) >= string(\"\") should have been false");
    resultB = var15->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= string(\"\") is inconsistent");
    Passed("float(-0.1) >= string(\"\")");
    resultA = var8->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= string(\"\") should have been false");
    resultB = var15->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= string(\"\") is inconsistent");
    Passed("float(-0.1) <= string(\"\")");

// Evaluating float(-0.1) against string("..")
    resultA = var8->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "float(-0.1) == string(\"..\") should have been false");
    resultB = var16->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == string(\"..\") is inconsistent");
    Passed("float(-0.1) == string(\"..\")");
    resultA = var8->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-0.1) != string(\"..\") should have been true");
    resultB = var16->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != string(\"..\") is inconsistent");
    Passed("float(-0.1) != string(\"..\")");
    resultA = var8->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < string(\"..\") should have been false");
    resultB = var16->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < string(\"..\") is inconsistent");
    Passed("float(-0.1) < string(\"..\")");
    resultA = var8->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) >= string(\"..\") should have been false");
    resultB = var16->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= string(\"..\") is inconsistent");
    Passed("float(-0.1) >= string(\"..\")");
    resultA = var8->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= string(\"..\") should have been false");
    resultB = var16->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= string(\"..\") is inconsistent");
    Passed("float(-0.1) <= string(\"..\")");

// Evaluating float(-0.1) against string("t")
    resultA = var8->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "float(-0.1) == string(\"t\") should have been false");
    resultB = var17->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == string(\"t\") is inconsistent");
    Passed("float(-0.1) == string(\"t\")");
    resultA = var8->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-0.1) != string(\"t\") should have been true");
    resultB = var17->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != string(\"t\") is inconsistent");
    Passed("float(-0.1) != string(\"t\")");
    resultA = var8->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < string(\"t\") should have been false");
    resultB = var17->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < string(\"t\") is inconsistent");
    Passed("float(-0.1) < string(\"t\")");
    resultA = var8->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) >= string(\"t\") should have been false");
    resultB = var17->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= string(\"t\") is inconsistent");
    Passed("float(-0.1) >= string(\"t\")");
    resultA = var8->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= string(\"t\") should have been false");
    resultB = var17->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= string(\"t\") is inconsistent");
    Passed("float(-0.1) <= string(\"t\")");

// Evaluating float(-0.1) against string("f")
    resultA = var8->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "float(-0.1) == string(\"f\") should have been false");
    resultB = var18->Compare(var8, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-0.1) == string(\"f\") is inconsistent");
    Passed("float(-0.1) == string(\"f\")");
    resultA = var8->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-0.1) != string(\"f\") should have been true");
    resultB = var18->Compare(var8, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-0.1) != string(\"f\") is inconsistent");
    Passed("float(-0.1) != string(\"f\")");
    resultA = var8->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "float(-0.1) < string(\"f\") should have been false");
    resultB = var18->Compare(var8, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-0.1) < string(\"f\") is inconsistent");
    Passed("float(-0.1) < string(\"f\")");
    resultA = var8->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) >= string(\"f\") should have been false");
    resultB = var18->Compare(var8, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) >= string(\"f\") is inconsistent");
    Passed("float(-0.1) >= string(\"f\")");
    resultA = var8->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-0.1) <= string(\"f\") should have been false");
    resultB = var18->Compare(var8, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-0.1) <= string(\"f\") is inconsistent");
    Passed("float(-0.1) <= string(\"f\")");

// * Evaluating float(-1.0)
    Assert(var9->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of float(-1.0) failed");
    Passed("Implicit test of float(-1.0)");

// Evaluating float(-1.0) against float(-1.0)
    resultA = var9->Compare(var9, ConditionalEquals);
    Assert(resultA == true,
           "float(-1.0) == float(-1.0) should have been true");
    resultB = var9->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == float(-1.0) is inconsistent");
    Passed("float(-1.0) == float(-1.0)");
    resultA = var9->Compare(var9, ConditionalNotEquals);
    Assert(resultA == false,
           "float(-1.0) != float(-1.0) should have been false");
    resultB = var9->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != float(-1.0) is inconsistent");
    Passed("float(-1.0) != float(-1.0)");
    resultA = var9->Compare(var9, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < float(-1.0) should have been false");
    resultB = var9->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < float(-1.0) is inconsistent");
    Passed("float(-1.0) < float(-1.0)");
    resultA = var9->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "float(-1.0) >= float(-1.0) should have been true");
    resultB = var9->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= float(-1.0) is inconsistent");
    Passed("float(-1.0) >= float(-1.0)");
    resultA = var9->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "float(-1.0) <= float(-1.0) should have been true");
    resultB = var9->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= float(-1.0) is inconsistent");
    Passed("float(-1.0) <= float(-1.0)");

// Evaluating float(-1.0) against hash
    resultA = var9->Compare(var10, ConditionalEquals);
    Assert(resultA == false,
           "float(-1.0) == hash should have been false");
    resultB = var10->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == hash is inconsistent");
    Passed("float(-1.0) == hash");
    resultA = var9->Compare(var10, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-1.0) != hash should have been true");
    resultB = var10->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != hash is inconsistent");
    Passed("float(-1.0) != hash");
    resultA = var9->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < hash should have been false");
    resultB = var10->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < hash is inconsistent");
    Passed("float(-1.0) < hash");
    resultA = var9->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) >= hash should have been false");
    resultB = var10->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= hash is inconsistent");
    Passed("float(-1.0) >= hash");
    resultA = var9->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) <= hash should have been false");
    resultB = var10->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= hash is inconsistent");
    Passed("float(-1.0) <= hash");

// Evaluating float(-1.0) against array()
    resultA = var9->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "float(-1.0) == array() should have been false");
    resultB = var11->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == array() is inconsistent");
    Passed("float(-1.0) == array()");
    resultA = var9->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-1.0) != array() should have been true");
    resultB = var11->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != array() is inconsistent");
    Passed("float(-1.0) != array()");
    resultA = var9->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < array() should have been false");
    resultB = var11->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < array() is inconsistent");
    Passed("float(-1.0) < array()");
    resultA = var9->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) >= array() should have been false");
    resultB = var11->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= array() is inconsistent");
    Passed("float(-1.0) >= array()");
    resultA = var9->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) <= array() should have been false");
    resultB = var11->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= array() is inconsistent");
    Passed("float(-1.0) <= array()");

// Evaluating float(-1.0) against array(..)
    resultA = var9->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "float(-1.0) == array(..) should have been false");
    resultB = var12->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == array(..) is inconsistent");
    Passed("float(-1.0) == array(..)");
    resultA = var9->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-1.0) != array(..) should have been true");
    resultB = var12->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != array(..) is inconsistent");
    Passed("float(-1.0) != array(..)");
    resultA = var9->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < array(..) should have been false");
    resultB = var12->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < array(..) is inconsistent");
    Passed("float(-1.0) < array(..)");
    resultA = var9->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) >= array(..) should have been false");
    resultB = var12->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= array(..) is inconsistent");
    Passed("float(-1.0) >= array(..)");
    resultA = var9->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) <= array(..) should have been false");
    resultB = var12->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= array(..) is inconsistent");
    Passed("float(-1.0) <= array(..)");

// Evaluating float(-1.0) against bool(true)
    resultA = var9->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "float(-1.0) == bool(true) should have been false");
    resultB = var13->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == bool(true) is inconsistent");
    Passed("float(-1.0) == bool(true)");
    resultA = var9->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-1.0) != bool(true) should have been true");
    resultB = var13->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != bool(true) is inconsistent");
    Passed("float(-1.0) != bool(true)");
    resultA = var9->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < bool(true) should have been false");
    resultB = var13->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < bool(true) is inconsistent");
    Passed("float(-1.0) < bool(true)");
    resultA = var9->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) >= bool(true) should have been false");
    resultB = var13->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= bool(true) is inconsistent");
    Passed("float(-1.0) >= bool(true)");
    resultA = var9->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) <= bool(true) should have been false");
    resultB = var13->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= bool(true) is inconsistent");
    Passed("float(-1.0) <= bool(true)");

// Evaluating float(-1.0) against bool(false)
    resultA = var9->Compare(var14, ConditionalEquals);
    Assert(resultA == true,
           "float(-1.0) == bool(false) should have been true");
    resultB = var14->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == bool(false) is inconsistent");
    Passed("float(-1.0) == bool(false)");
    resultA = var9->Compare(var14, ConditionalNotEquals);
    Assert(resultA == false,
           "float(-1.0) != bool(false) should have been false");
    resultB = var14->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != bool(false) is inconsistent");
    Passed("float(-1.0) != bool(false)");
    resultA = var9->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < bool(false) should have been false");
    resultB = var14->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < bool(false) is inconsistent");
    Passed("float(-1.0) < bool(false)");
    resultA = var9->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) >= bool(false) should have been false");
    resultB = var14->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= bool(false) is inconsistent");
    Passed("float(-1.0) >= bool(false)");
    resultA = var9->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) <= bool(false) should have been false");
    resultB = var14->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= bool(false) is inconsistent");
    Passed("float(-1.0) <= bool(false)");

// Evaluating float(-1.0) against string("")
    resultA = var9->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "float(-1.0) == string(\"\") should have been false");
    resultB = var15->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == string(\"\") is inconsistent");
    Passed("float(-1.0) == string(\"\")");
    resultA = var9->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-1.0) != string(\"\") should have been true");
    resultB = var15->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != string(\"\") is inconsistent");
    Passed("float(-1.0) != string(\"\")");
    resultA = var9->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < string(\"\") should have been false");
    resultB = var15->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < string(\"\") is inconsistent");
    Passed("float(-1.0) < string(\"\")");
    resultA = var9->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) >= string(\"\") should have been false");
    resultB = var15->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= string(\"\") is inconsistent");
    Passed("float(-1.0) >= string(\"\")");
    resultA = var9->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) <= string(\"\") should have been false");
    resultB = var15->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= string(\"\") is inconsistent");
    Passed("float(-1.0) <= string(\"\")");

// Evaluating float(-1.0) against string("..")
    resultA = var9->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "float(-1.0) == string(\"..\") should have been false");
    resultB = var16->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == string(\"..\") is inconsistent");
    Passed("float(-1.0) == string(\"..\")");
    resultA = var9->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-1.0) != string(\"..\") should have been true");
    resultB = var16->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != string(\"..\") is inconsistent");
    Passed("float(-1.0) != string(\"..\")");
    resultA = var9->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < string(\"..\") should have been false");
    resultB = var16->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < string(\"..\") is inconsistent");
    Passed("float(-1.0) < string(\"..\")");
    resultA = var9->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) >= string(\"..\") should have been false");
    resultB = var16->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= string(\"..\") is inconsistent");
    Passed("float(-1.0) >= string(\"..\")");
    resultA = var9->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) <= string(\"..\") should have been false");
    resultB = var16->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= string(\"..\") is inconsistent");
    Passed("float(-1.0) <= string(\"..\")");

// Evaluating float(-1.0) against string("t")
    resultA = var9->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "float(-1.0) == string(\"t\") should have been false");
    resultB = var17->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == string(\"t\") is inconsistent");
    Passed("float(-1.0) == string(\"t\")");
    resultA = var9->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-1.0) != string(\"t\") should have been true");
    resultB = var17->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != string(\"t\") is inconsistent");
    Passed("float(-1.0) != string(\"t\")");
    resultA = var9->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < string(\"t\") should have been false");
    resultB = var17->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < string(\"t\") is inconsistent");
    Passed("float(-1.0) < string(\"t\")");
    resultA = var9->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) >= string(\"t\") should have been false");
    resultB = var17->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= string(\"t\") is inconsistent");
    Passed("float(-1.0) >= string(\"t\")");
    resultA = var9->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) <= string(\"t\") should have been false");
    resultB = var17->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= string(\"t\") is inconsistent");
    Passed("float(-1.0) <= string(\"t\")");

// Evaluating float(-1.0) against string("f")
    resultA = var9->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "float(-1.0) == string(\"f\") should have been false");
    resultB = var18->Compare(var9, ConditionalEquals);
    Assert(resultA == resultB,
           "float(-1.0) == string(\"f\") is inconsistent");
    Passed("float(-1.0) == string(\"f\")");
    resultA = var9->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "float(-1.0) != string(\"f\") should have been true");
    resultB = var18->Compare(var9, ConditionalNotEquals);
    Assert(resultA == resultB,
           "float(-1.0) != string(\"f\") is inconsistent");
    Passed("float(-1.0) != string(\"f\")");
    resultA = var9->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "float(-1.0) < string(\"f\") should have been false");
    resultB = var18->Compare(var9, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "float(-1.0) < string(\"f\") is inconsistent");
    Passed("float(-1.0) < string(\"f\")");
    resultA = var9->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) >= string(\"f\") should have been false");
    resultB = var18->Compare(var9, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) >= string(\"f\") is inconsistent");
    Passed("float(-1.0) >= string(\"f\")");
    resultA = var9->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "float(-1.0) <= string(\"f\") should have been false");
    resultB = var18->Compare(var9, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "float(-1.0) <= string(\"f\") is inconsistent");
    Passed("float(-1.0) <= string(\"f\")");

// * Evaluating hash
    Assert(var10->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of hash failed");
    Passed("Implicit test of hash");

// Evaluating hash against hash
    resultA = var10->Compare(var10, ConditionalEquals);
    Assert(resultA == true,
           "hash == hash should have been true");
    resultB = var10->Compare(var10, ConditionalEquals);
    Assert(resultA == resultB,
           "hash == hash is inconsistent");
    Passed("hash == hash");
    resultA = var10->Compare(var10, ConditionalNotEquals);
    Assert(resultA == false,
           "hash != hash should have been false");
    resultB = var10->Compare(var10, ConditionalNotEquals);
    Assert(resultA == resultB,
           "hash != hash is inconsistent");
    Passed("hash != hash");
    resultA = var10->Compare(var10, ConditionalLessThan);
    Assert(resultA == false,
           "hash < hash should have been false");
    resultB = var10->Compare(var10, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "hash < hash is inconsistent");
    Passed("hash < hash");
    resultA = var10->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "hash >= hash should have been false");
    resultB = var10->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "hash >= hash is inconsistent");
    Passed("hash >= hash");
    resultA = var10->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "hash <= hash should have been false");
    resultB = var10->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "hash <= hash is inconsistent");
    Passed("hash <= hash");

// Evaluating hash against array()
    resultA = var10->Compare(var11, ConditionalEquals);
    Assert(resultA == false,
           "hash == array() should have been false");
    resultB = var11->Compare(var10, ConditionalEquals);
    Assert(resultA == resultB,
           "hash == array() is inconsistent");
    Passed("hash == array()");
    resultA = var10->Compare(var11, ConditionalNotEquals);
    Assert(resultA == true,
           "hash != array() should have been true");
    resultB = var11->Compare(var10, ConditionalNotEquals);
    Assert(resultA == resultB,
           "hash != array() is inconsistent");
    Passed("hash != array()");
    resultA = var10->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "hash < array() should have been false");
    resultB = var11->Compare(var10, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "hash < array() is inconsistent");
    Passed("hash < array()");
    resultA = var10->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "hash >= array() should have been false");
    resultB = var11->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "hash >= array() is inconsistent");
    Passed("hash >= array()");
    resultA = var10->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "hash <= array() should have been false");
    resultB = var11->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "hash <= array() is inconsistent");
    Passed("hash <= array()");

// Evaluating hash against array(..)
    resultA = var10->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "hash == array(..) should have been false");
    resultB = var12->Compare(var10, ConditionalEquals);
    Assert(resultA == resultB,
           "hash == array(..) is inconsistent");
    Passed("hash == array(..)");
    resultA = var10->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "hash != array(..) should have been true");
    resultB = var12->Compare(var10, ConditionalNotEquals);
    Assert(resultA == resultB,
           "hash != array(..) is inconsistent");
    Passed("hash != array(..)");
    resultA = var10->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "hash < array(..) should have been false");
    resultB = var12->Compare(var10, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "hash < array(..) is inconsistent");
    Passed("hash < array(..)");
    resultA = var10->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "hash >= array(..) should have been false");
    resultB = var12->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "hash >= array(..) is inconsistent");
    Passed("hash >= array(..)");
    resultA = var10->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "hash <= array(..) should have been false");
    resultB = var12->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "hash <= array(..) is inconsistent");
    Passed("hash <= array(..)");

// Evaluating hash against bool(true)
    resultA = var10->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "hash == bool(true) should have been false");
    resultB = var13->Compare(var10, ConditionalEquals);
    Assert(resultA == resultB,
           "hash == bool(true) is inconsistent");
    Passed("hash == bool(true)");
    resultA = var10->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "hash != bool(true) should have been true");
    resultB = var13->Compare(var10, ConditionalNotEquals);
    Assert(resultA == resultB,
           "hash != bool(true) is inconsistent");
    Passed("hash != bool(true)");
    resultA = var10->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "hash < bool(true) should have been false");
    resultB = var13->Compare(var10, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "hash < bool(true) is inconsistent");
    Passed("hash < bool(true)");
    resultA = var10->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "hash >= bool(true) should have been false");
    resultB = var13->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "hash >= bool(true) is inconsistent");
    Passed("hash >= bool(true)");
    resultA = var10->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "hash <= bool(true) should have been false");
    resultB = var13->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "hash <= bool(true) is inconsistent");
    Passed("hash <= bool(true)");

// Evaluating hash against bool(false)
    resultA = var10->Compare(var14, ConditionalEquals);
    Assert(resultA == false,
           "hash == bool(false) should have been false");
    resultB = var14->Compare(var10, ConditionalEquals);
    Assert(resultA == resultB,
           "hash == bool(false) is inconsistent");
    Passed("hash == bool(false)");
    resultA = var10->Compare(var14, ConditionalNotEquals);
    Assert(resultA == true,
           "hash != bool(false) should have been true");
    resultB = var14->Compare(var10, ConditionalNotEquals);
    Assert(resultA == resultB,
           "hash != bool(false) is inconsistent");
    Passed("hash != bool(false)");
    resultA = var10->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "hash < bool(false) should have been false");
    resultB = var14->Compare(var10, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "hash < bool(false) is inconsistent");
    Passed("hash < bool(false)");
    resultA = var10->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "hash >= bool(false) should have been false");
    resultB = var14->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "hash >= bool(false) is inconsistent");
    Passed("hash >= bool(false)");
    resultA = var10->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "hash <= bool(false) should have been false");
    resultB = var14->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "hash <= bool(false) is inconsistent");
    Passed("hash <= bool(false)");

// Evaluating hash against string("")
    resultA = var10->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "hash == string(\"\") should have been false");
    resultB = var15->Compare(var10, ConditionalEquals);
    Assert(resultA == resultB,
           "hash == string(\"\") is inconsistent");
    Passed("hash == string(\"\")");
    resultA = var10->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "hash != string(\"\") should have been true");
    resultB = var15->Compare(var10, ConditionalNotEquals);
    Assert(resultA == resultB,
           "hash != string(\"\") is inconsistent");
    Passed("hash != string(\"\")");
    resultA = var10->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "hash < string(\"\") should have been false");
    resultB = var15->Compare(var10, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "hash < string(\"\") is inconsistent");
    Passed("hash < string(\"\")");
    resultA = var10->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "hash >= string(\"\") should have been false");
    resultB = var15->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "hash >= string(\"\") is inconsistent");
    Passed("hash >= string(\"\")");
    resultA = var10->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "hash <= string(\"\") should have been false");
    resultB = var15->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "hash <= string(\"\") is inconsistent");
    Passed("hash <= string(\"\")");

// Evaluating hash against string("..")
    resultA = var10->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "hash == string(\"..\") should have been false");
    resultB = var16->Compare(var10, ConditionalEquals);
    Assert(resultA == resultB,
           "hash == string(\"..\") is inconsistent");
    Passed("hash == string(\"..\")");
    resultA = var10->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "hash != string(\"..\") should have been true");
    resultB = var16->Compare(var10, ConditionalNotEquals);
    Assert(resultA == resultB,
           "hash != string(\"..\") is inconsistent");
    Passed("hash != string(\"..\")");
    resultA = var10->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "hash < string(\"..\") should have been false");
    resultB = var16->Compare(var10, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "hash < string(\"..\") is inconsistent");
    Passed("hash < string(\"..\")");
    resultA = var10->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "hash >= string(\"..\") should have been false");
    resultB = var16->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "hash >= string(\"..\") is inconsistent");
    Passed("hash >= string(\"..\")");
    resultA = var10->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "hash <= string(\"..\") should have been false");
    resultB = var16->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "hash <= string(\"..\") is inconsistent");
    Passed("hash <= string(\"..\")");

// Evaluating hash against string("t")
    resultA = var10->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "hash == string(\"t\") should have been false");
    resultB = var17->Compare(var10, ConditionalEquals);
    Assert(resultA == resultB,
           "hash == string(\"t\") is inconsistent");
    Passed("hash == string(\"t\")");
    resultA = var10->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "hash != string(\"t\") should have been true");
    resultB = var17->Compare(var10, ConditionalNotEquals);
    Assert(resultA == resultB,
           "hash != string(\"t\") is inconsistent");
    Passed("hash != string(\"t\")");
    resultA = var10->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "hash < string(\"t\") should have been false");
    resultB = var17->Compare(var10, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "hash < string(\"t\") is inconsistent");
    Passed("hash < string(\"t\")");
    resultA = var10->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "hash >= string(\"t\") should have been false");
    resultB = var17->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "hash >= string(\"t\") is inconsistent");
    Passed("hash >= string(\"t\")");
    resultA = var10->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "hash <= string(\"t\") should have been false");
    resultB = var17->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "hash <= string(\"t\") is inconsistent");
    Passed("hash <= string(\"t\")");

// Evaluating hash against string("f")
    resultA = var10->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "hash == string(\"f\") should have been false");
    resultB = var18->Compare(var10, ConditionalEquals);
    Assert(resultA == resultB,
           "hash == string(\"f\") is inconsistent");
    Passed("hash == string(\"f\")");
    resultA = var10->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "hash != string(\"f\") should have been true");
    resultB = var18->Compare(var10, ConditionalNotEquals);
    Assert(resultA == resultB,
           "hash != string(\"f\") is inconsistent");
    Passed("hash != string(\"f\")");
    resultA = var10->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "hash < string(\"f\") should have been false");
    resultB = var18->Compare(var10, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "hash < string(\"f\") is inconsistent");
    Passed("hash < string(\"f\")");
    resultA = var10->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "hash >= string(\"f\") should have been false");
    resultB = var18->Compare(var10, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "hash >= string(\"f\") is inconsistent");
    Passed("hash >= string(\"f\")");
    resultA = var10->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "hash <= string(\"f\") should have been false");
    resultB = var18->Compare(var10, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "hash <= string(\"f\") is inconsistent");
    Passed("hash <= string(\"f\")");

// * Evaluating array()
    Assert(var11->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of array() failed");
    Passed("Implicit test of array()");

// Evaluating array() against array()
    resultA = var11->Compare(var11, ConditionalEquals);
    Assert(resultA == true,
           "array() == array() should have been true");
    resultB = var11->Compare(var11, ConditionalEquals);
    Assert(resultA == resultB,
           "array() == array() is inconsistent");
    Passed("array() == array()");
    resultA = var11->Compare(var11, ConditionalNotEquals);
    Assert(resultA == false,
           "array() != array() should have been false");
    resultB = var11->Compare(var11, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array() != array() is inconsistent");
    Passed("array() != array()");
    resultA = var11->Compare(var11, ConditionalLessThan);
    Assert(resultA == false,
           "array() < array() should have been false");
    resultB = var11->Compare(var11, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array() < array() is inconsistent");
    Passed("array() < array()");
    resultA = var11->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array() >= array() should have been false");
    resultB = var11->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array() >= array() is inconsistent");
    Passed("array() >= array()");
    resultA = var11->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array() <= array() should have been false");
    resultB = var11->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array() <= array() is inconsistent");
    Passed("array() <= array()");

// Evaluating array() against array(..)
    resultA = var11->Compare(var12, ConditionalEquals);
    Assert(resultA == false,
           "array() == array(..) should have been false");
    resultB = var12->Compare(var11, ConditionalEquals);
    Assert(resultA == resultB,
           "array() == array(..) is inconsistent");
    Passed("array() == array(..)");
    resultA = var11->Compare(var12, ConditionalNotEquals);
    Assert(resultA == true,
           "array() != array(..) should have been true");
    resultB = var12->Compare(var11, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array() != array(..) is inconsistent");
    Passed("array() != array(..)");
    resultA = var11->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "array() < array(..) should have been false");
    resultB = var12->Compare(var11, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array() < array(..) is inconsistent");
    Passed("array() < array(..)");
    resultA = var11->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array() >= array(..) should have been false");
    resultB = var12->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array() >= array(..) is inconsistent");
    Passed("array() >= array(..)");
    resultA = var11->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array() <= array(..) should have been false");
    resultB = var12->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array() <= array(..) is inconsistent");
    Passed("array() <= array(..)");

// Evaluating array() against bool(true)
    resultA = var11->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "array() == bool(true) should have been false");
    resultB = var13->Compare(var11, ConditionalEquals);
    Assert(resultA == resultB,
           "array() == bool(true) is inconsistent");
    Passed("array() == bool(true)");
    resultA = var11->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "array() != bool(true) should have been true");
    resultB = var13->Compare(var11, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array() != bool(true) is inconsistent");
    Passed("array() != bool(true)");
    resultA = var11->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "array() < bool(true) should have been false");
    resultB = var13->Compare(var11, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array() < bool(true) is inconsistent");
    Passed("array() < bool(true)");
    resultA = var11->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array() >= bool(true) should have been false");
    resultB = var13->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array() >= bool(true) is inconsistent");
    Passed("array() >= bool(true)");
    resultA = var11->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array() <= bool(true) should have been false");
    resultB = var13->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array() <= bool(true) is inconsistent");
    Passed("array() <= bool(true)");

// Evaluating array() against bool(false)
    resultA = var11->Compare(var14, ConditionalEquals);
    Assert(resultA == false,
           "array() == bool(false) should have been false");
    resultB = var14->Compare(var11, ConditionalEquals);
    Assert(resultA == resultB,
           "array() == bool(false) is inconsistent");
    Passed("array() == bool(false)");
    resultA = var11->Compare(var14, ConditionalNotEquals);
    Assert(resultA == true,
           "array() != bool(false) should have been true");
    resultB = var14->Compare(var11, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array() != bool(false) is inconsistent");
    Passed("array() != bool(false)");
    resultA = var11->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "array() < bool(false) should have been false");
    resultB = var14->Compare(var11, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array() < bool(false) is inconsistent");
    Passed("array() < bool(false)");
    resultA = var11->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array() >= bool(false) should have been false");
    resultB = var14->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array() >= bool(false) is inconsistent");
    Passed("array() >= bool(false)");
    resultA = var11->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array() <= bool(false) should have been false");
    resultB = var14->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array() <= bool(false) is inconsistent");
    Passed("array() <= bool(false)");

// Evaluating array() against string("")
    resultA = var11->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "array() == string(\"\") should have been false");
    resultB = var15->Compare(var11, ConditionalEquals);
    Assert(resultA == resultB,
           "array() == string(\"\") is inconsistent");
    Passed("array() == string(\"\")");
    resultA = var11->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "array() != string(\"\") should have been true");
    resultB = var15->Compare(var11, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array() != string(\"\") is inconsistent");
    Passed("array() != string(\"\")");
    resultA = var11->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "array() < string(\"\") should have been false");
    resultB = var15->Compare(var11, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array() < string(\"\") is inconsistent");
    Passed("array() < string(\"\")");
    resultA = var11->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array() >= string(\"\") should have been false");
    resultB = var15->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array() >= string(\"\") is inconsistent");
    Passed("array() >= string(\"\")");
    resultA = var11->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array() <= string(\"\") should have been false");
    resultB = var15->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array() <= string(\"\") is inconsistent");
    Passed("array() <= string(\"\")");

// Evaluating array() against string("..")
    resultA = var11->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "array() == string(\"..\") should have been false");
    resultB = var16->Compare(var11, ConditionalEquals);
    Assert(resultA == resultB,
           "array() == string(\"..\") is inconsistent");
    Passed("array() == string(\"..\")");
    resultA = var11->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "array() != string(\"..\") should have been true");
    resultB = var16->Compare(var11, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array() != string(\"..\") is inconsistent");
    Passed("array() != string(\"..\")");
    resultA = var11->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "array() < string(\"..\") should have been false");
    resultB = var16->Compare(var11, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array() < string(\"..\") is inconsistent");
    Passed("array() < string(\"..\")");
    resultA = var11->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array() >= string(\"..\") should have been false");
    resultB = var16->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array() >= string(\"..\") is inconsistent");
    Passed("array() >= string(\"..\")");
    resultA = var11->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array() <= string(\"..\") should have been false");
    resultB = var16->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array() <= string(\"..\") is inconsistent");
    Passed("array() <= string(\"..\")");

// Evaluating array() against string("t")
    resultA = var11->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "array() == string(\"t\") should have been false");
    resultB = var17->Compare(var11, ConditionalEquals);
    Assert(resultA == resultB,
           "array() == string(\"t\") is inconsistent");
    Passed("array() == string(\"t\")");
    resultA = var11->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "array() != string(\"t\") should have been true");
    resultB = var17->Compare(var11, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array() != string(\"t\") is inconsistent");
    Passed("array() != string(\"t\")");
    resultA = var11->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "array() < string(\"t\") should have been false");
    resultB = var17->Compare(var11, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array() < string(\"t\") is inconsistent");
    Passed("array() < string(\"t\")");
    resultA = var11->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array() >= string(\"t\") should have been false");
    resultB = var17->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array() >= string(\"t\") is inconsistent");
    Passed("array() >= string(\"t\")");
    resultA = var11->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array() <= string(\"t\") should have been false");
    resultB = var17->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array() <= string(\"t\") is inconsistent");
    Passed("array() <= string(\"t\")");

// Evaluating array() against string("f")
    resultA = var11->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "array() == string(\"f\") should have been false");
    resultB = var18->Compare(var11, ConditionalEquals);
    Assert(resultA == resultB,
           "array() == string(\"f\") is inconsistent");
    Passed("array() == string(\"f\")");
    resultA = var11->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "array() != string(\"f\") should have been true");
    resultB = var18->Compare(var11, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array() != string(\"f\") is inconsistent");
    Passed("array() != string(\"f\")");
    resultA = var11->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "array() < string(\"f\") should have been false");
    resultB = var18->Compare(var11, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array() < string(\"f\") is inconsistent");
    Passed("array() < string(\"f\")");
    resultA = var11->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array() >= string(\"f\") should have been false");
    resultB = var18->Compare(var11, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array() >= string(\"f\") is inconsistent");
    Passed("array() >= string(\"f\")");
    resultA = var11->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array() <= string(\"f\") should have been false");
    resultB = var18->Compare(var11, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array() <= string(\"f\") is inconsistent");
    Passed("array() <= string(\"f\")");

// * Evaluating array(..)
    Assert(var12->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of array(..) failed");
    Passed("Implicit test of array(..)");

// Evaluating array(..) against array(..)
    resultA = var12->Compare(var12, ConditionalEquals);
    Assert(resultA == true,
           "array(..) == array(..) should have been true");
    resultB = var12->Compare(var12, ConditionalEquals);
    Assert(resultA == resultB,
           "array(..) == array(..) is inconsistent");
    Passed("array(..) == array(..)");
    resultA = var12->Compare(var12, ConditionalNotEquals);
    Assert(resultA == false,
           "array(..) != array(..) should have been false");
    resultB = var12->Compare(var12, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array(..) != array(..) is inconsistent");
    Passed("array(..) != array(..)");
    resultA = var12->Compare(var12, ConditionalLessThan);
    Assert(resultA == false,
           "array(..) < array(..) should have been false");
    resultB = var12->Compare(var12, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array(..) < array(..) is inconsistent");
    Passed("array(..) < array(..)");
    resultA = var12->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array(..) >= array(..) should have been false");
    resultB = var12->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array(..) >= array(..) is inconsistent");
    Passed("array(..) >= array(..)");
    resultA = var12->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array(..) <= array(..) should have been false");
    resultB = var12->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array(..) <= array(..) is inconsistent");
    Passed("array(..) <= array(..)");

// Evaluating array(..) against bool(true)
    resultA = var12->Compare(var13, ConditionalEquals);
    Assert(resultA == false,
           "array(..) == bool(true) should have been false");
    resultB = var13->Compare(var12, ConditionalEquals);
    Assert(resultA == resultB,
           "array(..) == bool(true) is inconsistent");
    Passed("array(..) == bool(true)");
    resultA = var12->Compare(var13, ConditionalNotEquals);
    Assert(resultA == true,
           "array(..) != bool(true) should have been true");
    resultB = var13->Compare(var12, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array(..) != bool(true) is inconsistent");
    Passed("array(..) != bool(true)");
    resultA = var12->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "array(..) < bool(true) should have been false");
    resultB = var13->Compare(var12, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array(..) < bool(true) is inconsistent");
    Passed("array(..) < bool(true)");
    resultA = var12->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array(..) >= bool(true) should have been false");
    resultB = var13->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array(..) >= bool(true) is inconsistent");
    Passed("array(..) >= bool(true)");
    resultA = var12->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array(..) <= bool(true) should have been false");
    resultB = var13->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array(..) <= bool(true) is inconsistent");
    Passed("array(..) <= bool(true)");

// Evaluating array(..) against bool(false)
    resultA = var12->Compare(var14, ConditionalEquals);
    Assert(resultA == false,
           "array(..) == bool(false) should have been false");
    resultB = var14->Compare(var12, ConditionalEquals);
    Assert(resultA == resultB,
           "array(..) == bool(false) is inconsistent");
    Passed("array(..) == bool(false)");
    resultA = var12->Compare(var14, ConditionalNotEquals);
    Assert(resultA == true,
           "array(..) != bool(false) should have been true");
    resultB = var14->Compare(var12, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array(..) != bool(false) is inconsistent");
    Passed("array(..) != bool(false)");
    resultA = var12->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "array(..) < bool(false) should have been false");
    resultB = var14->Compare(var12, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array(..) < bool(false) is inconsistent");
    Passed("array(..) < bool(false)");
    resultA = var12->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array(..) >= bool(false) should have been false");
    resultB = var14->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array(..) >= bool(false) is inconsistent");
    Passed("array(..) >= bool(false)");
    resultA = var12->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array(..) <= bool(false) should have been false");
    resultB = var14->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array(..) <= bool(false) is inconsistent");
    Passed("array(..) <= bool(false)");

// Evaluating array(..) against string("")
    resultA = var12->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "array(..) == string(\"\") should have been false");
    resultB = var15->Compare(var12, ConditionalEquals);
    Assert(resultA == resultB,
           "array(..) == string(\"\") is inconsistent");
    Passed("array(..) == string(\"\")");
    resultA = var12->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "array(..) != string(\"\") should have been true");
    resultB = var15->Compare(var12, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array(..) != string(\"\") is inconsistent");
    Passed("array(..) != string(\"\")");
    resultA = var12->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "array(..) < string(\"\") should have been false");
    resultB = var15->Compare(var12, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array(..) < string(\"\") is inconsistent");
    Passed("array(..) < string(\"\")");
    resultA = var12->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array(..) >= string(\"\") should have been false");
    resultB = var15->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array(..) >= string(\"\") is inconsistent");
    Passed("array(..) >= string(\"\")");
    resultA = var12->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array(..) <= string(\"\") should have been false");
    resultB = var15->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array(..) <= string(\"\") is inconsistent");
    Passed("array(..) <= string(\"\")");

// Evaluating array(..) against string("..")
    resultA = var12->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "array(..) == string(\"..\") should have been false");
    resultB = var16->Compare(var12, ConditionalEquals);
    Assert(resultA == resultB,
           "array(..) == string(\"..\") is inconsistent");
    Passed("array(..) == string(\"..\")");
    resultA = var12->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "array(..) != string(\"..\") should have been true");
    resultB = var16->Compare(var12, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array(..) != string(\"..\") is inconsistent");
    Passed("array(..) != string(\"..\")");
    resultA = var12->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "array(..) < string(\"..\") should have been false");
    resultB = var16->Compare(var12, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array(..) < string(\"..\") is inconsistent");
    Passed("array(..) < string(\"..\")");
    resultA = var12->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array(..) >= string(\"..\") should have been false");
    resultB = var16->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array(..) >= string(\"..\") is inconsistent");
    Passed("array(..) >= string(\"..\")");
    resultA = var12->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array(..) <= string(\"..\") should have been false");
    resultB = var16->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array(..) <= string(\"..\") is inconsistent");
    Passed("array(..) <= string(\"..\")");

// Evaluating array(..) against string("t")
    resultA = var12->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "array(..) == string(\"t\") should have been false");
    resultB = var17->Compare(var12, ConditionalEquals);
    Assert(resultA == resultB,
           "array(..) == string(\"t\") is inconsistent");
    Passed("array(..) == string(\"t\")");
    resultA = var12->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "array(..) != string(\"t\") should have been true");
    resultB = var17->Compare(var12, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array(..) != string(\"t\") is inconsistent");
    Passed("array(..) != string(\"t\")");
    resultA = var12->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "array(..) < string(\"t\") should have been false");
    resultB = var17->Compare(var12, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array(..) < string(\"t\") is inconsistent");
    Passed("array(..) < string(\"t\")");
    resultA = var12->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array(..) >= string(\"t\") should have been false");
    resultB = var17->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array(..) >= string(\"t\") is inconsistent");
    Passed("array(..) >= string(\"t\")");
    resultA = var12->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array(..) <= string(\"t\") should have been false");
    resultB = var17->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array(..) <= string(\"t\") is inconsistent");
    Passed("array(..) <= string(\"t\")");

// Evaluating array(..) against string("f")
    resultA = var12->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "array(..) == string(\"f\") should have been false");
    resultB = var18->Compare(var12, ConditionalEquals);
    Assert(resultA == resultB,
           "array(..) == string(\"f\") is inconsistent");
    Passed("array(..) == string(\"f\")");
    resultA = var12->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "array(..) != string(\"f\") should have been true");
    resultB = var18->Compare(var12, ConditionalNotEquals);
    Assert(resultA == resultB,
           "array(..) != string(\"f\") is inconsistent");
    Passed("array(..) != string(\"f\")");
    resultA = var12->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "array(..) < string(\"f\") should have been false");
    resultB = var18->Compare(var12, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "array(..) < string(\"f\") is inconsistent");
    Passed("array(..) < string(\"f\")");
    resultA = var12->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "array(..) >= string(\"f\") should have been false");
    resultB = var18->Compare(var12, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "array(..) >= string(\"f\") is inconsistent");
    Passed("array(..) >= string(\"f\")");
    resultA = var12->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "array(..) <= string(\"f\") should have been false");
    resultB = var18->Compare(var12, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "array(..) <= string(\"f\") is inconsistent");
    Passed("array(..) <= string(\"f\")");

// * Evaluating bool(true)
    Assert(var13->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of bool(true) failed");
    Passed("Implicit test of bool(true)");

// Evaluating bool(true) against bool(true)
    resultA = var13->Compare(var13, ConditionalEquals);
    Assert(resultA == true,
           "bool(true) == bool(true) should have been true");
    resultB = var13->Compare(var13, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(true) == bool(true) is inconsistent");
    Passed("bool(true) == bool(true)");
    resultA = var13->Compare(var13, ConditionalNotEquals);
    Assert(resultA == false,
           "bool(true) != bool(true) should have been false");
    resultB = var13->Compare(var13, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(true) != bool(true) is inconsistent");
    Passed("bool(true) != bool(true)");
    resultA = var13->Compare(var13, ConditionalLessThan);
    Assert(resultA == false,
           "bool(true) < bool(true) should have been false");
    resultB = var13->Compare(var13, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(true) < bool(true) is inconsistent");
    Passed("bool(true) < bool(true)");
    resultA = var13->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(true) >= bool(true) should have been false");
    resultB = var13->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) >= bool(true) is inconsistent");
    Passed("bool(true) >= bool(true)");
    resultA = var13->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(true) <= bool(true) should have been false");
    resultB = var13->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) <= bool(true) is inconsistent");
    Passed("bool(true) <= bool(true)");

// Evaluating bool(true) against bool(false)
    resultA = var13->Compare(var14, ConditionalEquals);
    Assert(resultA == false,
           "bool(true) == bool(false) should have been false");
    resultB = var14->Compare(var13, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(true) == bool(false) is inconsistent");
    Passed("bool(true) == bool(false)");
    resultA = var13->Compare(var14, ConditionalNotEquals);
    Assert(resultA == true,
           "bool(true) != bool(false) should have been true");
    resultB = var14->Compare(var13, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(true) != bool(false) is inconsistent");
    Passed("bool(true) != bool(false)");
    resultA = var13->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "bool(true) < bool(false) should have been false");
    resultB = var14->Compare(var13, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(true) < bool(false) is inconsistent");
    Passed("bool(true) < bool(false)");
    resultA = var13->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(true) >= bool(false) should have been false");
    resultB = var14->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) >= bool(false) is inconsistent");
    Passed("bool(true) >= bool(false)");
    resultA = var13->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(true) <= bool(false) should have been false");
    resultB = var14->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) <= bool(false) is inconsistent");
    Passed("bool(true) <= bool(false)");

// Evaluating bool(true) against string("")
    resultA = var13->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "bool(true) == string(\"\") should have been false");
    resultB = var15->Compare(var13, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(true) == string(\"\") is inconsistent");
    Passed("bool(true) == string(\"\")");
    resultA = var13->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "bool(true) != string(\"\") should have been true");
    resultB = var15->Compare(var13, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(true) != string(\"\") is inconsistent");
    Passed("bool(true) != string(\"\")");
    resultA = var13->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "bool(true) < string(\"\") should have been false");
    resultB = var15->Compare(var13, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(true) < string(\"\") is inconsistent");
    Passed("bool(true) < string(\"\")");
    resultA = var13->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(true) >= string(\"\") should have been false");
    resultB = var15->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) >= string(\"\") is inconsistent");
    Passed("bool(true) >= string(\"\")");
    resultA = var13->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(true) <= string(\"\") should have been false");
    resultB = var15->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) <= string(\"\") is inconsistent");
    Passed("bool(true) <= string(\"\")");

// Evaluating bool(true) against string("..")
    resultA = var13->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "bool(true) == string(\"..\") should have been false");
    resultB = var16->Compare(var13, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(true) == string(\"..\") is inconsistent");
    Passed("bool(true) == string(\"..\")");
    resultA = var13->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "bool(true) != string(\"..\") should have been true");
    resultB = var16->Compare(var13, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(true) != string(\"..\") is inconsistent");
    Passed("bool(true) != string(\"..\")");
    resultA = var13->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "bool(true) < string(\"..\") should have been false");
    resultB = var16->Compare(var13, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(true) < string(\"..\") is inconsistent");
    Passed("bool(true) < string(\"..\")");
    resultA = var13->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(true) >= string(\"..\") should have been false");
    resultB = var16->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) >= string(\"..\") is inconsistent");
    Passed("bool(true) >= string(\"..\")");
    resultA = var13->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(true) <= string(\"..\") should have been false");
    resultB = var16->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) <= string(\"..\") is inconsistent");
    Passed("bool(true) <= string(\"..\")");

// Evaluating bool(true) against string("t")
    resultA = var13->Compare(var17, ConditionalEquals);
    Assert(resultA == true,
           "bool(true) == string(\"t\") should have been true");
    resultB = var17->Compare(var13, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(true) == string(\"t\") is inconsistent");
    Passed("bool(true) == string(\"t\")");
    resultA = var13->Compare(var17, ConditionalNotEquals);
    Assert(resultA == false,
           "bool(true) != string(\"t\") should have been false");
    resultB = var17->Compare(var13, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(true) != string(\"t\") is inconsistent");
    Passed("bool(true) != string(\"t\")");
    resultA = var13->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "bool(true) < string(\"t\") should have been false");
    resultB = var17->Compare(var13, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(true) < string(\"t\") is inconsistent");
    Passed("bool(true) < string(\"t\")");
    resultA = var13->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(true) >= string(\"t\") should have been false");
    resultB = var17->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) >= string(\"t\") is inconsistent");
    Passed("bool(true) >= string(\"t\")");
    resultA = var13->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(true) <= string(\"t\") should have been false");
    resultB = var17->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) <= string(\"t\") is inconsistent");
    Passed("bool(true) <= string(\"t\")");

// Evaluating bool(true) against string("f")
    resultA = var13->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "bool(true) == string(\"f\") should have been false");
    resultB = var18->Compare(var13, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(true) == string(\"f\") is inconsistent");
    Passed("bool(true) == string(\"f\")");
    resultA = var13->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "bool(true) != string(\"f\") should have been true");
    resultB = var18->Compare(var13, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(true) != string(\"f\") is inconsistent");
    Passed("bool(true) != string(\"f\")");
    resultA = var13->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "bool(true) < string(\"f\") should have been false");
    resultB = var18->Compare(var13, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(true) < string(\"f\") is inconsistent");
    Passed("bool(true) < string(\"f\")");
    resultA = var13->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(true) >= string(\"f\") should have been false");
    resultB = var18->Compare(var13, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) >= string(\"f\") is inconsistent");
    Passed("bool(true) >= string(\"f\")");
    resultA = var13->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(true) <= string(\"f\") should have been false");
    resultB = var18->Compare(var13, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(true) <= string(\"f\") is inconsistent");
    Passed("bool(true) <= string(\"f\")");

// * Evaluating bool(false)
    Assert(var14->Compare(NULL, ConditionalImplicit) == false,
           "Implicit test of bool(false) failed");
    Passed("Implicit test of bool(false)");

// Evaluating bool(false) against bool(false)
    resultA = var14->Compare(var14, ConditionalEquals);
    Assert(resultA == true,
           "bool(false) == bool(false) should have been true");
    resultB = var14->Compare(var14, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(false) == bool(false) is inconsistent");
    Passed("bool(false) == bool(false)");
    resultA = var14->Compare(var14, ConditionalNotEquals);
    Assert(resultA == false,
           "bool(false) != bool(false) should have been false");
    resultB = var14->Compare(var14, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(false) != bool(false) is inconsistent");
    Passed("bool(false) != bool(false)");
    resultA = var14->Compare(var14, ConditionalLessThan);
    Assert(resultA == false,
           "bool(false) < bool(false) should have been false");
    resultB = var14->Compare(var14, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(false) < bool(false) is inconsistent");
    Passed("bool(false) < bool(false)");
    resultA = var14->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(false) >= bool(false) should have been false");
    resultB = var14->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) >= bool(false) is inconsistent");
    Passed("bool(false) >= bool(false)");
    resultA = var14->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(false) <= bool(false) should have been false");
    resultB = var14->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) <= bool(false) is inconsistent");
    Passed("bool(false) <= bool(false)");

// Evaluating bool(false) against string("")
    resultA = var14->Compare(var15, ConditionalEquals);
    Assert(resultA == false,
           "bool(false) == string(\"\") should have been false");
    resultB = var15->Compare(var14, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(false) == string(\"\") is inconsistent");
    Passed("bool(false) == string(\"\")");
    resultA = var14->Compare(var15, ConditionalNotEquals);
    Assert(resultA == true,
           "bool(false) != string(\"\") should have been true");
    resultB = var15->Compare(var14, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(false) != string(\"\") is inconsistent");
    Passed("bool(false) != string(\"\")");
    resultA = var14->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "bool(false) < string(\"\") should have been false");
    resultB = var15->Compare(var14, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(false) < string(\"\") is inconsistent");
    Passed("bool(false) < string(\"\")");
    resultA = var14->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(false) >= string(\"\") should have been false");
    resultB = var15->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) >= string(\"\") is inconsistent");
    Passed("bool(false) >= string(\"\")");
    resultA = var14->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(false) <= string(\"\") should have been false");
    resultB = var15->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) <= string(\"\") is inconsistent");
    Passed("bool(false) <= string(\"\")");

// Evaluating bool(false) against string("..")
    resultA = var14->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "bool(false) == string(\"..\") should have been false");
    resultB = var16->Compare(var14, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(false) == string(\"..\") is inconsistent");
    Passed("bool(false) == string(\"..\")");
    resultA = var14->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "bool(false) != string(\"..\") should have been true");
    resultB = var16->Compare(var14, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(false) != string(\"..\") is inconsistent");
    Passed("bool(false) != string(\"..\")");
    resultA = var14->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "bool(false) < string(\"..\") should have been false");
    resultB = var16->Compare(var14, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(false) < string(\"..\") is inconsistent");
    Passed("bool(false) < string(\"..\")");
    resultA = var14->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(false) >= string(\"..\") should have been false");
    resultB = var16->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) >= string(\"..\") is inconsistent");
    Passed("bool(false) >= string(\"..\")");
    resultA = var14->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(false) <= string(\"..\") should have been false");
    resultB = var16->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) <= string(\"..\") is inconsistent");
    Passed("bool(false) <= string(\"..\")");

// Evaluating bool(false) against string("t")
    resultA = var14->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "bool(false) == string(\"t\") should have been false");
    resultB = var17->Compare(var14, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(false) == string(\"t\") is inconsistent");
    Passed("bool(false) == string(\"t\")");
    resultA = var14->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "bool(false) != string(\"t\") should have been true");
    resultB = var17->Compare(var14, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(false) != string(\"t\") is inconsistent");
    Passed("bool(false) != string(\"t\")");
    resultA = var14->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "bool(false) < string(\"t\") should have been false");
    resultB = var17->Compare(var14, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(false) < string(\"t\") is inconsistent");
    Passed("bool(false) < string(\"t\")");
    resultA = var14->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(false) >= string(\"t\") should have been false");
    resultB = var17->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) >= string(\"t\") is inconsistent");
    Passed("bool(false) >= string(\"t\")");
    resultA = var14->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(false) <= string(\"t\") should have been false");
    resultB = var17->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) <= string(\"t\") is inconsistent");
    Passed("bool(false) <= string(\"t\")");

// Evaluating bool(false) against string("f")
    resultA = var14->Compare(var18, ConditionalEquals);
    Assert(resultA == true,
           "bool(false) == string(\"f\") should have been true");
    resultB = var18->Compare(var14, ConditionalEquals);
    Assert(resultA == resultB,
           "bool(false) == string(\"f\") is inconsistent");
    Passed("bool(false) == string(\"f\")");
    resultA = var14->Compare(var18, ConditionalNotEquals);
    Assert(resultA == false,
           "bool(false) != string(\"f\") should have been false");
    resultB = var18->Compare(var14, ConditionalNotEquals);
    Assert(resultA == resultB,
           "bool(false) != string(\"f\") is inconsistent");
    Passed("bool(false) != string(\"f\")");
    resultA = var14->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "bool(false) < string(\"f\") should have been false");
    resultB = var18->Compare(var14, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "bool(false) < string(\"f\") is inconsistent");
    Passed("bool(false) < string(\"f\")");
    resultA = var14->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "bool(false) >= string(\"f\") should have been false");
    resultB = var18->Compare(var14, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) >= string(\"f\") is inconsistent");
    Passed("bool(false) >= string(\"f\")");
    resultA = var14->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "bool(false) <= string(\"f\") should have been false");
    resultB = var18->Compare(var14, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "bool(false) <= string(\"f\") is inconsistent");
    Passed("bool(false) <= string(\"f\")");

// * Evaluating string("")
    Assert(var15->Compare(NULL, ConditionalImplicit) == false,
           "Implicit test of string(\"\") failed");
    Passed("Implicit test of string(\"\")");

// Evaluating string("") against string("")
    resultA = var15->Compare(var15, ConditionalEquals);
    Assert(resultA == true,
           "string(\"\") == string(\"\") should have been true");
    resultB = var15->Compare(var15, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"\") == string(\"\") is inconsistent");
    Passed("string(\"\") == string(\"\")");
    resultA = var15->Compare(var15, ConditionalNotEquals);
    Assert(resultA == false,
           "string(\"\") != string(\"\") should have been false");
    resultB = var15->Compare(var15, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"\") != string(\"\") is inconsistent");
    Passed("string(\"\") != string(\"\")");
    resultA = var15->Compare(var15, ConditionalLessThan);
    Assert(resultA == false,
           "string(\"\") < string(\"\") should have been false");
    resultB = var15->Compare(var15, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"\") < string(\"\") is inconsistent");
    Passed("string(\"\") < string(\"\")");
    resultA = var15->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "string(\"\") >= string(\"\") should have been true");
    resultB = var15->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"\") >= string(\"\") is inconsistent");
    Passed("string(\"\") >= string(\"\")");
    resultA = var15->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "string(\"\") <= string(\"\") should have been true");
    resultB = var15->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"\") <= string(\"\") is inconsistent");
    Passed("string(\"\") <= string(\"\")");

// Evaluating string("") against string("..")
    resultA = var15->Compare(var16, ConditionalEquals);
    Assert(resultA == false,
           "string(\"\") == string(\"..\") should have been false");
    resultB = var16->Compare(var15, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"\") == string(\"..\") is inconsistent");
    Passed("string(\"\") == string(\"..\")");
    resultA = var15->Compare(var16, ConditionalNotEquals);
    Assert(resultA == true,
           "string(\"\") != string(\"..\") should have been true");
    resultB = var16->Compare(var15, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"\") != string(\"..\") is inconsistent");
    Passed("string(\"\") != string(\"..\")");
    resultA = var15->Compare(var16, ConditionalLessThan);
    Assert(resultA == true,
           "string(\"\") < string(\"..\") should have been true");
    resultB = var16->Compare(var15, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"\") < string(\"..\") is inconsistent");
    Passed("string(\"\") < string(\"..\")");
    resultA = var15->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "string(\"\") >= string(\"..\") should have been false");
    resultB = var16->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"\") >= string(\"..\") is inconsistent");
    Passed("string(\"\") >= string(\"..\")");
    resultA = var15->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "string(\"\") <= string(\"..\") should have been true");
    resultB = var16->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"\") <= string(\"..\") is inconsistent");
    Passed("string(\"\") <= string(\"..\")");

// Evaluating string("") against string("t")
    resultA = var15->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "string(\"\") == string(\"t\") should have been false");
    resultB = var17->Compare(var15, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"\") == string(\"t\") is inconsistent");
    Passed("string(\"\") == string(\"t\")");
    resultA = var15->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "string(\"\") != string(\"t\") should have been true");
    resultB = var17->Compare(var15, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"\") != string(\"t\") is inconsistent");
    Passed("string(\"\") != string(\"t\")");
    resultA = var15->Compare(var17, ConditionalLessThan);
    Assert(resultA == true,
           "string(\"\") < string(\"t\") should have been true");
    resultB = var17->Compare(var15, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"\") < string(\"t\") is inconsistent");
    Passed("string(\"\") < string(\"t\")");
    resultA = var15->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "string(\"\") >= string(\"t\") should have been false");
    resultB = var17->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"\") >= string(\"t\") is inconsistent");
    Passed("string(\"\") >= string(\"t\")");
    resultA = var15->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "string(\"\") <= string(\"t\") should have been true");
    resultB = var17->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"\") <= string(\"t\") is inconsistent");
    Passed("string(\"\") <= string(\"t\")");

// Evaluating string("") against string("f")
    resultA = var15->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "string(\"\") == string(\"f\") should have been false");
    resultB = var18->Compare(var15, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"\") == string(\"f\") is inconsistent");
    Passed("string(\"\") == string(\"f\")");
    resultA = var15->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "string(\"\") != string(\"f\") should have been true");
    resultB = var18->Compare(var15, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"\") != string(\"f\") is inconsistent");
    Passed("string(\"\") != string(\"f\")");
    resultA = var15->Compare(var18, ConditionalLessThan);
    Assert(resultA == true,
           "string(\"\") < string(\"f\") should have been true");
    resultB = var18->Compare(var15, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"\") < string(\"f\") is inconsistent");
    Passed("string(\"\") < string(\"f\")");
    resultA = var15->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "string(\"\") >= string(\"f\") should have been false");
    resultB = var18->Compare(var15, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"\") >= string(\"f\") is inconsistent");
    Passed("string(\"\") >= string(\"f\")");
    resultA = var15->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "string(\"\") <= string(\"f\") should have been true");
    resultB = var18->Compare(var15, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"\") <= string(\"f\") is inconsistent");
    Passed("string(\"\") <= string(\"f\")");

// * Evaluating string("..")
    Assert(var16->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of string(\"..\") failed");
    Passed("Implicit test of string(\"..\")");

// Evaluating string("..") against string("..")
    resultA = var16->Compare(var16, ConditionalEquals);
    Assert(resultA == true,
           "string(\"..\") == string(\"..\") should have been true");
    resultB = var16->Compare(var16, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"..\") == string(\"..\") is inconsistent");
    Passed("string(\"..\") == string(\"..\")");
    resultA = var16->Compare(var16, ConditionalNotEquals);
    Assert(resultA == false,
           "string(\"..\") != string(\"..\") should have been false");
    resultB = var16->Compare(var16, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"..\") != string(\"..\") is inconsistent");
    Passed("string(\"..\") != string(\"..\")");
    resultA = var16->Compare(var16, ConditionalLessThan);
    Assert(resultA == false,
           "string(\"..\") < string(\"..\") should have been false");
    resultB = var16->Compare(var16, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"..\") < string(\"..\") is inconsistent");
    Passed("string(\"..\") < string(\"..\")");
    resultA = var16->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "string(\"..\") >= string(\"..\") should have been true");
    resultB = var16->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"..\") >= string(\"..\") is inconsistent");
    Passed("string(\"..\") >= string(\"..\")");
    resultA = var16->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "string(\"..\") <= string(\"..\") should have been true");
    resultB = var16->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"..\") <= string(\"..\") is inconsistent");
    Passed("string(\"..\") <= string(\"..\")");

// Evaluating string("..") against string("t")
    resultA = var16->Compare(var17, ConditionalEquals);
    Assert(resultA == false,
           "string(\"..\") == string(\"t\") should have been false");
    resultB = var17->Compare(var16, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"..\") == string(\"t\") is inconsistent");
    Passed("string(\"..\") == string(\"t\")");
    resultA = var16->Compare(var17, ConditionalNotEquals);
    Assert(resultA == true,
           "string(\"..\") != string(\"t\") should have been true");
    resultB = var17->Compare(var16, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"..\") != string(\"t\") is inconsistent");
    Passed("string(\"..\") != string(\"t\")");
    resultA = var16->Compare(var17, ConditionalLessThan);
    Assert(resultA == true,
           "string(\"..\") < string(\"t\") should have been true");
    resultB = var17->Compare(var16, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"..\") < string(\"t\") is inconsistent");
    Passed("string(\"..\") < string(\"t\")");
    resultA = var16->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "string(\"..\") >= string(\"t\") should have been false");
    resultB = var17->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"..\") >= string(\"t\") is inconsistent");
    Passed("string(\"..\") >= string(\"t\")");
    resultA = var16->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "string(\"..\") <= string(\"t\") should have been true");
    resultB = var17->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"..\") <= string(\"t\") is inconsistent");
    Passed("string(\"..\") <= string(\"t\")");

// Evaluating string("..") against string("f")
    resultA = var16->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "string(\"..\") == string(\"f\") should have been false");
    resultB = var18->Compare(var16, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"..\") == string(\"f\") is inconsistent");
    Passed("string(\"..\") == string(\"f\")");
    resultA = var16->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "string(\"..\") != string(\"f\") should have been true");
    resultB = var18->Compare(var16, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"..\") != string(\"f\") is inconsistent");
    Passed("string(\"..\") != string(\"f\")");
    resultA = var16->Compare(var18, ConditionalLessThan);
    Assert(resultA == true,
           "string(\"..\") < string(\"f\") should have been true");
    resultB = var18->Compare(var16, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"..\") < string(\"f\") is inconsistent");
    Passed("string(\"..\") < string(\"f\")");
    resultA = var16->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == false,
           "string(\"..\") >= string(\"f\") should have been false");
    resultB = var18->Compare(var16, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"..\") >= string(\"f\") is inconsistent");
    Passed("string(\"..\") >= string(\"f\")");
    resultA = var16->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "string(\"..\") <= string(\"f\") should have been true");
    resultB = var18->Compare(var16, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"..\") <= string(\"f\") is inconsistent");
    Passed("string(\"..\") <= string(\"f\")");

// * Evaluating string("t")
    Assert(var17->Compare(NULL, ConditionalImplicit) == true,
           "Implicit test of string(\"t\") failed");
    Passed("Implicit test of string(\"t\")");

// Evaluating string("t") against string("t")
    resultA = var17->Compare(var17, ConditionalEquals);
    Assert(resultA == true,
           "string(\"t\") == string(\"t\") should have been true");
    resultB = var17->Compare(var17, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"t\") == string(\"t\") is inconsistent");
    Passed("string(\"t\") == string(\"t\")");
    resultA = var17->Compare(var17, ConditionalNotEquals);
    Assert(resultA == false,
           "string(\"t\") != string(\"t\") should have been false");
    resultB = var17->Compare(var17, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"t\") != string(\"t\") is inconsistent");
    Passed("string(\"t\") != string(\"t\")");
    resultA = var17->Compare(var17, ConditionalLessThan);
    Assert(resultA == false,
           "string(\"t\") < string(\"t\") should have been false");
    resultB = var17->Compare(var17, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"t\") < string(\"t\") is inconsistent");
    Passed("string(\"t\") < string(\"t\")");
    resultA = var17->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "string(\"t\") >= string(\"t\") should have been true");
    resultB = var17->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"t\") >= string(\"t\") is inconsistent");
    Passed("string(\"t\") >= string(\"t\")");
    resultA = var17->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "string(\"t\") <= string(\"t\") should have been true");
    resultB = var17->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"t\") <= string(\"t\") is inconsistent");
    Passed("string(\"t\") <= string(\"t\")");

// Evaluating string("t") against string("f")
    resultA = var17->Compare(var18, ConditionalEquals);
    Assert(resultA == false,
           "string(\"t\") == string(\"f\") should have been false");
    resultB = var18->Compare(var17, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"t\") == string(\"f\") is inconsistent");
    Passed("string(\"t\") == string(\"f\")");
    resultA = var17->Compare(var18, ConditionalNotEquals);
    Assert(resultA == true,
           "string(\"t\") != string(\"f\") should have been true");
    resultB = var18->Compare(var17, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"t\") != string(\"f\") is inconsistent");
    Passed("string(\"t\") != string(\"f\")");
    resultA = var17->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "string(\"t\") < string(\"f\") should have been false");
    resultB = var18->Compare(var17, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"t\") < string(\"f\") is inconsistent");
    Passed("string(\"t\") < string(\"f\")");
    resultA = var17->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "string(\"t\") >= string(\"f\") should have been true");
    resultB = var18->Compare(var17, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"t\") >= string(\"f\") is inconsistent");
    Passed("string(\"t\") >= string(\"f\")");
    resultA = var17->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == false,
           "string(\"t\") <= string(\"f\") should have been false");
    resultB = var18->Compare(var17, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"t\") <= string(\"f\") is inconsistent");
    Passed("string(\"t\") <= string(\"f\")");

// * Evaluating string("f")
    Assert(var18->Compare(NULL, ConditionalImplicit) == false,
           "Implicit test of string(\"f\") failed");
    Passed("Implicit test of string(\"f\")");

// Evaluating string("f") against string("f")
    resultA = var18->Compare(var18, ConditionalEquals);
    Assert(resultA == true,
           "string(\"f\") == string(\"f\") should have been true");
    resultB = var18->Compare(var18, ConditionalEquals);
    Assert(resultA == resultB,
           "string(\"f\") == string(\"f\") is inconsistent");
    Passed("string(\"f\") == string(\"f\")");
    resultA = var18->Compare(var18, ConditionalNotEquals);
    Assert(resultA == false,
           "string(\"f\") != string(\"f\") should have been false");
    resultB = var18->Compare(var18, ConditionalNotEquals);
    Assert(resultA == resultB,
           "string(\"f\") != string(\"f\") is inconsistent");
    Passed("string(\"f\") != string(\"f\")");
    resultA = var18->Compare(var18, ConditionalLessThan);
    Assert(resultA == false,
           "string(\"f\") < string(\"f\") should have been false");
    resultB = var18->Compare(var18, ConditionalGreaterThan);
    Assert(resultA == resultB,
           "string(\"f\") < string(\"f\") is inconsistent");
    Passed("string(\"f\") < string(\"f\")");
    resultA = var18->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == true,
           "string(\"f\") >= string(\"f\") should have been true");
    resultB = var18->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == resultB,
           "string(\"f\") >= string(\"f\") is inconsistent");
    Passed("string(\"f\") >= string(\"f\")");
    resultA = var18->Compare(var18, ConditionalLessThanOrEquals);
    Assert(resultA == true,
           "string(\"f\") <= string(\"f\") should have been true");
    resultB = var18->Compare(var18, ConditionalGreaterThanOrEquals);
    Assert(resultA == resultB,
           "string(\"f\") <= string(\"f\") is inconsistent");
    Passed("string(\"f\") <= string(\"f\")");

    Cleanup();
}
