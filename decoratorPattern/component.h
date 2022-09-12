#pragma once

// Component
class VisualComponent
{
public:
	VisualComponent();
	virtual void Draw();
	virtual void Resize();
	// . . .
};

// Concrete Component
class TextView : public VisualComponent
{
	virtual void Draw();
};