set sample=%1
echo Challenge 123-1E: Sample %sample%
echo ==========================
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
Challenge_123-1E < sample%sample%.dat
echo.
pause