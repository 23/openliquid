#include <liquid/Expressions.hpp>
#include <iostream>

#define Tests() int main()

Tests()
{
    

        static std::string ContextualSignature = "(\\w+)(\\[[0-9]+\\])?";

        static pcrecpp::RE IntegerFragment("[+-]?([0-9]+)");
        static pcrecpp::RE FloatFragment("[+-]?([0-9]*)\\.([0-9]+)");
        static pcrecpp::RE StringFragment("(\"(?:[^\"\\]|\\.)*\")|('(?:[^'\\]|\\.)*')");
        static pcrecpp::RE ContextualFragment(ContextualSignature + "((\\.)" + ContextualSignature + ")*");
        static pcrecpp::RE IdentifierFragment("(\\w+)");

    return 0;
}
