def skel():
  myImg=r"E:\School\CIS122\Image_Base\MyPic.jpg"
  #firstImageOpen(myImg)
  myPicture=makePicture(myImg)
  #reduceBeard(myPicture)
  #ratioTest(myPicture)
  #lighten_fn(myPicture)
  #mylighten_Fn(myPicture,1.2,1.5,.5)
  #grayFn(myPicture)
  #greyScaleNew(myPicture)
  #reduceRedLen(myPicture)
  #firstColorSet(myPicture)
  #colorSetDay2(myPicture)
  #reduceRed(myPicture,0,len(getPixels(myPicture)),"Green")
  #logicalColorSet(myPicture)
  #mirroredImage(myPicture)
  #everyOtherLight(myPicture)
  #reduceRedColumns(myPicture,0,len(getPixels(myPicture)),"Red")
  #everyOther(myPicture)
  #rain(myPicture)
  #japaneseSun(myPicture)
  #japaneseSun(myPicture)
  #sunBeam(myPicture)
  #colorDistance(myPicture)
  sepiaTint(myPicture)
  #diagonal(myPicture)
  #circle(myPicture,0,0,50)
  glasses(myPicture)
  #exampleTeach(myPicture)
  #everyOtherBlack(myPicture)
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
def japaneseSun(myPicture):
 myColor=makeColor(0,0,0)
 pixels = getPixels(myPicture)
 height = getHeight(myPicture)
 width = getWidth(myPicture)
 slope = float(float(height)/float(width))
 slopeInverse = float(float(width)/float(height))
 lines = 9
 xLinePosArray = ""
  
 print height
 print width
 print slope
 for i in range(0,len(pixels)):
  one_pixel=pixels[i]
  xPix=getX(one_pixel)
  yPix=getY(one_pixel)
  if int(slope*8*xPix)<yPix<int(slope*9*xPix) or int(slopeInverse*8*yPix)<xPix<int(slopeInverse*9*yPix):
    my_red=getRed(one_pixel)
    my_green=getGreen(one_pixel)*.3
    my_blue=getBlue(one_pixel)*.3
    setColor(one_pixel,makeColor(my_red,my_green,my_blue))
  elif int(slope*6*xPix)<yPix<int(slope*7*xPix) or int(slopeInverse*6*yPix)<xPix<int(slopeInverse*7*yPix):
    my_red=getRed(one_pixel)
    my_green=getGreen(one_pixel)*.3
    my_blue=getBlue(one_pixel)*.3
    setColor(one_pixel,makeColor(my_red,my_green,my_blue))
  elif int(slope*4*xPix)<yPix<int(slope*5*xPix) or int(slopeInverse*4*yPix)<xPix<int(slopeInverse*5*yPix):
    my_red=getRed(one_pixel)
    my_green=getGreen(one_pixel)*.3
    my_blue=getBlue(one_pixel)*.3
    setColor(one_pixel,makeColor(my_red,my_green,my_blue))
  elif int(slope*2*xPix)<yPix<int(slope*3*xPix) or int(slopeInverse*2*yPix)<xPix<int(slopeInverse*3*yPix):
    my_red=getRed(one_pixel)
    my_green=getGreen(one_pixel)*.3
    my_blue=getBlue(one_pixel)*.3
    setColor(one_pixel,makeColor(my_red,my_green,my_blue))
  elif int(xPix)>yPix and xPix<int(2*yPix):
    my_red=getRed(one_pixel)
    my_green=getGreen(one_pixel)*.3
    my_blue=getBlue(one_pixel)*.3
    setColor(one_pixel,makeColor(my_red,my_green,my_blue))
  else:
    my_red=getRed(one_pixel)
    my_green=getGreen(one_pixel)
    my_blue=getBlue(one_pixel)
    setColor(one_pixel,makeColor(my_red,my_green,my_blue))
###################################################  
def colorDistance(myPicture):
  boat=makeColor(26,56,48)
  water=makeColor(126,132,132) 
  water2=makeColor(171,183,181)
  
  for i in getPixels(myPicture):
    theColor=getColor(i)
    if distance(theColor,boat) < 150:
      my_red=34
      my_green=155
      my_blue=233
      setColor(i,makeColor(my_red,my_green,my_blue))
    elif distance(theColor,water) < 50:
      my_red=getRed(i)-145
      my_green=getGreen(i)-0
      my_blue=getBlue(i)-65
      setColor(i,makeColor(my_red,my_green,my_blue))
    elif distance(theColor,water2) < 50:
      my_red=30
      my_green=65
      my_blue=122
      setColor(i,makeColor(my_red,my_green,my_blue)) 
