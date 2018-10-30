def skel():
  myImg='E:\\School\\CIS122\\Image_Base\\redeyebaby.jpg'
  myPicture=makePicture(myImg)
  #myPicture=makePicture(pickAFile)
  redEye(myPicture)
  explore(myPicture)
  
def redEye(myPicture):
  eye=makeColor(138,23,36)
  test=makeColor(0,0,0)
  
  for i in getPixels(myPicture):
    theColor=getColor(i)
    yPix = getY(i)
    xPix = getX(i)
    if 421<yPix<528 and 390<xPix<720:
      if distance(theColor,eye) < 50:
        my_red = getRed(i)*.02
        my_green = getGreen(i)
        my_blue = getBlue(i)
        setColor(i,test)