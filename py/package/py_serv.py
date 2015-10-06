import SocketServer
import socket
import traceback
import sys
import struct


import serv_conf

##SERV_HOST = "192.168.0.224"
##SERV_PORT = 7700

class MyTcpHandler(SocketServer.BaseRequestHandler):
	def handle(self):
		while True:
			try:
				data = self.request.recv(1024)
				if data == '':
					break
				v1 = struct.unpack_from("i", data, 0)
#				v1, v2 = struct.unpack("8s", data)
				v2 = struct.unpack_from("8s", data, 4)
				print "receive from (%r) with data: %r, %r" % (self.client_address, v1,str(v2))
#				print "len:" + str(len(v2))
				print "packet len:" + str(len(data))
#				self.request.close()
#				print "close socket"
#				break
			except Exception, e:
				print "On Exception"
				print e
	
class MyTcpServer(SocketServer.TCPServer):
	def close_request(self, request):
		SocketServer.TCPServer.close_request(self, request)

if __name__ == "__main__":
	try:
		SocketServer.TCPServer.allow_reuse_address = True
#		server = SocketServer.TCPServer((serv_conf.SERV_HOST, serv_conf.SERV_PORT), MyTcpHandler)

#		server.allow_reuse_address = 1
##		server = SocketServer.TCPServer(("192.168.0.88", 6620), MyTcpHandler)
		server = MyTcpServer((serv_conf.SERV_HOST, serv_conf.SERV_PORT), MyTcpHandler)
		server.serve_forever()	
	except socket.error, msg:
		print 'Failed to create socket. Error code: ' + str(msg[0]) + ' , Error message : ' + msg[1]
	except KeyboardInterrupt:
		print "keyboadrd Interrupt"
	except Exception ,e:
		print e
#	print serv_conf.SERV_HOST
#	print serv_conf.SERV_PORT
