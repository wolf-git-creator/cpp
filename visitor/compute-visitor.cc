#include "compute-visitor.hh"


void visitor::ComputeVisitor::visit(const tree::Tree& e)
{
    e.accept(*this);
    return;
}

void visitor::ComputeVisitor::visit(const tree::Node& e)
{
    visit(*(e.lhs_get()));
    int lhs = std::stoi(output);
    const std::string symbol = e.value_get();
    if (symbol == "+")
    {
        visit(*(e.rhs_get()));
        int rhs = std::stoi(output);
        output = std::to_string(lhs + rhs);
    }
    else if (symbol == "-")
    {
        visit(*(e.rhs_get()));
        int rhs = std::stoi(output);
        output = std::to_string(lhs - rhs);
    }
    else if (symbol == "*")
    {
        visit(*(e.rhs_get()));
        int rhs = std::stoi(output);
        output = std::to_string(lhs * rhs);
    }
    else if (symbol == "/")
    {
        visit(*(e.rhs_get()));
        int rhs = std::stoi(output);
        if (rhs == 0)
            throw std::overflow_error("Divide by zero exception");
        output = std::to_string(lhs / rhs);
    }
}

void visitor::ComputeVisitor::visit(const tree::Leaf& e)
{
    output = e.value_get();
}

int visitor::ComputeVisitor::value_get()
{
    return std::stoi(output);
}






