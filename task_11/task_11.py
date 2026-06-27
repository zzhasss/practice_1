import cv2
import numpy as np

image = cv2.imread("test2.jpg")

blur = cv2.GaussianBlur(image, (11,11),0)
hsv = cv2.cvtColor(blur, cv2.COLOR_BGR2HSV)

mask = cv2.inRange(hsv,
                   np.array((36,25,25),np.uint8),
                   np.array((70,255,255),np.uint8))

contours,_ = cv2.findContours(mask, cv2.RETR_EXTERNAL,
                              cv2.CHAIN_APPROX_SIMPLE)

cnt = contours[0]

x,y,w,h = cv2.boundingRect(cnt)

cv2.circle(image,(x,y),8,(0,0,255),-1)

cv2.imshow("Img",image)
cv2.waitKey(0)
cv2.destroyAllWindows()