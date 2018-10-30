def skel():
  myImg='F:\\School\\CIS122\\Image_Base\\MyPic.jpg'
  myPicture=makePicture(myImg)
  sepiaTint(myPicture)
  #writePictureTo(myPicture,"F:\\School\\CIS122\\Image_Base\\Changed\\MypicGlasses.jpeg")
  explore(myPicture)
#########################################################################
def greyScaleNew(myPicture):
  for p in getPixels(myPicture):
    intensity = (getRed(p)+getGreen(p)+getBlue(p))/3
    setColor(p,makeColor(intensity, intensity, intensity))

##########################################################################
def sepiaTint(myPicture):
 # greyScaleNew(myPicture)
  for p in getPixels(myPicture):
    newRed = getRed(p)
    newBlue = getBlue(p)
    if (newRed<63):
      newRed = newRed*1.1
      newBlue=newBlue*.9
    if (newRed>62 and newRed <192):
      newRed = newRed*1.15
      newBlue = newBlue*.85
    if (newRed > 191):
      newRed = newRed*1.08
      newBlue = newBlue*.93
      if ( newRed > 255):
        newRed = 255
    setBlue(p,newBlue)
    setRed(p,newRed)
#########################################################################################
