@echo off
echo Challenge 129E
echo ==============

call:test "abbccc" "bbccc"
call:test "abcabcabcabccc" "bccc"
call:test "qwertyytrewq" "tyyt"

pause

exit

:test
echo Input: "%~1"
echo Expected output: "%~2"
echo|set /p=Actual output: "
Challenge_129E "%~1"
echo "
echo.
echo.