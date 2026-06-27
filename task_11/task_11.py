import cv2

image = cv2.imread("test2.jpg")

cv2.imshow("Original", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
