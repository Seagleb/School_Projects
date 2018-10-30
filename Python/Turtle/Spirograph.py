import time
def mainFn(path):
  theWorld = makeEmptyPicture(1000,1000)
  turtlehex=shapes(theWorld)
  turtlevort=shapes(theWorld)
  turtletwist=shapes(theWorld)
  turtlehex.hectagon()
  turtlevort.vortex()
  turtletwist.hextwist()
  explore(theWorld)
  writePictureTo(theWorld,path)

  
class shapes(Turtle):
  def hectagon(self):
    forwardMovement=0
    increment=100 
    self.penUp()
    self.moveTo(250,250)   
    self.penDown()
    for i in range(1,100):
      increment += 1
      newColor=makeColor(150,increment,150)
      self.setColor(newColor)
      for i in range(0,6):
        self.forward(forwardMovement)
        self.turn(-60)    
      forwardMovement += 1 
         
  def vortex(self):
    forwardMovement=0
    increment=20 
    increment2=50
    self.penUp()
    self.moveTo(500,250)   
    self.penDown()
    for i in range(1,100):
      increment += 1
      increment2 -= 1
      newColor=makeColor(increment2,increment,100)
      self.setColor(newColor)
      for i in range(0,50):
        self.forward(forwardMovement)
        self.turn(-42)    
      forwardMovement += 1 
      
  def hextwist(self):
    forwardMovement=50
    increment=20 
    increment2=50
    self.penUp()
    self.moveTo(335,625)   
    self.penDown()
    for i in range(1,100):
      increment += 1
      increment2 -= 1
      newColor=makeColor(increment,30,increment2)
      self.setColor(newColor)
      self.turn(2)
      for i in range(0,6):
        self.forward(forwardMovement)
        self.turn(60)    
      forwardMovement += 1   