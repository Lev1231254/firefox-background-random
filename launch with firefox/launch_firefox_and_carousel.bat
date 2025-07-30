@echo off
set LOGFILE=C:\Users\Lev\projects\firefox-background-random\logfile.txt

echo Starting background-randomizer-firefox.exe... >> %LOGFILE%
start /B "" "C:\Users\Lev\projects\firefox-background-random\out\build\GCC 15.1.0 x86_64-w64-mingw32 (ucrt64)\background-randomizer-firefox.exe" >> %LOGFILE% 2>&1

start /B "" "C:\Users\Lev\AppData\Local\Mozilla Firefox\firefox.exe" 

echo Stopping background-randomizer-firefox.exe... >> %LOGFILE%
taskkill /IM "background-randomizer-firefox.exe" /F >> %LOGFILE% 2>&1


echo Log completed at %date% %time% >> %LOGFILE%
