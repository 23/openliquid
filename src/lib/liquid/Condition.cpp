#include "Condition.hpp"
#include "RenderContext.hpp"
#include "Fragment.hpp"

namespace Liquid
{
    Condition::Condition(Token* lhs,
                         ConditionalOperator op,
                         Token* rhs)
        :   _childCondition(NULL),
            _lhs(Fragment::Initialize(lhs)),
            _op(op),
            _rhs(rhs ? Fragment::Initialize(rhs) : NULL)
    {

    }
    
    Condition::~Condition()
    {
        if (this->_childCondition)
            delete this->_childCondition;

        delete this->_lhs;

        if (this->_rhs)
            delete this->_rhs;
    }

    void Condition::Attach(Condition* childCondition,
                           UnaryOperator childUnary)
    {
        this->_childCondition = childCondition;
        this->_childUnary = childUnary;
    }

    bool Condition::Evaluate(RenderContext& context)
    {
        NullFragment nullFragment;

        Fragment* lhs = this->_lhs;
        Fragment* rhs = this->_rhs;

        if ((lhs) &&
            (lhs->GetType() == FragmentTypeContextual))
            lhs = reinterpret_cast<ContextualFragment*>(lhs)->Resolve(context);

        if ((rhs) &&
            (rhs->GetType() == FragmentTypeContextual))
            rhs = reinterpret_cast<ContextualFragment*>(rhs)->Resolve(context);

        if (lhs == NULL)
            lhs = &nullFragment;
        if (rhs == NULL)
            rhs = &nullFragment;
        
        bool result = lhs->Compare(rhs,
                                   this->_op);

        if (this->_childCondition)
        {
            if (this->_childUnary == UnaryAnd)
                return ((result) && (this->_childCondition->Evaluate(context)));
            else
                return ((result) || (this->_childCondition->Evaluate(context)));
        }
        else
            return result;
    }
}
