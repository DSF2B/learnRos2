import face_recognition
import cv2
from ament_index_python.packages import get_package_share_directory
import os

def main():
   #get image real path
   default_image_path = os.path.join(get_package_share_directory("demo_python_service"), 'resource/default.jpg')
   print(f"real path of image:{default_image_path}")
   
   image = cv2.imread(default_image_path)
   if image is None:
      print(f"无法读取图片: {default_image_path}")
      return
   face_locations = face_recognition.face_locations(image,number_of_times_to_upsample=1,model='hog')
   for top,right,bottom,left in face_locations:
      cv2.rectangle(image,(left,top),(right,bottom),[255,0,0],4)
   cv2.imshow('face recognition result:',image)
   cv2.waitKey(0)