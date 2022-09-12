using System;

namespace TemplateMethod
{
	public abstract class Document
	{
		public abstract void Open();
		public abstract void Save();
		public abstract void Close();
		public abstract void DoRead();
	}

	public class Docs
	{
		private List<Document> docs = new List<docs>();
		public void AddDocument(Document doc)
		{
			docs.Add(doc);
		}
	}

  // Abstract class
	public abstract class Application
	{
		Docs docs = new Docs();
		// Template method - Invariants encapsulated
		public void OpenDocument(string name)
		{
			if(CanOpenDocument(name) == false)
			{
				return;
			}

			Document doc = DoCreateDocument();

			if(!(doc is null))
			{
					docs.AddDocument(doc);
					AboutToOpenDocument(doc);
					doc.Open();
					doc.DoRead();
			}
		}
	
	  // Primitive operations - Has to be overridden (etc. abstract operations)
		public abstract bool CanOpenDocument(string name);
	  // Factory Method
		public abstract Document DoCreateDocument();
		// Primitive operations - Has to be overridden (etc. abstract operations)
		public abstract void AboutToOpenDocument(Document doc);
	}

	// Concrete class
	public class ConcreteApplication : Application
	{
		public override bool CanOpenDocument(string name)
		{
			return true;
		}

		public override Document DoCreateDocument()
		{
			return new Document();
		}

		public override void AboutToOpenDocument(Document doc)
		{
			System.Console.WriteLine("Do something");
		}
	}
	
}
