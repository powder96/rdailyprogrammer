set sample=%1
echo Sample %sample%
echo ========
echo.
echo Input
echo -----
type sample%sample%.dat
echo.
echo.
echo Output
echo ------
Challenge_130E < sample%sample%.dat
echo.
pause