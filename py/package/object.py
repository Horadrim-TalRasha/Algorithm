class PyClass:
	def __init__(self):
		print "PyClass inited"

	def __enter__(self):
		pass

	def __exit__(self, type, value, trace):
		pass

	def foo(self):
		print "call member functin foo"

if(__name__ == "__main__"):
	c = PyClass()
	c.foo();
	print "start"
