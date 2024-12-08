import cv2

cam = cv2.VideoCapture(3)

# Check if the camera opened successfully
if not cam.isOpened():
    print("Error: Could not access the camera.")
    exit()

while True:
    _, frame = cam.read()
    if frame is None:
        print("Error: No frame captured.")
        break
    cv2.imshow('my cam', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):  # Press 'q' to exit
        break

cam.release()
cv2.destroyAllWindows()
