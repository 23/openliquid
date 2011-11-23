#include "Variable.hpp"

namespace Liquid
{
    Variable::Variable(std::string markup)
        :   _root(NULL)
    {

    }

    Variable::~Variable()
    {
        if (this->_root)
            delete this->_root;
    }
}
