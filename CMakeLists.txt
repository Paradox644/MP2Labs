cmake_minimum_required(VERSION 3.0) #Ïðîâåðêà âåðñèè CMake.
set(PROJECT_NAME MyLabs) #Ñîçäàåì îáû÷íóþ ëîêàëüíóþ ïåðåìåííóþ ñ èìåíåì ïðîåêòà
project(${PROJECT_NAME}) # Íàçâàíèå ïðîåêòà

set(TMatrix TMatrix)
set(TMatrixlib TMatrixlib)
set(TMatrixtest TMatrixtest)

set(TStack TStack)
set(TStacklib TStacklib)
set(TStacktest TStacktest)

set(TQueue TQueue)
set(TQueuelib TQueuelib)
set(TQueuetest TQueuetest)

set(Postfix Postfix)
set(Postfixlib Postfixlib)
set(Postfixtest Postfixtest)


set(TPolinom TPolinom)
set(TPolinomlib TPolinomlib)
set(TPolinomtest TPolinomtest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Ñîçäàåòñÿ ïåðåìåííàÿ CMAKE_CONFIGURATION_TYPES ñî çíà÷åíèåì "Debug;Release" è ìåòêîé/ðàçäåëîì Configs, ïåðåìåííàÿ ñîõðàíèåòñÿ â ñïåöèàëüíîì ôàéëå äîñòóïíîì èç âñåõ ôàéëîâ,
if(NOT CMAKE_BUILD_TYPE) # ïðîâåðêà èìåþùèõñÿ ó êîìïèëÿòîðà âàðèàíòîâ ñáîðêè
    set(CMAKE_BUILD_TYPE Release) #Åñëè íåò òî óñòàíàâëèâàåì Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TMatrixlib)
add_subdirectory(TMatrix)
add_subdirectory(TMatrixlib)
add_subdirectory(TMatrixtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TStacklib)
add_subdirectory(TStack)
add_subdirectory(TStacklib)
add_subdirectory(TStacktest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TQueuelib)
add_subdirectory(TQueue)
add_subdirectory(TQueuelib)
add_subdirectory(TQueuetest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Postfixlib)
add_subdirectory(Postfix)
add_subdirectory(Postfixlib)
add_subdirectory(Postfixtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TPolinomlib)
add_subdirectory(TPolinom)
add_subdirectory(TPolinomlib)
add_subdirectory(TPolinomtest)

#file(GLOB hdrs "*.h*") #Äîáàâëÿåì â ïåðåìåííóþ hdrs âñå ôàéëû ñ ðàñøèðåíèåì .h
#file(GLOB srcs "*.cpp") #Äîáàâëÿåì â ïåðåìåííóþ srcs âñå ôàéëû ñ ðàñøèðåíèåì .cpp
#include_directories(lib1)
#add_executable(${{PROJECT_NAME}} ${{srcs}} ${{hdrs}}) #Ñîçäàåì ïðîåêò ñ èìåíåì èç ïåðåìåííîé ${{PROJECT_NAME}}, â íåãî äîáàâëÿþòñÿ ôàéëû èç ïåðåìåííûõ ${{srcs}} è ${{hdrs}}
#Ñîáèðàåì ïðîåêò â ïîääèðåêòîðèè lib1
#target_link_libraries(${{PROJECT_NAME}} ${{MyLib1}}) #Ïîäêëþ÷àåì ê ïðîåêòó ñ èìåíåì ${{PROJECT_NAME}} áèáëèîòåêó ñ èìåíåì ${{MyLib1}}