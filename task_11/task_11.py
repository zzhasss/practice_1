import cv2
import numpy as np

image = cv2.imread("test2.jpg")

blur = cv2.GaussianBlur(image, (11, 11), 0)
hsv = cv2.cvtColor(blur, cv2.COLOR_BGR2HSV)

lower = np.array((36, 25, 25), np.uint8)
upper = np.array((70, 255, 255), np.uint8)

mask = cv2.inRange(hsv, lower, upper)

cv2.imshow("Img", mask)
cv2.waitKey(0)
cv2.destroyAllWindows()