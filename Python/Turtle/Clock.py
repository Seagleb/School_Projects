#from time import gmtime, strftime
import time
import random

#print strftime("%Y-%m-%d %H:%M:%S", gmtime())
#print strftime("%H",gmtime())
print time.localtime()
print time.localtime()[3]
hour = time.localtime()[3]
minute = time.localtime()[4]
seconds = time.localtime()[5]
earth = makeWorld(1000,1000)
secondTurtle = makeTurtle(earth)
minuteTurtle = makeTurtle(earth)
hourTurtle = makeTurtle(earth)
circleTurtle = makeTurtle(earth)
minuteTurtle.setPenWidth(3)
hourTurtle.setPenWidth(5)
secondTurtle.setColor(black)
minuteTurtle.setColor(black)
hourTurtle.setColor(black)
def circle():
  print circleTurtle
  circleTurtle.penUp()
  circleTurtle.moveTo(385,500)
  circleTurtle.penDown()
  circleTurtle.setColor(black)
  for i in range(0,180):
    circleTurtle.turn(2)
    circleTurtle.forward(4)
  circleTurtle.penUp()
  circleTurtle.moveTo(500,500)
  circleTurtle.penDown()
 
def secondHand():
  secondTurtle.clearPath()  
  secondTurtle.turnToFace(500,499)
  secondTurnDegree = 6*int(time.localtime()[5])
  secondTurtle.turn(secondTurnDegree)
  secondTurtle.forward(115)  
  secondTurtle.moveTo(500,500)
  
def minuteHand():
  minuteTurtle.clearPath()  
  minuteTurtle.turnToFace(500,499)
  minuteTurnDegree = 6*int(time.localtime()[4])
  minuteTurtle.turn(minuteTurnDegree)
  minuteTurtle.forward(100)  
  minuteTurtle.moveTo(500,500)
  
def hourHand():
  hourTurtle.clearPath()  
  hourTurtle.turnToFace(500,499)
  if time.localtime()[3] <= 12:
    hourTurnDegree = 30*int(time.localtime()[3])
  else:
    hourTurnDegree = 30*int((time.localtime()[3]-12))
  hourTurtle.turn(hourTurnDegree)
  hourTurtle.forward(75)  
  hourTurtle.moveTo(500,500) 
circle()
while true:

  time.sleep(1)
  secondHand()
  minuteHand()
  hourHand()
  print "Time: " + str(time.localtime()[3])+":"+str(time.localtime()[4])+":"+str(time.localtime()[5])
  

  