####################################################      
def rain(myPicture):
  myColor=makeColor(0,0,0)
  pixels = getPixels(myPicture)
  height = getHeight(myPicture)
  width = getWidth(myPicture)
  checker = 0
  newRed=0
  
  print height
  print width
  
  for i in range(0,width):
    one_pixel=pixels[i]
    checker = checker + 1
    xPix=getX(one_pixel)
    yPix=getY(one_pixel)
    newRed = newRed + 10
    newGreen = 0
    newBlue = 0
    if xPix==checker-1:
      pixel = pixels[i]
      #newRed=255-getRed(one_pixel)
      #newBlue=255-getBlue(one_pixel)
      #newGreen=255-getGreen(one_pixel)
      setRed(one_pixel,255)
      setBlue(one_pixel,255)
      setGreen(one_pixel,255)
    if checker == width:
      checker = 0
   # if getX(pixels[i])< getY(pixels[i])/2:
     # setColor(pixels[i],myColo  
##################################################
def sunBeam(myPicture):
  myColor=makeColor(0,0,0)
  pixels = getPixels(myPicture)
  height = getHeight(myPicture)
  width = getWidth(myPicture)
  slope = float(float(height)/float(width))
  lines = 8
  
  print height
  print width
  print slope
  print width/2
  print height/2
  for i in range(0,len(pixels)):
    one_pixel=pixels[i]
    xPix=getX(one_pixel)
    yPix=getY(one_pixel)
    for j in range(lines,0,-1):
      transpose = (height/2)-(j*(width/2))

      if  yPix==(j*xPix)+transpose or xPix==(yPix/j)+transpose:
        if yPix > height/2:
          distanceFromY = yPix - (height/2)
          correctiveY=(height/2)-distanceFromY
          print correctiveY
          print xPix
          newX=xPix
        setColor(pixels[i],myColor)
        pixel = pixels[i]
        #newRed=255-getRed(one_pixel)
        #newBlue=255-getBlue(one_pixel)
        #newGreen=255-getGreen(one_pixel)
        #setRed(one_pixel,newRed)
        #setBlue(one_pixel,newBlue)
        #setGreen(one_pixel,newGreen)
        setColor(pixels[i],myColor)
   # if getX(pixels[i])< getY(pixels[i])/2:
     # setColor(pixels[i],myColor)
    #  pixel = pixels[i]
#######################################################################  
def circle(myPicture,xCenter,yCenter,radius):
  myColor=makeColor(0,0,0)
  pixels = getPixels(myPicture)
  for i in range(0,len(pixels)):
    one_pixel=pixels[i]
    xPix=getX(one_pixel)
    yPix=getY(one_pixel)
    radicand = radius**2-(xPix-xCenter)**2
    if radicand == abs(radicand):
      halfCircUp=int(yCenter-sqrt(radicand))
      halfCircDown=int(yCenter+sqrt(radicand))
      if yPix > halfCircUp and yPix < halfCircDown:
        pixel = pixels[i]
        newRed=getRed(one_pixel)*.3
        newBlue=getBlue(one_pixel)*.3
        newGreen=getGreen(one_pixel)*.3
        setRed(one_pixel,newRed)
        setBlue(one_pixel,newBlue)
        setGreen(one_pixel,newGreen)
##########################################################  
def exampleTeach(myPicture):
  pixels = getPixels(myPicture)
  for i in range(0,len(pixels)):
    one_pixel=pixels[i]
    xPix=getX(one_pixel)
    yPix=getY(one_pixel)
    print "Pixel Number:",
    print i 
    print "X Coordinate:",
    print xPix
    print "Y Coordinate:",
    print yPix
    print "Color: ",
    print one_pixel
    
