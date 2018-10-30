#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
#
# William Seagle
import cgi, cgitb
cgitb.enable()
print("Content-type:   text/html\n\n")
def printTextBox():
    print ("<p>")
    print ("Insert words to be sorted:")
    print ("</p>")
    print ("<form method='POST'>")
    print ("<textarea name='paragraph' rows='10' cols='40'>")
    print ("</textarea>")
    print ("<input type='submit' name='Sort'>")
    print ("</form>")

def lexicoSort(unsorted_string):
    if unsorted_string is None:
        unsorted_string = "You haven't Entered anything yet"
    split_string = unsorted_string.split()
    split_string.sort()
    return split_string

def printTable(split_string):
    average = sum(len(word) for word in split_string) / len(split_string)
    print("<p>")
    print("You entered %d words"%(len(split_string)))
    print("</p>")
    print("<p>")
    print("The average word length was %d"%(average))
    print("</p>")

    count = 0
    columns = 10
    print ("<table>")
    print ("<tr>")
    for words in split_string:
        print ("<td>{}</td>".format(words))
        count += 1
        if count % columns == 0:
            print("</tr>")
            print("<tr>")
        if count == 400:
            break
    print ("</tr>")
    print ("</table>")

printTextBox()
form = cgi.FieldStorage()
unsorted_string = form.getvalue('paragraph')
sorted_string = lexicoSort(unsorted_string)
printTable(sorted_string)
