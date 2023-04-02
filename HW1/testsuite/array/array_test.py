#!/usr/bin/env python3

import os
import logging
import subprocess

def check(cond):
    if not cond:
        raise RuntimeError("Check not passed")

def system_run_command(args, ignore_stderr = True, additional_env = dict()):
   command = ' '.join([str(arg) for arg in args]) # str - поддержка Path
   print('Run command %s', command)
   cmd_env = os.environ.copy()
   cmd_env.update(additional_env)
   p = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                        env=cmd_env)
   output, errors = p.communicate()
   if p.returncode or (not ignore_stderr and errors):
       raise IOError("CMD = [{}]\nErrors: {}".format(command, errors if errors else "[]"))
   p.wait()
   result = output.decode("utf-8").strip()
   return result

array_wrapper_app = '../../bin/array_wrapper'
#change element
print(system_run_command(['echo', "1", '|', array_wrapper_app]))
print(system_run_command(['echo', "1", '|', array_wrapper_app]))
print(system_run_command(['echo', "2", '|', array_wrapper_app]))
print(system_run_command(['echo', "50", '|', array_wrapper_app]))

#==
print(system_run_command(['echo', "2", '|', array_wrapper_app]))
print(system_run_command(['echo', "1", '|', array_wrapper_app]))

#!=
print(system_run_command(['echo', "3", '|', array_wrapper_app]))
print(system_run_command(['echo', "2", '|', array_wrapper_app]))


#>=
print(system_run_command(['echo', "4", '|', array_wrapper_app]))
print(system_run_command(['echo', "4", '|', array_wrapper_app]))

#<=
print(system_run_command(['echo', "5", '|', array_wrapper_app]))
print(system_run_command(['echo', "6", '|', array_wrapper_app]))

#>
print(system_run_command(['echo', "6", '|', array_wrapper_app]))
print(system_run_command(['echo', "1", '|', array_wrapper_app]))

#<
print(system_run_command(['echo', "7", '|', array_wrapper_app]))
print(system_run_command(['echo', "8", '|', array_wrapper_app]))

#print element
print(system_run_command(['echo', "8", '|', array_wrapper_app]))
print(system_run_command(['echo', "5", '|', array_wrapper_app]))
print(system_run_command(['echo', "2", '|', array_wrapper_app]))

#empty
print(system_run_command(['echo', "9", '|', array_wrapper_app]))
print(system_run_command(['echo', "4", '|', array_wrapper_app]))

#size
print(system_run_command(['echo', "10", '|', array_wrapper_app]))
print(system_run_command(['echo', "1", '|', array_wrapper_app]))

#front
print(system_run_command(['echo', "11", '|', array_wrapper_app]))
print(system_run_command(['echo', "2", '|', array_wrapper_app]))

#back
print(system_run_command(['echo', "12", '|', array_wrapper_app]))
print(system_run_command(['echo', "4", '|', array_wrapper_app]))

#print array
print(system_run_command(['echo', "13", '|', array_wrapper_app]))
print(system_run_command(['echo', "1", '|', array_wrapper_app]))

#create
print(system_run_command(['echo', "14", '|', array_wrapper_app]))

#exit
print(system_run_command(['echo', "15", '|', array_wrapper_app]))