#ifndef RENDERNODE_H_
#define RENDERNODE_H_

#include "node.h"
#include "visitor.h"

class RenderNode : public AbstractNode
{
public:
	RenderNode(const ModuleInstantiation *mi) : AbstractNode(mi), convexity(1) { }
  virtual Response accept(const class State &state, Visitor &visitor) const {
		return visitor.visit(state, *this);
	}
	virtual std::string toString() const;

	int convexity;
	CSGTerm *render_csg_term(double m[20], QVector<CSGTerm*> *highlights, QVector<CSGTerm*> *background) const;	
#ifndef REMOVE_DUMP
	virtual QString dump(QString indent) const;
#endif
};

#endif
