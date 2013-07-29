@echo off
echo Challenge 113E
echo ==============

call:test "0" "int"
call:test "123" "int"
call:test "+123" "int"
call:test "-123" "int"
call:test "123.456" "float"
call:test "+123.456" "float"
call:test "-123.456" "float"
call:test "20-11-2012" "date"
call:test "" "string"
call:test "+" "string"
call:test "-" "string"
call:test "123abc" "string"
call:test "123.456abc" "string"
call:test "20-11-2012-10" "string"
call:test "Hello, World!" "string"
call:test "Hello 123" "string"

pause

exit

:test
echo|set /p='%~1' = 
Challenge_113E "%~1"
echo  (expected: %~2)