#include "./composite.h"

/**
 * A composite object can add or remove other components (both primitive or
 * composite) to or from its child list.
 */
void BasicComposite::Add(Component *component)
{
	this->children_.push_back(component);
	component->SetParent(this);
}
/**
 * Have in mind that this method removes the pointer to the list but doesn't
 * frees the memory, you should do it manually or better use smart pointers.
 */
void BasicComposite::Remove(Component *component)
{
	children_.remove(component);
	component->SetParent(nullptr);
}

bool BasicComposite::IsComposite() const
{
	return true;
}

/**
 * The Composite executes its primary logic in a particular way. It traverses
 * recursively through all its children, collecting and summing their results.
 * Since the composite's children pass these calls to their children and so
 * forth, the whole object tree is traversed as a result.
 */
std::string BasicComposite::Operation() const
{
	std::string result;
	for (const Component *component : children_)
	{
		if (component == children_.back())
		{
			result += component->Operation();
		}
		else
		{
			result += component->Operation() + "+";
		}
	}
	return "Branch(" + result + ")";
}