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
	// out << type()->fullName() <<endl;
	prtSpace(out, indent);
	out << "event";
	out << step;
	out << this->name();
	out << "(";
	if (this->symTab() != NULL) {
		auto it = this->symTab()->begin();
		for(; it != this->symTab()->end(); ++it) {
			(*it)->print(out, 0);
			if ((*it)->next() != NULL)
				out<<", ";
		}
	}
	out << ")";
	out << ";";
	out <<endl;
}

VariableEntry::VariableEntry(const VariableEntry &v):
    SymTabEntry(*(new string(v.name())), SymTabEntry::Kind::VARIABLE_KIND, v.line(), v.column(), v.file(), (Type *)v.type()) {
	vkind_ = v.varKind();
	initVal_ = (ExprNode *)v.initVal();
}

void VariableEntry::print(ostream& out, int indent) const
{
	// Add your code
	this->type()->print(out, indent);
	out<<step;
	out<<this->name();
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
