def mainFn():
  myImg=pickAFile()
  myPicture=makePicture(myImg)
  scaleUp(myPicture)
  explore(scaleUp(myPicture))
#####################################################################################
def scaleUp(myPicture):
  picWidth=getWidth(myPicture)
  picHeight=getHeight(myPicture)
  blankCanvas=makeEmptyPicture(picWidth/2,picHeight/2)  
  srcX=0
  for targetX in range(0,picWidth/2):
    srcY=0
    for targetY in range(0,picHeight/2):
      srcpx = getPixel(myPicture,int(srcX),int(srcY))
      color = getColor(srcpx)
      setColor(getPixel(blankCanvas,targetX,targetY),color)
      srcY=srcY + 2
    srcX=srcX + 2
  return blankCanvas