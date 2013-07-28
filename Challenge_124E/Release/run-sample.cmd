set sample=%1
echo Challenge 124E: Sample %sample%
echo ========================
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
Challenge_124E sample%sample%.dat
echo.
pause