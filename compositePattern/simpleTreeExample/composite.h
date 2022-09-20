#pragma once
#include <list>
#include "./component.h"
#include "./leaf.h"

/**
 * The Composite class represents the complex components that may have children.
 * Usually, the Composite objects delegate the actual work to their children and
 * then "sum-up" the result.
 */
class BasicComposite : public Component
{
	/**
	 * @var \SplObjectStorage
	 */
protected:
	std::list<Component *> children_;

public:
	/**
	 * A composite object can add or remove other components (both primitive or
	 * composite) to or from its child list.
	 */
	void Add(Component *component) override;
	/**
	 * Have in mind that this method removes the pointer to the list but doesn't
	 * frees the memory, you should do it manually or better use smart pointers.
	 */
	void Remove(Component *component) override;
	bool IsComposite() const override;
	/**
	 * The Composite executes its primary logic in a particular way. It traverses
	 * recursively through all its children, collecting and summing their results.
	 * Since the composite's children pass these calls to their children and so
	 * forth, the whole object tree is traversed as a result.
	 */
	std::string Operation() const override;
};