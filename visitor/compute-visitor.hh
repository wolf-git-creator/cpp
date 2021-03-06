#pragma once

#include "visitor.hh"
#include "node.hh"
#include "leaf.hh"
#include <string>
#include <iostream>
#include <stdexcept>

namespace visitor
{
    class ComputeVisitor : public Visitor
    {
        public:
            ComputeVisitor()
            {}
            void visit(const tree::Tree& e) override;

            void visit(const tree::Node& e) override;

            void visit(const tree::Leaf& e) override;

            int value_get();
        protected:
            std::string output;

    };
}

