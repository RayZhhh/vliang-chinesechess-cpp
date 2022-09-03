import ctypes
from ctypes import CDLL

dll = CDLL('testlib.dylib', winmode=False)

dll.test()