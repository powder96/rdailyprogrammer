@echo off
echo Challenge 109E
echo ==============

call:test "123" "true"
call:test "123.123" "false"
call:test "abc" "false"

pause

exit

:test
echo Input: "%~1"
echo Expected output: "%~2"
echo|set /p=Actual output: "
Challenge_109E "%~1"
echo "
echo.
echo.