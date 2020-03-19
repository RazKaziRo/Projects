@echo off

del "%AppData%\Microsoft\Windows\Start Menu\Programs\Brain Fuel.lnk"

set folder="%~dp0" 
cd /d %folder% 
for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)