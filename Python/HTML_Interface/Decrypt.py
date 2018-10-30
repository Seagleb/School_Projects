#!/usr/local/bin/python3
import cgi, cgitb
cgitb.enable()
print("Content-type:   text/html\n\n")

def printTextBox():
    print ("<p>")
    print ("Insert Encrypted Text")
    print ("</p>")
    print ("<form method='POST'>")
    print ("<textarea name='paragraph' rows='10' cols='40'>")
    print ("</textarea>")
    print ("<input type='submit' name='Decrypt'>")
    print ("</form>")

printTextBox()
form = cgi.FieldStorage()
form_input = form.getvalue('paragraph')
space = form_input.count(' ')
a = form_input.count('a') + form_input.count('A')
b = form_input.count('b') + form_input.count('B')
c = form_input.count('c') + form_input.count('C')
d = form_input.count('d') + form_input.count('D')
e = form_input.count('e') + form_input.count('E')
f = form_input.count('f') + form_input.count('F')
g = form_input.count('g') + form_input.count('G')
h = form_input.count('h') + form_input.count('H')
i = form_input.count('i') + form_input.count('I')
j = form_input.count('j') + form_input.count('J')
k = form_input.count('k') + form_input.count('K')
l = form_input.count('l') + form_input.count('L')
m = form_input.count('m') + form_input.count('M')
n = form_input.count('n') + form_input.count('N')
o = form_input.count('o') + form_input.count('O')
p = form_input.count('p') + form_input.count('P')
q = form_input.count('q') + form_input.count('Q')
r = form_input.count('r') + form_input.count('R')
s = form_input.count('s') + form_input.count('S')
t = form_input.count('t') + form_input.count('T')
u = form_input.count('u') + form_input.count('U')
v = form_input.count('v') + form_input.count('V')
w = form_input.count('w') + form_input.count('W')
x = form_input.count('x') + form_input.count('X')
y = form_input.count('y') + form_input.count('Y')
z = form_input.count('z') + form_input.count('Z')

input_list = list(form_input)
new_list = input_list


commonality_list = [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,space]
commonality_list.sort(reverse=True)
#print (commonality_list)
commonality_map = {'a':a,'b':b,'c':c,'d':d,'e':e,'f':f,'g':g,'h':h,'i':i,'j':j,'k':k,'l':l,'m':m,'n':n,'o':o,'p':p,'q':q,'r':r,'s':s,'t':t,'u':u,'v':v,'w':w,'x':x,'y':y,'z':z,' ':space}

#print (commonality_map)
ordered_commonality = {commonality_list[0]:' ',commonality_list[1]:'e',commonality_list[2]:'t',commonality_list[3]:'a',commonality_list[4]:'o',commonality_list[5]:'i',commonality_list[6]:'n',commonality_list[7]:'s',commonality_list[8]:'h',commonality_list[9]:'r',commonality_list[10]:'d',commonality_list[11]:'l',commonality_list[12]:'u',commonality_list[13]:'c',commonality_list[14]:'m',commonality_list[15]:'w',commonality_list[16]:'f',commonality_list[17]:'g',commonality_list[18]:'y',commonality_list[19]:'p',commonality_list[20]:'b',commonality_list[21]:'v',commonality_list[22]:'k',commonality_list[23]:'j',commonality_list[24]:'x',commonality_list[25]:'q',commonality_list[26]:'z'}
#print (ordered_commonality)
count = 0
for letter in input_list:
    if letter.lower() in commonality_map:
        placement=commonality_map[letter.lower()]
        new_list[count]=ordered_commonality[placement]
    count = count + 1

print (''.join(str(i) for i in new_list))
