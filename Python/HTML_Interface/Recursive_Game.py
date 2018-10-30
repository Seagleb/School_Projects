#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
#
# William Seagle
import cgi, cgitb
cgitb.enable()
print("Content-type:   text/html\n\n")


testList = [4, 1, 3, 1, 2, 2, 2, 1]
winRoute = []
pos = 0

def recursiveCheck(pos,sampleList,winRoute):
    if pos == len(sampleList)-1:
        winRoute.append(pos)
        print("<p>")
        print("You Win!") 
        print("</p>")
        print('-->'.join(map(str,winRoute)))
        return 1
    elif sampleList[pos] == 0:
        return -1
    else:
        winRoute.append(pos)
        backward = pos - sampleList[pos]
        forward = pos + sampleList[pos]
        sampleList[pos]=0
        if backward > 0:
            if recursiveCheck(backward,sampleList,winRoute) == 1:
                return 1
        if forward < len(sampleList):
            if recursiveCheck(forward,sampleList,winRoute) == 1:
                return 1

def printInputBox():
    print("<p>")
    print("Insert numbers separated by spaces:")
    print("</p>")
    print("<form method='POST'>")
    print("<textarea name='paragraph' rows='1' cols='40'>")
    print("</textarea>")
    print("<input type='Submit' name='Submit'>")
    print("</form>")
    
printInputBox()

form = cgi.FieldStorage()
inputNums=form.getvalue('paragraph')
if inputNums is None:
    inputNums = '4 1 3 1 2 2 2 1'
print(inputNums)
setList= inputNums.split()
numList = []
for numbers in setList:
    numList.append(int(numbers))
  
if recursiveCheck(0,numList,winRoute) != 1:
    print('There was no path to the finish!')

