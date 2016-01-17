class foo:
    def __init__(self):
        print "construct"
    def __enter__(self):
        print "enter"
        return self

    def __exit__(self, type, value, traceback):
        print "exit"
        return self



if __name__ == "__main__":
    with foo() as f:
        raise TypeError
        print "in with-as block"

    print f
