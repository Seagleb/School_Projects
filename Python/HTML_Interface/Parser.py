#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
#
# William Seagle
import cgi, cgitb
cgitb.enable()
print("Content-type:   text/html\n\n")

def printTextBox():
    print("<p>")
    print("Insert Text")
    print("<p>")
    print("<form method='POST'>")
    print("<textarea name='code' rows='10' cols='40'>")
    print("</textarea>")
    print("<input type='submit' name='finish'>")
    print("</form>")

def is_number(n):
    try:
        float(n)
    except ValueError:
        return False
    return True

def replaceSpaces(sep_list):
    for element in range(len(sep_list)):
        if sep_list[character] == '\n':
            sep_list[character] = '<br />'
        
def dump(variable_dict):
    for key,val in variable_dict.items():
        print (key,val)
        print ('<br />')

printTextBox()
form = cgi.FieldStorage()
form_input = form.getvalue('code')
variable_dict = {}

character_list = list(form_input)

string_input = ''.join(str(i) for i in character_list)

word_list=string_input.split()

for word in range(len(word_list)):
    if word_list[word] == 'NAME':
        word_list[word] = 'William'
        print ('William')
        print ('<br />')
    elif word_list[word] == 'DUMP':
        dump(variable_dict)
    elif word_list[word+1] == '=':
        if is_number(word_list[word+2]) == True:
            variable_dict[word_list[word]] = word_list[word+2]
        elif word_list[word+2] in variable_dict:
            variable_dict[word_list[word]] = variable_dict[word_list[word+2]]
        else:
            print ('Error: {} not defined'.format(word_list[word+2]))
            print('<br />')
#print(word_list)
