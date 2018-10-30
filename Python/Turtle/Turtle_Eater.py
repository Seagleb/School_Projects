import random
import time

earth = makeWorld(1000,1000)
turtle = makeTurtle(earth)
eater = makeTurtle(earth)
eaterSpeed = 18

while true:
  
  def killerTurtle():
    print eater
    turtle.setShellColor(java.awt.Color.black)
    turtle.setBodyColor(java.awt.Color.black)
    eater.turnToFace(turtle)
    eater.forward(eaterSpeed)
  def victimTurtle():
    steps = random.randint(0,40)
    turnDegrees = random.randint(-50, 50)
    print turtle
    turtle.setShellColor(java.awt.Color.lightGray)
    turtle.setBodyColor(java.awt.Color.GREEN)
    turtle.forward(steps)
    turtle.turn(turnDegrees)
    time.sleep(.1)
    
  victimTurtle()
  killerTurtle()
  victimXPos = turtle.getXPos()
  victimYPos = turtle.getYPos()
  eaterXPos = eater.getXPos()
  eaterYPos = eater.getYPos()
  randX = random.randint(0,1000)
  randY = random.randint(0,1000)
  
  print "Turtle pos is: " + str(eaterXPos) + "," + str(eaterYPos)
  if victimXPos-5<eaterXPos<victimXPos+5 and victimYPos-5<eaterYPos<victimYPos+5:
    turtle.penUp()
    turtle.moveTo(randX,randY)
    turtle.clearPath()
    turtle.penDown()
    eaterSpeed + 5
    print "THEY HAVE MET"