namespace StrategyPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			Compositor strategy = new SimpleCompositor();
			Composition context = new Composition(strategy);
			context.Repair();
		}
	}
}