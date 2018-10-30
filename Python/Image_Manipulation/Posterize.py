def skel():
  myImg='E:\\School\\CIS122\\Image_Base\\MyPic.jpg'
  myPicture=makePicture(myImg)
  posterize(myPicture)
  #writePictureTo(myPicture,"F:\\School\\CIS122\\Image_Base\\Changed\\MypicGlasses.jpeg")
  explore(myPicture)

##########################################################################
def posterize(myPicture):
 # greyScaleNew(myPicture)
  for p in getPixels(myPicture):
    theRed = getRed(p)
    theBlue = getBlue(p)
    theGreen = getGreen(p)
    
    if (theRed <64):
      setRed(p,31)
    if (theRed>63 and theRed <128):
      setRed(p,95)
    if (theRed>127 and theRed< 192):
      setRed(p,159)
    if (theRed>191 and theRed< 256):
      setRed(p,223)
      
    if (theGreen <64):
      setGreen(p,31)
    if (theGreen>63 and theGreen <128):
      setGreen(p,95)
    if (theGreen>127 and theGreen< 192):
      setGreen(p,159)
    if (theGreen>191 and theGreen< 256):
      setGreen(p,223)
      
      
    if (theBlue <64):
      setBlue(p,31)
    if (theBlue>63 and theBlue <128):
      setBlue(p,95)
    if (theBlue>127 and theBlue< 192):
      setBlue(p,159)
    if (theBlue>191 and theBlue< 256):
      setBlue(p,223)
#########################################################################################
