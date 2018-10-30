#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
#
# William Seagle
from Stack import ArrayStack
from Que import ArrayQueue
from Person import Person
import cgi, cgitb
cgitb.enable()
print("Content-type:   text/html\n\n")



def printTextBox():
    print('<html>')
    print('<head>')
    print('<h1 style="color: #4485b8; text-align: center;">Servers and Customers</h1>')
    print('<body>')
    print("<form method='POST'>")
    print('<table style="margin-left: auto; margin-right: auto;">')
    print('<tr>')
    print('<td align="center">Enter servers below<br/>Name numberServed</td>')
    print('<td align="center">Enter customers below<br/>Name numberPresent</td>')
    print('</tr>')
    print('<tr>')
    print('<td align="center"><textarea rows="15" cols="20" name="servers"></textarea></td>')
    print('<td align="center"><textarea rows="15" cols="20" name="customers"></textarea></td>')
    print('</tr>')
    print('<tr>')
    print('<td colspan="2" align="center">')
    print('<input type="submit" name="selection" value="Serve">')
    print('</td>')
    print('</tr>')
    print('</table>')
    print('</form>')
    print('</body>')


printTextBox()
servers = ArrayStack()
customers = ArrayQueue()

def collectServers(webInput,serverlist):
    while len(webInput) != 0:
        serverlist.push(Person(webInput[0],webInput[1]))
        webInput.pop(0)
        webInput.pop(0)

def collectCustomers(webInput,customerlist):
    while len(webInput) != 0:
        customerlist.enqueue(Person(webInput[0],webInput[1]))
        webInput.pop(0)
        webInput.pop(0)


def serve(servers,customers):
    print("<br>{} is now serving and can serve {}</br>".format(servers.top().get_Name(),servers.top().get_Number()))
    while len(servers) != 0 and len(customers) != 0:
        if servers.top().get_Number() == customers.first().get_Number():
            print("<br>{} serves all of {}'s party of {}</br>".format(servers.top().get_Name(),customers.first().get_Name(), customers.first().get_Number())) 
            servers.pop()
            if len(servers) != 0:
                print("<br>{} is now serving and can serve {}</br>".format(servers.top().get_Name(),servers.top().get_Number()))
            customers.dequeue()
        elif servers.top().get_Number() > customers.first().get_Number():
            servers.top().set_Number(servers.top().get_Number() - customers.first().get_Number())
            print("<br>{} serves all of {}'s party of {}</br>".format(servers.top().get_Name(),customers.first().get_Name(), customers.first().get_Number())) 
            customers.dequeue()
            
        elif customers.first().get_Number() > servers.top().get_Number():
            customers.first().set_Number(customers.first().get_Number() - servers.top().get_Number())
            print("<br>{} serves {} of {}'s party</br>".format(servers.top().get_Name(),servers.top().get_Number(),customers.first().get_Name()))
            servers.pop()
            if len(servers) != 0:
                print("<br>{} is now serving and can serve {}</br>".format(servers.top().get_Name(),servers.top().get_Number()))
    if len(servers) == 0:
        print("<br>There are no more Servers to server</br>")
    elif len(customers) == 0:
        print("<br>There are no more Customers to serve</br>")
#serve(servers,customers)
form = cgi.FieldStorage()
unsorted_servers = form.getvalue('servers')
unsorted_customers = form.getvalue('customers')

if unsorted_servers != None:
    array_servers = unsorted_servers.split()
    array_customers = unsorted_customers.split()
    collectServers(array_servers,servers)
    collectCustomers(array_customers,customers)
    serve(servers,customers)
