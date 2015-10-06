import socket
import sys
import serv_conf
import struct
import unittest
import time


if __name__ == "__main__":
	try:
#		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		s = socket.socket()
		s.connect((serv_conf.SERV_HOST, serv_conf.SERV_PORT))
		Str = "eafeafea"
		data_format = "i" + str(len(Str)) + "s"
		print "format:" + data_format
		data = struct.pack(data_format, 22, "ssss")
		s.sendall(data)
#		time.sleep(30)
#		s.sendall("hello world again")
		data = s.recv(1024)
		print "data: " + data
	except Exception, e:
		print "exception occured"
		print e
