#include <string>
#include <pcrecpp.h>

#ifndef __LIQUID_EXPRESSIONS
#define __LIQUID_EXPRESSIONS
namespace Liquid
{
    namespace Expressions
    {
        static std::string ContextualSignature = "(\\w+)(\\[[0-9]+\\])?";

        static pcrecpp::RE IntegerFragment("[+-]?([0-9]+)");
        static pcrecpp::RE FloatFragment("[+-]?([0-9]*)\\.([0-9]+)");
        static pcrecpp::RE StringFragment("(\"(?:[^\"\\]|\\.)*\")|('(?:[^'\\]|\\.)*')");
        static pcrecpp::RE ContextualFragment(ContextualSignature + "((\\.)" + ContextualSignature + ")*");
        static pcrecpp::RE IdentifierFragment("(\\w+)");
    }
}
#endif
