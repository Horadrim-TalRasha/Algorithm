#!/usr/bin/python

import struct
from module.pkg_1.module2 import foo2


if __name__ == "__main__":
	Str = struct.pack("i4s", 20, 'feawfeawfew')
	v1, v2 = struct.unpack("i4s", Str)
	print 'v1 = ' + str(v1)
	print 'v2 = ' + str(v2)
