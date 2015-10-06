import sys
import getopt
##import 


def usage():
	print "==========	help	==========="

def KillProcByName(ProcName, flag):
	print ""

if __name__ == "__main__":
	killAll = False
	procName = ""
	try:
		options, args = getopt.getopt(sys.argv[1:], "hn", ["help", "name=", "all"])
	except getopt.GetoptError:
		print "Get Opt Error"
		sys.exit();

	for name, value in options:
		if name in ("-h","--help"):
			usage()
		elif(name in ("-n", "--name")):
			procName = value
			print "you want to kill " + value
##		elif(cmp(name, "--all") == 0):
		elif(name in ("--all")):
			killAll = True

	if(procName == ""):
		print "please input proc name"
