#include "STEClasses.h"
#include "Value.h"
#include "ParserUtil.h"

void GlobalEntry::print(ostream& out, int indent) const
{
	// Add your code
}

void EventEntry::print(ostream& out, int indent) const
{
	// Add your code
	out << type()->fullName() <<endl;
}

VariableEntry::VariableEntry(const VariableEntry &v):
    SymTabEntry(*(new string(v.name())), SymTabEntry::Kind::VARIABLE_KIND, v.line(), v.column(), v.file(), (Type *)v.type()) {
	vkind_ = v.varKind();
	initVal_ = (ExprNode *)v.initVal();
}

void VariableEntry::print(ostream& out, int indent) const
{
	// Add your code
}

void BlockEntry::print(ostream& os, int indent) const{
	// Add your code
}

void ClassEntry::print(ostream& os, int indent) const{
	// Add your code
}

void FunctionEntry::print(ostream& os, int indent) const{
	// Add your code
}
