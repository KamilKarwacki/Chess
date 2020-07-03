#!/usr/bin/python3
# little tool to make header and c++ file automatically
# name given as parameter

import sys
assert(len(sys.argv) == 2)

name = str(sys.argv[1])

include_string = """#pragma once \n\n
class {} {{         
public:\n         
private:            
}};""".format(name)

source_string = """#include \"{}.h\" """.format(name)

include_dir = "./include"
source_dir = "./src"

source_file = open(source_dir + "/" + name + ".cpp","w+")
source_file.write(source_string)

include_file = open(include_dir + "/" + name + ".h","w+")
include_file.write(include_string)
