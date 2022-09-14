#include <iostream>

// ============= Implementation =============
class WindowImp
{
public:
	explicit WindowImp();
	virtual void DeviceRect() = 0;
};

// ============= Concrete Implementation =============
class XWindowImp : public WindowImp
{
public:
	explicit XWindowImp();

	void DeviceRect();
};

// ============= Concrete Implementation =============
class PMWindowImp : public WindowImp
{
public:
	explicit PMWindowImp();
	void DeviceRect();
};
