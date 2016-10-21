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

void VariableEntry::print(ostream& out, int indent) const
{
	// Add your code
}

PrimitivePatNode::PrimitivePatNode(EventEntry* ee, vector<VariableEntry*>* params,
				   ExprNode* c,
				   int line, int column, string file):
	BasePatNode(BasePatNode::PatNodeKind::PRIMITIVE, line, column, file) {
	ee_ = ee;
	params_ = params;
	// TODO we only consider cond_ here. condition_ seems useless so far.
	cond_ = c;
	condition_ = nullptr;
}

bool PrimitivePatNode::hasSeqOps() const{
	return false;
}

bool PrimitivePatNode::hasNeg() const{
	return false;
}

bool PrimitivePatNode::hasAnyOrOther() const{
	// TODO what does this function mean? Any means "any" event ???
	if (ee_->name().compare(string("any")) == 0)
		return true;
	else
		return false;
}

void PrimitivePatNode::print(ostream& os, int indent) const{
	// Add your code
}

PatNode::PatNode(PatNodeKind pk, BasePatNode *p1, BasePatNode *p2, int line, int column, string file):
	BasePatNode(pk, line, column, file) {

	pat1_ = p1;
	pat2_ = p2;
}

bool PatNode::hasNeg() const{
	bool p1 = false, p2 = false;
	if (kind() == BasePatNode::PatNodeKind::NEG)
		return true;
	else {
		if (pat1() != nullptr)
			p1 = pat1()->hasNeg();
		if (pat2() != nullptr)
			p2 = pat2()->hasNeg();

		return p1 | p2;
	}
}

bool PatNode::hasSeqOps() const{
	bool p1 = false, p2 = false;

	if (kind() == BasePatNode::PatNodeKind::SEQ)
		return true;
	else {
		if (pat1() != nullptr)
			p1 = pat1()->hasSeqOps();
		if (pat2() != nullptr)
			p2 = pat2()->hasSeqOps();

		return p1 | p2;
	}
}

// TODO don't understand hasAnyOrOther() means? Any event and sth like STAR ?
// Only consider any here.
bool PatNode::hasAnyOrOther() const{
	bool p1 = false, p2 = false;

	if (pat1() != nullptr)
		p1 = pat1()->hasAnyOrOther();
	if (pat2() != nullptr)
		p2 = pat2()->hasAnyOrOther();

	return p1 | p2;
}

void PatNode::print(ostream& os, int indent) const{
	// Add your code
}

void ValueNode::print(ostream& os, int indent) const{
	// Add your code
}

RefExprNode::RefExprNode(string ext, const SymTabEntry* ste,
	      int line, int column, string file):
	ExprNode(ExprNode::ExprNodeType::REF_EXPR_NODE, NULL, line, column, file){
	// TODO
	ext_ = ext;
	sym_ = ste;
}

void RefExprNode::print(ostream& os, int indent) const{
	// Add your code
}

// TODO don't know what kind of copy here it is, should we copy ext_???
RefExprNode::RefExprNode(const RefExprNode& ren):
	ExprNode(ExprNode::ExprNodeType::REF_EXPR_NODE){
	ext_ = ren.ext();
	sym_ = ren.symTabEntry();
}

InvocationNode::InvocationNode(const SymTabEntry *ste, vector<ExprNode*>* param,
		 int line, int column, string file):
	ExprNode(ExprNode::ExprNodeType::INV_NODE) {
	ste_ = ste;
	params_ = param;
}

InvocationNode::InvocationNode(const InvocationNode& in):
	ExprNode(ExprNode::ExprNodeType::INV_NODE) {
	ste_ = in.symTabEntry();
	params_ = (vector <ExprNode*> *)in.params();
}

void InvocationNode::print(ostream& os, int indent) const{
	// Add your code
}
