set sample=%1
echo Challenge 121E: Sample %sample%
echo ========================
echo.
echo Input
echo -----
type sample%sample%.dat
echo.
echo.
if not exist sample%sample%.txt goto actualOutput
echo Expected output
echo ---------------
type sample%sample%.txt
echo.
:actualOutput
echo Actual output
echo -------------
Challenge_121E < sample%sample%.dat
echo.
pause