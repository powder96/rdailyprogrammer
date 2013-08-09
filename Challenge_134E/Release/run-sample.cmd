set sample=%1
echo Sample %sample%
echo ========
echo.
echo Input
echo -----
type sample%sample%.dat
echo.
echo.
echo Expected output
echo ---------------
type sample%sample%.txt
echo.
echo Actual output
echo -------------
Challenge_134E < sample%sample%.dat
echo.
pause