// ============= Implementation =============
abstract class WindowImp
{
	public abstract void DeviceRect();
}

// ============= Concrete Implementation =============
class XWindowImp : WindowImp
{
	public override void DeviceRect()
	{
		System.Console.WriteLine("XWindow implementation DeviceRect");
	}
}

// ============= Concrete Implementation =============
class PMWindowImp : WindowImp
{
	public override void DeviceRect()
	{
		System.Console.WriteLine("PMWindow implementation DeviceRect");
	}
}