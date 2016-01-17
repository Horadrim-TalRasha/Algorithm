def fab(max):
    n, a, b = 0, 0, 1
    while n < max:
        print b
        a, b = b, a + b
        n = n + 1

def fab_yield(max):
    n, a, b = 0, 0, 1
    while n < max:
        print "before yield a = %d, b = %d, n = %d" %(a, b, n)
        yield b
        a, b = b, a + b
        n = n + 1
        print "after yield a = %d, b = %d, n = %d" %(a, b, n)

if __name__ == "__main__":
    fab(6)
    for n in fab_yield(6):
        print "in block b = %d" %(n)
