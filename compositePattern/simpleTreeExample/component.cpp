#include "./component.h"

void Component::SetParent(Component *parent)
{
	this->parent_ = parent;
}

Component *Component::GetParent() const
{
	return this->parent_;
}

/**
 * In some cases, it would be beneficial to define the child-management
 * operations right in the base Component class. This way, you won't need to
 * expose any concrete component classes to the client code, even during the
 * object tree assembly. The downside is that these methods will be empty for
 * the leaf-level components.
 */
void Component::Add(Component *component){};
void Component::Remove(Component *component){};

/**
 * You can provide a method that lets the client code figure out whether a
 * component can bear children.
 */
bool Component::IsComposite() const
{
	return false;
}
