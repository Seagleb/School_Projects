def mainFn():
  myImg=pickAFile()
  myPicture=makePicture(myImg)
  mirror(myPicture)
  explore(myPicture)
  
def mirror(myPicture):
  height = getHeight(myPicture)
  mirrorPoint = height/2
  for x in range(0,getWidth(myPicture)):
    for y in range(0,mirrorPoint):
      topPixel = getPixel(myPicture,x,y)
      bottomPixel = getPixel(myPicture,x,height - y - 1)
      color= getColor(topPixel)
      setColor(bottomPixel,color)