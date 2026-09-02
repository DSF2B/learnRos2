import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/zilu/myProgramFile/learnRos2/cpp/install/ch3_status_publisher'
