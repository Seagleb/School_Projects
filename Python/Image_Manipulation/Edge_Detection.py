def skel():
  myImg='D:\\School\\CIS122\\Image_Base\\Spartan.jpg'
  myPicture=makePicture(myImg)
  newEdgeDetection(myPicture)
  #writePictureTo(myPicture,"F:\\School\\CIS122\\Image_Base\\Changed\\MypicGlasses.jpeg")
  explore(myPicture)
##########################################################################
def luminance(pixel):
  r = getRed(pixel)
  g = getGreen(pixel)
  b = getBlue(pixel)
  return (r+g+b)/3
##########################################################################
def newEdgeDetection(myPicture):
 # greyScaleNew(myPicture)
  for p in getPixels(myPicture):
    x = getX(p)
    y = getY(p)
    
    if y < getHeight(myPicture)-1 and x < getWidth(myPicture)-1:
      botrt = getPixel(myPicture,x+1,y+1)
      thislum = luminance(p)
      brlum = luminance(botrt)
      if abs(brlum-thislum) > 10:
        setColor(p,black)
      if abs(brlum-thislum) <= 10:
        setColor(p,white)
#########################################################################################
