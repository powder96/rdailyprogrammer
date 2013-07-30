@echo off

setlocal EnableDelayedExpansion

echo Challenge 108E
echo ==============

call:test "239487" "2.39487 x 10^5"
call:test ".654" "6.54 x 10^-1"
call:test "" "RANDOM"
REM Bonus: call:test "0.935 x 10^-3" "935"

pause

exit

:test
setlocal DisableDelayedExpansion
set param1=%~1
set param2=%~2
setlocal EnableDelayedExpansion
echo Input: "!param1!"
echo Expected output: "!param2!"
echo|set /p=Actual output: "
Challenge_108E "!param1!"
echo "
echo.
echo.