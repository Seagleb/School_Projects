def mainFn():
  myImg=pickAFile()
  myPicture=makePicture(myImg)
  scaleUp(myPicture)
  blur(myPicture)
  explore(scaleUp(myPicture))
#####################################################################################
def scaleUp(myPicture):
  picWidth=getWidth(myPicture)
  picHeight=getHeight(myPicture)
  blankCanvas=makeEmptyPicture(picWidth*2,picHeight*2)  
  srcX=0
  for targetX in range(0,picWidth*2):
    srcY=0
    for targetY in range(0,picHeight*2):
      srcpx = getPixel(myPicture,int(srcX),int(srcY))
      color = getColor(srcpx)
      setColor(getPixel(blankCanvas,targetX,targetY),color)
      srcY=srcY + 0.5
    srcX=srcX + 0.5
  return blankCanvas
#################################################  
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