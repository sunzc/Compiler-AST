#include "STEClasses.h"
#include "Value.h"
#include "ParserUtil.h"

void GlobalEntry::print(ostream& out, int indent) const
{
	// Add your code
	const SymTab *st = this->symTab();
	out << endl;
	if (st != NULL) {
		auto it = st->begin();
		while(it != st->end()) {
			if ((*it)->name().compare("any") == 0) {
				++it;
				continue;
			}

			if ((*it)->kind() == SymTabEntry::Kind::VARIABLE_KIND) {
				prtSpace(out, indent);
				(*it)->print(out, indent);
				out << ";" << endl;
			} else {
				(*it)->print(out, indent);
			}

			++it;
		}

		out<<endl;

		int i = 0;
		int size = this->rules().size();

		const RuleNode *rn;
		while (i < size){
			rn = this->rule(i);
			rn->print(out, indent);
			i++;
		}
	}

	prtSpace(out, indent);
	out<<endl;
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
	out << step;
	out << (this->name());
	if (this->initVal() != NULL) {
		out << " = ";
		this->initVal()->print(out, indent);
	}
}

void BlockEntry::print(ostream& os, int indent) const{
	// Add your code
}

void ClassEntry::print(ostream& os, int indent) const{
	// Add your code
	prtSpace(os, indent);
	os << "class";
	os << step;
	os << this->name();
	os << ";";
	os << endl;
}

void FunctionEntry::print(ostream& os, int indent) const{
	// Add your code
	prtSpace(os, indent);
	this->type()->retType()->print(os, indent);
	os << step;
	os << this->name();
	os << "(";
	if (this->symTab() != NULL) {
		auto it = this->symTab()->begin();
		for(; it != this->symTab()->end(); ++it) {
			(*it)->print(os, 0);
			if ((*it)->next() != NULL)
				os<<", ";
		}
	}
	os << ")";
	if (this->body() != NULL)
		this->body()->print(os, indent);
	os << ";";
	os <<endl;
}
