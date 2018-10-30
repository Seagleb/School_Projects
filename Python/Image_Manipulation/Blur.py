def mainFn():
  #myImg=r"F:\School\CIS122\Image_Base\MyPic.jpg"
  myImg=pickAFile()
  myPicture=makePicture(myImg)
  blur(myPicture)
  explore(myPicture)
#####################################################################################
#Takes all the surrounding pixels of a selected pixel and averages their r/g/b value#
#and then it changes the value of the currently selected pixel to that average      #
#####################################################################################
def blur(myPicture):
  for x in range(1,getWidth(myPicture)-1):
    for y in range(1,getHeight(myPicture)-1):
      top = getPixel(myPicture,x,y-1)
      left = getPixel(myPicture,x-1,y)
      bottom = getPixel(myPicture,x,y+1)
      right = getPixel(myPicture,x+1,y)
      center = getPixel(myPicture,x,y)
      blurRed= (getRed(top)+getRed(left)+getRed(bottom)+getRed(right)+getRed(center))/5
      blurGreen= (getGreen(top)+getGreen(left)+getGreen(bottom)+getGreen(right)+getGreen(center))/5
      blurBlue= (getBlue(top)+getBlue(left)+getBlue(bottom)+getBlue(right)+getBlue(center))/5
      setColor(center,makeColor(blurRed,blurGreen,blurBlue))