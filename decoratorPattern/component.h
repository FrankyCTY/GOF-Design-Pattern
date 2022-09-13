#pragma once

// Component
class VisualComponent
{
public:
	VisualComponent();
	virtual void Draw() = 0;
	// . . .
};

// Concrete Component
class TextView : public VisualComponent
{
	void Draw(){};
};