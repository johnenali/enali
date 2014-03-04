add_library (imageFuns salt.cpp colorReduce.cpp sharpen.cpp)
install (TARGETS imageFuns DESTINATION lib)
install (FILES imageFuns.hpp DESTINATION include)
