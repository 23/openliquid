#include <string>

#include "Token.hpp"
#include "ConditionalOperator.hpp"

#ifndef __LIQUID_FRAGMENT
#define __LIQUID_FRAGMENT
namespace Liquid
{
    enum FragmentType
    {
        FragmentTypeArray,
        FragmentTypeBoolean,
        FragmentTypeFloat,
        FragmentTypeEmpty,
        FragmentTypeHash,
        FragmentTypeInteger,
        FragmentTypeNull,
        FragmentTypeString,
        FragmentTypeContextual
    };

    /// Fragment base class
    class Fragment
    {
    public:
        /// Dispose of a variable base class
        virtual ~Fragment() {}
        
        
        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType() = 0;


        /// Get the string representation of the variable

        /// @returns the printable string representation of the variable
        virtual std::string ToString() = 0;


        /// Compare this fragment to another fragment
        
        /// @param other Other fragment to compare to
        /// @param comparator Comparator
        /// @returns true if the statement is true, otherwise false
        virtual bool Compare(Fragment* other,
                             ConditionalOperator op) = 0;


        /// Clone this fragment

        /// @returns the pointer to a clone of this fragment
        virtual Fragment* Clone() = 0;


        /// Construct a fragment from markup
        
        /// @param markup Markup of the fragment
        /// @returns a pointer to the created fragment if successful, otherwise NULL
        static Fragment* Initialize(std::string markup);


        /// Construct a fragment from a token

        /// @param token Token to construct the fragment from
        /// @returns a pointer to the created fragment if successful, otherwise NULL
        static Fragment* Initialize(Token* token);


        /// Check if a token is a valid fragment representation
        
        /// @param token Token to check
        /// @returns true if the token is a valid fragment, otherwise false
        static bool IsValid(Token* token)
        {
            return ((token->Type & TokenString) ||
                    (token->Type & TokenInteger) ||
                    (token->Type & TokenFloat) ||
                    (token->Type & TokenBoolean) ||
                    (token->Type & TokenNull) ||
                    (token->Type & TokenEmpty) ||
                    (token->Type & TokenPath));
        }
    };
}
#endif
