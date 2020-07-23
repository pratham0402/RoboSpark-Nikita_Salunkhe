import cv2

img = cv2.imread('text.jpg',-1)                       # reading image
gray_img = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)       # convert into gray scale
hsv_img = cv2.cvtColor(img,cv2.COLOR_RGB2HSV)         # convert into HSV

new_img = cv2.resize(img,(300,300))
print(img.shape)                                      # shape of original
print(new_img.shape)                                  # shape of new image
print(img.size)                                       # size of original
print(new_img.size)                                   # size of new image

# simple threshold -----------------------------------------------------------------------------------------------------
ret1,thresh1 = cv2.threshold(gray_img,155,255,cv2.THRESH_BINARY)
ret2,thresh2 = cv2.threshold(gray_img,155,255,cv2.THRESH_BINARY_INV)

# adaptive threshold ---------------------------------------------------------------------------------------------------
adp_thresh3 = cv2.adaptiveThreshold(gray_img,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,5,15)
adp_thresh4 = cv2.adaptiveThreshold(gray_img,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,5,15)

# ----------------------------------------------------------------------------------------------------------------------
titles = ['original','resized','gray_image','HSV_image','simple_threshold_binary','simple_threshold_binary_inv','adaptive_thresh_mean','adaptive_thresh_guass']
names = [img,new_img,gray_img,hsv_img,thresh1,thresh2,adp_thresh3,adp_thresh4]

# showing images -------------------------------------------------------------------------------------------------------
for i in range(len(titles)):
    cv2.imshow(titles[i],names[i])

# saving all images ----------------------------------------------------------------------------------------------------
for i in range(1,len(titles)):
    cv2.imwrite(f"E:/TRF/upl_task/RoboSpark-Nikita_Salunkhe/23-7-20_IP_Task-1_Prathamesh_Yadav/{titles[i]}.jpg",names[i])

# ----------------------------------------------------------------------------------------------------------------------
cv2.waitKey(0)
cv2.destroyWindow()