def mainFn():
  myImg=pickAFile()
  myPicture=makePicture(myImg)
  rotate(myPicture)
  explore(rotate(myPicture))
#####################################################################################
def rotate(myPicture):
  width=getWidth(myPicture)
  height=getHeight(myPicture)
  if width>height:
    bigger = width
  elif height>width:
    bigger =height
  blankCanvas=makeEmptyPicture(bigger,bigger)  
  targetX=0
  for sourceX in range(0,width):
    targetY=0
    for sourceY in range(0,height):
      color = getColor(getPixel(myPicture,sourceX,sourceY))
      setColor(getPixel(blankCanvas,targetY,targetX),color)
      targetY=targetY + 1
    targetX=targetX + 1
  return blankCanvas