#################################################
def glasses(myPicture):
  myColor=makeColor(0,0,0)
  pixels = getPixels(myPicture)
  for i in range(0,len(pixels)):
    one_pixel=pixels[i]
    xPix=getX(one_pixel)
    yPix=getY(one_pixel)
    rootTestEye1 = 400-(xPix-245)**2  #400=radius^2 245 = x center
    rootTestEye2 = 400-(xPix-316)**2
    if rootTestEye1 == abs(rootTestEye1):
      eye1Up=int(135-sqrt(rootTestEye1)) #135 = y center
      eye1Down=int(135+sqrt(rootTestEye1))
      if yPix > eye1Up and yPix < eye1Down:
        pixel = pixels[i]
      #setColor(pixels[i],myColor)
        newRed=getRed(one_pixel)*.5
        newBlue=getBlue(one_pixel)*.5
        newGreen=getGreen(one_pixel)*.5
        setRed(one_pixel,newRed)
        setBlue(one_pixel,newBlue)
        setGreen(one_pixel,newGreen)
    if rootTestEye2 == abs(rootTestEye2):
      eye2Up=int(135-sqrt(rootTestEye2))
      eye2Down=int(135+sqrt(rootTestEye2))
      if yPix > eye2Up and yPix < eye2Down:
        pixel = pixels[i]
      #setColor(pixels[i],myColor)
        newRed=getRed(one_pixel)*.5
        newBlue=getBlue(one_pixel)*.5
        newGreen=getGreen(one_pixel)*.5
        setRed(one_pixel,newRed)
        setBlue(one_pixel,newBlue)
        setGreen(one_pixel,newGreen)
    if yPix == 136 and 264 < xPix < 297:
      setColor(pixels[i],myColor)
    if yPix == int((xPix)*.275862)+44 and 365 > xPix > 336: #.2758=slope 44=offset(b)
      setColor(pixels[i],myColor)
    if yPix == int((xPix)*-.647)+281 and 208<xPix<225: 
      setColor(pixels[i],myColor)
       
   # if getX(pixels[i])< getY(pixels[i])/2:
     # setColor(pixels[i],myColor)
    #  pixel = pixels[i]

####################################################
def diagonal(myPicture):
  myColor=makeColor(0,0,0)
  pixels = getPixels(myPicture)
  height = getHeight(myPicture)
  width = getWidth(myPicture)
  slope = float(float(height)/float(width))
  print height
  print width
  print slope
  for i in range(0,len(pixels)):
    one_pixel=pixels[i]
    xPix=getX(one_pixel)
    yPix=getY(one_pixel)
    if yPix < slope*xPix:
      #setColor(pixels[i],myColor)
      pixel = pixels[i]
      newRed=255-getRed(one_pixel)
      newBlue=255-getBlue(one_pixel)
      newGreen=255-getGreen(one_pixel)
      setRed(one_pixel,newRed)
      setBlue(one_pixel,newBlue)
      setGreen(one_pixel,newGreen)
   # if getX(pixels[i])< getY(pixels[i])/2:
     # setColor(pixels[i],myColor)
    #  pixel = pixels[i]
########################################################
def reduceBeard(myPicture):
  pixels = getPixels(myPicture)
  for i in range(0,len(pixels)/2.7):
  #for i in range(len(pixels,len(pixels)):
    one_pixel=pixels[i]
    if getBlue(one_pixel) > 230 and getRed(one_pixel) > 95 and getGreen(one_pixel) >150:
      newRed=255-getRed(one_pixel)
      newBlue=255-getBlue(one_pixel)
      newGreen=255-getGreen(one_pixel)
      setRed(one_pixel,newRed)
      setBlue(one_pixel,newBlue)
      setGreen(one_pixel,newGreen)
#####################Day 2##############################
def everyOtherBlack(myPicture):
  myColor=makeColor(0,0,0)
  pixels = getPixels(myPicture)
  height = getHeight(myPicture)
  width = getWidth(myPicture)
  for i in range(0,len(pixels),2):
    pixel = pixels[i]
    setColor(pixel,myColor)
  for i in range(0,len(pixels)):
    if (getY(pixels[i]))%2>0:
      setColor(pixels[i],myColor)
      pixel = pixels[i]
######################################################
def reduceRedColumns(myPicture,startPx,stopPx,whatColor):
  theWidth=getWidth(myPicture)
  theHeight=getHeight(myPicture)

  pixels = getPixels(myPicture)
  for i in range(startPx,stopPx):
  #for i in range(len(pixels)/2,len(pixels)):
    one_pixel=pixels[i]
    if whatColor == "Red" and getX(one_pixel) < (theWidth*.5):
      newRed=getRed(one_pixel)*.5
      setRed(one_pixel,newRed)
    if whatColor == "Blue":
      newBlue=getBlue(one_pixel)*.5
      setBlue(one_pixel,newBlue)
    if whatColor == "Green":
      newGreen=getGreen(one_pixel)*.5
      setGreen(one_pixel,newGreen)  
######################################################
def reduceRedLen(myPicture):
  pixels=getPixels(myPicture)
  for i in range(0,len(pixels)):
    one_pixel=pixels[i]
    pix_value=getRed(one_pixel)
    setRed(one_pixel,pix_value*.5) 
########################################################
def grayFn(myPicture):
  for i in getPixels(myPicture):
    theGray=(getRed(i) + getGreen(i) + getBlue(i))/3
    setRed(i,theGray)
    setGreen(i,theGray)
    setBlue(i,theGray)
