rem delete old solution/workspace files
rem
rmdir /S /Q ..\vs2019
rem
rem delete old compiled libraries
rem
del ..\..\lib\*.lib
rem
rem create new solution/workspace files
rem
"premake5.exe" --os=windows --file=premake5.lua vs2019
