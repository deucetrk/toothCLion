cmake_minimum_required(VERSION 3.14)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp include/header/Vec3.h include/resouce/Vec3.cpp include/header/Resources.h include/header/SphereNode.h include/resouce/SphereNode.cpp include/header/SphereTree.h include/header/Matrix4.h include/resouce/Matrix4.cpp include/resouce/SphereTree.cpp include/header/Misc.h include/header/buildparams.h include/header/Bankhelper.h )