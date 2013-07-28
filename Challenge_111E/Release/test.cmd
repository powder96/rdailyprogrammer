@echo off
echo Challenge #111E
echo ===============

call:test "adf*lp" "adp"
call:test "a*o" ""
call:test "*dech*" "ec"
call:test "de**po" "do"
call:test "sa*n*ti" "si"
call:test "abc" "abc"

pause

exit

:test
echo Input: "%~1"
echo Expected output: "%~2"
echo|set /p=Actual output: "
Challenge_111E "%~1"
echo "
echo.
echo.