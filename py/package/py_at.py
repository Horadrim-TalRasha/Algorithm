from time import ctime, sleep

def minus(f):
    print 'minus'
    f()
 
def plus(f):
    print 'plus'
    f()
 
def test(a):
    if a > 3 : return plus
    else : return minus
 
@test(5)
def xxx():
    print 'ok'

def tcfunc(func):
    def wrappedFunc():
        print '[%s] %s() called' %(
            ctime(), func)
        return func()
    print "in tcfunc called"
    print "wrapped func %s" %wrappedFunc
    return wrappedFunc

@tcfunc         # call sequence is : tcfunc(func) --> wrappedFunc -- > func
def foo():
    print "in foo called"
    pass

print "foo func : %s" %foo

foo()  
print "-"*100
sleep(4)

for i in range(2):
    sleep(i)
    foo()
    print "-"*100
