@echo off
echo Challenge 110E
echo ==============

call:test "Jr;;p ept;f" "Hello World"
call:test "Lmiyj od ,u jrtp" "Knuth is my hero"

pause

exit

:test
echo Input: "%~1"
echo Expected output: "%~2"
echo|set /p=Actual output: "
Challenge_110E "%~1"
echo "
echo.
echo.