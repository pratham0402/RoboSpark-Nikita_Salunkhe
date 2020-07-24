import cv2
import numpy as np

# ----------------------------------------------------------------------------------------------------------------------
img = cv2.imread('rose_flower.jpg')
# print(img.shape)
img = cv2.resize(img,(300,600))
def fun(x):
    pass

# masking code ---------------------------------------------------------------------------------------------------------
# cv2.namedWindow('masked')
#
# cv2.createTrackbar('blue low','masked',0,255,fun)
# cv2.createTrackbar('green low', 'masked', 0, 255, fun)
# cv2.createTrackbar('red low', 'masked', 0, 255, fun)
# cv2.createTrackbar('blue high', 'masked', 0, 255, fun)
# cv2.createTrackbar('green high', 'masked', 0, 255, fun)
# cv2.createTrackbar('red high', 'masked', 0, 255, fun)
#
# while True:
#     # cv2.imshow('original', img)
#     blt = cv2.getTrackbarPos('blue low', 'masked')
#     glt = cv2.getTrackbarPos('green low', 'masked')
#     rlt = cv2.getTrackbarPos('red low', 'masked')
#     bht = cv2.getTrackbarPos('blue high', 'masked')
#     ght = cv2.getTrackbarPos('green high', 'masked')
#     rht = cv2.getTrackbarPos('red high', 'masked')
#
#     low = np.array([blt,glt,rlt], np.uint8)
#     high = np.array([bht,ght,rht], np.uint8)
#
#     # mask = cv2.inRange(img,low,high)
#     # mask = cv2.resize(mask,(300,600))
#
#     # cv2.imshow('masked',mask)
#
#     k = cv2.waitKey(1)
#     if k == 32:
#         break

# masking image --------------------------------------------------------------------------------------------------------
final_low = np.array([25,18,14], np.uint8)
final_high = np.array([196,93,255], np.uint8)
mask = cv2.inRange(img,final_low,final_high)

# blurring -------------------------------------------------------------------------------------------------------------
kernel = np.array(([4,5,6],[5,8,9],[6,3,1]),np.uint8)

# filter2D
blurred = cv2.filter2D(mask,-1,kernel)

# averaging
averaging = cv2.blur(mask,(5,5))

# gaussian
gaussian = cv2.GaussianBlur(mask,(5,5),0)

# median
median = cv2.medianBlur(mask,5)

# bilateralFilter
bilateral = cv2.bilateralFilter(mask,9,80,80)

# flowerpot and name ---------------------------------------------------------------------------------------------------
font = cv2.FONT_HERSHEY_DUPLEX
final_img = cv2.putText(img,'ROSE',(0,150),font,1,(0,0,0),2)

final_img = cv2.line(img, (10, 500), (50, 600), (42, 42, 165), 2)
final_img = cv2.line(img, (200, 500), (160, 600), (42, 42, 165), 2)
final_img = cv2.line(img, (50, 600), (160, 600), (42, 42, 165), 2)
final_img = cv2.ellipse(img,(105,500),(95,10),0,0,360,(42, 42, 165), 2)

# getting image --------------------------------------------------------------------------------------------------------
var = [mask, blurred, averaging, gaussian, median, bilateral, final_img]
names = ['masked', 'filter2D', 'averaging', 'gaussian', 'median', 'bilateralFilter', 'final_img']

for i in range(len(var)):
    cv2.imshow(names[i],var[i])

# saving ---------------------------------------------------------------------------------------------------------------
for i in range(len(var)):
    cv2.imwrite(f'E:/TRF/upl_task/RoboSpark-Nikita_Salunkhe/24-7-20_IP_Task-1_Prathamesh_Yadav/{names[i]}.jpg',var[i])

# ----------------------------------------------------------------------------------------------------------------------
cv2.waitKey(0)
cv2.destroyAllWindows()