########################################################  
def mylighten_Fn(myPicture,redMulti,greenMulti,blueMulti):
  for i in getPixels(myPicture):
    newRed=getRed(i)*redMulti
    newGreen=getGreen(i)*greenMulti
    newBlue=getBlue(i)*blueMulti
    setRed(i,newRed)
    setGreen(i,newGreen)
    setBlue(i,newBlue)
########################################################    
def everyOther(myPicture):
  myColor=makeColor(0,0,0)
  pixels = getPixels(myPicture)
  height = getHeight(myPicture)
  width = getWidth(myPicture)
  for i in range(0,len(pixels),2):
    pixel = pixels[i]
    newRed=getRed(pixel)*.5
    newGreen=getGreen(pixel)*2.5
    newBlue=getBlue(pixel)*.5
    setRed(pixel,newRed)
    setGreen(pixel,newGreen)
    setBlue(pixel,newBlue)
    #setColor(pixel,myColor)
  for i in range(0,len(pixels)):
    if (getY(pixels[i]))%2>0:
      #setColor(pixels[i],myColor)
      pixel = pixels[i]
      newRed=getRed(pixel)*.5
      newGreen=getGreen(pixel)*.5
      newBlue=getBlue(pixel)*2.5
      setRed(pixel,newRed)
      setGreen(pixel,newGreen)
      setBlue(pixel,newBlue)
########################################################
def lighten_fn(myPicture):
  for i in getPixels(myPicture):
    current_value=getColor(i)
    current_value=makeLighter(current_value)
    setColor(i,current_value)
########################################################
def everyOtherLight(myPicture):
  myColor=makeColor(0,0,0)
  pixels = getPixels(myPicture)
  widthStep = 0
  height = getHeight(myPicture)
  width = getWidth(myPicture)
  for i in range(0,len(pixels),2):
    newGreen=getGreen(i)*1
    newBlue=getBlue(i)*1.25
    newRed=getRed(i)*1
    setRed(i,newRed)
    setBlue(i,newBlue)
    setGreen(i,newGreen)
  for i in range(0,len(pixels)):
    new2Green=getGreen(i)*1
    new2Blue=getBlue(i)*1.25
    new2Red=getRed(i)*1
    if (getY(pixels[i]))%2>0:
      setRed(i,new2Red)
      setBlue(i,new2Blue)
      setGreen(i,new2Green)
########################################################
def mirroredImage(myPicture):
  pixels = getPixels(myPicture)
  target = len(pixels)/2
  for i in range(0,len(pixels)):
    pixel1 = pixels[i]
    color1 = getColor(pixel1)
    pixel2 = pixels[target]
    setColor(pixel2,color1)
    target = target -1
    
########################################################
def logicalColorSet(myPicture):
  myPurple=makeColor(10,120,120)
  for i in getPixels(myPicture):
    theGreen=getGreen(i)
    theBlue=getBlue(i)
    theRed=getRed(i)
    if getX(i) > 100 and getY > 100:
      if theGreen > 140:
        newGreen=makeColor(theGreen-60)
        setColor(i,myPurple)
########################################################
def reduceRed(myPicture,startPx,stopPx,whatColor):
  pixels = getPixels(myPicture)
  for i in range(startPx,stopPx):
  #for i in range(len(pixels)/2,len(pixels)):
    one_pixel=pixels[i]
    if whatColor == "Red":
      newRed=getRed(one_pixel)*.5
      setRed(one_pixel,newRed)
    if whatColor == "Blue":
      newBlue=getBlue(one_pixel)*.5
      setBlue(one_pixel,newBlue)
    if whatColor == "Green":
      newGreen=getGreen(one_pixel)*.5
      setGreen(one_pixel,newGreen)
#####################Day 2##############################
def colorSetDay2(myPicture):
  myPurple=makeColor(150,235,200)
  for i in getPixels(myPicture):
    newGreen=getGreen(i)*1
    newBlue=getBlue(i)*1.25
    newRed=getRed(i)*1
    setRed(i,newRed)
    setBlue(i,newBlue)
    setGreen(i,newGreen)
####################Day One for Images##############################
def firstColorSet(myPicture):
  myPurple=makeColor(150,235,200)
  for i in getPixels(myPicture):
    theGreen=getGreen(i)
    theBlue=getBlue(i)
    theRed=getRed(i)
    if theGreen > 240 and theBlue > 240 and theRed > 240:
      newGreen=makeColor(theGreen-60)
      setColor(i,myPurple)

def firstImageOpen(myImg):
  myPicture=makePicture(myImg)
  explore(myPicture)
  print getPixel(myPicture, 0, 0)
  
  