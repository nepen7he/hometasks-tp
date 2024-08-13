import sys

file = open(sys.argv[1], 'w')
file.write("#include <iostream>\n\n int sum(int a, int b) {\n\treturn a+b; \n}\n")
