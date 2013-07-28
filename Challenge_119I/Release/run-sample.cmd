set sample=%1
echo Challenge #119E - Sample %sample%
echo ==========================
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
Challenge_119I sample%sample%.dat
echo.
pause