#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
#
# William Seagle

class Person:
    def __init__(self,name,number):
        self._name = name
        self._number =  int(number)
    def get_Name(self):
        return self._name
    def get_Number(self):
        return self._number 
    def set_Name(self,name):
        self._name = name
    def set_Number(self,number):
        self._number = number
